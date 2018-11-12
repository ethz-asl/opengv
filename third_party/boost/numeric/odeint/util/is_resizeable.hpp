/*
 [auto_generated]
 boost/numeric/odeint/util/is_resizeable.hpp

 [begin_description]
 Metafunction to determine if a state type can resized. For usage in the steppers.
 [end_description]

 Copyright 2009-2011 Karsten Ahnert
 Copyright 2009-2011 Mario Mulansky

 Distributed under the Boost Software License, Version 1.0.
 (See accompanying file LICENSE_1_0.txt or
 copy at http://www.boost.org/LICENSE_1_0.txt)
 */


#ifndef BOOST_NUMERIC_ODEINT_UTIL_IS_RESIZEABLE_HPP_INCLUDED
#define BOOST_NUMERIC_ODEINT_UTIL_IS_RESIZEABLE_HPP_INCLUDED


#include <vector>

#include <boost/type_traits/integral_constant.hpp>
#include <boost/type_traits/remove_reference.hpp>
#include <boost/fusion/include/front.hpp>
#include <boost/fusion/include/is_sequence.hpp>

#include <boost/mpl/find_if.hpp>
#include <boost/mpl/end.hpp>
#include <boost/mpl/placeholders.hpp>
// #include <boost/mpl/not.hpp>
#include <boost/mpl/if.hpp>
#include <boost/type_traits/is_same.hpp>

namespace boost {
namespace numeric {
namespace odeint {

/*
 * by default any type is not resizable
 */
template< class Container , class Enabler = void >
struct is_resizeable
{
    //struct type : public std::false_type { };
    typedef std::false_type type;
    const static bool value = type::value;
};

/*
 * specialization for std::vector
 */
template< class V, class A >
struct is_resizeable< std::vector< V , A  > >
{
    //struct type : public std::true_type { };
    typedef std::true_type type;
    const static bool value = type::value;
};


/*
 * specialization for fusion sequences
 */
template< class FusionSequence >
struct is_resizeable< FusionSequence , typename std::enable_if< typename std::fusion::traits::is_sequence< FusionSequence >::type >::type >
{
    typedef typename std::mpl::find_if< FusionSequence , is_resizeable< std::mpl::_1 > >::type iter;
    typedef typename std::mpl::end< FusionSequence >::type last;

    typedef typename std::mpl::if_< std::is_same< iter , last > , std::false_type , std::true_type >::type type;
    const static bool value = type::value;
};



} // namespace odeint
} // namespace numeric
} // namespace boost



#endif // BOOST_NUMERIC_ODEINT_UTIL_IS_RESIZEABLE_HPP_INCLUDED
