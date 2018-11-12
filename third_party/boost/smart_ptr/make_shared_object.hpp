#ifndef BOOST_SMART_PTR_MAKE_SHARED_OBJECT_HPP_INCLUDED
#define BOOST_SMART_PTR_MAKE_SHARED_OBJECT_HPP_INCLUDED

//  make_shared_object.hpp
//
//  Copyright (c) 2007, 2008, 2012 Peter Dimov
//
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//
//  See http://www.boost.org/libs/smart_ptr/make_shared.html
//  for documentation.

#include <boost/config.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/smart_ptr/detail/sp_forward.hpp>
#include <boost/type_traits/type_with_alignment.hpp>
#include <boost/type_traits/alignment_of.hpp>
#include <cstddef>
#include <new>

namespace boost
{

namespace detail
{

template< std::size_t N, std::size_t A > struct sp_aligned_storage
{
    union type
    {
        char data_[ N ];
        typename std::type_with_alignment< A >::type align_;
    };
};

template< class T > class sp_ms_deleter
{
private:

    typedef typename sp_aligned_storage< sizeof( T ), ::std::alignment_of< T >::value >::type storage_type;

    bool initialized_;
    storage_type storage_;

private:

    void destroy()
    {
        if( initialized_ )
        {
#if defined( __GNUC__ )

            // fixes incorrect aliasing warning
            T * p = reinterpret_cast< T* >( storage_.data_ );
            p->~T();

#else

            reinterpret_cast< T* >( storage_.data_ )->~T();

#endif

            initialized_ = false;
        }
    }

public:

    sp_ms_deleter() BOOST_NOEXCEPT : initialized_( false )
    {
    }

    // optimization: do not copy storage_
    sp_ms_deleter( sp_ms_deleter const & ) BOOST_NOEXCEPT : initialized_( false )
    {
    }

    ~sp_ms_deleter()
    {
        destroy();
    }

    void operator()( T * )
    {
        destroy();
    }

    static void operator_fn( T* ) // operator() can't be static
    {
    }

    void * address() BOOST_NOEXCEPT
    {
        return storage_.data_;
    }

    void set_initialized() BOOST_NOEXCEPT
    {
        initialized_ = true;
    }
};

template< class T > struct sp_if_not_array
{
    typedef std::shared_ptr< T > type;
};

#if !defined( BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION )

template< class T > struct sp_if_not_array< T[] >
{
};

#if !defined( __BORLANDC__ ) || !BOOST_WORKAROUND( __BORLANDC__, < 0x600 )

template< class T, std::size_t N > struct sp_if_not_array< T[N] >
{
};

#endif

#endif

} // namespace detail

#if !defined( BOOST_NO_FUNCTION_TEMPLATE_ORDERING )
# define BOOST_SP_MSD( T ) std::detail::sp_inplace_tag< std::detail::sp_ms_deleter< T > >()
#else
# define BOOST_SP_MSD( T ) std::detail::sp_ms_deleter< T >()
#endif

// Zero-argument versions
//
// Used even when variadic templates are available because of the new T() vs new T issue

template< class T > typename std::detail::sp_if_not_array< T >::type make_shared()
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ) );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T();
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

template< class T > typename std::detail::sp_if_not_array< T >::type make_shared_noinit()
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ) );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T;
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

template< class T, class A > typename std::detail::sp_if_not_array< T >::type allocate_shared( A const & a )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ), a );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T();
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

template< class T, class A > typename std::detail::sp_if_not_array< T >::type allocate_shared_noinit( A const & a )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ), a );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T;
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

#if !defined( BOOST_NO_CXX11_VARIADIC_TEMPLATES ) && !defined( BOOST_NO_CXX11_RVALUE_REFERENCES )

// Variadic templates, rvalue reference

template< class T, class Arg1, class... Args > typename std::detail::sp_if_not_array< T >::type make_shared( Arg1 && arg1, Args && ... args )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ) );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T( std::detail::sp_forward<Arg1>( arg1 ), std::detail::sp_forward<Args>( args )... );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

