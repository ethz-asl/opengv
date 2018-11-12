//  (C) Copyright John Maddock 2005.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_TR1_TYPE_TRAITS_HPP_INCLUDED
#  define BOOST_TR1_TYPE_TRAITS_HPP_INCLUDED
#  include <boost/tr1/detail/config.hpp>

#ifdef BOOST_HAS_TR1_TYPE_TRAITS

#  if defined(BOOST_HAS_INCLUDE_NEXT) && !defined(BOOST_TR1_DISABLE_INCLUDE_NEXT)
#     include_next BOOST_TR1_HEADER(type_traits)
#  else
#     include <boost/tr1/detail/config_all.hpp>
#     include BOOST_TR1_STD_HEADER(BOOST_TR1_PATH(type_traits))
#  endif

#else
// Boost Type Traits:
#include <boost/type_traits.hpp>
#include <boost/type_traits/is_base_of_tr1.hpp>

namespace std { namespace tr1{

   using ::std::integral_constant;
   using ::std::true_type;
   using ::std::false_type;
   using ::std::is_void;
   using ::std::is_integral;
   using ::std::is_floating_point;
   using ::std::is_array;
   using ::std::is_pointer;
   using ::std::is_reference;
   using ::std::is_member_object_pointer;
   using ::std::is_member_function_pointer;
   using ::std::is_enum;
   using ::std::is_union;
   using ::std::is_class;
   using ::std::is_function;
   using ::std::is_arithmetic;
   using ::std::is_fundamental;
   using ::std::is_object;
   using ::std::is_scalar;
   using ::std::is_compound;
   using ::std::is_member_pointer;
   using ::std::is_const;
   using ::std::is_volatile;
   using ::std::is_pod;
   using ::std::is_empty;
   using ::std::is_polymorphic;
   using ::std::is_abstract;
   using ::std::has_trivial_constructor;
   using ::std::has_trivial_copy;
   using ::std::has_trivial_assign;
   using ::std::has_trivial_destructor;
   using ::std::has_nothrow_constructor;
   using ::std::has_nothrow_copy;
   using ::std::has_nothrow_assign;
   using ::std::has_virtual_destructor;
   using ::std::is_signed;
   using ::std::is_unsigned;
   using ::std::alignment_of;
   using ::std::rank;
   using ::std::extent;
   using ::std::is_same;
   using ::std::tr1::is_base_of;
   using ::std::is_convertible;
   using ::std::remove_const;
   using ::std::remove_volatile;
   using ::std::remove_cv;
   using ::std::add_const;
   using ::std::add_volatile;
   using ::std::add_cv;
   using ::std::remove_reference;
   using ::std::add_reference;
   using ::std::remove_extent;
   using ::std::remove_all_extents;
   using ::std::remove_pointer;
   using ::std::add_pointer;
   using ::std::aligned_storage;

} }

#endif

#endif
