/**
* Begin svn Header
* $Rev: 27 $:	Revision of last commit
* $Author: josephodada@gmail.com $:	Author of last commit
* $Date: 2013-04-25 10:07:15 +0100 (Thu, 25 Apr 2013) $:	Date of last commit
* $HeadURL: https://numl.googlecode.com/svn/trunk/libnuml/src/common/libnuml-config-win.h $
* $Id: libnuml-config-win.h 27 2013-04-25 09:07:15Z josephodada@gmail.com $
* End svn Header
* ***************************************************************************
* This file is part of libNUML.  Please visit http://code.google.com/p/numl/for more
* information about NUML, and the latest version of libNUML.
* Copyright (c) 2013 The University of Manchester.
*
* This library is free software; you can redistribute it and/or modify it
* under the terms of the GNU Lesser General Public License as published
* by the Free Software Foundation.  A copy of the license agreement is
* provided in the file named "LICENSE.txt" included with this software
* distribution and also available online as http://www.gnu.org/licenses/lgpl.html
*
* The original code was initially developed by:
*
* 	SBML Team
* 	Control and Dynamical Systems, MC 107-81
* 	California Institute of Technology
* 	Pasadena, CA, 91125, USA
*
*  	http://www.sbml.org
* 	mailto:sbml-team@caltech.edu
*
* Adapted for NUML by:
*
* 	NUML Team
* 	Computational Systems Biology Group
* 	School of Computer Science
* 	The University of Manchester
* 	Manchester, M1 7DN UK
* 	mailto:josephodada@gmail.com
*
*   Contributor(s):
*   Joseph O. Dada, The University of Manchester - initial LIBNUML API and implementation
* ***************************************************************************
**/


/**
 *
 * Some explanations about this file are warranted.  On Linux, MacOS X,
 * Cygwin, etc., <tt>libsbml-config-unix.h</tt> and
 * <tt>libsbml-package.h</tt> are generated from
 * <tt>libsbml-config-unix.h.in</tt> and <tt>libsbml-package.h.in</tt>,
 * respectively, by the @c configure script at the top level of the libNUML
 * distribution.
 * 
 * On Windows, we cannot rely on <tt>libsbml-config-win.h</tt> being
 * generated by @c configure, since most developers will not be able to run
 * @c configure in that environment.  Instead, both
 * <tt>libsbml-config-win.h</tt> and <tt>libsbml-package.h</tt> (which see)
 * are stored in the source repository and must be updated by the libNUML
 * developers as necessary.  The file <tt>libsbml-config-win.h</tt> should
 * rarely, if ever, need to be updated, while <tt>libsbml-package.h</tt>
 * should require minor updates prior to each libsbml release.  This is
 * admittedly not an ideal and fool-proof arrangement; however, at this
 * time it is the best we have been able to find under the circumstances.
 */

/* Define to 1 if you have the <check.h> header file. */
/* #define HAVE_CHECK_H 1 */

/* Define to 1 if you have the `check' library (-lcheck). */
/* #define HAVE_LIBCHECK 1 */


/* Define to 1 if you have the <expat.h> header file. */
/* #undef HAVE_EXPAT_H */

/* Define to 1 to use the Expat XML library */
/* #undef USE_EXPAT */


/* Define to 1 if you have the <errno.h> header file. */
#define HAVE_ERRNO_H 1

/* Define to 1 if you have the <ieeefp.h> header file. */
/* #define HAVE_IEEEFP_H 1 */

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Define to 1 if you have the <math.h> header file. */
#define HAVE_MATH_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the `m' library (-lm). */
/* #define HAVE_LIBM 1 */


/* Define to 1 to enable primitive memory tracing. */
/* #define TRACE_MEMORY 1 */

/* Define to 1 to build the NUML layout extension. */
/* #define USE_LAYOUT 1 */


/* Define to 1 if your processor stores words with the most significant byte
   first (like Motorola and SPARC, unlike Intel and VAX). */
/* #define WORDS_BIGENDIAN 1 */


/* Define to the full name of this package. */
#define PACKAGE_NAME "libNUML"

/* Define to the version of this package. */
#define PACKAGE_VERSION "1.0.1"
