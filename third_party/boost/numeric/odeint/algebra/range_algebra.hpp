/*
 [auto_generated]
 boost/numeric/odeint/algebra/range_algebra.hpp

 [begin_description]
 Default algebra, which works with the most state types, like vector< double >, std::array< double >, std::range.
 Internally is uses std::range to obtain the begin and end iterator of the according sequence.
 [end_description]

 Copyright 2009-2011 Karsten Ahnert
 Copyright 2009-2011 Mario Mulansky

 Distributed under the Boost Software License, Version 1.0.
 (See accompanying file LICENSE_1_0.txt or
 copy at http://www.boost.org/LICENSE_1_0.txt)
 */


#ifndef BOOST_NUMERIC_ODEINT_ALGEBRA_RANGE_ALGEBRA_HPP_INCLUDED
#define BOOST_NUMERIC_ODEINT_ALGEBRA_RANGE_ALGEBRA_HPP_INCLUDED

#include <boost/range.hpp>
#include <boost/mpl/size_t.hpp>

#include <boost/numeric/odeint/algebra/detail/macros.hpp>
#include <boost/numeric/odeint/algebra/detail/for_each.hpp>
#include <boost/numeric/odeint/algebra/detail/reduce.hpp>

namespace boost {
namespace numeric {
namespace odeint {

struct range_algebra
{
    template< class S1 , class Op >
    static void for_each1( S1 &s1 , Op op )
    {
        detail::for_each1( std::begin( s1 ) , std::end( s1 ) ,
                op );
    }

    template< class S1 , class S2 , class Op >
    static void for_each2( S1 &s1 , S2 &s2 , Op op )
    {
        detail::for_each2( std::begin( s1 ) , std::end( s1 ) ,
                std::begin( s2 ) , op );
    }

    template< class S1 , class S2 , class S3 , class Op >
    static void for_each3( S1 &s1 , S2 &s2 , S3 &s3 , Op op )
    {
        detail::for_each3( std::begin( s1 ) , std::end( s1 ) , std::begin( s2 ) , std::begin( s3 ) , op );
    }

    template< class S1 , class S2 , class S3 , class S4 , class Op >
    static void for_each4( S1 &s1 , S2 &s2 , S3 &s3 , S4 &s4 , Op op )
    {
        detail::for_each4( std::begin( s1 ) , std::end( s1 ) , std::begin( s2 ) , std::begin( s3 ) , std::begin( s4 ) , op );
    }

    template< class S1 , class S2 , class S3 , class S4 , class S5 , class Op >
    static void for_each5( S1 &s1 , S2 &s2 , S3 &s3 , S4 &s4 , S5 &s5 , Op op )
    {
        detail::for_each5( std::begin( s1 ) , std::end( s1 ) , std::begin( s2 ) , std::begin( s3 ) , std::begin( s4 ) , std::begin( s5 ) , op );
    }

    template< class S1 , class S2 , class S3 , class S4 , class S5 , class S6 , class Op >
    static void for_each6( S1 &s1 , S2 &s2 , S3 &s3 , S4 &s4 , S5 &s5 , S6 &s6 , Op op )
    {
        detail::for_each6( std::begin( s1 ) , std::end( s1 ) , std::begin( s2 ) , std::begin( s3 ) , std::begin( s4 ) , std::begin( s5 ) , std::begin( s6 ) , op );
    }

    template< class S1 , class S2 , class S3 , class S4 , class S5 , class S6 ,class S7 , class Op >
    static void for_each7( S1 &s1 , S2 &s2 , S3 &s3 , S4 &s4 , S5 &s5 , S6 &s6 , S7 &s7 , Op op )
    {
        detail::for_each7( std::begin( s1 ) , std::end( s1 ) , std::begin( s2 ) , std::begin( s3 ) , std::begin( s4 ) , std::begin( s5 ) , std::begin( s6 ) , std::begin( s7 ) , op );
    }

