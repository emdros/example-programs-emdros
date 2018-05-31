/*
 * hal_string_func.cpp
 *
 * String helper functions
 *
 * Ulrik Petersen
 * Created: 3/1-2001
 * Last update: 11/9-2017
 *
 */
/************************************************************************
 *
 *   Emdros - the database engine for analyzed or annotated text
 *   Copyright (C) 2001-2017  Ulrik Sandborg-Petersen
 *
 *   See the file LICENSE in the root of the sources for copyright
 *   information.
 *
 **************************************************************************/


#include "hal_string_func.h"

#include <emdros.h>


#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <sstream>
#include <iostream>

bool hal_is_other_than_whitespace(const std::string& str)
{
  return strcspn(str.c_str(), " \t\n\r\v") != 0;
}

bool hal_has_double_quote(const std::string& str)
{
  return str.find_first_of('"') != std::string::npos;
}

std::string hal_strip_string(const std::string& input, const std::string& chars_to_strip)
{
	std::string result = "";
	for (std::string::size_type i = 0; i < input.length(); ++i) {
		// See if input[i] can not be found in chars_to_strip
		if (chars_to_strip.find_first_of(input[i], 0) == std::string::npos) {
			result += input[i];
		} else {
			; // Don't add it.
		}
	}
	return result;
}
