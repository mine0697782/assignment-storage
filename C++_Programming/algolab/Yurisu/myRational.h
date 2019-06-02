#ifndef UNTITLED_MYRATIONAL_H
#define UNTITLED_MYRATIONAL_H
#include <iostream>
using namespace std;

class myRational {
private:
    long _num;          // numerator
    long _den;          // denominator

    long gcd(long m, long n) const;
    void reduce();

public:
    myRational(long num=0, long den=1);
    myRational(const myRational &rat);

    long getNumerator() const;
    long getDenominator() const;

    myRational operator+(const myRational& rat) const;
    myRational operator+(int value) const;
    myRational operator-(const myRational& rat) const;
    myRational operator-(int value) const;
    myRational operator*(const myRational& rat) const;
    myRational operator*(int value) const;
    myRational operator/(const myRational& rat) const;
    myRational operator/(int value) const;

    friend myRational operator+(int value, const myRational& rat);
    friend myRational operator-(int value, const myRational& rat);
    friend myRational operator*(int value, const myRational& rat);
    friend myRational operator/(int value, const myRational& rat);

    myRational& operator++();
    myRational operator++(int value);
    myRational& operator--();
    myRational operator--(int value);
    myRational operator-();

    bool operator<(const myRational& rat);
    bool operator<=(const myRational& rat);
    bool operator>(const myRational& rat);
    bool operator>=(const myRational& rat);
    bool operator==(const myRational& rat);
    bool operator!=(const myRational& rat);

    myRational& operator=(const myRational& rat);
    myRational& operator+=(const myRational& rat);
    myRational& operator-=(const myRational& rat);
    myRational& operator*=(const myRational& rat);
    myRational& operator/=(const myRational& rat);

    friend ostream& operator<<(ostream& outStream, const myRational &rat);
    friend istream& operator>>(istream& inStream, myRational &rat);

    myRational reciprocal() const;
};


#endif //UNTITLED_MYRATIONAL_H
