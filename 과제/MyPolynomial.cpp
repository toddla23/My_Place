#include "MyPolynomial.h"
/********************* add your code here ********************************/
// output operator
ostream& operator <<(ostream &outStream, const myPolynomial& poly)
{
    if (poly == myPolynomial::ZERO)
        return outStream << 0;

    /********************* add your code here ********************************/
    for(auto begin_iter: poly.term)
    {
        cout << begin_iter;
    }
}

myPolynomial::myPolynomial(int c, unsigned e)
{
    term[0] = myTerm(c, e);
}

myPolynomial::myPolynomial(int nTerms, int mono[])
{
    size = nTerms;
    for(int i = 0; i < nTerms; i = i + 2)
        term[i] = myTerm(mono[i],mono[i+1]); // 내림차순으로 정렬됨... 젠장 
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

myPolynomial& myPolynomial::operator += (const myPolynomial &poly)
{
    int term_size = (size > poly.size)? size:poly.size;

    int a = 0, b = 0, i = 0;

    while(a == size && b == poly.size)
    {
        if(term[a].getExp() == poly.term[b].getExp())
        {
            term[i] = myTerm(term[a].getCoeff() + poly.term[b].getCoeff(), term[a].getExp());
            a++;
            b++;
            i++;
        }
        else if(term[a].getExp() < poly.term[b].getExp())
        {
            i++;
            a++;
        }

        else if(term[a].getExp() > poly.term[b].getExp())
        {
            for(int j = i; j < 49; j++)
                term[j + 1] = term[j];
            
            term[i] = poly.term[b];

            i++;
            b++;
        }
    }

    return *this;
}

myPolynomial& myPolynomial::operator -= (const myPolynomial &poly)
{
    int term_size = (size > poly.size)? size:poly.size;

    int a = 0, b = 0, i = 0;

    while(a == size && b == poly.size)
    {
        if(term[a].getExp() == poly.term[b].getExp())
        {
            term[i] = myTerm(term[a].getCoeff() - poly.term[b].getCoeff(), term[a].getExp());
            a++;
            b++;
            i++;
        }
        else if(term[a].getExp() < poly.term[b].getExp())
        {
            i++;
            a++;
        }

        else if(term[a].getExp() > poly.term[b].getExp())
        {
            for(int j = i; j < 49; j++)
                term[j + 1] = term[j];
            
            term[i] = -poly.term[b];

            i++;
            b++;
        }
    }

    return *this;

}

myPolynomial& myPolynomial::operator *= (const myPolynomial &poly)
{

}

myPolynomial& myPolynomial::operator *= (int k)
{
    for(int i = 0; i < size; i++)
        term[i] = term[i] * 3;
    
    return *this;
}

myPolynomial myPolynomial::operator -() const
{
    for(int i = 0; i < size; i++)
        term[i] = -term[i];
}

myPolynomial myPolynomial::operator *(int k) const
{
    for(int i = 0; i < size; i++)
        term[i] = term[i] * 3;
}

myPolynomial myPolynomial::operator +(const myPolynomial &poly) const
{
    int term_size = (size > poly.size)? size:poly.size;
    int Data[term_size * 2];

    int a = 0, b = 0, i = 0;

    while(a == size && b == poly.size)
    {
        if(term[a].getExp() == poly.term[b].getExp())
        {
            Data[i] = term[a].getCoeff() + poly.term[b].getCoeff();
            Data[i+1] = term[a].getExp();
            i = i + 2;
            a++;
            b++;
        }
        else if(term[a].getExp() < poly.term[b].getExp())
        {
            Data[i] = term[a].getCoeff();
            Data[i+1] = term[a].getExp();
            i = i + 2;
            a++;
        }

        else if(term[a].getExp() > poly.term[b].getExp())
        {
            Data[i] = term[b].getCoeff();
            Data[i+1] = term[b].getExp();
            i = i + 2;
            b++;
        }
    }

    return myPolynomial(term_size, Data);
}

myPolynomial myPolynomial::operator -(const myPolynomial &poly) const
{
    int term_size = (size > poly.size)? size:poly.size;
    int Data[term_size * 2];

    int a = 0, b = 0, i = 0;

    while(a == size && b == poly.size)
    {
        if(term[a].getExp() == poly.term[b].getExp())
        {
            Data[i] = term[a].getCoeff() - poly.term[b].getCoeff();
            Data[i+1] = term[a].getExp();
            i = i + 2;
            a++;
            b++;
        }
        else if(term[a].getExp() < poly.term[b].getExp())
        {
            Data[i] = term[a].getCoeff();
            Data[i+1] = term[a].getExp();
            i = i + 2;
            a++;
        }

        else if(term[a].getExp() > poly.term[b].getExp())
        {
            Data[i] = -term[b].getCoeff();
            Data[i+1] = term[b].getExp();
            i = i + 2;
            b++;
        }
    }

    return myPolynomial(term_size, Data);
}
myPolynomial myPolynomial::operator *(const myPolynomial &poly) const
{

}

long operator() (int x) const; // evaluate the polynomial
int getDegree() const; // get a degree of the polynomial
unsigned getNumTerms() const; // number of terms in the polynomial

myPolynomial myPolynomial::ddx() const // derivative of a polynomial
{
    for(int i = 0; i < size; i++)
        term[i] = term[i].ddx(); // 이거 에러 왜남...? 둘다 myTerm인데숭...
}




const myPolynomial myPolynomial::ZERO(0);     // the zero polynomial P(x) = 0
const myPolynomial myPolynomial::ONE(1, (unsigned)0); // the monomial P(x) = 1    
const myPolynomial myPolynomial::X(1, 1); // the monomial P(x) = x