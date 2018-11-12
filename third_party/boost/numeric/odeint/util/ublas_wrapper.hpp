/*
 [auto_generated]
 boost/numeric/odeint/util/ublas_wrapper.hpp

 [begin_description]
 Resizing for ublas::vector and ublas::matrix
 [end_description]

 Copyright 2009-2011 Karsten Ahnert
 Copyright 2009-2011 Mario Mulansky

 Distributed under the Boost Software License, Version 1.0.
 (See accompanying file LICENSE_1_0.txt or
 copy at http://www.boost.org/LICENSE_1_0.txt)
 */


#ifndef BOOST_NUMERIC_ODEINT_UTIL_UBLAS_WRAPPER_HPP_INCLUDED
#define BOOST_NUMERIC_ODEINT_UTIL_UBLAS_WRAPPER_HPP_INCLUDED


#include <boost/type_traits/integral_constant.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/lu.hpp>

#include <boost/numeric/odeint/util/is_resizeable.hpp>
#include <boost/numeric/odeint/util/state_wrapper.hpp>

namespace boost {
namespace numeric {
namespace odeint {

/*
 * resizeable specialization for std::numeric::ublas::vector
 */
template< class T , class A >
struct is_resizeable< std::numeric::ublas::vector< T , A > >
{
    typedef std::true_type type;
    const static bool value = type::value;
};


/*
 * resizeable specialization for std::numeric::ublas::matrix
 */
template< class T , class L , class A >
struct is_resizeable< std::numeric::ublas::matrix< T , L , A > >
{
    typedef std::true_type type;
    const static bool value = type::value;
};


/*
 * resizeable specialization for std::numeric::ublas::permutation_matrix
 */
template< class T , class A >
struct is_resizeable< std::numeric::ublas::permutation_matrix< T , A > >
{
    typedef std::true_type type;
    const static bool value = type::value;
};


// specialization for ublas::matrix
// same size and resize specialization for matrix-matrix resizing
template< class T , class L , class A , class T2 , class L2 , class A2 >
struct same_size_impl< std::numeric::ublas::matrix< T , L , A > , std::numeric::ublas::matrix< T2 , L2 , A2 > >
{
    static bool same_size( const std::numeric::ublas::matrix< T , L , A > &m1 ,
                           const std::numeric::ublas::matrix< T2 , L2 , A2 > &m2 )
    {
        return ( ( m1.size1() == m2.size1() ) && ( m1.size2() == m2.size2() ) );
    }
};

template< class T , class L , class A , class T2 , class L2 , class A2 >
struct resize_impl< std::numeric::ublas::matrix< T , L , A > , std::numeric::ublas::matrix< T2 , L2 , A2 > >
{
    static void resize( std::numeric::ublas::matrix< T , L , A > &m1 ,
                        const std::numeric::ublas::matrix< T2 , L2 , A2 > &m2 )
    {
        m1.resize( m2.size1() , m2.size2() );
    }
};



// same size and resize specialization for matrix-vector resizing
template< class T , class L , class A , class T_V , class A_V >
struct same_size_impl< std::numeric::ublas::matrix< T , L , A > , std::numeric::ublas::vector< T_V , A_V > >
{
    static bool same_size( const std::numeric::ublas::matrix< T , L , A > &m ,
                           const std::numeric::ublas::vector< T_V , A_V > &v )
    {
        return ( ( m.size1() == v.size() ) && ( m.size2() == v.size() ) );
    }
};

template< class T , class L , class A , class T_V , class A_V >
struct resize_impl< std::numeric::ublas::matrix< T , L , A > , std::numeric::ublas::vector< T_V , A_V > >
{
    static void resize( std::numeric::ublas::matrix< T , L , A > &m ,
                        const std::numeric::ublas::vector< T_V , A_V > &v )
    {
        m.resize( v.size() , v.size() );
    }
};



// specialization for ublas::permutation_matrix
// same size and resize specialization for matrix-vector resizing
template< class T , class A , class T_V , class A_V >
struct same_size_impl< std::numeric::ublas::permutation_matrix< T , A > , std::numeric::ublas::vector< T_V , A_V > >
{
    static bool same_size( const std::numeric::ublas::permutation_matrix< T , A > &m ,
                           const std::numeric::ublas::vector< T_V , A_V > &v )
    {
        return ( m.size() == v.size() ); // && ( m.size2() == v.size() ) );
    }
};

template< class T , class A , class T_V , class A_V >
struct resize_impl< std::numeric::ublas::vector< T_V , A_V > , std::numeric::ublas::permutation_matrix< T , A > >
{
    static void resize( const std::numeric::ublas::vector< T_V , A_V > &v,
                        std::numeric::ublas::permutation_matrix< T , A > &m )
    {
        m.resize( v.size() , v.size() );
    }
};







template< class T , class A >
struct state_wrapper< std::numeric::ublas::permutation_matrix< T , A > > // with resizing
{
    typedef std::numeric::ublas::permutation_matrix< T , A > state_type;
    typedef state_wrapper< state_type > state_wrapper_type;

