#include <iostream>
#include <fstream>
#include <cstdlib>
#include <numeric>

using namespace std;

class myRational
{
private:
 // 분수는 항상 내부적으로 기약분수로 표현하며, 또한 항상 _den>0 이다. 
    long _num; // numerator
    long _den; // denominator
    long gcd(long m, long n); // 최대공약수
    void reduce();

public:
    myRational(long _num = 0, long _den = 1);
    myRational(const myRational &rat);
    friend ostream &operator <<(ostream &outStream, const myRational& r);
    friend istream &operator >>(istream &inStream, myRational& r);
    long getNumerator();
    long getDenominator();

    myRational operator +(const myRational& n1)const;
    friend myRational operator+(int value, const myRational &n1);

    myRational operator -(const myRational& n11)const;
    friend myRational operator-(int value, const myRational &n1);

    myRational operator *(const myRational& n1)const;
    friend myRational operator*(int value, const myRational &n1);

    myRational operator /(const myRational& n1)const;
    friend myRational operator/(int value, const myRational &n1);

    bool operator < (const myRational& n1)const;
    bool operator <= (const myRational& n1)const;
    bool operator > (const myRational& n1)const;
    bool operator >= (const myRational& n1)const;
    bool operator == (const myRational& n1)const;
    bool operator != (const myRational& n1)const;

    myRational& operator +=(const myRational& number);
    myRational& operator -=(const myRational& number);
    myRational& operator *=(const myRational& number);
    myRational& operator /=(const myRational& number);

    myRational operator -();

    myRational &operator ++();
    myRational operator ++(int);
    myRational &operator --();
    myRational operator --(int);

}; 

myRational::myRational(long n, long d)//:_num(n/gcd(n,d)), _den(d/gcd(n,d))
{
    if(n == 0 || d == 0)
    {
        _num = n;
        _den = d;
    }
    else if(n < 0 && d < 0)
    {
        n = n * -1;
        d = d * -1;
        _num = n / gcd(n, d);
        _den = d / gcd(n, d);
    }
    else if(n < 0)
    {
        _num = n / gcd(-n, d);
        _den = d / gcd(-n, d);
    }
    else if(d < 0)
    {
        _num = (n * -1) / gcd(n, -d);
        _den = (d * -1) / gcd(n, -d);
    }

    else
    {
        _num = n / gcd(n, d);
        _den = d / gcd(n, d);
    }
    
}

myRational::myRational(const myRational &rat)
{
    _num = rat._num;
    _den = rat._den;
}
ostream &operator <<(ostream &outStream, const myRational& r)
{
    if (r._num == 0)
        outStream << 0;
    else if (r._den == 1)
        outStream << r._num;
    else
        outStream << r._num << "/" << r._den;

    return outStream;
}
istream &operator >>(istream &inStream, myRational& r)
{
    inStream >> r._num >> r._den;
    if (r._den == 0)
    {
        r._num = 0;
        r._den = 1;
    }
    r.reduce();
    return inStream;
}

long myRational::getNumerator()
{
    return _num;
}

long myRational::getDenominator()
{
    return _den;
}

myRational myRational::operator +(const myRational& n1)const
{
    long temp_den = _den * n1._den;
    long temp_num = _num * n1._den + n1._num *_den;

    return myRational(temp_num, temp_den);
}

myRational operator+(int value, const myRational &n1)
{
    return myRational(n1._num + value*n1._den, n1._den);
}

myRational myRational::operator -(const myRational& n1)const
{
    long temp_den = _den * n1._den;
    long temp_num = _num * n1._den - n1._num *_den;

    return myRational(temp_num, temp_den);
}

myRational operator-(int value, const myRational &n1)
{
    return myRational(value * n1._den - n1._num, n1._den);
}

myRational myRational::operator *(const myRational& n1)const
{
    long temp_den = _den * n1._den;
    long temp_num = _num * n1._num;

    return myRational(temp_num, temp_den);
}

myRational operator*(int value, const myRational &n1)
{
    return myRational(n1._num * value, n1._den);
}

myRational myRational::operator /(const myRational& n1)const
{
    long temp_den = _den * n1._num;
    long temp_num = _num * n1._den;

    return myRational(temp_num, temp_den);
}

myRational operator/(int value, const myRational &n1)
{
    return myRational(n1._den * value, n1._num);
}

bool myRational::operator < (const myRational& n1)const
{
    long temp_num = _num * n1._den - n1._num *_den;

    if(temp_num < 0)
        return 1;
    
    return 0;
}
bool myRational::operator <= (const myRational& n1)const
{
    long temp_num = _num * n1._den - n1._num *_den;

    if(temp_num <= 0)
        return 1;
    
    return 0;
}

bool myRational::operator > (const myRational& n1)const
{
    long temp_num = _num * n1._den - n1._num *_den;

    if(temp_num > 0)
        return 1;
    
    return 0;
}
bool myRational::operator >= (const myRational& n1)const
{
    long temp_num = _num * n1._den - n1._num *_den;

    if(temp_num >= 0)
        return 1;
    
    return 0;
}

