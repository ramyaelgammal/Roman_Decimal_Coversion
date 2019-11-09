/*
 * IntWrapper.h
 *
 *  Created on: Nov 9, 2019
 *      Author: ramy
 */

#ifndef INTWRAPPER_H_
#define INTWRAPPER_H_
#include "common.h"

// Wrapper Class for built-in unsigned short integer
class IntWrapper{
public:
	 explicit IntWrapper(uint16_t builtInInt): builtInInt{builtInInt}{}
	void operator =( const uint16_t &rhs);

	friend bool operator < ( const IntWrapper &lhs, const uint16_t &rhs);
	friend bool operator > ( const IntWrapper &lhs, const uint16_t &rhs);
	friend bool operator == ( const IntWrapper &lhs, const uint16_t &rhs);
	friend uint16_t operator %( const IntWrapper &lhs, const uint16_t &rhs);
	friend uint16_t operator /( const IntWrapper &lhs, const uint16_t &rhs);
	friend uint16_t operator %=( const IntWrapper &lhs, const uint16_t &rhs);


private:
	uint16_t builtInInt;
};



#endif /* INTWRAPPER_H_ */
