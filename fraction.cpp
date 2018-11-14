/*
 * fraction.cpp
 *
 *  Created on: Oct 10, 2018
 *      Author: Jack Wotherspoon
 */
#include "fraction.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

FractionException::FractionException(const string& message) : message(message) {}

// display the message
string& FractionException::what() { return message; }
Fraction::Fraction() : numer(0), denom(1) { } //default constructor that should return 0/1 fraction

Fraction::Fraction(int num) : numer(num), denom(1){ } //constructor when only one integer is passed in, counts it as numerator and returns "numerator/1"

Fraction::Fraction(int num, int den) : numer(num), denom(den){
	if (den==0){
		throw FractionException("Denominator of 0 is not allowed!");
	}
	else{
		reduce();
	}
} // constructor for when both numerator and denominator are passed in
void Fraction::reduce(){
	int gcd=greatestCommonDivisor(abs(numer),abs(denom));
	if ((numer < 0 && (denom < 0)) || (numer > 0 && (denom > 0))){
		numer=abs(numer)/gcd;
		denom=abs(denom)/gcd;
	}
	else{
		numer=-abs(numer)/gcd;
		denom=abs(denom)/gcd;
	}
}
int Fraction::greatestCommonDivisor(int n, int m){ //gives you lowest term fraction
	if (m<=n && (n % m ==0)){
		return m;
	}
	else if ( n < m){
		return greatestCommonDivisor(m,n);
	}
	else {
		return greatestCommonDivisor(m, n % m);
	}
}

int Fraction::numerator() const {return numer;}
int Fraction::denominator() const {return denom;}

Fraction operator-(const Fraction& right){
	return Fraction(-right.numerator(), right.denominator());
}
Fraction operator+(const Fraction& left, const Fraction& right) {
	return Fraction(left.numerator() * right.denominator() + left.denominator() * right.numerator(),left.denominator()*right.denominator());
}
Fraction operator-(const Fraction& left, const Fraction& right) {
	return Fraction(left.numerator() * right.denominator() - left.denominator() * right.numerator(),left.denominator()*right.denominator());
}
Fraction operator*(const Fraction& left, const Fraction& right) {
	return Fraction(left.numerator() * right.numerator(), left.denominator() * right.denominator());
}
Fraction operator/(const Fraction& left, const Fraction& right) {
	return Fraction(left.numerator() * right.denominator(), left.denominator() * right.numerator());
}
Fraction& Fraction::operator+=(const Fraction& right) {
	numer = numer * right.denominator() + denom *right.numerator();
	denom *= right.denominator();
	return *this;
}
// Pre-increment
Fraction& Fraction::operator++() {
	numer+=denom;
	return *this;
}

// Post-increment
Fraction Fraction::operator++(int unused) {
	Fraction clone(numer, denom);
	numer+=denom;
	return clone;
}
int Fraction::compare(const Fraction& right) const {
	return this->numer * right.denominator() -
			this->denom * right.numerator();
}

bool operator<(const Fraction& left, const Fraction& right) {
	return left.compare(right) < 0;
}

bool operator<=(const Fraction& left, const Fraction& right) {
	return left.compare(right) <= 0;
}

bool operator==(const Fraction& left, const Fraction& right) {
	return left.compare(right) == 0;
}

bool operator!=(const Fraction& left, const Fraction& right) {
	return left.compare(right) != 0;
}

bool operator>=(const Fraction& left, const Fraction& right) {
	return left.compare(right) >= 0;
}

bool operator>(const Fraction& left, const Fraction& right) {
	return left.compare(right) > 0;
}


ostream& operator<<(ostream& out, const Fraction& right) {
   out << right.numerator() << "/" << right.denominator();
   return out;
}

istream& operator>>(istream& in, Fraction& right) {
	int inNumerator, inDenominator;
	in >> inNumerator;
	if (in.peek() != 10) {
		char nextChar;
		in >> nextChar;
		if (nextChar == '/')
			in >> inDenominator;
		else
			inDenominator = 1;
		right = Fraction(inNumerator, inDenominator);
	}
	else
		right = Fraction(inNumerator);
	return in;
}

