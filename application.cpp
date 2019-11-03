/*
 * Test Derive For Roman-Decimal Conversions and vice versa
 *
 */
#include <iostream>
#include <map>
#include <exception>
#include <string>
#include "roman_convert.h"
#include <regex>
#include <type_traits>
#include "decimal_convert.h"
#include <sstream>

#include "common.h"
using namespace std;

void runTestCases();

void testRomanBoundaries();
void testRomanInvalidInputs();
void testRomanGarbageInputs();

void testTroubleSomeDecimalValues();
void testNormalDecimalValue();

int main() {
	cout << "Roman to Decimal Conversion and vice-versa:\n";
	cout << "\t - Press 't' to run test cases\n";
	cout << "\t - Press 'r <Roman Numeral>'  to convert to a Decimal Number ex.: r XI ==> 11\n";
	cout << "\t - Press 'd <Decimal Number>' to convert to a Roman Numeral  ex.: d 23 ==> XXIII\n";
	cout << "Please enter a choice, for 'r' or 'd' follow them by a space then the number: ";

	// Obtaining user input
	string userInput;
	getline(cin, userInput);
	stringstream ss{userInput};

	string choice = "";
	ss >> choice;

	if (choice.length() == 1){
		//obtaining predicate in case choice was 'r' or 'd'
		string predicate = "";
		do{
			ss >> predicate;
		}while( predicate == " ");

		// notify a warning if another predicate is entered
		if(ss >> predicate){
			cout << "just one predicate the rest is not needed\n";
		}
		switch(choice[0]){
		case 't':
			if(predicate != ""){
				cout << "No predicate needed to run test cases\n";
			}
			runTestCases();
			break;
		case 'r':
		{
			RomanNumerals romanInst;
			uint16_t result;
			romanInst.convert(predicate, result);
			cout << "Equivalent Roman Numeral is: "<< result;
		}
		break;
		case 'd':
		{
			stringstream ss{predicate};
			uint16_t decInput;
			string result;

			// Search for double inputs got from Test Group 4
			if(predicate.find('.') != std::string::npos){
				cout << "Non-integer numbers are not allowed\n";
			}
			else if(ss >> decInput){
				DecimalNumerals DecimalInst;
				// if there is still characters in ss buffer, it means a case like "d 7abc"
				// i.e. a number followed by a non-numeric character, then reject this input.
				if (ss.eof() == false) {
					cout << "Please enter a number only without any other characters.\n";
				}
				else if (decInput == 0){
					cout << "zero has no equivalent Roman Numeral\n";
				}
				else{
					DecimalInst.convert(decInput,result);
				}
				if (result != "") (cout << "Equivalent Decimal Number is: "<< result);
			}
			else if(predicate ==""){
				cout << "no number supplied\n";
			}
			else{
				cout << "Non-numerical characters are not allowed\n";
			}
		}
		break;
		default:
			cout << "Wrong option entered\n";
		}
	}
	else{
		cout << "Wrong choice [more than one character]\n";
	}
	
	cout << "\n\nThank You ... Press Enter to leave\n";
	cin.get();
	return 0;
}

// It would be better to use google test gtest as a reliable framework for TDD unit testing
// First create a RomanNumerals class instance with convert function contain a simple prototype
// then through excessive testing the convert function can be improved
void runTestCases()
{
	cout << std::boolalpha; // to display TRUE or FALSE in case of boolean input
   /*			Test From Roman to Decimal           */
	cout << "===================== Test Group 1: Roman Boundaries Tests ==============================\n\n";
	testRomanBoundaries();
	cout << "\n================== Test Group 2:Roman Invalid inputs ==================================\n\n";
	testRomanInvalidInputs();
	cout << "\n================== Test Group 3: Roman Garbage Inputs ==================================\n\n";
	testRomanGarbageInputs();
	cout << "\n================== Test Group 4: Decimal Troublesome Values Conversion =================\n\n";
	testTroubleSomeDecimalValues();
	cout << "\n================== Test Group 5: Decimal Normal Values Conversion ======================\n\n";

	testNormalDecimalValue();

}

/* These test cases caught the error of not initializing the out integer in convert function
 * Helped making sure of conversion of boundaries like XI and IX*/
