/*
 * hal_build_database.h
 *
 * Functions for building a HAL db
 *
 * Created: Sometime in the first half of 2003
 * Last update: 11/3-2015
 *
 *******************************************************************/
/************************************************************************
 *
 *   Emdros - the database engine for analyzed or annotated text
 *   Copyright (C) 2001-2015  Ulrik Sandborg-Petersen
 *
 *   See the file LICENSE in the root of the sources for copyright
 *   information.
 *
 **************************************************************************/


#ifndef __HAL_BUILD_DB__H__
#define __HAL_BUILD_DB__H__

#include <string>

class EmdrosEnv; // Forward declaration

extern bool CreateDB(EmdrosEnv *pEEE, std::string dbname);
extern bool build_db(std::string inputfilename, std::string dbname, std::string wordlist_filename, bool bAddNumbers);

#endif // __HAL_BUILD_DB__H__
