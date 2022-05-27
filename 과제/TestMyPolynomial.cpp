#include <fstream>
#include <cstdlib>
#include "MyPolynomial.h"

void testSimpleCase();
void testDataFromFile();

int main(void)
{
    testSimpleCase();
    testDataFromFile();
    return 0;
}

void testSimpleCase()
{
    // test static variables
    cout << myPolynomial::ZERO << endl;
    cout << myPolynomial::ONE << endl;
    cout << myPolynomial::X << endl;
    myPolynomial p0, p1(1), p2(1, 1), p3(3, 5);
    int testData4[10] = {1, 0, 1, 1, 1, 2, 1, 3, 1, 4};
    int testData5[10] = {-1, 0, -1, 1, -1, 2, -1, 3, -1, 4};
    int testData6[10] = {1, 0, -1, 1, 1, 2, -1, 3, 1, 4};
    int testData7[10] = {2, 2, 5, 5, 4, 4, 1, 1, 3, 3};
    int testData8[12] = {1, 1000000000, 1, 100000000, 1, 1000000, 1, 10000, 1, 100, 1, 0};
    myPolynomial p4(5, testData4);
    myPolynomial p5(5, testData5);
    myPolynomial p6(5, testData6);
    myPolynomial p7(5, testData7);
    myPolynomial p8(6, testData8);
    myPolynomial p9(p7);

    // test constructor
    cout << p0 << endl << p1 << endl << p2 << endl;
    cout << p4 << endl << p8 << endl;

    // test copy constructor
    cout << p9 << endl;
    
    // test accessor function
    cout << p8.getDegree() << " " << p8.getNumTerms() << endl;

    // test evaluation function
    cout << p1(2) << " " << p2(2) << " " << p3(2) << " " << p4(2) << " " << endl;
    cout << p5(3) << " " << p6(3) << " " << p7(3) << " " << p9(3) << " " << endl;
    // test comparison operators
    cout << (p7 == p9) << " " << (p7 != p9) << endl;
    // test derivative function
    cout << myPolynomial::ZERO.ddx() << endl;
    cout << myPolynomial::ONE.ddx() << endl;
    cout << myPolynomial::X.ddx() << endl;
    cout << p4.ddx() << endl;
    cout << p8.ddx() << endl;
    // test unary operator -
    cout << -myPolynomial::ZERO << endl;
    cout << -p4 << endl;
    // test k*p(x) or p(x) * k
    cout << 3*myPolynomial::ZERO << endl;
    cout << 3*myPolynomial::ONE << endl;
    cout << myPolynomial::X*3 << endl;
    cout << 3*p4 << " " << p4*3 << endl;
    cout << 0*p5 << " " << p5*5 << endl;
    // test binary operator +
    cout << p4 + p5 << endl;
    // test binary operator -
    cout << p6 - p7 << endl;
    // test binary operator *
    cout << p8 * p9 << endl;
    myPolynomial tmp1(p4), tmp2, tmp3, tmp4;
    tmp4 = tmp3 = tmp2 = tmp1;
    cout << (tmp1 += p5) << endl;
    cout << (tmp2 -= p5) << endl;
    cout << (tmp3 *= p5) << endl;
    cout << (tmp4 *= 3) << endl;
}

void testDataFromFile()
{
    int numTestCases;
    cin >> numTestCases;
    for (int i=0; i<numTestCases; i++)
    {
        int numTerms, terms[100];
       
       /* read first polynomial */
        cin >> numTerms;
        for (int j=0; j<numTerms; j++)
        cin >> terms[2*j] >> terms[2*j+1];
        myPolynomial p1(numTerms, terms);
        
        /* read second polynomial */
        cin >> numTerms;
        for (int j=0; j<numTerms; j++)
            cin >> terms[2*j] >> terms[2*j+1];
        
        myPolynomial p2(numTerms, terms);
        cout << p1 << endl << p2 << endl;
        cout << p1.getDegree() << " " << p2.getNumTerms() << endl;
        cout << p1.ddx() << endl << p2.ddx() << endl;
        cout << (p1 == p2) << " " << (p1 != p2) << endl;
        cout << p1(1) << endl;
        cout << -p1 + p1 * 2 * p2 - p2 * 2 + 3 * p1 << endl;
        myPolynomial p3(myPolynomial::ZERO), p4(myPolynomial::ONE), p5(myPolynomial::X);
        p3 += p1;
        p4 -= p2;
        p5 *= p4;
        p5 *= 2;
        cout << p5 << endl;
    }
}