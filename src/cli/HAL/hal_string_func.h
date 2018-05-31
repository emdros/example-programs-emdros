/*
 * hal_string_func.h
 *
 * String helper functions
 *
 * Ulrik Petersen
 * Created: 3/1-2001
 * Last update: 7/17-2003
 *
 */
/************************************************************************
 *
 *   Emdros - the database engine for analyzed or annotated text
 *   Copyright (C) 2001-2002  Ulrik Petersen
 *
 *   See the file LICENSE in the root of the sources for copyright
 *   information.
 *
 **************************************************************************/



#ifndef __HAL_STRING_FUNC__H__
#define __HAL_STRING_FUNC__H__

#include <string>

extern bool hal_is_other_than_whitespace(const std::string& str);
extern bool hal_has_double_quote(const std::string& str);
extern std::string hal_strip_string(const std::string& input, const std::string& chars_to_strip);

#endif // __HAL_STRING_FUNC__H__