void testRomanBoundaries()
{
	// TC1: valid input boundaries
	RomanNumerals romanInst;
	uint16_t result;
	RETURN_STATE retState;

	retState = romanInst.convert("IV", result);
	cout << "TEST CASE 1.1: [Boundaries] input[IV] result[4]        ? " << (result == 4) <<  endl;
	cout << "               return state is RETURN_STATE::OK        ? " << (retState == RETURN_STATE::OK) 
		 << endl << endl;

	retState = romanInst.convert("VI", result);
	cout << "TEST CASE 1.2: [Boundaries] input[VI] result[6]        ? " << (result == 6) << endl;
	cout << "               return state is RETURN_STATE::OK        ? " << (retState == RETURN_STATE::OK)
		<< endl << endl;

	retState = romanInst.convert("IX", result);
	cout << "TEST CASE 1.3: [Boundaries] input[IX] result[9]        ? " << (result == 9) << endl;
	cout << "               return state is RETURN_STATE::OK        ? " << (retState == RETURN_STATE::OK)
		<< endl << endl;

	retState = romanInst.convert("XI", result);
	cout << "TEST CASE 1.4: [Boundaries] input[XI] result[11]       ? " << (result == 11) << endl;
	cout << "               return state is RETURN_STATE::OK        ? " << (retState == RETURN_STATE::OK)
		<< endl << endl;

	retState = romanInst.convert("XL", result);
	cout << "TEST CASE 1.5: [Boundaries] input[XL] result[40]       ? " << (result == 40) << endl;
	cout << "               return state is RETURN_STATE::OK        ? " << (retState == RETURN_STATE::OK)
		<< endl << endl;

	retState = romanInst.convert("LX", result);
	cout << "TEST CASE 1.6: [Boundaries] input[LX] result[60]       ? " << (result == 60) << endl;
	cout << "               return state is RETURN_STATE::OK        ? " << (retState == RETURN_STATE::OK)
		<< endl << endl;

	retState = romanInst.convert("XC", result);
	cout << "TEST CASE 1.7: [Boundaries] input[XC] result[90]       ? " << (result == 90) << endl;
	cout << "               return state is RETURN_STATE::OK        ? " << (retState == RETURN_STATE::OK)
		<< endl << endl;

	retState = romanInst.convert("CD", result);
	cout << "TEST CASE 1.8: [Boundaries] input[CD] result[400]      ? " << (result == 400) << endl;
	cout << "               return state is RETURN_STATE::OK        ? " << (retState == RETURN_STATE::OK)
		<< endl << endl;

	retState = romanInst.convert("DC", result);
	cout << "TEST CASE 1.9: [Boundaries] input[DC] result[600]      ? " << (result == 600) << endl;
	cout << "               return state is RETURN_STATE::OK        ? " << (retState == RETURN_STATE::OK)
		<< endl << endl;

	retState = romanInst.convert("MD", result);
	cout << "TEST CASE 1.10: [Boundaries] input[MD] is result[1500] ? " << (result == 1500) << endl;
	cout << "                 return state is RETURN_STATE::OK ?  "
		<< (retState == RETURN_STATE::OK) << endl << endl;
}

