#include "MyPolynomial.h"
/********************* add your code here ********************************/
// output operator
ostream& operator <<(ostream &outStream, const myPolynomial& poly)
{
    if (poly == myPolynomial::ZERO)
        return outStream << 0;

    /********************* add your code here ********************************/
    return outStream;
}

myPolynomial::myPolynomial(int c, unsigned e)
{
    term.push_front(myTerm(c,e));
}

myPolynomial::myPolynomial(int nTerms, int mono[])
{
    for(int i = 0; i < nTerms; i = i + 2)
        term.push_front(myTerm(mono[i],mono[i+1]));
}

myPolynomial::myPolynomial(const myPolynomial &poly):term(poly.term)
{
}

bool myPolynomial::operator == (const myPolynomial &poly) const
{
    return (term == poly.term)? 1 : 0;
}

bool myPolynomial::operator != (const myPolynomial &poly) const
{
    return (term != poly.term)? 1 : 0;
}

myPolynomial& myPolynomial::operator += (const myPolynomial &poly);
myPolynomial& myPolynomial::operator -= (const myPolynomial &poly);
myPolynomial& myPolynomial::operator *= (const myPolynomial &poly);
myPolynomial& operator *= (int k);

myPolynomial myPolynomial::operator -() const
{
    for(auto begin_iter: term)
    {
        begin_iter = -begin_iter;
    }
}

myPolynomial operator *(int k) const;
myPolynomial operator +(const myPolynomial &poly) const;
myPolynomial operator -(const myPolynomial &poly) const;
myPolynomial operator *(const myPolynomial &poly) const;

myPolynomial myPolynomial::operator*(int value, const myPolynomial &poly)
{
    for(auto begin_iter: term)
    {
        begin_iter = begin_iter*value;
    }
}

long operator() (int x) const; // evaluate the polynomial
int getDegree() const; // get a degree of the polynomial
unsigned getNumTerms() const; // number of terms in the polynomial

myPolynomial myPolynomial::ddx() const // derivative of a polynomial
{
    for(auto begin_iter: term)
    {
        begin_iter = begin_iter.ddx();
    }
}




const myPolynomial myPolynomial::ZERO(0);     // the zero polynomial P(x) = 0
const myPolynomial myPolynomial::ONE(1, (unsigned)0); // the monomial P(x) = 1    
const myPolynomial myPolynomial::X(1, 1); // the monomial P(x) = x