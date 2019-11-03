/*
 * numerals.h
 *
 *  Created on: Oct 29, 2019
 *      Author: Ramy
 */

#ifndef COMMON_H_
#define COMMON_H_
typedef unsigned short int uint16_t;
typedef unsigned char uint8_t;

enum class RETURN_STATE
{
	OK,
	// Roman Errors
	ERR_INVALID_CHAR_IN_ROMAN_NUM,
	ERR_INVALID_ROMAN_INPUT_NUM,

	// Decimal Errors
	ERR_NEGATIVE_NUM_NOT_ALLOWED,
	ERR_GREATER_THAN_ONE_THOUSAND,
	ERR_ZERO_NOT_ALLOWED,
	ERR_FLOAT_NOT_ALLOWED,
	ERR_DECIMAL_OVER_MAX,

};

#endif /* COMMON_H_ */