// These test cases led to provide a regex to test against roman numeral
// obtained this regex from internet search, not mine
void testRomanInvalidInputs()
{
	// TC2: Testing Invalid inputs

	// Maximum Roman Numeral is MMMCMXCIX = 3999
	RomanNumerals romanInst;
	uint16_t result = 0;
	RETURN_STATE retState;

	retState = romanInst.convert("MMMCMXCXI", result);
	cout << "TEST CASE 2.1: [Invalid Inputs] input[MMMCMXCXI] > 3999 so result[0] i.e. no conversion" << endl;
	cout << "               return state is RETURN_STATE::ERR_INVALID_ROMAN_INPUT_NUM ?  " 
		 << (retState == RETURN_STATE::ERR_INVALID_ROMAN_INPUT_NUM) << endl << endl;

	// More than 3 X in a Roman Numeral
	retState = romanInst.convert("XXXX", result);
	cout << "TEST CASE 2.2: [Invalid Inputs] input[XXXX]  so result[0] i.e. no conversion" << endl;
	cout << "               return state is RETURN_STATE::ERR_INVALID_ROMAN_INPUT_NUM ?  "
		<< (retState == RETURN_STATE::ERR_INVALID_ROMAN_INPUT_NUM) << endl << endl;

	// Provide X between two M, not allowed M=1000 MM=2000 MXM not valid
	retState = romanInst.convert("MXM", result);
	cout << "TEST CASE 2.3: [Invalid Inputs] input[MXM]  so result[0] i.e. no conversion" << endl;
	cout << "               return state is RETURN_STATE::ERR_INVALID_ROMAN_INPUT_NUM ?  "
		<< (retState == RETURN_STATE::ERR_INVALID_ROMAN_INPUT_NUM) << endl << endl;

	// Provide D before M
	retState = romanInst.convert("DM", result);
	cout << "TEST CASE 2.4: [Invalid Inputs] input[DM]  so result[0] i.e. no conversion" << endl;
	cout << "               return state is RETURN_STATE::ERR_INVALID_ROMAN_INPUT_NUM ?  "
		<< (retState == RETURN_STATE::ERR_INVALID_ROMAN_INPUT_NUM) << endl << endl;

	retState = romanInst.convert("ID", result);
	cout << "TEST CASE 2.5: [Invalid Inputs] input[ID]  so result[0] i.e. no conversion" << endl;
	cout << "               return state is RETURN_STATE::ERR_INVALID_ROMAN_INPUT_NUM ?  "
		<< (retState == RETURN_STATE::ERR_INVALID_ROMAN_INPUT_NUM) << endl << endl;

	// V cannot be repeated, ex. 10 cannot be VV it should be X for 10
	retState = romanInst.convert("VV", result);
	cout << "TEST CASE 2.6: [Invalid Inputs] input[VV]  so result[0] i.e. no conversion" << endl;
	cout << "               return state is RETURN_STATE::ERR_INVALID_ROMAN_INPUT_NUM ?  "
		<< (retState == RETURN_STATE::ERR_INVALID_ROMAN_INPUT_NUM) << endl << endl;

}

// 1. led to adding try catch statement inside the romanNumerals validator function
//    by catching the exception thrown by the STL map if the entered character is not 
//    in the map of Roman symbols in this case the map throws an exception.
// 2. helped in adding a if statement before checking the pattern validity after searching
//    for invalid characters.
void testRomanGarbageInputs()
{
	RomanNumerals romanInst;
	uint16_t result = 0;
	RETURN_STATE retState;

	retState = romanInst.convert("1234", result);
	cout << "TEST CASE 3.1: [Garbage Input] input[1234]  so result[0] i.e. no conversion \n";
	cout << "               return state is RETURN_STATE::ERR_INVALID_CHAR_IN_ROMAN_NUM ?  "
		 << (retState == RETURN_STATE::ERR_INVALID_CHAR_IN_ROMAN_NUM) << endl << endl;

	retState = romanInst.convert("*%d2j", result);
	cout << "TEST CASE 3.2: [Garbage Input] input[*%d2j]  so result[0] i.e. no conversion \n";
	cout << "               return state is RETURN_STATE::ERR_INVALID_CHAR_IN_ROMAN_NUM ?  "
		 << (retState == RETURN_STATE::ERR_INVALID_CHAR_IN_ROMAN_NUM) << endl << endl;
}

