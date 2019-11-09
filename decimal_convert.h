
#ifndef DECIMAL_CONVERT_H_
#define DECIMAL_CONVERT_H_

#include <string>
#include <map>
#include "common.h"
#include "IntWrapper.h"
class DecimalNumerals
{
public:
	DecimalNumerals();
	~DecimalNumerals(){};

	/*
	 *param[in]  rIn: const reference to the input Deimal number
                          it is double to prevent implicit cast from double to uint16_t
			  if it is passed double, certain error codeshall be returned.

	 *param[out] rOut reference to the ouput resulted Roman numeral to be stored in
	 *return     RETURN_STATE enum of the error code or OK if no errors.
	*/
	RETURN_STATE convert(const IntWrapper &rIn, std::string &rOut);

private:
	// check if passed number is a real dobule
	bool isUint(const double d);
	std::string romanNum;
	//Look up table containing all the Roman symbols with the corresponding decimal value
	const std::string romanSymbols[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
	const uint16_t romanSymDecVals[13] = { 1,   4,    5,   9,    10,  40,   50,  90,   100, 400,  500, 900,  1000};
};

#endif /* DECIMAL_CONVERT_H_ */