template< class T, class A, class Arg1, class... Args > typename std::detail::sp_if_not_array< T >::type allocate_shared( A const & a, Arg1 && arg1, Args && ... args )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ), a );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T( std::detail::sp_forward<Arg1>( arg1 ), std::detail::sp_forward<Args>( args )... );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

#elif !defined( BOOST_NO_CXX11_RVALUE_REFERENCES )

// For example MSVC 10.0

template< class T, class A1 >
typename std::detail::sp_if_not_array< T >::type make_shared( A1 && a1 )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ) );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T(
        std::detail::sp_forward<A1>( a1 )
        );

    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

template< class T, class A, class A1 >
typename std::detail::sp_if_not_array< T >::type allocate_shared( A const & a, A1 && a1 )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ), a );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T( 
        std::detail::sp_forward<A1>( a1 )
        );

    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

template< class T, class A1, class A2 >
typename std::detail::sp_if_not_array< T >::type make_shared( A1 && a1, A2 && a2 )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ) );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T(
        std::detail::sp_forward<A1>( a1 ), 
        std::detail::sp_forward<A2>( a2 )
        );

    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

template< class T, class A, class A1, class A2 >
typename std::detail::sp_if_not_array< T >::type allocate_shared( A const & a, A1 && a1, A2 && a2 )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ), a );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T( 
        std::detail::sp_forward<A1>( a1 ), 
        std::detail::sp_forward<A2>( a2 )
        );

    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

template< class T, class A1, class A2, class A3 >
typename std::detail::sp_if_not_array< T >::type make_shared( A1 && a1, A2 && a2, A3 && a3 )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ) );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T(
        std::detail::sp_forward<A1>( a1 ), 
        std::detail::sp_forward<A2>( a2 ), 
        std::detail::sp_forward<A3>( a3 )
        );

    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

template< class T, class A, class A1, class A2, class A3 >
typename std::detail::sp_if_not_array< T >::type allocate_shared( A const & a, A1 && a1, A2 && a2, A3 && a3 )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ), a );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T( 
        std::detail::sp_forward<A1>( a1 ), 
        std::detail::sp_forward<A2>( a2 ), 
        std::detail::sp_forward<A3>( a3 )
        );

    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

template< class T, class A1, class A2, class A3, class A4 >
typename std::detail::sp_if_not_array< T >::type make_shared( A1 && a1, A2 && a2, A3 && a3, A4 && a4 )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ) );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T(
        std::detail::sp_forward<A1>( a1 ), 
        std::detail::sp_forward<A2>( a2 ), 
        std::detail::sp_forward<A3>( a3 ), 
        std::detail::sp_forward<A4>( a4 )
        );

    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

template< class T, class A, class A1, class A2, class A3, class A4 >
typename std::detail::sp_if_not_array< T >::type allocate_shared( A const & a, A1 && a1, A2 && a2, A3 && a3, A4 && a4 )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ), a );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T( 
        std::detail::sp_forward<A1>( a1 ), 
        std::detail::sp_forward<A2>( a2 ), 
        std::detail::sp_forward<A3>( a3 ), 
        std::detail::sp_forward<A4>( a4 )
        );

    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

template< class T, class A1, class A2, class A3, class A4, class A5 >
typename std::detail::sp_if_not_array< T >::type make_shared( A1 && a1, A2 && a2, A3 && a3, A4 && a4, A5 && a5 )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ) );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T(
        std::detail::sp_forward<A1>( a1 ), 
        std::detail::sp_forward<A2>( a2 ), 
        std::detail::sp_forward<A3>( a3 ), 
        std::detail::sp_forward<A4>( a4 ), 
        std::detail::sp_forward<A5>( a5 )
        );

    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

template< class T, class A, class A1, class A2, class A3, class A4, class A5 >
typename std::detail::sp_if_not_array< T >::type allocate_shared( A const & a, A1 && a1, A2 && a2, A3 && a3, A4 && a4, A5 && a5 )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ), a );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T( 
        std::detail::sp_forward<A1>( a1 ), 
        std::detail::sp_forward<A2>( a2 ), 
        std::detail::sp_forward<A3>( a3 ), 
        std::detail::sp_forward<A4>( a4 ), 
        std::detail::sp_forward<A5>( a5 )
        );

    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

