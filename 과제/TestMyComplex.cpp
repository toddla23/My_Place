#include <fstream>
#include <cstdlib>
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
    myComplex& operator +=(const myComplex& number);
    myComplex& operator ++();
    myComplex operator ++(int);

    myComplex operator -(const myComplex& number) const;
    myComplex operator -(int value) const;
    myComplex& operator -=(const myComplex& number);
    myComplex& operator --();
    myComplex operator --(int);

    myComplex operator *(const myComplex& number) const;
    myComplex operator *(int value) const;
    myComplex& operator *=(const myComplex& number);

    // Overloaded assignment operators
    myComplex& operator =(const myComplex& number);
    myComplex& operator =(int value);
    // Overloading relational operators

    bool operator ==(const myComplex& number) const;
    bool operator !=(const myComplex& number) const;

    bool operator >(const myComplex& number) const;
    bool operator >=(const myComplex& number) const;

    bool operator <(const myComplex& number) const;
    bool operator <=(const myComplex& number) const;


    // Overloaded unary operators
    myComplex operator -(); // unary minus

    friend ostream& operator<<(ostream &outStream, const myComplex& number);
    friend istream& operator>>(istream &inStream, myComplex& number);
};

// Constructor
myComplex::myComplex(int real, int imag)
{
    realPart = real;
    imaginaryPart = imag;
}
// Copy constructor
myComplex::myComplex(const myComplex& number)
{
    realPart = number.realPart;
    imaginaryPart = number.imaginaryPart;
}
// Accessor functions
int myComplex::getRealPart() const
{
    return realPart;
}
int myComplex::getImaginaryPart() const
{
        return imaginaryPart;
}
// Mutator functions
void myComplex::setRealPart(int real)
{
    realPart = real;
}
void myComplex::setImaginaryPart(int imag)
{
    imaginaryPart = imag;
}
void myComplex::set(int real, int imag)
{
    realPart = real;
    imaginaryPart = imag;
}
// Overloaded binary operators
myComplex myComplex::operator +(const myComplex& number) const
{
    int newReal = realPart + number.realPart;
    int newImag = imaginaryPart + number.imaginaryPart;
    return myComplex (newReal, newImag);
}
myComplex myComplex::operator +(int value) const
{
    return myComplex(value) + (*this);
}
myComplex& myComplex::operator +=(const myComplex& number)
{
    realPart += number.realPart;
    imaginaryPart += number.imaginaryPart;
    return *this;
}
myComplex& myComplex::operator ++()
{
    realPart++;
    return *this;
}
myComplex myComplex::operator ++(int)
{
    myComplex t(*this);
    operator++();
    return t;
}


myComplex myComplex::operator -(const myComplex& number) const
{
    int newReal = realPart - number.realPart;
    int newImag = imaginaryPart - number.imaginaryPart;
    return myComplex (newReal, newImag);
}
myComplex myComplex::operator -(int value) const
{
    int newReal = realPart - value;
    return myComplex (newReal, imaginaryPart);
}
myComplex& myComplex::operator -=(const myComplex& number)
{
    realPart = realPart - number.realPart;
    imaginaryPart = imaginaryPart - number.imaginaryPart;
    return *this;
}
myComplex& myComplex::operator --()
{
    realPart--;
    return *this;
}
myComplex myComplex::operator --(int)
{
    myComplex t(*this);
    operator--();
    return t;
}

myComplex myComplex::operator *(const myComplex& number) const
{
    int newReal = (realPart * number.realPart) - (imaginaryPart * number.imaginaryPart);
    int newImag = (imaginaryPart * number.realPart) + (realPart * number.imaginaryPart);
    return myComplex (newReal, newImag);
}
myComplex myComplex::operator *(int value) const
{
    return myComplex(value) * (*this);
}
myComplex& myComplex::operator *=(const myComplex& number) //c6 1 -32, c9 = 2 -64
{
    int newrealPart = (realPart * number.realPart) - (imaginaryPart * number.imaginaryPart);
    int newimaginaryPart = (imaginaryPart * number.realPart) + (realPart * number.imaginaryPart);
    realPart = newrealPart;
    imaginaryPart = newimaginaryPart;
    return *this;
}

// Assignment operators
myComplex& myComplex::operator =(const myComplex& number)
{
    this->realPart = number.realPart;
    this->imaginaryPart = number.imaginaryPart;
    return *this;
}
myComplex& myComplex::operator =(int value)
{
    realPart = value;
    imaginaryPart = 0;
    return *this;
}
// Overloading comparison operators
bool myComplex::operator ==(const myComplex& number) const
{
    return (realPart == number.realPart) && (imaginaryPart == number.imaginaryPart);
}

bool myComplex::operator !=(const myComplex& number) const
{
    return (realPart != number.realPart) || (imaginaryPart != number.imaginaryPart);
}

bool myComplex::operator >(const myComplex& number) const
{
    return norm() > number.norm();
}

bool myComplex::operator >=(const myComplex& number) const
{
    return norm() >= number.norm();
}

