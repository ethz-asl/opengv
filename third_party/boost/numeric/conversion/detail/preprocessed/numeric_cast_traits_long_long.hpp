//
//! Copyright (c) 2011-2012
//! Brandon Kohn
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
namespace boost { namespace numeric {
    
    
    template <>
    struct numeric_cast_traits
        <
            char
          , std::long_long_type
        >
    {
        typedef def_overflow_handler overflow_policy;
        typedef UseInternalRangeChecker range_checking_policy;
        typedef Trunc<std::long_long_type> rounding_policy;
    }; 
    
    template <>
    struct numeric_cast_traits
        <
            char
          , std::ulong_long_type
        >
    {
        typedef def_overflow_handler overflow_policy;
        typedef UseInternalRangeChecker range_checking_policy;
        typedef Trunc<std::ulong_long_type> rounding_policy;
    }; 
    
    template <>
    struct numeric_cast_traits
        <
            signed char
          , std::long_long_type
        >
    {
        typedef def_overflow_handler overflow_policy;
        typedef UseInternalRangeChecker range_checking_policy;
        typedef Trunc<std::long_long_type> rounding_policy;
    }; 
    
    template <>
    struct numeric_cast_traits
        <
            signed char
          , std::ulong_long_type
        >
    {
        typedef def_overflow_handler overflow_policy;
        typedef UseInternalRangeChecker range_checking_policy;
        typedef Trunc<std::ulong_long_type> rounding_policy;
    }; 
    
    template <>
    struct numeric_cast_traits
        <
            unsigned char
          , std::long_long_type
        >
    {
        typedef def_overflow_handler overflow_policy;
        typedef UseInternalRangeChecker range_checking_policy;
        typedef Trunc<std::long_long_type> rounding_policy;
    }; 
    
    template <>
    struct numeric_cast_traits
        <
            unsigned char
          , std::ulong_long_type
        >
    {
        typedef def_overflow_handler overflow_policy;
        typedef UseInternalRangeChecker range_checking_policy;
        typedef Trunc<std::ulong_long_type> rounding_policy;
    }; 
    
    template <>
    struct numeric_cast_traits
        <
            short
          , std::long_long_type
        >
    {
        typedef def_overflow_handler overflow_policy;
        typedef UseInternalRangeChecker range_checking_policy;
        typedef Trunc<std::long_long_type> rounding_policy;
    }; 
    
    template <>
    struct numeric_cast_traits
        <
            short
          , std::ulong_long_type
        >
    {
        typedef def_overflow_handler overflow_policy;
        typedef UseInternalRangeChecker range_checking_policy;
        typedef Trunc<std::ulong_long_type> rounding_policy;
    }; 
    
    template <>
    struct numeric_cast_traits
        <
            unsigned short
          , std::long_long_type
        >
    {
        typedef def_overflow_handler overflow_policy;
        typedef UseInternalRangeChecker range_checking_policy;
        typedef Trunc<std::long_long_type> rounding_policy;
    }; 
    
    template <>
    struct numeric_cast_traits
        <
            unsigned short
          , std::ulong_long_type
        >
    {
        typedef def_overflow_handler overflow_policy;
        typedef UseInternalRangeChecker range_checking_policy;
        typedef Trunc<std::ulong_long_type> rounding_policy;
    }; 
    
    template <>
    struct numeric_cast_traits
        <
            int
          , std::long_long_type
        >
    {
        typedef def_overflow_handler overflow_policy;
        typedef UseInternalRangeChecker range_checking_policy;
        typedef Trunc<std::long_long_type> rounding_policy;
    }; 
    
    template <>
    struct numeric_cast_traits
        <
            int
          , std::ulong_long_type
        >
    {
        typedef def_overflow_handler overflow_policy;
        typedef UseInternalRangeChecker range_checking_policy;
        typedef Trunc<std::ulong_long_type> rounding_policy;
    }; 
    
    template <>
    struct numeric_cast_traits
        <
            unsigned int
          , std::long_long_type
        >
    {
        typedef def_overflow_handler overflow_policy;
        typedef UseInternalRangeChecker range_checking_policy;
        typedef Trunc<std::long_long_type> rounding_policy;
    }; 
    
    template <>
    struct numeric_cast_traits
        <
            unsigned int
          , std::ulong_long_type
        >
    {
        typedef def_overflow_handler overflow_policy;
        typedef UseInternalRangeChecker range_checking_policy;
        typedef Trunc<std::ulong_long_type> rounding_policy;
    }; 
    
