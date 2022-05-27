#ifndef _MYPOLYNOMIAL_H_
#define _MYPOLYNOMIAL_H_
#include <iostream>
#include <list>
#include "MyTerm.h"

using namespace std;

class myPolynomial
{
private:
    int degree; // maximum expnent
    /********************* add your code here ********************************/
    list<myTerm> term;

public:
    myPolynomial(int c = 0, unsigned e = 0);
    myPolynomial(int nTerms, int mono[]);
    // copy constructor
    myPolynomial(const myPolynomial &poly);
    
    // overloaded operators
    bool operator == (const myPolynomial &poly) const;
    bool operator != (const myPolynomial &poly) const;
    myPolynomial& operator += (const myPolynomial &poly);
    myPolynomial& operator -= (const myPolynomial &poly);
    myPolynomial& operator *= (const myPolynomial &poly);
    myPolynomial& operator *= (int k);
    myPolynomial operator -() const;
    myPolynomial operator *(int k) const;
    myPolynomial operator +(const myPolynomial &poly) const;
    myPolynomial operator -(const myPolynomial &poly) const;
    
    myPolynomial operator *(const myPolynomial &poly) const;
    friend myPolynomial operator*(int value, const myPolynomial &poly);

    long operator() (int x) const; // evaluate the polynomial
    int getDegree() const; // get a degree of the polynomial
    unsigned getNumTerms() const; // number of terms in the polynomial
    myPolynomial ddx() const; // derivative of a polynomial
    
    // friend operators and functions
    friend myPolynomial operator *(int k, const myPolynomial &poly);
    friend ostream& operator <<(ostream &outStream, const myPolynomial &poly);
    static const myPolynomial ZERO; // P(x) = 0
    static const myPolynomial ONE; // P(x) = 1
    static const myPolynomial X; // P(x) = x


};
#endif _MYPOLYNOMIAL_H