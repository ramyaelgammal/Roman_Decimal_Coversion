#include <iostream>
#include <regex>
#include "roman_convert.h"
#include <sstream>

using namespace std;

RomanNumerals::RomanNumerals():
    		  decimalNum(0U),
			  romanLut({{'I',1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M',1000}})

{

}
RETURN_STATE RomanNumerals::convert(const string &rIn, uint16_t &rOut)
{
	// Checking the validity of the input Roman numeral
	RETURN_STATE retVal	= validator(rIn);

	// initialize the out to zero [Error fetched from boundaries test cases 1.2]
	rOut = 0;

	if(retVal == RETURN_STATE::OK){

		uint16_t curLetterVal = 0U;
		uint16_t nxtLetterVal = 0U;

		// Iterate on each character in the string
		// covered by Test Group 1
		for(auto itr = rIn.begin(); itr != rIn.end(); itr++){
			curLetterVal = romanLut.at(*itr);
			if ((itr + 1) != rIn.end())
				nxtLetterVal = romanLut.at(*(itr + 1));
			/*
			 * if the current letter's decimal value is greater than the previous one, then add it to the accumulated
			 * decimal value. Otherwise add the difference between the next letter value and the current one.
			 * ex: IX: I->1 and X -> 10 then decimalValue = 10 - 1 = 9
			 * ex: XI:                       deciamlValue = 10 + 1 = 11
			 *
			 */
			if(nxtLetterVal <= curLetterVal){
				rOut +=  curLetterVal;
			}
			else{
				rOut += nxtLetterVal - curLetterVal;
				++itr; // increment the iterator in this case
			}
		}
		decimalNum = rOut;
	}

	return retVal;
}

RETURN_STATE RomanNumerals::validator(const string &romanNum)
{
	RETURN_STATE retVal = RETURN_STATE::OK;

	// Iterate through the input string and search for any non-roman characters
	// Added as a result of Test Group 3
	for (uint8_t letter: romanNum){
		try{
			(void)romanLut.at(letter);

		}
		catch (exception &e){
			cout << "invalid character: \'" <<letter<< "\' in Roman Numeral\n";
			retVal = RETURN_STATE::ERR_INVALID_CHAR_IN_ROMAN_NUM;
		}
	}

	// if still retVal OK continue checking for the provided pattern
	// this if statment was provided after the addition of Test Group 3 when checking the return value
	if (retVal == RETURN_STATE::OK) {
		// Set regex pattern to test the input roman string against, the max possible is MMMMMMMMMM = 10000
		// Added as a result of Test Group 2
		// it states that M can be at most 10 times = 10000
		// only characters C, X, I can be repeated 3 times in certain places
		// I got this check-against regex pattern from internet search
		regex pattern("^M{0,10}(CM|CD|D?C{0,3})(C|X{0,3}|XL|LX{0,3}|XC)(I{0,3}|IV|VI{0,3}|IX)$");
		if (regex_match(romanNum, pattern)) {
			retVal = RETURN_STATE::OK;
		}
		else {
			cout << "Invalid Roman Numeral\n";
			retVal = RETURN_STATE::ERR_INVALID_ROMAN_INPUT_NUM;
		}
	}

	return retVal;
}