    template <>
    struct numeric_cast_traits
        <
            long
          , std::long_long_type
        >
    {
        typedef def_overflow_handler overflow_policy;
        typedef UseInternalRangeChecker range_checking_policy;
        typedef Trunc<std::long_long_type> rounding_policy;
    }; 
    
    template <>
    struct numeric_cast_traits
        <
            long
          , std::ulong_long_type
        >
    {
        typedef def_overflow_handler overflow_policy;
        typedef UseInternalRangeChecker range_checking_policy;
        typedef Trunc<std::ulong_long_type> rounding_policy;
    }; 
    
    template <>
    struct numeric_cast_traits
        <
            unsigned long
          , std::long_long_type
        >
    {
        typedef def_overflow_handler overflow_policy;
        typedef UseInternalRangeChecker range_checking_policy;
        typedef Trunc<std::long_long_type> rounding_policy;
    }; 
    
    template <>
    struct numeric_cast_traits
        <
            unsigned long
          , std::ulong_long_type
        >
    {
        typedef def_overflow_handler overflow_policy;
        typedef UseInternalRangeChecker range_checking_policy;
        typedef Trunc<std::ulong_long_type> rounding_policy;
    }; 
    
    template <>
    struct numeric_cast_traits
        <
            float
          , std::long_long_type
        >
    {
        typedef def_overflow_handler overflow_policy;
        typedef UseInternalRangeChecker range_checking_policy;
        typedef Trunc<std::long_long_type> rounding_policy;
    }; 
    
    template <>
    struct numeric_cast_traits
        <
            float
          , std::ulong_long_type
        >
    {
        typedef def_overflow_handler overflow_policy;
        typedef UseInternalRangeChecker range_checking_policy;
        typedef Trunc<std::ulong_long_type> rounding_policy;
    }; 
    
    template <>
    struct numeric_cast_traits
        <
            double
          , std::long_long_type
        >
    {
        typedef def_overflow_handler overflow_policy;
        typedef UseInternalRangeChecker range_checking_policy;
        typedef Trunc<std::long_long_type> rounding_policy;
    }; 
    
    template <>
    struct numeric_cast_traits
        <
            double
          , std::ulong_long_type
        >
    {
        typedef def_overflow_handler overflow_policy;
        typedef UseInternalRangeChecker range_checking_policy;
        typedef Trunc<std::ulong_long_type> rounding_policy;
    }; 
    
    template <>
    struct numeric_cast_traits
        <
            long double
          , std::long_long_type
        >
    {
        typedef def_overflow_handler overflow_policy;
        typedef UseInternalRangeChecker range_checking_policy;
        typedef Trunc<std::long_long_type> rounding_policy;
    }; 
    
    template <>
    struct numeric_cast_traits
        <
            long double
          , std::ulong_long_type
        >
    {
        typedef def_overflow_handler overflow_policy;
        typedef UseInternalRangeChecker range_checking_policy;
        typedef Trunc<std::ulong_long_type> rounding_policy;
    }; 
    
    template <>
    struct numeric_cast_traits
        <
            std::long_long_type
          , std::long_long_type
        >
    {
        typedef def_overflow_handler overflow_policy;
        typedef UseInternalRangeChecker range_checking_policy;
        typedef Trunc<std::long_long_type> rounding_policy;
    }; 
    
    template <>
    struct numeric_cast_traits
        <
            std::long_long_type
          , std::ulong_long_type
        >
    {
        typedef def_overflow_handler overflow_policy;
        typedef UseInternalRangeChecker range_checking_policy;
        typedef Trunc<std::ulong_long_type> rounding_policy;
    }; 
    
    template <>
    struct numeric_cast_traits
        <
            std::ulong_long_type
          , std::long_long_type
        >
    {
        typedef def_overflow_handler overflow_policy;
        typedef UseInternalRangeChecker range_checking_policy;
        typedef Trunc<std::long_long_type> rounding_policy;
    }; 
    
    template <>
    struct numeric_cast_traits
        <
            std::ulong_long_type
          , std::ulong_long_type
        >
    {
        typedef def_overflow_handler overflow_policy;
        typedef UseInternalRangeChecker range_checking_policy;
        typedef Trunc<std::ulong_long_type> rounding_policy;
    }; 
}}
