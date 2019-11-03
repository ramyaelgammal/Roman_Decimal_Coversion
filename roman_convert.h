
#ifndef ROMAN_CONVERT_H_
#define ROMAN_CONVERT_H_

#include <string>
#include <map>

#include "common.h"

class RomanNumerals
{
public:
	RomanNumerals();
	/*
	 *param[in]  rIn: const reference to the input Roman numeral
	 *param[out] rOut reference to the ouput resulted decimal to be stored in
	 *return     RETURN_STATE enum of the error code or OK if no errors.
	*/
	virtual RETURN_STATE convert(const std::string &rIn, uint16_t &rOut);
	virtual ~RomanNumerals(){}
private:
	/* @param[in] romanNum: reference to the input Roman numeral string
	 * return 	RETURN_STATE can be OK if no error or a certain error code
	 */
	RETURN_STATE validator(const std::string &romanNum);
	uint16_t decimalNum;
	const std::map <uint8_t, uint16_t> romanLut;
};



#endif /* ROMAN_CONVERT_H_ */

