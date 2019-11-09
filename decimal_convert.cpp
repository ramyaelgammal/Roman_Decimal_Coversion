#include <iostream>
#include "decimal_convert.h"
using namespace std;

DecimalNumerals::DecimalNumerals():
		romanNum{""}
{
}

RETURN_STATE DecimalNumerals::convert(const IntWrapper &rIn, string &rOut)
{
	RETURN_STATE retVal = RETURN_STATE::OK;
	// each time initialize the output string, caught from Test Group 5 [TC 5.1 to TC 5.7]
	rOut="";
	// As a result of Test Case 4.2
	if ( rIn == 0){
		cout << "Zero cannot be converted to Roman\n";
		rOut = "";
		retVal = RETURN_STATE::ERR_ZERO_NOT_ALLOWED;
	}
	else if ( rIn < 0){
		cout << "Negative numbers not allowed\n";
		rOut = "";
		retVal = RETURN_STATE::ERR_NEGATIVE_NUM_NOT_ALLOWED;
	}

	else if (rIn > 10000U){
		cout << "Greater than the Max [10000]\n";
		retVal = RETURN_STATE::ERR_DECIMAL_OVER_MAX;
		rOut = "";
	}
	else{


		IntWrapper  num = rIn;
		for ( uint8_t i = 12; num > 0; i--){
			uint8_t div = num/romanSymDecVals[i];
			num = num % romanSymDecVals[i];
			while(div--){
				rOut += romanSymbols[i];
			}
		}
	}

	return retVal;
}