bool myComplex::operator <(const myComplex& number) const
{
    return norm() < number.norm();
}
bool myComplex::operator <=(const myComplex& number) const
{
    return norm() <= number.norm();
}

// Overloaded unary operators
myComplex myComplex::operator -() // unary minus
{
    return myComplex(-realPart, -imaginaryPart);
}

// private function
int myComplex::norm() const
{
    return realPart * realPart + imaginaryPart * imaginaryPart;
}

ostream &operator <<(ostream &outStream, const myComplex& number)
{
    outStream << "(" << number.realPart << "," << number.imaginaryPart << ")";
    return outStream;
}

istream &operator >>(istream &inStream, myComplex& number)
{
    inStream >> number.realPart >> number.imaginaryPart;
    return inStream;
}



void testSimpleCase();
void testDataFromFile();
int main(void)
{
testSimpleCase();
testDataFromFile();
}
void testSimpleCase()
{
myComplex c0, c1(1), c2(2, 2);
myComplex c3(c2);
myComplex c4, c5, c6, c7, c8, c9;
// test constructor
cout << c0 << endl << c1 << endl << c2 << endl;
// test copy constructor
cout << c3 << endl;
// test accessor function
cout << c3 << endl;
// test mutator function
c3.set(3, 3);
cout << c3 << endl;
c3.setRealPart(4);
cout << c3 << endl;
c3.setImaginaryPart(4);
cout << c3 << endl;
// test binary operators
c4 = c1 + c3;
c5 = c1 - c3;
c6 = c4 * c5;
cout << c4 << endl << c5 << endl << c6 << endl;
c7 = c6 + 2;
c8 = c6 - 2;
c9 = c6 * 2;
cout << c7 << endl << c8 << endl << c9 << endl;
c7 += c4;
c8 -= c5;
c9 *= c6;
cout << c7 << endl << c8 << endl << c9 << endl; 
c7 += 2;
c8 -= 2;
c9 *= 2;
cout << c7 << endl << c8 << endl << c9 << endl;
// test comparison operators
cout << (c8 != c9) << " " << (c8 == c9) << endl;
cout << (c8 > c9) << " " << (c8 >= c9) << " " << (c8 < c9) << " " << (c8 <=
c9) << endl;
c7 = c8 = c9;
cout << (c8 != c9) << " " << (c8 == c9) << endl;
cout << (c8 > c9) << " " << (c8 >= c9) << " " << (c8 < c9) << " " << (c8 <=c9) << endl;
// test prefix operators
c7 = -myComplex(2, 3);
c8 = (++c7) * 2;
c9 = (c7++)*2;
cout << c7 << " " << c8 << " " << c9 << endl;
c7 = -myComplex(2, 3);
c8 = (--c7) * 2;
c9 = (c7--)*2;
cout << c7 << " " << c8 << " " << c9 << endl;
// test expressions with myComplex numbers
c1 = myComplex(1,2);
c2 = myComplex(2,3);
c3 = myComplex(4,5);
c4 = myComplex(5,6);
c5 = myComplex(6,7);
c6 = 3;
cout << -(c1*c2) - c3*2 + -c4 * c5 * 3 + 2 -c6 << endl; // 여기 뭐가 뜨는데 뭐지...?

}
void testDataFromFile()
{
ifstream inStream;
int numTestCases;
inStream.open("input.txt");
if (inStream.fail())
{
cerr << "Input file opening failed.\n";
exit(1);
}
inStream >> numTestCases;
for (int i=0; i<numTestCases; i++)
{
myComplex c1, c2, c3, c4;
myComplex c5, c6, c7, c8, c9;
inStream >> c1 >> c2 >> c3 >> c4;
cout << c1 << " " << c2 << " " << c3 << " " << c4 << endl;
cout << (c1 + 5) + (-c2 - 1) * (c3 * 6) - (c4 * 2 - 3) <<
endl;
c5 = c6 = c7 = c8 = c1;
cout << (c5 == c2) << " " << (c5 != c2) << endl;
cout << (c5 > c2) << " " << (c5 >= c2) << " " << (c5 < c2) << " " <<
(c5 <= c2) << endl;
cout << (c5 == c6) << " " << (c5 != c6) << endl;
cout << (c5 > c6) << " " << (c5 >= c6) << " " << (c5 < c6) << " " <<
(c5 <= c6) << endl;
c5 += c2;
c6 -= c3;
c7 *= c4;
c8 = c2.getRealPart();
c9 = c3.getImaginaryPart();
cout << c5 << " " << c6 << " " << c7 << " " << c8 << " " << c9 << endl;
c7 = -c6;
c8 = (++c7) * 2;
c9 = (c7++) * 2;
cout << c7 << " " << c8 << " " << c9 << endl;
c7 = -c6;
c8 = (++c7) * 2;
c9 = (c7++) * 2;
cout << c7 << " " << c8 << " " << c9 << endl;
}
inStream.close();
}