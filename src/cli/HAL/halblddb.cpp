/*
 * hal_build_db.cpp
 *
 * Main program for building db
 *
 * Created: Sometime in the first half of 2003
 * Last update: 11/9-2017
 *
 *******************************************************************/
/************************************************************************
 *
 *   Emdros - the database engine for analyzed or annotated text
 *   Copyright (C) 2003-2017  Ulrik Sandborg-Petersen
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, license version 2.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *
 *   Other licensing forms
 *   =====================
 *
 *   If you wish to negotiate commercial licensing, please contact
 *   Ulrik Petersen at ulrikp[at]users.sourceforge.net.
 *
 *   Licensing can also be negotiated if your organization is an
 *   educational, non-profit, charity, missionary or similar
 *   organization.
 *
 **************************************************************************/


#include <emdros.h>

#include <iostream>
#include <fstream>

#include "hal_build_database.h"
#include "hal_defines.h"



// Global variables
extern EmdrosEnv *pEEE;

void show_version(std::ostream& ostr)
{
	ostr << "halblddb from Emdros version " << EMDROS_VERSION << std::endl;
}


void print_usage(std::ostream& ostr)
{
	show_version(ostr);
	ostr << "Usage: build_db [options]" << std::endl;
	ostr << "OPTIONS:" << std::endl;
	printUsageStandardArguments(ostr);
	ostr << "   -d , --dbname db     Use this database" << std::endl;
	ostr << "   -f , --input file    Use this text input file" << std::endl;
	ostr << "   -o , --output file   Use this wordlist output file" << std::endl;
	ostr << "   -n , --add-numbers   Don't ignore numbers" << std::endl;
	ostr << "DEFAULTS:" << std::endl;
	printUsageDefaultsOfStandardArguments(ostr);
}

bool DoDB(EmdrosEnv *pEEE, const std::string& input_filename, const std::string&dbname, const std::string& wordlist_filename, bool bAddNumbers) 
{
	if (input_filename == "") {
		std::cerr << "ERROR: you must give an input filename with -f." << std::endl;
		std::cerr << "type build_db --help for more information." << std::endl;
		return false;
	}

	if (wordlist_filename == "") {
		std::cerr << "ERROR: you must give a wordlist filename with -o." << std::endl;
		std::cerr << "type build_db --help for more information." << std::endl;
		return false;
	}

	if (dbname == "") {
		std::cerr << "ERROR: you must give a database name with -d." << std::endl;
		std::cerr << "type build_db --help for more information." << std::endl;
		return false;
	}

	// Test input_filename
	std::ifstream fin;
	fin.open(input_filename.c_str());
	if (!fin) {
		std::cerr << "ERROR: Cannot open " << input_filename << " for reading." << std::endl;
		fin.close();
		return false;
	}
	fin.close();

	// Open file
	std::ofstream fout;
	fout.open(wordlist_filename.c_str());
	if (!fout) {
		std::cerr << "ERROR: Cannot open " << wordlist_filename << " for writing." << std::endl;
		fout.close();
		return false;
	}
	fout.close();
  

	if (!CreateDB(pEEE, dbname)) {
		return false;
	}

	if (!build_db(input_filename, dbname, wordlist_filename, bAddNumbers)) {
		return false;
	}

	return true;
}

int main(int argc, char *argv[])
{
	// Initialize WordNet
	/*
	  if (wninit() != 0) {
	  std::cerr << "Error: Could not initialize WordNet." << std::endl;
	  return 1;
	  }
	*/

	std::string dbname;
	std::string input_filename;
	std::string wordlist_filename;
	std::string hostname;
	std::string user;
	std::string password;
	eBackendKind backend_kind;
	eCharsets dummy_charset;
	bool bAddNumbers = false;

	addStandardArguments(false // Do not add -e | --encoding
			     );

	addOption("-f", "--input", true, 
		  "",
		  "ERROR: -f and --input must have a filename as their argument.\n"
		  "       example: -f /home/joe/mytext.txt\n");

	addOption("-o", "--output", true, 
		  "",
		  "ERROR: -o and --output must have a filename as their argument.\n"
		  "       example: -o /home/joe/mywordlist.txt\n");

	addOption("-d", "--dbname", true, 
		  "",
		  "ERROR: -d and --dbname must have a database-name as their argument.\n"
		  "       example: -d book1\n");

	addOption("-n", "--add-numbers");
	
	// Parse arguments
	std::list<std::string> surplus_arguments;

	std::string error_message;
	if (!parseArguments(argc, argv, error_message, surplus_arguments)) {
		print_usage(std::cerr);
		std::cerr << error_message << std::endl;
		return 1;
	} else {
		bool bShowVersion;
		bool bShowHelp;
		std::string error_message;
		if (!getStandardArguments(bShowVersion, bShowHelp,
					  hostname,
					  user,
					  password,
					  backend_kind,
					  dummy_charset,
					  error_message)) {
			print_usage(std::cerr);
			std::cerr << error_message << std::endl;
			return 1;
		}

		// -V | --version
		if (bShowVersion) {
			show_version(std::cout);
			return 0;
		}

		// --help
		if (bShowHelp) {
			print_usage(std::cout);
			return 0;
		}

		// -d | --dbname
		getArgumentValue("-d", dbname);

		// -f | --input
		getArgumentValue("-f", input_filename);

		// -o | --output
		getArgumentValue("-o", wordlist_filename);

		// --nop | -n
		if (getArgumentPresent("-n")) {
			bAddNumbers = true;
		} else {
			bAddNumbers = false;
		}

		if (surplus_arguments.size() != 0) {
			print_usage(std::cerr);
			std::cerr << "ERROR: Extraneous argument(s) not parsed: '" << joinList("' and '", surplus_arguments) << "'." << std::endl;
			return 1;
		}
	}
  
	// Create Emdros environment
	pEEE = new EmdrosEnv(kOKConsole, kCSISO_8859_1,
			     hostname, user, password,
			     "emdf", backend_kind);
	if (!pEEE->connectionOk()) {
		std::cerr << "Error: Could not establish connection to DB." << std::endl;
		delete pEEE;
		return 3;
	}

	if (!DoDB(pEEE, input_filename, dbname, wordlist_filename, bAddNumbers)) {
		delete pEEE;
		return 3;
	}



	// Build db
	int nResult;
	bool bResult = true;

	if (bResult) {
		std::cerr << "Success!" << std::endl;
		nResult = 0;
	} else {
		std::cerr << "Failure!" << std::endl;
		nResult = 2;
	}


	// Return result
	return nResult;
}


