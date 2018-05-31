/*
 * hal_schema.cpp
 *
 * HAL schema string
 *
 * Created: Sometime in the first half of 2003
 * Last update: 11/9-2017
 *
 ************************************************************************/
/************************************************************************
 *
 *   Emdros - the database engine for analyzed or annotated text
 *   Copyright (C) 2001-2017  Ulrik Petersen
 *
 *   See the file LICENSE in the root of the sources for copyright
 *   information.
 *
 **************************************************************************/

#include "hal_schema.h"

std::string strHALschema = 
  "//\n"
  "// schema.mql - schema for HAL space\n"
  "//\n"
  "// Created: 29/5-2003\n"
  "// Last update: 11/9-2017\n"
  "//\n"
  "\n"
  "CREATE ENUMERATION boolean = {\n"
  "  false = 0, \n"
  "  true = 1\n"
  "} GO\n"
  "\n"
  "CREATE OBJECT TYPE\n"
  "WITH SINGLE MONAD OBJECTS\n"
  "[Word\n"
  "   surface : string FROM SET WITH INDEX;\n"
  "   stripped_surface : string FROM SET WITH INDEX;\n"
  "   is_number : boolean DEFAULT false;\n"
  "]\n"
  "GO\n"
  "\n"
  "CREATE OBJECT TYPE\n"
  "WITH SINGLE RANGE OBJECTS\n"
  "[Sentence\n"
  "  end_of_sentence_punctuation : STRING(1);\n"
  "]\n"
  "GO\n"
  "\n"
  "CREATE OBJECT TYPE\n"
  "WITH SINGLE RANGE OBJECTS\n"
  "[Text\n"
  "   add_numbers : boolean DEFAULT false;\n"	
  "]\n"
  "GO\n"
  "\n"
  "CREATE OBJECT TYPE\n"
  "WITH SINGLE MONAD OBJECTS\n"
  "[HAL_word\n"
  "   stripped_surface : string FROM SET WITH INDEX;\n"
  "]\n"
  "GO\n"
  "\n"
  "CREATE OBJECT TYPE\n"
  "WITH SINGLE MONAD OBJECTS\n"
  "[HAL_cell\n"
  "   n : integer;\n"
  "   column : integer;\n"
  "   value : integer;\n"
  "]\n"
  "GO\n"
  "\n"
  "CREATE OBJECT TYPE\n"
  "WITH SINGLE RANGE OBJECTS\n"
  "[HAL_space\n"
  "   n : integer;\n"
  "]\n"
  "GO\n"
  "\n";
