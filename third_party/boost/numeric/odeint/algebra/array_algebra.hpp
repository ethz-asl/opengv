/*
 [auto_generated]
 boost/numeric/odeint/algebra/array_algebra.hpp

 [begin_description]
 Algebra for std::array. Highly specialized for odeint. Const arguments are introduce to work with odeint.
 [end_description]

 Copyright 2009-2011 Karsten Ahnert
 Copyright 2009-2011 Mario Mulansky

 Distributed under the Boost Software License, Version 1.0.
 (See accompanying file LICENSE_1_0.txt or
 copy at http://www.boost.org/LICENSE_1_0.txt)
 */


#ifndef BOOST_NUMERIC_ODEINT_ALGEBRA_ARRAY_ALGEBRA_HPP_INCLUDED
#define BOOST_NUMERIC_ODEINT_ALGEBRA_ARRAY_ALGEBRA_HPP_INCLUDED

#include <boost/array.hpp>

namespace boost {
namespace numeric {
namespace odeint {

struct array_algebra
{
    template< typename T , size_t dim , class Op >
    static void for_each1( std::array< T , dim > &s1 , Op op )
    {
        for( size_t i=0 ; i<dim ; ++i )
            op( s1[i] );
    }


    template< typename T1 , typename T2 , size_t dim , class Op >
    static void for_each2( std::array< T1 , dim > &s1 ,
            const std::array< T2 , dim > &s2 , Op op )
    {
        for( size_t i=0 ; i<dim ; ++i )
            op( s1[i] , s2[i] );
    }

    template< typename T , size_t dim , class Op >
    static void for_each3( std::array< T , dim > &s1 ,
            const std::array< T , dim > &s2 ,
            const std::array< T , dim > &s3 , Op op )
    {
        for( size_t i=0 ; i<dim ; ++i )
            op( s1[i] , s2[i] , s3[i] );
    }

    /* different const signature - required for the scale_sum_swap2 operation */
    template< typename T , size_t dim , class Op >
    static void for_each3( std::array< T , dim > &s1 ,
            std::array< T , dim > &s2 ,
            const std::array< T , dim > &s3 , Op op )
    {
        for( size_t i=0 ; i<dim ; ++i )
            op( s1[i] , s2[i] , s3[i] );
    }

    template< typename T , size_t dim , class Op >
    static void for_each4( std::array< T , dim > &s1 ,
            const std::array< T , dim > &s2 ,
            const std::array< T , dim > &s3 ,
            const std::array< T , dim > &s4 , Op op )
    {
        for( size_t i=0 ; i<dim ; ++i )
            op( s1[i] , s2[i] , s3[i] , s4[i] );
    }

    template< typename T , size_t dim , class Op >
    static void for_each5( std::array< T , dim > &s1 ,
            const std::array< T , dim > &s2 ,
            const std::array< T , dim > &s3 ,
            const std::array< T , dim > &s4 ,
            const std::array< T , dim > &s5 , Op op )
    {
        for( size_t i=0 ; i<dim ; ++i )
            op( s1[i] , s2[i] , s3[i] , s4[i] , s5[i] );
    }

    template< typename T , size_t dim , class Op >
    static void for_each6( std::array< T , dim > &s1 ,
            const std::array< T , dim > &s2 ,
            const std::array< T , dim > &s3 ,
            const std::array< T , dim > &s4 ,
            const std::array< T , dim > &s5 ,
            const std::array< T , dim > &s6 , Op op )
    {
        for( size_t i=0 ; i<dim ; ++i )
            op( s1[i] , s2[i] , s3[i] , s4[i] , s5[i] , s6[i] );
    }

    template< typename T , size_t dim , class Op >
    static void for_each7( std::array< T , dim > &s1 ,
            const std::array< T , dim > &s2 ,
            const std::array< T , dim > &s3 ,
            const std::array< T , dim > &s4 ,
            const std::array< T , dim > &s5 ,
            const std::array< T , dim > &s6 ,
            const std::array< T , dim > &s7 , Op op )
    {
        for( size_t i=0 ; i<dim ; ++i )
            op( s1[i] , s2[i] , s3[i] , s4[i] , s5[i] , s6[i] , s7[i] );
    }

    template< typename T , size_t dim , class Op >
    static void for_each8( std::array< T , dim > &s1 ,
            const std::array< T , dim > &s2 ,
            const std::array< T , dim > &s3 ,
            const std::array< T , dim > &s4 ,
            const std::array< T , dim > &s5 ,
            const std::array< T , dim > &s6 ,
            const std::array< T , dim > &s7 ,
            const std::array< T , dim > &s8 , Op op )
    {
        for( size_t i=0 ; i<dim ; ++i )
            op( s1[i] , s2[i] , s3[i] , s4[i] , s5[i] , s6[i] , s7[i] , s8[i] );
    }

    template< typename T , size_t dim , class Op >
    static void for_each9( std::array< T , dim > &s1 ,
            const std::array< T , dim > &s2 ,
            const std::array< T , dim > &s3 ,
            const std::array< T , dim > &s4 ,
            const std::array< T , dim > &s5 ,
            const std::array< T , dim > &s6 ,
            const std::array< T , dim > &s7 ,
            const std::array< T , dim > &s8 ,
            const std::array< T , dim > &s9 , Op op )
    {
        for( size_t i=0 ; i<dim ; ++i )
            op( s1[i] , s2[i] , s3[i] , s4[i] , s5[i] , s6[i] , s7[i] , s8[i] , s9[i] );
    }

