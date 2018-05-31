#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([emdros-example-programs], [1.0.0], [ulrikp@scripturesys.com])
AC_CONFIG_MACRO_DIRS([m4])
LT_INIT
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([src/cli/HAL/hal.cpp])
AC_CONFIG_HEADERS([emdros-example-programs-config.h])


# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

AX_CXX_COMPILE_STDCXX(11, noext, optional)

EMDROS_BUILDENV
EMDROS_SOLARIS
EMDROS_MACOS

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdint.h string.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_INT32_T
AC_TYPE_INT64_T
AC_C_RESTRICT
AC_TYPE_SIZE_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([memset strtol])



# Do wxWidgets, if necessary
EMDROS_WX_SUPPORT

PKG_CHECK_MODULES([EMDROS], [emdros])
EMDROS_STATIC_LIBS=`pkg-config --libs --static emdros`
AC_SUBST(EMDROS_STATIC_LIBS)

AC_CONFIG_FILES([Makefile
                 emdros-example-programs.spec
		 doc/Makefile
		 src/Makefile
		 src/cli/Makefile
		 src/cli/HAL/Makefile
		 src/cli/HAL/doc/Makefile
		 src/gui/Makefile
		 src/gui/art/Makefile
		 src/gui/chunkingtool/Makefile
		 src/gui/chunkingtool/doc/Makefile
               ])
AC_OUTPUT