    template< class S1 , class S2 , class S3 , class S4 , class S5 , class S6 ,class S7 , class S8 , class Op >
    static void for_each8( S1 &s1 , S2 &s2 , S3 &s3 , S4 &s4 , S5 &s5 , S6 &s6 , S7 &s7 , S8 &s8 , Op op )
    {
        detail::for_each8( std::begin( s1 ) , std::end( s1 ) , std::begin( s2 ) , std::begin( s3 ) , std::begin( s4 ) , std::begin( s5 ) , std::begin( s6 ) , std::begin( s7 ) , std::begin( s8 ) , op );
    }

    template< class S1 , class S2 , class S3 , class S4 , class S5 , class S6 ,class S7 , class S8 , class S9 , class Op >
    static void for_each9( S1 &s1 , S2 &s2 , S3 &s3 , S4 &s4 , S5 &s5 , S6 &s6 , S7 &s7 , S8 &s8 , S9 &s9 , Op op )
    {
        detail::for_each9( std::begin( s1 ) , std::end( s1 ) , std::begin( s2 ) , std::begin( s3 ) , std::begin( s4 ) , std::begin( s5 ) , std::begin( s6 ) , std::begin( s7 ) , std::begin( s8 ) , std::begin( s9 ) , op );
    }

    template< class S1 , class S2 , class S3 , class S4 , class S5 , class S6 ,class S7 , class S8 , class S9 , class S10 , class Op >
    static void for_each10( S1 &s1 , S2 &s2 , S3 &s3 , S4 &s4 , S5 &s5 , S6 &s6 , S7 &s7 , S8 &s8 , S9 &s9 , S10 &s10 , Op op )
    {
        detail::for_each10( std::begin( s1 ) , std::end( s1 ) , std::begin( s2 ) , std::begin( s3 ) , std::begin( s4 ) , std::begin( s5 ) , std::begin( s6 ) , std::begin( s7 ) , std::begin( s8 ) , std::begin( s9 ) , std::begin( s10 ) , op );
    }

    template< class S1 , class S2 , class S3 , class S4 , class S5 , class S6 ,class S7 , class S8 , class S9 , class S10 , class S11 , class Op >
    static void for_each11( S1 &s1 , S2 &s2 , S3 &s3 , S4 &s4 , S5 &s5 , S6 &s6 , S7 &s7 , S8 &s8 , S9 &s9 , S10 &s10 , S11 &s11 , Op op )
    {
        detail::for_each11( std::begin( s1 ) , std::end( s1 ) , std::begin( s2 ) , std::begin( s3 ) , std::begin( s4 ) , std::begin( s5 ) , std::begin( s6 ) , std::begin( s7 ) , std::begin( s8 ) , std::begin( s9 ) , std::begin( s10 ) , std::begin( s11 ) , op );
    }

    template< class S1 , class S2 , class S3 , class S4 , class S5 , class S6 ,class S7 , class S8 , class S9 , class S10 , class S11 , class S12 , class Op >
    static void for_each12( S1 &s1 , S2 &s2 , S3 &s3 , S4 &s4 , S5 &s5 , S6 &s6 , S7 &s7 , S8 &s8 , S9 &s9 , S10 &s10 , S11 &s11 , S12 &s12 , Op op )
    {
        detail::for_each12( std::begin( s1 ) , std::end( s1 ) , std::begin( s2 ) , std::begin( s3 ) , std::begin( s4 ) , std::begin( s5 ) , std::begin( s6 ) , std::begin( s7 ) , std::begin( s8 ) , std::begin( s9 ) , std::begin( s10 ) , std::begin( s11 ) , std::begin( s12 ) , op );
    }