bool myRational::operator == (const myRational& n1)const
{
    long temp_num = _num * n1._den - n1._num *_den;

    if(temp_num == 0)
        return 1;
    
    return 0;
}

bool myRational::operator != (const myRational& n1)const
{
    long temp_num = _num * n1._den - n1._num *_den;

    if(temp_num != 0)
        return 1;
    
    return 0;
}

myRational& myRational::operator +=(const myRational& n1)
{
    int temp = _den;
    _den = _den * n1._den;
    _num = _num * n1._den + n1._num *temp;

    this->reduce();
    return *this;
}

myRational& myRational::operator -=(const myRational& n1)
{    
    int temp = _den;

    _den = _den * n1._den;
    _num = _num * n1._den - n1._num *temp;
    this->reduce();
    return *this;
}

myRational& myRational::operator *=(const myRational& n1)
{
    _den = _den * n1._den;
    _num = _num * n1._num;
    this->reduce();
    return *this;
}
myRational& myRational::operator /=(const myRational& n1)
{
    _den = _den * n1._num;
    _num = _num * n1._den;
    this->reduce();
    return *this;
}

myRational myRational::operator -()
{
    return myRational(-1 * _num, _den);
}

myRational &myRational::operator ++()
{
    _num = _num + _den;
    return *this;
}

myRational myRational::operator ++(int)
{
    myRational t = *this;
    ++ *this;
    return t;
}

myRational &myRational::operator --()
{
    _num = _num - _den;
    return *this;
}

myRational myRational::operator --(int)
{
    myRational t = *this;
    -- *this;
    return t;
}

long myRational::gcd(long m, long n)
{
    if (m == n)
        return n;
    else if (m < n)
        return gcd(m, n-m);
    else
        return gcd(m-n, n);
}
void myRational::reduce()
{
    if (_num == 0 || _den == 0)
    {
    _num = 0;
    _den = 1;
    return;
    }
    if (_den < 0)
    {
        _den *= -1;
        _num *= -1;
    }
    if (_num == 1)
        return;
    int sgn = (_num < 0 ? -1 : 1);
    long g = gcd(sgn * _num, _den);
    _num /= g;
    _den /= g;
} 


void testSimpleCase();
void testDataFromFile();
int main()
{
    testSimpleCase();
    testDataFromFile();
}
void testSimpleCase()
{
    myRational frac1(2), frac2(3, 2), frac3(6, 4), frac4(12, 8), frac5, frac6, frac7;
    cout << frac1 << " " << frac2 << " " << frac3 << " " << frac4 << " " << frac5 << endl;
    cout << frac1.getNumerator() << " " << frac1.getDenominator() << endl;
    // Check arithmetic operators
    cout << frac1 * frac2 << " " << frac1 + frac3 << " " << frac2 - frac1 << " " << frac3 / frac2 << endl;
    // Check comparison operators

    cout << ((frac1 < frac2) ? 1 : 0) << " "
    << ((frac1 <= frac2) ? 1 : 0) << " "
    << ((frac1 > frac2) ? 1 : 0) << " "
    << ((frac1 >= frac2) ? 1 : 0) << " "
    << ((frac1 == frac2) ? 1 : 0) << " "
    << ((frac1 != frac2) ? 1 : 0) << " "
    << ((frac2 < frac3) ? 1 : 0) << " "
    << ((frac2 <= frac3) ? 1 : 0) << " "
    << ((frac2 > frac3) ? 1 : 0) << " "
    << ((frac2 >= frac3) ? 1 : 0) << " "
    << ((frac2 == frac3) ? 1 : 0) << " "
    << ((frac2 != frac3) ? 1 : 0) << endl;

    cout << (frac6 = frac3) << " ";
    cout << (frac6 += frac3) << " ";
    cout << (frac6 -= frac3) << " ";
    cout << (frac6 *= frac3) << " ";
    cout << (frac6 /= frac3) << endl;
    cout << -frac6 << endl;
    frac6 = (++frac4) + 2;
    frac7 = 2 + (frac4++);
    cout << frac4 << " " << frac6 << " " << frac7 << endl;
    frac6 = (--frac4) - 2;
    frac7 = 2 - (frac4--);
    cout << frac4 << " " << frac6 << " " << frac7 << endl;
    cout << 2 * frac3 << " " << frac3 * 2 << " "
    << 2 / frac3 << " " << frac3 / 2 << endl;
}

void testDataFromFile()
{
    int t;
    cin >>t;
    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        myRational arr[n];

        for(int j = 0; j < n; j++)
        {
            int a, b;
            cin >> a >> b;
            myRational X(a,b); 
            arr[j] = X;
            //cout <<"uploaded "<<endl;
        }

        for(int j = 0 ; j < n-1; j++)
        {
            for(int k = 1; k < j; k++)
            {
                if(arr[k-1] - arr[k] > 0)
                {
                    myRational temp = arr[k-1];
                    arr[k-1] = arr[k];
                    arr[k] = temp;

                }
            }
        }
        for(int j = 0; j < n; j++)
            cout << arr[j] <<" ";
        cout <<endl;
    }
    
}