template< class T, class A1, class A2, class A3, class A4, class A5, class A6 >
typename std::detail::sp_if_not_array< T >::type make_shared( A1 && a1, A2 && a2, A3 && a3, A4 && a4, A5 && a5, A6 && a6 )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ) );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T(
        std::detail::sp_forward<A1>( a1 ), 
        std::detail::sp_forward<A2>( a2 ), 
        std::detail::sp_forward<A3>( a3 ), 
        std::detail::sp_forward<A4>( a4 ), 
        std::detail::sp_forward<A5>( a5 ), 
        std::detail::sp_forward<A6>( a6 )
        );

    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

template< class T, class A, class A1, class A2, class A3, class A4, class A5, class A6 >
typename std::detail::sp_if_not_array< T >::type allocate_shared( A const & a, A1 && a1, A2 && a2, A3 && a3, A4 && a4, A5 && a5, A6 && a6 )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ), a );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T( 
        std::detail::sp_forward<A1>( a1 ), 
        std::detail::sp_forward<A2>( a2 ), 
        std::detail::sp_forward<A3>( a3 ), 
        std::detail::sp_forward<A4>( a4 ), 
        std::detail::sp_forward<A5>( a5 ), 
        std::detail::sp_forward<A6>( a6 )
        );

    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

template< class T, class A1, class A2, class A3, class A4, class A5, class A6, class A7 >
typename std::detail::sp_if_not_array< T >::type make_shared( A1 && a1, A2 && a2, A3 && a3, A4 && a4, A5 && a5, A6 && a6, A7 && a7 )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ) );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T(
        std::detail::sp_forward<A1>( a1 ), 
        std::detail::sp_forward<A2>( a2 ), 
        std::detail::sp_forward<A3>( a3 ), 
        std::detail::sp_forward<A4>( a4 ), 
        std::detail::sp_forward<A5>( a5 ), 
        std::detail::sp_forward<A6>( a6 ), 
        std::detail::sp_forward<A7>( a7 )
        );

    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

template< class T, class A, class A1, class A2, class A3, class A4, class A5, class A6, class A7 >
typename std::detail::sp_if_not_array< T >::type allocate_shared( A const & a, A1 && a1, A2 && a2, A3 && a3, A4 && a4, A5 && a5, A6 && a6, A7 && a7 )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ), a );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T( 
        std::detail::sp_forward<A1>( a1 ), 
        std::detail::sp_forward<A2>( a2 ), 
        std::detail::sp_forward<A3>( a3 ), 
        std::detail::sp_forward<A4>( a4 ), 
        std::detail::sp_forward<A5>( a5 ), 
        std::detail::sp_forward<A6>( a6 ), 
        std::detail::sp_forward<A7>( a7 )
        );

    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

template< class T, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8 >
typename std::detail::sp_if_not_array< T >::type make_shared( A1 && a1, A2 && a2, A3 && a3, A4 && a4, A5 && a5, A6 && a6, A7 && a7, A8 && a8 )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ) );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T(
        std::detail::sp_forward<A1>( a1 ), 
        std::detail::sp_forward<A2>( a2 ), 
        std::detail::sp_forward<A3>( a3 ), 
        std::detail::sp_forward<A4>( a4 ), 
        std::detail::sp_forward<A5>( a5 ), 
        std::detail::sp_forward<A6>( a6 ), 
        std::detail::sp_forward<A7>( a7 ), 
        std::detail::sp_forward<A8>( a8 )
        );

    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

