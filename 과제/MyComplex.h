#ifndef _MYCOMPLEX_H_
#define _MYCOMPLEX_H_
#include <iostream>

using namespace std;

class myComplex {
private:
    int realPart;
    int imaginaryPart;
    int norm() const;
    
public:
     // Constructor (생성자)
    myComplex(int real = 0, int imag = 0);
    
    // Copy constructor (복사 생성자)
    myComplex(const myComplex& number);
    
    // Accessor functions (접근자)
    int getRealPart() const;
    int getImaginaryPart() const;
    
    // Mutator functions (변경자)
    void setRealPart(int real);
    void setImaginaryPart(int imag);
    void set(int real, int imag);
    
    // Overloaded binary operators
    myComplex operator +(const myComplex& number) const;
    myComplex operator +(int value) const;

    myComplex operator -(const myComplex& number) const;
    myComplex operator -(int value) const;

    myComplex operator *(const myComplex& number) const;
    myComplex operator *(int value) const;


    // Overloaded assignment operators
    myComplex& operator =(const myComplex& number);
    myComplex& operator =(int value);

    myComplex& operator +=(const myComplex& number);
    myComplex& operator -=(const myComplex& number);
    myComplex& operator *=(const myComplex& number);
    
    myComplex& operator ++();
    myComplex& operator ++(int);

    myComplex& operator --();
    myComplex& operator --(int);

    // Overloading relational operators
    bool operator ==(const myComplex& number) const;
    bool operator !=(const myComplex& number) const;

    bool operator >(const myComplex& number) const;
    bool operator >=(const myComplex& number) const;
    bool operator <(const myComplex& number) const;
    bool operator <=(const myComplex& number) const;


    // Overloaded unary operators
    myComplex operator -(); // unary minus

    friend ostream& operator <<(ostream& outStream, const myComplex& number);

};
#endif