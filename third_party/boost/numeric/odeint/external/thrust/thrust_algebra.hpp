/*
 [auto_generated]
 boost/numeric/odeint/external/thrust/thrust_algebra.hpp

 [begin_description]
 An algebra for thrusts device_vectors.
 [end_description]

 Copyright 2009-2011 Karsten Ahnert
 Copyright 2009-2011 Mario Mulansky

 Distributed under the Boost Software License, Version 1.0.
 (See accompanying file LICENSE_1_0.txt or
 copy at http://www.boost.org/LICENSE_1_0.txt)
 */


#ifndef BOOST_NUMERIC_ODEINT_EXTERNAL_THRUST_THRUST_ALGEBRA_HPP_INCLUDED
#define BOOST_NUMERIC_ODEINT_EXTERNAL_THRUST_THRUST_ALGEBRA_HPP_INCLUDED


#include <thrust/device_vector.h>
#include <thrust/for_each.h>
#include <thrust/iterator/zip_iterator.h>

#include <boost/range.hpp>

namespace boost {
namespace numeric {
namespace odeint {



/** ToDO extend until for_each14 for rk78 */

/*
 * The const versions are needed for boost.range to work, i.e.
 * it allows you to do
 * for_each1( make_pair( vec1.begin() , vec1.begin() + 10 ) , op );
 */

struct thrust_algebra
{
    template< class StateType , class Operation >
    static void for_each1( StateType &s , Operation op )
    {
        thrust::for_each( std::begin(s) , std::begin(s) , op );
    }

    template< class StateType1 , class StateType2 , class Operation >
    static void for_each2( StateType1 &s1 , StateType2 &s2 , Operation op )
    {
        thrust::for_each(
                thrust::make_zip_iterator( thrust::make_tuple( std::begin(s1) ,
                        std::begin(s2) ) ) ,
                        thrust::make_zip_iterator( thrust::make_tuple( std::end(s1) ,
                                std::end(s2) ) ) ,
                                op);
    }

    template< class StateType1 , class StateType2 , class StateType3 , class Operation >
    static void for_each3( StateType1 &s1 , StateType2 &s2 , StateType3 &s3 , Operation op )
    {
        thrust::for_each(
                thrust::make_zip_iterator( thrust::make_tuple( std::begin(s1) ,
                        std::begin(s2) ,
                        std::begin(s3) ) ) ,
                        thrust::make_zip_iterator( thrust::make_tuple( std::end(s1) ,
                                std::end(s2) ,
                                std::end(s3) ) ) ,
                                op);
    }

    template< class StateType1 , class StateType2 , class StateType3 , class StateType4 ,
    class Operation >
    static void for_each4( StateType1 &s1 , StateType2 &s2 , StateType3 &s3 , StateType4 &s4 ,
            Operation op )
    {
        thrust::for_each(
                thrust::make_zip_iterator( thrust::make_tuple( std::begin(s1) ,
                        std::begin(s2) ,
                        std::begin(s3) ,
                        std::begin(s4) ) ) ,
                        thrust::make_zip_iterator( thrust::make_tuple( std::end(s1) ,
                                std::end(s2) ,
                                std::end(s3) ,
                                std::end(s4) ) ) ,
                                op);
    }

    template< class StateType1 , class StateType2 , class StateType3 ,
    class StateType4 , class StateType5 ,class Operation >
    static void for_each5( StateType1 &s1 , StateType2 &s2 , StateType3 &s3 , StateType4 &s4 ,
            StateType5 &s5 , Operation op )
    {
        thrust::for_each(
                thrust::make_zip_iterator( thrust::make_tuple( std::begin(s1) ,
                        std::begin(s2) ,
                        std::begin(s3) ,
                        std::begin(s4) ,
                        std::begin(s5) ) ) ,
                        thrust::make_zip_iterator( thrust::make_tuple( std::end(s1) ,
                                std::end(s2) ,
                                std::end(s3) ,
                                std::end(s4) ,
                                std::end(s5) ) ) ,
                                op);
    }

    template< class StateType1 , class StateType2 , class StateType3 ,
    class StateType4 , class StateType5 , class StateType6 , class Operation >
    static void for_each6( StateType1 &s1 , StateType2 &s2 , StateType3 &s3 , StateType4 &s4 ,
            StateType5 &s5 , StateType6 &s6 , Operation op )
    {
        thrust::for_each(
                thrust::make_zip_iterator( thrust::make_tuple( std::begin(s1) ,
                        std::begin(s2) ,
                        std::begin(s3) ,
                        std::begin(s4) ,
                        std::begin(s5) ,
                        std::begin(s6) ) ) ,
                        thrust::make_zip_iterator( thrust::make_tuple( std::end(s1) ,
                                std::end(s2) ,
                                std::end(s3) ,
                                std::end(s4) ,
                                std::end(s5) ,
                                std::end(s6) ) ) ,
                                op);
    }

    template< class StateType1 , class StateType2 , class StateType3 , class StateType4 ,
    class StateType5 , class StateType6 , class StateType7 , class Operation >
    static void for_each7( StateType1 &s1 , StateType2 &s2 , StateType3 &s3 , StateType4 &s4 ,
            StateType5 &s5 , StateType6 &s6 , StateType7 &s7 , Operation op )
    {
        thrust::for_each(
                thrust::make_zip_iterator( thrust::make_tuple( std::begin(s1) ,
                        std::begin(s2) ,
                        std::begin(s3) ,
                        std::begin(s4) ,
                        std::begin(s5) ,
                        std::begin(s6) ,
                        std::begin(s7) ) ) ,
                        thrust::make_zip_iterator( thrust::make_tuple( std::end(s1) ,
                                std::end(s2) ,
                                std::end(s3) ,
                                std::end(s4) ,
                                std::end(s5) ,
                                std::end(s6) ,
                                std::end(s7) ) ) ,
                                op);
    }

    template< class StateType1 , class StateType2 , class StateType3 , class StateType4 ,
    class StateType5 , class StateType6 , class StateType7 , class StateType8 , class Operation >
    static void for_each8( StateType1 &s1 , StateType2 &s2 , StateType3 &s3 , StateType4 &s4 ,
            StateType5 &s5 , StateType6 &s6 , StateType7 &s7 , StateType8 &s8 , Operation op )
    {
        thrust::for_each(
                thrust::make_zip_iterator( thrust::make_tuple( std::begin(s1) ,
                        std::begin(s2) ,
                        std::begin(s3) ,
                        std::begin(s4) ,
                        std::begin(s5) ,
                        std::begin(s6) ,
                        std::begin(s7) ,
                        std::begin(s8) ) ) ,
                thrust::make_zip_iterator( thrust::make_tuple( std::end(s1) ,
                        std::end(s2) ,
                        std::end(s3) ,
                        std::end(s4) ,
                        std::end(s5) ,
                        std::end(s6) ,
                        std::end(s7) ,
                        std::end(s8) ) ) ,
                op);
    }


    template< class Value , class S , class Red >
    Value reduce( const S &s , Red red , Value init)
    {
        return thrust::reduce( std::begin( s ) , std::end( s ) , init , red );
    }




};


} // odeint
} // numeric
} // boost



#endif // BOOST_NUMERIC_ODEINT_EXTERNAL_THRUST_THRUST_ALGEBRA_HPP_INCLUDED