template< class T, class A, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8 >
typename std::detail::sp_if_not_array< T >::type allocate_shared( A const & a, A1 && a1, A2 && a2, A3 && a3, A4 && a4, A5 && a5, A6 && a6, A7 && a7, A8 && a8 )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ), a );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T( 
        std::detail::sp_forward<A1>( a1 ), 
        std::detail::sp_forward<A2>( a2 ), 
        std::detail::sp_forward<A3>( a3 ), 
        std::detail::sp_forward<A4>( a4 ), 
        std::detail::sp_forward<A5>( a5 ), 
        std::detail::sp_forward<A6>( a6 ), 
        std::detail::sp_forward<A7>( a7 ), 
        std::detail::sp_forward<A8>( a8 )
        );

    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

template< class T, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9 >
typename std::detail::sp_if_not_array< T >::type make_shared( A1 && a1, A2 && a2, A3 && a3, A4 && a4, A5 && a5, A6 && a6, A7 && a7, A8 && a8, A9 && a9 )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ) );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T(
        std::detail::sp_forward<A1>( a1 ), 
        std::detail::sp_forward<A2>( a2 ), 
        std::detail::sp_forward<A3>( a3 ), 
        std::detail::sp_forward<A4>( a4 ), 
        std::detail::sp_forward<A5>( a5 ), 
        std::detail::sp_forward<A6>( a6 ), 
        std::detail::sp_forward<A7>( a7 ), 
        std::detail::sp_forward<A8>( a8 ), 
        std::detail::sp_forward<A9>( a9 )
        );

    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

template< class T, class A, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9 >
typename std::detail::sp_if_not_array< T >::type allocate_shared( A const & a, A1 && a1, A2 && a2, A3 && a3, A4 && a4, A5 && a5, A6 && a6, A7 && a7, A8 && a8, A9 && a9 )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ), a );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T( 
        std::detail::sp_forward<A1>( a1 ), 
        std::detail::sp_forward<A2>( a2 ), 
        std::detail::sp_forward<A3>( a3 ), 
        std::detail::sp_forward<A4>( a4 ), 
        std::detail::sp_forward<A5>( a5 ), 
        std::detail::sp_forward<A6>( a6 ), 
        std::detail::sp_forward<A7>( a7 ), 
        std::detail::sp_forward<A8>( a8 ), 
        std::detail::sp_forward<A9>( a9 )
        );

    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

#else

// C++03 version

template< class T, class A1 >
typename std::detail::sp_if_not_array< T >::type make_shared( A1 const & a1 )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ) );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T( a1 );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

template< class T, class A, class A1 >
typename std::detail::sp_if_not_array< T >::type allocate_shared( A const & a, A1 const & a1 )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ), a );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T( a1 );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

template< class T, class A1, class A2 >
typename std::detail::sp_if_not_array< T >::type make_shared( A1 const & a1, A2 const & a2 )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ) );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T( a1, a2 );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

template< class T, class A, class A1, class A2 >
typename std::detail::sp_if_not_array< T >::type allocate_shared( A const & a, A1 const & a1, A2 const & a2 )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ), a );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T( a1, a2 );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

template< class T, class A1, class A2, class A3 >
typename std::detail::sp_if_not_array< T >::type make_shared( A1 const & a1, A2 const & a2, A3 const & a3 )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ) );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T( a1, a2, a3 );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

template< class T, class A, class A1, class A2, class A3 >
typename std::detail::sp_if_not_array< T >::type allocate_shared( A const & a, A1 const & a1, A2 const & a2, A3 const & a3 )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ), a );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T( a1, a2, a3 );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

template< class T, class A1, class A2, class A3, class A4 >
typename std::detail::sp_if_not_array< T >::type make_shared( A1 const & a1, A2 const & a2, A3 const & a3, A4 const & a4 )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ) );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T( a1, a2, a3, a4 );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

template< class T, class A, class A1, class A2, class A3, class A4 >
typename std::detail::sp_if_not_array< T >::type allocate_shared( A const & a, A1 const & a1, A2 const & a2, A3 const & a3, A4 const & a4 )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ), a );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T( a1, a2, a3, a4 );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