    state_type m_v;

    state_wrapper() : m_v( 1 ) // permutation matrix constructor requires a size, choose 1 as default
    { }

};




} } }

//// all specializations done, ready to include state_wrapper
//
//#include <boost/numeric/odeint/util/state_wrapper.hpp>
//
//namespace boost {
//namespace numeric {
//namespace odeint {
//
///* specialization for permutation matrices wrapper because we need to change the construction */
//template< class T , class A >
//struct state_wrapper< std::numeric::ublas::permutation_matrix< T , A > , true > // with resizing
//{
//    typedef std::numeric::ublas::permutation_matrix< T , A > state_type;
//    typedef state_wrapper< state_type > state_wrapper_type;
//    //typedef typename V::value_type value_type;
//    typedef std::true_type is_resizeable;
//
//    state_type m_v;
//
//    state_wrapper() : m_v( 1 ) // permutation matrix constructor requires a size, choose 1 as default
//    { }
//
//    template< class T_V , class A_V >
//    bool same_size( const std::numeric::ublas::vector< T_V , A_V > &x )
//    {
//        return std::numeric::odeint::same_size( m_v , x );
//    }
//
//    template< class T_V , class A_V >
//    bool resize( const std::numeric::ublas::vector< T_V , A_V > &x )
//    {
//        //standard resizing done like for std::vector
//        if( !same_size( x ) )
//        {
//            std::numeric::odeint::resize( m_v , x );
//            return true;
//        } else
//            return false;
//    }
//};
//
//}
//}
//}


/*
 * preparing ublas::matrix for std::range, such that ublas::matrix can be used in all steppers with the range algebra
 */

namespace boost
{
template< class T , class L , class A >
struct range_mutable_iterator< std::numeric::ublas::matrix< T , L , A > >
{
    typedef typename std::numeric::ublas::matrix< T , L , A >::array_type::iterator type;
};

template< class T , class L , class A >
struct range_const_iterator< std::numeric::ublas::matrix< T , L , A > >
{
    typedef typename std::numeric::ublas::matrix< T , L , A >::array_type::const_iterator type;
};

} // namespace boost


namespace boost { namespace numeric { namespace ublas {

template< class T , class L , class A >
inline typename matrix< T , L , A >::array_type::iterator
range_begin( matrix< T , L , A > &x )
{
    return x.data().begin();
}

template< class T , class L , class A >
inline typename matrix< T , L , A >::array_type::const_iterator
range_begin( const matrix< T , L , A > &x )
{
    return x.data().begin();
}

template< class T , class L , class A >
inline typename matrix< T , L , A >::array_type::iterator
range_end( matrix< T , L , A > &x )
{
    return x.data().end();
}

template< class T , class L , class A >
inline typename matrix< T , L , A >::array_type::const_iterator
range_end( const matrix< T , L , A > &x )
{
    return x.data().end();
}

} } } // namespace std::numeric::ublas


#endif // BOOST_NUMERIC_ODEINT_UTIL_UBLAS_WRAPPER_HPP_INCLUDED
