/*
 * IntWrapper.cpp
 *
 *  Created on: Nov 9, 2019
 *      Author: ramy
 */

#include "IntWrapper.h"

bool operator < ( const IntWrapper &lhs, const uint16_t &rhs)
{
	return lhs.builtInInt < rhs;
}
bool operator > ( const IntWrapper &lhs, const uint16_t &rhs)
{
	return lhs.builtInInt > rhs;
}

bool operator == ( const IntWrapper &lhs, const uint16_t &rhs)
{
	return lhs.builtInInt == rhs;
}

uint16_t operator / (const IntWrapper &lhs, const uint16_t &rhs)
{
	return lhs.builtInInt / rhs; // integer division
}
uint16_t operator % (const IntWrapper &lhs, const uint16_t &rhs)
{
	return lhs.builtInInt % rhs;
}
void IntWrapper::operator = ( const uint16_t &rhs)
{
	 builtInInt = rhs;
}

