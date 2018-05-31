%{

/*
 * hallexer.l
 *
 * Created: Sometime in the first half of 2003
 * Last update: 7/25-2003
 *
 *******************************************************************/
/************************************************************************
 *
 *   Emdros - the database engine for analyzed or annotated text
 *   Copyright (C) 2001-2003  Ulrik Petersen
 *
 *   See the file LICENSE in the root of the sources for copyright
 *   information.
 *
 **************************************************************************/


#define HAL_LEXER


#include <string>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <hal_execution_environment.h>
#include <hal_defines.h>


%}

%option c++ 
%option prefix="hh"
%option yylineno
/* %option case-insensitive */
%option noyywrap
%option 8bit

/*
%x STRINGDQ
%x STRINGSQ
%x COMMENT_SLASH_STAR
%x COMMENT_SLASH_SLASH

*/


%%

[\(\"\'\)]+                          /* remove */
[A-Za-z\xa6\xa8\xb4\xb8\xbc-\xbe\xc0-\xd6\xd8-\xf6\xf8-\xff\(\"\'][A-Za-z\xa6\xa8\xb4\xb8\xbc-\xbe\xc0-\xd6\xd8-\xf6\xf8-\xff\-]*-[0-9]+[\)\"\']?         { pHEE->set_current_word(yytext); return TT_WORD; }
[A-Za-z\xa6\xa8\xb4\xb8\xbc-\xbe\xc0-\xd6\xd8-\xf6\xf8-\xff\(\"\'][A-Za-z\xa6\xa8\xb4\xb8\xbc-\xbe\xc0-\xd6\xd8-\xf6\xf8-\xff\-\(\)\"\']*         { pHEE->set_current_word(yytext); return TT_WORD; }
\-                          /* remove */
[\.\!\?]                { pHEE->set_current_punctuation(yytext); return TT_END_OF_SENTENCE_PUNCTUATION; }
[0-9]                       { pHEE->set_current_word(yytext); return TT_NUMBER; }
[0-9][0-9\.\,]*[0-9]        { /* NOTE: When changing this definition, 
                                 also change HAL_Execution_environment::is_number(). */
                                  pHEE->set_current_word(yytext); return TT_NUMBER; }
[\(\)\'\"\,\;\:\/\&\%\*\[\]~\+_§\#\$]                /* remove */
[ \t]+                      /* remove */
[\x80-\xa5\xa6\xa9-\xb3\xb5-\xb7\xb9-\xbb\xbf\xd7\xf7]+               /* remove */
\n                          /* remove */




%%

