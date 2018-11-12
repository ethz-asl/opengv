//  (C) Copyright John Maddock 2005.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_TR1_REGEX_HPP_INCLUDED
#  define BOOST_TR1_REGEX_HPP_INCLUDED
#  include <boost/tr1/detail/config.hpp>

#ifdef BOOST_HAS_TR1_REGEX

#  if defined(BOOST_HAS_INCLUDE_NEXT) && !defined(BOOST_TR1_DISABLE_INCLUDE_NEXT)
#     include_next BOOST_TR1_HEADER(regex)
#  else
#     include <boost/tr1/detail/config_all.hpp>
#     include BOOST_TR1_STD_HEADER(BOOST_TR1_PATH(regex))
#  endif

#else

#include <boost/regex.hpp>

namespace std{ namespace tr1{

// [7.5] Regex constants
namespace regex_constants {

using ::std::regex_constants::syntax_option_type;
using ::std::regex_constants::icase;
using ::std::regex_constants::nosubs;
using ::std::regex_constants::optimize;
using ::std::regex_constants::collate;
using ::std::regex_constants::ECMAScript;
using ::std::regex_constants::basic;
using ::std::regex_constants::extended;
using ::std::regex_constants::awk;
using ::std::regex_constants::grep;
using ::std::regex_constants::egrep;

using ::std::regex_constants::match_flag_type;
using ::std::regex_constants::match_default;
using ::std::regex_constants::match_not_bol;
using ::std::regex_constants::match_not_eol;
using ::std::regex_constants::match_not_bow;
using ::std::regex_constants::match_not_eow;
using ::std::regex_constants::match_any;
using ::std::regex_constants::match_not_null;
using ::std::regex_constants::match_continuous;
using ::std::regex_constants::match_prev_avail;
using ::std::regex_constants::format_default;
using ::std::regex_constants::format_sed;
using ::std::regex_constants::format_no_copy;
using ::std::regex_constants::format_first_only;

using ::std::regex_constants::error_type;
using ::std::regex_constants::error_collate;
using ::std::regex_constants::error_ctype;
using ::std::regex_constants::error_escape;
using ::std::regex_constants::error_backref;
using ::std::regex_constants::error_brack;
using ::std::regex_constants::error_paren;
using ::std::regex_constants::error_brace;
using ::std::regex_constants::error_badbrace;
using ::std::regex_constants::error_range;
using ::std::regex_constants::error_space;
using ::std::regex_constants::error_badrepeat;
using ::std::regex_constants::error_complexity;
using ::std::regex_constants::error_stack;

} // namespace regex_constants

// [7.6] Class regex_error
using ::std::regex_error;

// [7.7] Class template regex_traits
using ::std::regex_traits;

// [7.8] Class template basic_regex
using ::std::basic_regex;
using ::std::regex;
#ifndef BOOST_NO_WREGEX
using ::std::wregex;
#endif

#if !BOOST_WORKAROUND(__BORLANDC__, < 0x0582)
// [7.8.6] basic_regex swap
using ::std::swap;
#endif

// [7.9] Class template sub_match
using ::std::sub_match;

using ::std::csub_match;
#ifndef BOOST_NO_WREGEX
using ::std::wcsub_match;
#endif
using ::std::ssub_match;
#ifndef BOOST_NO_WREGEX
using ::std::wssub_match;
#endif

// [7.10] Class template match_results
using ::std::match_results;
using ::std::cmatch;
#ifndef BOOST_NO_WREGEX
using ::std::wcmatch;
#endif
using ::std::smatch;
#ifndef BOOST_NO_WREGEX
using ::std::wsmatch;
#endif

using ::std::regex_match;

// [7.11.3] Function template regex_search
using ::std::regex_search;

// [7.11.4] Function template regex_replace
using ::std::regex_replace;

// [7.12.1] Class template regex_iterator
using ::std::regex_iterator;
using ::std::cregex_iterator;
#ifndef BOOST_NO_WREGEX
using ::std::wcregex_iterator;
#endif
using ::std::sregex_iterator;
#ifndef BOOST_NO_WREGEX
using ::std::wsregex_iterator;
#endif

// [7.12.2] Class template regex_token_iterator
using ::std::regex_token_iterator;
using ::std::cregex_token_iterator;
#ifndef BOOST_NO_WREGEX
using ::std::wcregex_token_iterator;
#endif
using ::std::sregex_token_iterator;
#ifndef BOOST_NO_WREGEX
using ::std::wsregex_token_iterator;
#endif

} } // namespaces

#endif

#endif
