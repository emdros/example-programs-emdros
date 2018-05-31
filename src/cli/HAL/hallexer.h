/*
 * hallexer.h
 *
 * HALScanner
 *
 * Ulrik Petersen
 * Created: 6/23-2007
 * Last update: 11/9-2017
 *
 */
/************************************************************************
 *
 *   Emdros - the database engine for analyzed or annotated text
 *   Copyright (C) 2017  Ulrik Sandborg-Petersen
 *
 *   See the file LICENSE in the root of the sources for copyright
 *   information.
 *
 **************************************************************************/

/**@file hallexer.h
 *@brief Header file for HALScanner
 */


#ifndef HALLEXER__H__
#define HALLEXER__H__

#include <istream>

class HAL_Execution_environment; // Forward declaration

class HALScanner {
protected:
	std::istream *pIn;
	HAL_Execution_environment *pHEE;
	char *bot, *tok, *ptr, *cur, *pos, *lim, *top, *eof;
public:
	HALScanner(std::istream *pIn);
	virtual ~HALScanner();
	int scan(HAL_Execution_environment *pHee);
	bool noMoreInput() { return eof != 0 && cur == eof; };
protected:
	char *fill(char* cursor);
	void addWord(void);
private:
	HALScanner(const HALScanner&); // Copy constructor unimplemented
	HALScanner& operator=(const HALScanner&); // Assignment operator unimplemented
};

#endif /* HALLEXER__H__ */