    template< typename T , size_t dim , class Op >
    static void for_each10( std::array< T , dim > &s1 ,
            const std::array< T , dim > &s2 ,
            const std::array< T , dim > &s3 ,
            const std::array< T , dim > &s4 ,
            const std::array< T , dim > &s5 ,
            const std::array< T , dim > &s6 ,
            const std::array< T , dim > &s7 ,
            const std::array< T , dim > &s8 ,
            const std::array< T , dim > &s9 ,
            const std::array< T , dim > &s10 , Op op )
    {
        for( size_t i=0 ; i<dim ; ++i )
            op( s1[i] , s2[i] , s3[i] , s4[i] , s5[i] , s6[i] , s7[i] , s8[i] , s9[i] , s10[i] );
    }

    template< typename T , size_t dim , class Op >
    static void for_each11( std::array< T , dim > &s1 ,
            const std::array< T , dim > &s2 ,
            const std::array< T , dim > &s3 ,
            const std::array< T , dim > &s4 ,
            const std::array< T , dim > &s5 ,
            const std::array< T , dim > &s6 ,
            const std::array< T , dim > &s7 ,
            const std::array< T , dim > &s8 ,
            const std::array< T , dim > &s9 ,
            const std::array< T , dim > &s10 ,
            const std::array< T , dim > &s11 , Op op )
    {
        for( size_t i=0 ; i<dim ; ++i )
            op( s1[i] , s2[i] , s3[i] , s4[i] , s5[i] , s6[i] , s7[i] , s8[i] , s9[i] , s10[i] , s11[i] );
    }

    template< typename T , size_t dim , class Op >
    static void for_each12( std::array< T , dim > &s1 ,
            const std::array< T , dim > &s2 ,
            const std::array< T , dim > &s3 ,
            const std::array< T , dim > &s4 ,
            const std::array< T , dim > &s5 ,
            const std::array< T , dim > &s6 ,
            const std::array< T , dim > &s7 ,
            const std::array< T , dim > &s8 ,
            const std::array< T , dim > &s9 ,
            const std::array< T , dim > &s10 ,
            const std::array< T , dim > &s11 ,
            const std::array< T , dim > &s12 , Op op )
    {
        for( size_t i=0 ; i<dim ; ++i )
            op( s1[i] , s2[i] , s3[i] , s4[i] , s5[i] , s6[i] , s7[i] , s8[i] , s9[i] , s10[i] , s11[i] , s12[i] );
    }

    template< typename T , size_t dim , class Op >
    static void for_each13( std::array< T , dim > &s1 ,
            const std::array< T , dim > &s2 ,
            const std::array< T , dim > &s3 ,
            const std::array< T , dim > &s4 ,
            const std::array< T , dim > &s5 ,
            const std::array< T , dim > &s6 ,
            const std::array< T , dim > &s7 ,
            const std::array< T , dim > &s8 ,
            const std::array< T , dim > &s9 ,
            const std::array< T , dim > &s10 ,
            const std::array< T , dim > &s11 ,
            const std::array< T , dim > &s12 ,
            const std::array< T , dim > &s13 , Op op )
    {
        for( size_t i=0 ; i<dim ; ++i )
            op( s1[i] , s2[i] , s3[i] , s4[i] , s5[i] , s6[i] , s7[i] , s8[i] , s9[i] , s10[i] , s11[i] , s12[i] , s13[i] );
    }

    template< typename T , size_t dim , class Op >
    static void for_each14( std::array< T , dim > &s1 ,
            const std::array< T , dim > &s2 ,
            const std::array< T , dim > &s3 ,
            const std::array< T , dim > &s4 ,
            const std::array< T , dim > &s5 ,
            const std::array< T , dim > &s6 ,
            const std::array< T , dim > &s7 ,
            const std::array< T , dim > &s8 ,
            const std::array< T , dim > &s9 ,
            const std::array< T , dim > &s10 ,
            const std::array< T , dim > &s11 ,
            const std::array< T , dim > &s12 ,
            const std::array< T , dim > &s13 ,
            const std::array< T , dim > &s14 , Op op )
    {
        for( size_t i=0 ; i<dim ; ++i )
            op( s1[i] , s2[i] , s3[i] , s4[i] , s5[i] , s6[i] , s7[i] , s8[i] , s9[i] , s10[i] , s11[i] , s12[i] , s13[i] , s14[i] );
    }

    template< typename T , size_t dim , class Op >
    static void for_each15( std::array< T , dim > &s1 ,
            const std::array< T , dim > &s2 ,
            const std::array< T , dim > &s3 ,
            const std::array< T , dim > &s4 ,
            const std::array< T , dim > &s5 ,
            const std::array< T , dim > &s6 ,
            const std::array< T , dim > &s7 ,
            const std::array< T , dim > &s8 ,
            const std::array< T , dim > &s9 ,
            const std::array< T , dim > &s10 ,
            const std::array< T , dim > &s11 ,
            const std::array< T , dim > &s12 ,
            const std::array< T , dim > &s13 ,
            const std::array< T , dim > &s14 ,
            const std::array< T , dim > &s15 , Op op )
    {
        for( size_t i=0 ; i<dim ; ++i )
            op( s1[i] , s2[i] , s3[i] , s4[i] , s5[i] , s6[i] , s7[i] , s8[i] , s9[i] , s10[i] , s11[i] , s12[i] , s13[i] , s14[i] , s15[i] );
    }


    template< class Value , class T , size_t dim , class Red >
    static Value reduce( const std::array< T , dim > &s , Red red , Value init)
    {
        for( size_t i=0 ; i<dim ; ++i )
            init = red( init , s[i] );
        return init;
    }

};

}
}
}

#endif // BOOST_NUMERIC_ODEINT_ALGEBRA_ARRAY_ALGEBRA_HPP_INCLUDED