template< class T, class A1, class A2, class A3, class A4, class A5 >
typename std::detail::sp_if_not_array< T >::type make_shared( A1 const & a1, A2 const & a2, A3 const & a3, A4 const & a4, A5 const & a5 )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ) );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T( a1, a2, a3, a4, a5 );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

template< class T, class A, class A1, class A2, class A3, class A4, class A5 >
typename std::detail::sp_if_not_array< T >::type allocate_shared( A const & a, A1 const & a1, A2 const & a2, A3 const & a3, A4 const & a4, A5 const & a5 )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ), a );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T( a1, a2, a3, a4, a5 );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

template< class T, class A1, class A2, class A3, class A4, class A5, class A6 >
typename std::detail::sp_if_not_array< T >::type make_shared( A1 const & a1, A2 const & a2, A3 const & a3, A4 const & a4, A5 const & a5, A6 const & a6 )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ) );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T( a1, a2, a3, a4, a5, a6 );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

template< class T, class A, class A1, class A2, class A3, class A4, class A5, class A6 >
typename std::detail::sp_if_not_array< T >::type allocate_shared( A const & a, A1 const & a1, A2 const & a2, A3 const & a3, A4 const & a4, A5 const & a5, A6 const & a6 )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ), a );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T( a1, a2, a3, a4, a5, a6 );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

template< class T, class A1, class A2, class A3, class A4, class A5, class A6, class A7 >
typename std::detail::sp_if_not_array< T >::type make_shared( A1 const & a1, A2 const & a2, A3 const & a3, A4 const & a4, A5 const & a5, A6 const & a6, A7 const & a7 )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ) );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T( a1, a2, a3, a4, a5, a6, a7 );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

template< class T, class A, class A1, class A2, class A3, class A4, class A5, class A6, class A7 >
typename std::detail::sp_if_not_array< T >::type allocate_shared( A const & a, A1 const & a1, A2 const & a2, A3 const & a3, A4 const & a4, A5 const & a5, A6 const & a6, A7 const & a7 )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ), a );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T( a1, a2, a3, a4, a5, a6, a7 );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

template< class T, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8 >
typename std::detail::sp_if_not_array< T >::type make_shared( A1 const & a1, A2 const & a2, A3 const & a3, A4 const & a4, A5 const & a5, A6 const & a6, A7 const & a7, A8 const & a8 )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ) );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T( a1, a2, a3, a4, a5, a6, a7, a8 );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

template< class T, class A, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8 >
typename std::detail::sp_if_not_array< T >::type allocate_shared( A const & a, A1 const & a1, A2 const & a2, A3 const & a3, A4 const & a4, A5 const & a5, A6 const & a6, A7 const & a7, A8 const & a8 )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ), a );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T( a1, a2, a3, a4, a5, a6, a7, a8 );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

template< class T, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9 >
typename std::detail::sp_if_not_array< T >::type make_shared( A1 const & a1, A2 const & a2, A3 const & a3, A4 const & a4, A5 const & a5, A6 const & a6, A7 const & a7, A8 const & a8, A9 const & a9 )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ) );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T( a1, a2, a3, a4, a5, a6, a7, a8, a9 );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

template< class T, class A, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9 >
typename std::detail::sp_if_not_array< T >::type allocate_shared( A const & a, A1 const & a1, A2 const & a2, A3 const & a3, A4 const & a4, A5 const & a5, A6 const & a6, A7 const & a7, A8 const & a8, A9 const & a9 )
{
    std::shared_ptr< T > pt( static_cast< T* >( 0 ), BOOST_SP_MSD( T ), a );

    std::detail::sp_ms_deleter< T > * pd = static_cast<std::detail::sp_ms_deleter< T > *>( pt._internal_get_untyped_deleter() );

    void * pv = pd->address();

    ::new( pv ) T( a1, a2, a3, a4, a5, a6, a7, a8, a9 );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    std::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return std::shared_ptr< T >( pt, pt2 );
}

#endif

#undef BOOST_SP_MSD

} // namespace boost

#endif // #ifndef BOOST_SMART_PTR_MAKE_SHARED_OBJECT_HPP_INCLUDED