void testTroubleSomeDecimalValues()
{
	DecimalNumerals decInst;
	string result = "";
	RETURN_STATE retState;

	// Double/Float Conversion not allowed, return Roman Numeral should be empty
	retState = decInst.convert(23.5, result);
	cout << "TEST CASE 4.1: [Decimal Conversion] input [23.5] result[] empty           ? "<< (result=="") << endl;
	cout << "               return state is RETURN_STATE::ERR_FLOAT_NOT_ALLOWED        ? "
		 << (retState == RETURN_STATE::ERR_FLOAT_NOT_ALLOWED) << endl << endl;

	// Passing wrong inputs like strings or a character results in compilation errors.

	// Negative Numbers
	retState = decInst.convert(-24, result);
	cout << "TEST CASE 4.2: [Decimal Conversion] input [-24]  result[] empty           ? "<< (result=="") << endl;
	cout << "               return state is RETURN_STATE::ERR_NEGATIVE_NUM_NOT_ALLOWED ? "
		 << (retState == RETURN_STATE::ERR_NEGATIVE_NUM_NOT_ALLOWED) << endl << endl;

	// Zero Decimal
	retState = decInst.convert(0, result);
	cout << "TEST CASE 4.3: [Decimal Conversion] input [0]    result[] empty           ? "<< (result=="") << endl;
	cout << "               return state is RETURN_STATE::ERR_ZERO_NOT_ALLOWED         ? "
		<< (retState == RETURN_STATE::ERR_ZERO_NOT_ALLOWED) << endl << endl;

	// Greater than 10000 Decimal
	retState = decInst.convert(10001, result);
	cout << "TEST CASE 4.4: [Decimal Conversion] input [0]    result[] empty           ? "<< (result=="") << endl;
	cout << "               return state is RETURN_STATE::ERR_DECIMAL_OVER_MAX         ? "
		<< (retState == RETURN_STATE::ERR_DECIMAL_OVER_MAX) << endl << endl;
}

void testNormalDecimalValue()
{
	DecimalNumerals decInst;
	string result = "";
	RETURN_STATE retState;

	// Test Normal Values
	retState = decInst.convert(15, result);
	cout << "TEST CASE 5.1: [Decimal Conversion] input [15]    result[XV]                ? "<< (result=="XV") << endl;
	cout << "               return state is RETURN_STATE::OK                             ? "
		<< (retState == RETURN_STATE::OK) << endl << endl;

	// Test Normal Values
	retState = decInst.convert(23, result);
	cout << "TEST CASE 5.2: [Decimal Conversion] input [23]    result[XXIII]             ? "<< (result=="XXIII") << endl;
	cout << "               return state is RETURN_STATE::OK                             ? "
		<< (retState == RETURN_STATE::OK) << endl << endl;

	// Test Normal Values
	retState = decInst.convert(45, result);
	cout << "TEST CASE 5.3: [Decimal Conversion] input [45]    result[XLV]               ? "<< (result=="XLV") << endl;
	cout << "               return state is RETURN_STATE::OK                             ? "
		<< (retState == RETURN_STATE::OK) << endl << endl;

	// Test Normal Values
	retState = decInst.convert(234, result);
	cout << "TEST CASE 5.4: [Decimal Conversion] input [234]   result[CCXXXIV]           ? "<< (result=="CCXXXIV") << endl;
	cout << "               return state is RETURN_STATE::OK                             ? "
		<< (retState == RETURN_STATE::OK) << endl << endl;

	// Test Normal Values
	retState = decInst.convert(1467, result);
	cout << "TEST CASE 5.5: [Decimal Conversion] input [1467]  result[MCDLXVII]          ? "<< (result=="MCDLXVII") << endl;
	cout << "               return state is RETURN_STATE::OK                             ? "
		<< (retState == RETURN_STATE::OK) << endl << endl;

	// Test Normal Values
	retState = decInst.convert(2765, result);
	cout << "TEST CASE 5.6: [Decimal Conversion] input [2765]  result[MMDCCLXV]          ? "<< (result=="MMDCCLXV") << endl;
	cout << "               return state is RETURN_STATE::OK                             ? "
		<< (retState == RETURN_STATE::OK) << endl << endl;

	// Test Normal Values
	retState = decInst.convert(3575, result);
	cout << "TEST CASE 5.7: [Decimal Conversion] input [2765]  result[MMMDLXXV]          ? "<< (result=="MMMDLXXV") << endl;
	cout << "               return state is RETURN_STATE::OK                             ? "
		<< (retState == RETURN_STATE::OK) << endl << endl;

	retState = decInst.convert(9899, result);
	cout << "TEST CASE 5.7: [Decimal Conversion] input [9899]  result[MMMMMMMMMDCCCXCIX] ? "<< (result=="MMMMMMMMMDCCCXCIX") << endl;
	cout << "               return state is RETURN_STATE::OK                             ? "
		<< (retState == RETURN_STATE::OK) << endl << endl;
}
