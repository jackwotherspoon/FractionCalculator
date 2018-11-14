/*
 * fraction.h
 *
 *  Created on: Oct 10, 2018
 *      Author: Jack Wotherspoon
 */

#ifndef FRACTION_H_
#define FRACTION_H_

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//Exception for division by zero case
class FractionException{
public:
		FractionException(const string& message);
		string& what();
private:
		string message;
}; //end FractionException class

class Fraction{
public:
		Fraction(); // constructor for empty paramaters, returns num=0, den=1
		Fraction(int); // constructor to make fraction with single int as numerator, den=1
		Fraction(int, int); //constructor when numerator and denominator are given
		int numerator() const; //accessor for numerator
		int denominator()const; //accessor for denominator
		void reduce(); //function to reduce fraction
		int greatestCommonDivisor(int, int); //function to return gcd of two integers
		Fraction& operator+=(const Fraction& right); //update fraction with addition of another
		Fraction& operator++();	// Pre-increment
		Fraction  operator++(int);	// Post-increment
		int compare(const Fraction& right) const; //compare function used for boolean operators
private:
		int numer;
		int denom;
};

// arithmetic overloading of operators
Fraction operator-(const Fraction& right);
Fraction operator+(const Fraction&left, const Fraction& right);
Fraction operator-(const Fraction&left, const Fraction& right);
Fraction operator*(const Fraction&left, const Fraction& right);
Fraction operator/(const Fraction&left, const Fraction& right);

// non member overloading of input and output
ostream& operator<<(ostream& out, const Fraction& right);
istream& operator>>(istream& in, Fraction& right);

//Boolean operator overloading
bool operator<(const Fraction& left, const Fraction& right);
bool operator<=(const Fraction& left, const Fraction& right);
bool operator==(const Fraction& left, const Fraction& right);
bool operator!=(const Fraction& left, const Fraction& right);
bool operator>=(const Fraction& left, const Fraction& right);
bool operator>(const Fraction& left, const Fraction& right);

#endif /* FRACTION_H_ */
