//  (C) Copyright John Maddock 2008.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_TR1_CMATH_HPP_INCLUDED
#  define BOOST_TR1_CMATH_HPP_INCLUDED
#  include <boost/tr1/detail/config.hpp>

#ifdef BOOST_HAS_TR1_CMATH

#  if defined(BOOST_HAS_INCLUDE_NEXT) && !defined(BOOST_TR1_DISABLE_INCLUDE_NEXT)
#     include_next BOOST_TR1_HEADER(cmath)
#  else
#     include <boost/tr1/detail/config_all.hpp>
#     include BOOST_TR1_HEADER(cmath)
#  endif

#else

#include <boost/math/tr1.hpp>

namespace std{ namespace tr1{

using std::math::tr1::assoc_laguerre;
using std::math::tr1::assoc_laguerref;
using std::math::tr1::assoc_laguerrel;
// [5.2.1.2] associated Legendre functions:
using std::math::tr1::assoc_legendre;
using std::math::tr1::assoc_legendref;
using std::math::tr1::assoc_legendrel;
// [5.2.1.3] beta function:
using std::math::tr1::beta;
using std::math::tr1::betaf;
using std::math::tr1::betal;
// [5.2.1.4] (complete) elliptic integral of the first kind:
using std::math::tr1::comp_ellint_1;
using std::math::tr1::comp_ellint_1f;
using std::math::tr1::comp_ellint_1l;
// [5.2.1.5] (complete) elliptic integral of the second kind:
using std::math::tr1::comp_ellint_2;
using std::math::tr1::comp_ellint_2f;
using std::math::tr1::comp_ellint_2l;
// [5.2.1.6] (complete) elliptic integral of the third kind:
using std::math::tr1::comp_ellint_3;
using std::math::tr1::comp_ellint_3f;
using std::math::tr1::comp_ellint_3l;
#if 0
// [5.2.1.7] confluent hypergeometric functions:
using std::math::tr1::conf_hyperg;
using std::math::tr1::conf_hypergf;
using std::math::tr1::conf_hypergl;
#endif
// [5.2.1.8] regular modified cylindrical Bessel functions:
using std::math::tr1::cyl_bessel_i;
using std::math::tr1::cyl_bessel_if;
using std::math::tr1::cyl_bessel_il;
// [5.2.1.9] cylindrical Bessel functions (of the first kind):
using std::math::tr1::cyl_bessel_j;
using std::math::tr1::cyl_bessel_jf;
using std::math::tr1::cyl_bessel_jl;
// [5.2.1.10] irregular modified cylindrical Bessel functions:
using std::math::tr1::cyl_bessel_k;
using std::math::tr1::cyl_bessel_kf;
using std::math::tr1::cyl_bessel_kl;
// [5.2.1.11] cylindrical Neumann functions;
// cylindrical Bessel functions (of the second kind):
using std::math::tr1::cyl_neumann;
using std::math::tr1::cyl_neumannf;
using std::math::tr1::cyl_neumannl;
// [5.2.1.12] (incomplete) elliptic integral of the first kind:
using std::math::tr1::ellint_1;
using std::math::tr1::ellint_1f;
using std::math::tr1::ellint_1l;
// [5.2.1.13] (incomplete) elliptic integral of the second kind:
using std::math::tr1::ellint_2;
using std::math::tr1::ellint_2f;
using std::math::tr1::ellint_2l;
// [5.2.1.14] (incomplete) elliptic integral of the third kind:
using std::math::tr1::ellint_3;
using std::math::tr1::ellint_3f;
using std::math::tr1::ellint_3l;
// [5.2.1.15] exponential integral:
using std::math::tr1::expint;
using std::math::tr1::expintf;
using std::math::tr1::expintl;
// [5.2.1.16] Hermite polynomials:
using std::math::tr1::hermite;
using std::math::tr1::hermitef;
using std::math::tr1::hermitel;
#if 0
// [5.2.1.17] hypergeometric functions:
using std::math::tr1::hyperg;
using std::math::tr1::hypergf;
using std::math::tr1::hypergl;
#endif
// [5.2.1.18] Laguerre polynomials:
using std::math::tr1::laguerre;
using std::math::tr1::laguerref;
using std::math::tr1::laguerrel;
// [5.2.1.19] Legendre polynomials:
using std::math::tr1::legendre;
using std::math::tr1::legendref;
using std::math::tr1::legendrel;
// [5.2.1.20] Riemann zeta function:
using std::math::tr1::riemann_zeta;
using std::math::tr1::riemann_zetaf;
using std::math::tr1::riemann_zetal;
// [5.2.1.21] spherical Bessel functions (of the first kind):
using std::math::tr1::sph_bessel;
using std::math::tr1::sph_besself;
using std::math::tr1::sph_bessell;
// [5.2.1.22] spherical associated Legendre functions:
using std::math::tr1::sph_legendre;
using std::math::tr1::sph_legendref;
using std::math::tr1::sph_legendrel;
// [5.2.1.23] spherical Neumann functions;
// spherical Bessel functions (of the second kind):
using std::math::tr1::sph_neumann;
using std::math::tr1::sph_neumannf;
using std::math::tr1::sph_neumannl;

// types
using std::math::tr1::double_t;
using std::math::tr1::float_t;
// functions
using std::math::tr1::acosh;
using std::math::tr1::acoshf;
using std::math::tr1::acoshl;
using std::math::tr1::asinh;
using std::math::tr1::asinhf;
using std::math::tr1::asinhl;
using std::math::tr1::atanh;
using std::math::tr1::atanhf;
using std::math::tr1::atanhl;
using std::math::tr1::cbrt;
using std::math::tr1::cbrtf;
using std::math::tr1::cbrtl;
using std::math::tr1::copysign;
using std::math::tr1::copysignf;
using std::math::tr1::copysignl;
using std::math::tr1::erf;
using std::math::tr1::erff;
using std::math::tr1::erfl;
using std::math::tr1::erfc;
using std::math::tr1::erfcf;
using std::math::tr1::erfcl;
#if 0
using std::math::tr1::exp2;
using std::math::tr1::exp2f;
using std::math::tr1::exp2l;
#endif
using std::math::tr1::expm1;
using std::math::tr1::expm1f;
using std::math::tr1::expm1l;
#if 0
using std::math::tr1::fdim;
using std::math::tr1::fdimf;
using std::math::tr1::fdiml;
using std::math::tr1::fma;
using std::math::tr1::fmaf;
using std::math::tr1::fmal;
#endif
using std::math::tr1::fmax;
using std::math::tr1::fmaxf;
using std::math::tr1::fmaxl;
using std::math::tr1::fmin;
using std::math::tr1::fminf;
using std::math::tr1::fminl;
using std::math::tr1::hypot;
using std::math::tr1::hypotf;
using std::math::tr1::hypotl;
#if 0
using std::math::tr1::ilogb;
using std::math::tr1::ilogbf;
using std::math::tr1::ilogbl;
#endif
using std::math::tr1::lgamma;
using std::math::tr1::lgammaf;
using std::math::tr1::lgammal;
#if 0
using std::math::tr1::llrint;
using std::math::tr1::llrintf;
using std::math::tr1::llrintl;
#endif
using std::math::tr1::llround;
using std::math::tr1::llroundf;
using std::math::tr1::llroundl;
using std::math::tr1::log1p;
using std::math::tr1::log1pf;
using std::math::tr1::log1pl;
#if 0
using std::math::tr1::log2;
using std::math::tr1::log2f;
using std::math::tr1::log2l;
using std::math::tr1::logb;
using std::math::tr1::logbf;
using std::math::tr1::logbl;
using std::math::tr1::lrint;
using std::math::tr1::lrintf;
using std::math::tr1::lrintl;
#endif
using std::math::tr1::lround;
using std::math::tr1::lroundf;
using std::math::tr1::lroundl;
#if 0
using std::math::tr1::nan;
using std::math::tr1::nanf;
using std::math::tr1::nanl;
using std::math::tr1::nearbyint;
using std::math::tr1::nearbyintf;
using std::math::tr1::nearbyintl;
#endif
using std::math::tr1::nextafter;
using std::math::tr1::nextafterf;
using std::math::tr1::nextafterl;
using std::math::tr1::nexttoward;
using std::math::tr1::nexttowardf;
using std::math::tr1::nexttowardl;
#if 0
using std::math::tr1::remainder;
using std::math::tr1::remainderf;
using std::math::tr1::remainderl;
using std::math::tr1::remquo;
using std::math::tr1::remquof;
using std::math::tr1::remquol;
using std::math::tr1::rint;
using std::math::tr1::rintf;
using std::math::tr1::rintl;
#endif
using std::math::tr1::round;
using std::math::tr1::roundf;
using std::math::tr1::roundl;
#if 0
using std::math::tr1::scalbln;
using std::math::tr1::scalblnf;
using std::math::tr1::scalblnl;
using std::math::tr1::scalbn;
using std::math::tr1::scalbnf;
using std::math::tr1::scalbnl;
#endif
using std::math::tr1::tgamma;
using std::math::tr1::tgammaf;
using std::math::tr1::tgammal;
using std::math::tr1::trunc;
using std::math::tr1::truncf;
using std::math::tr1::truncl;
// C99 macros defined as C++ templates
using std::math::tr1::signbit;
using std::math::tr1::fpclassify;
using std::math::tr1::isfinite;
using std::math::tr1::isinf;
using std::math::tr1::isnan;
using std::math::tr1::isnormal;
#if 0
using std::math::tr1::isgreater;
using std::math::tr1::isgreaterequal;
using std::math::tr1::isless;
using std::math::tr1::islessequal;
using std::math::tr1::islessgreater;
using std::math::tr1::isunordered;
#endif
} } // namespaces

#endif // BOOST_HAS_TR1_CMATH

#endif // BOOST_TR1_CMATH_HPP_INCLUDED