    template< class S1 , class S2 , class S3 , class S4 , class S5 , class S6 ,class S7 , class S8 , class S9 , class S10 , class S11 , class S12 , class S13 , class Op >
    static void for_each13( S1 &s1 , S2 &s2 , S3 &s3 , S4 &s4 , S5 &s5 , S6 &s6 , S7 &s7 , S8 &s8 , S9 &s9 , S10 &s10 , S11 &s11 , S12 &s12 , S13 &s13 , Op op )
    {
        detail::for_each13( std::begin( s1 ) , std::end( s1 ) , std::begin( s2 ) , std::begin( s3 ) , std::begin( s4 ) , std::begin( s5 ) , std::begin( s6 ) , std::begin( s7 ) , std::begin( s8 ) , std::begin( s9 ) , std::begin( s10 ) , std::begin( s11 ) , std::begin( s12 ) , std::begin( s13 ) , op );
    }

    template< class S1 , class S2 , class S3 , class S4 , class S5 , class S6 ,class S7 , class S8 , class S9 , class S10 , class S11 , class S12 , class S13 , class S14 , class Op >
    static void for_each14( S1 &s1 , S2 &s2 , S3 &s3 , S4 &s4 , S5 &s5 , S6 &s6 , S7 &s7 , S8 &s8 , S9 &s9 , S10 &s10 , S11 &s11 , S12 &s12 , S13 &s13 , S14 &s14 , Op op )
    {
        detail::for_each14( std::begin( s1 ) , std::end( s1 ) , std::begin( s2 ) , std::begin( s3 ) , std::begin( s4 ) , std::begin( s5 ) , std::begin( s6 ) , std::begin( s7 ) , std::begin( s8 ) , std::begin( s9 ) , std::begin( s10 ) , std::begin( s11 ) , std::begin( s12 ) , std::begin( s13 ) , std::begin( s14 ) , op );
    }

    template< class S1 , class S2 , class S3 , class S4 , class S5 , class S6 ,class S7 , class S8 , class S9 , class S10 , class S11 , class S12 , class S13 , class S14 , class S15 , class Op >
    static void for_each15( S1 &s1 , S2 &s2 , S3 &s3 , S4 &s4 , S5 &s5 , S6 &s6 , S7 &s7 , S8 &s8 , S9 &s9 , S10 &s10 , S11 &s11 , S12 &s12 , S13 &s13 , S14 &s14 , S15 &s15 , Op op )
    {
        detail::for_each15( std::begin( s1 ) , std::end( s1 ) , std::begin( s2 ) , std::begin( s3 ) , std::begin( s4 ) , std::begin( s5 ) , std::begin( s6 ) , std::begin( s7 ) , std::begin( s8 ) , std::begin( s9 ) , std::begin( s10 ) , std::begin( s11 ) , std::begin( s12 ) , std::begin( s13 ) , std::begin( s14 ) , std::begin( s15 ) , op );
    }

    template< class Value , class S , class Red >
    static Value reduce( const S &s , Red red , Value init)
    {
        return detail::reduce( std::begin( s ) , std::end( s ) , red , init );
    }

    template< class Value , class S1 , class S2 , class Red >
    static Value reduce2( const S1 &s1 , const S2 &s2 , Red red , Value init )
    {
        return detail::reduce2( std::begin( s1 ) , std::end( s1 ) , std::begin( s2 ) , red , init );
    }

    template< class Value , class S1 , class S2 , class S3 , class Red >
    static Value reduce3( const S1 &s1 , const S2 &s2 , const S3 &s3 , Red red , Value init )
    {
        return detail::reduce3( std::begin( s1 ) , std::end( s1 ) , std::begin( s2 ) , std::begin( s3 ) , red , init );
    }

    template< class Value , class S1 , class S2 , class S3 , class S4 , class Red >
    static Value reduce4( const S1 &s1 , const S2 &s2 , const S3 &s3 , const S4 &s4 , Red red , Value init )
    {
        return detail::reduce4( std::begin( s1 ) , std::end( s1 ) , std::begin( s2 ) , std::begin( s3 ) , std::begin( s4 ) , red , init );
    }


};

} // odeint
} // numeric
} // boost


#endif // BOOST_NUMERIC_ODEINT_ALGEBRA_RANGE_ALGEBRA_HPP_INCLUDED
