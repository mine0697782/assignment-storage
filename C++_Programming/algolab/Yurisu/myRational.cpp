#include "myRational.h"
#include <cmath>

/* Constructor & Copy Constructor */
myRational::myRational(long num, long den) {
    if (den < 0) {
        den = -den;
        num = -num;
    }

    _num = num / gcd(abs(num), den);
    _den = den / gcd(abs(num), den);
}

myRational::myRational(const myRational &rat) {
    _num = rat._num;
    _den = rat._den;
}


/* Getter * Setter */
long myRational::getNumerator() const {
    return _num / gcd(abs(_num), _den);
}

long myRational::getDenominator() const {
    return _den / gcd(abs(_num), _den);
}


/* Overloading Method */
myRational myRational::operator+(const myRational &rat) const {
    long _newNum = _num * rat._den + rat._num * _den;
    long _newDen = _den * rat._den;

    if (_newDen < 0) {
        _newDen = -_newDen;
        _newNum = -_newNum;
    }

    long gcdNum = gcd(abs(_newNum), _newDen);

    return myRational(_newNum / gcdNum, _newDen / gcdNum);
}

myRational myRational::operator+(int value) const {
    return (*this) + myRational(value);
}

myRational operator+(int value, const myRational& rat) {
    return rat + value;
}

myRational myRational::operator-(const myRational &rat) const {
    long _newNum = _num * rat._den - rat._num * _den;
    long _newDen = _den * rat._den;

    if (_newDen < 0) {
        _newDen = -_newDen;
        _newNum = -_newNum;
    }

    long gcdNum = gcd(abs(_newNum), _newDen);

    return myRational(_newNum / gcdNum, _newDen / gcdNum);
}

myRational myRational::operator-(int value) const {
    return (*this) - myRational(value);
}

myRational operator-(int value, const myRational& rat) {
    return myRational(value) - rat;
}

myRational myRational::operator*(const myRational &rat) const {
    long _newNum = _num * rat._num;
    long _newDen = _den * rat._den;

    if (_newDen < 0) {
        _newDen = -_newDen;
        _newNum = -_newNum;
    }

    long gcdNum = gcd(abs(_newNum), abs(_newDen));

    return myRational(_newNum / gcdNum, _newDen / gcdNum);
}

myRational myRational::operator*(int value) const {
    return (*this) * myRational(value);
}

myRational operator*(int value, const myRational& rat) {
    return rat * value;
}

myRational myRational::operator/(const myRational &rat) const {
    if (rat._num == 0) {
        return myRational(0, 1);
    }

    myRational rec = rat.reciprocal();
    return (*this) * rec;
}

myRational myRational::operator/(int value) const {
    return (*this) / myRational(value);
}

myRational operator/(int value, const myRational& rat) {
    return myRational(value) / rat;
}

/* Unary operator overloading */
myRational& myRational::operator++() {
    (*this) = (*this) + 1;
    return (*this);
}

myRational myRational::operator++(int value) {
    myRational result = (*this);
    ++(*this);
    return result;
}

myRational& myRational::operator--() {
    (*this) = (*this) - 1;
    return (*this);
}

myRational myRational::operator--(int value) {
    myRational result = (*this);
    --(*this);
    return result;
}

myRational myRational::operator-() {
    return myRational(-_num, _den);
}


/* Compare Operator Method */
bool myRational::operator<(const myRational &rat) {
    long thisNum = _num * rat._den;
    long otherNum = rat._num * _den;

    return thisNum < otherNum;
}

bool myRational::operator<=(const myRational &rat) {
    long thisNum = _num * rat._den;
    long otherNum = rat._num * _den;

    return thisNum <= otherNum;
}

bool myRational::operator>(const myRational &rat) {
    long thisNum = _num * rat._den;
    long otherNum = rat._num * _den;

    return thisNum > otherNum;
}

bool myRational::operator>=(const myRational &rat) {
    long thisNum = _num * rat._den;
    long otherNum = rat._num * _den;

    return thisNum >= otherNum;
}

bool myRational::operator==(const myRational &rat) {
    long thisNum = _num * rat._den;
    long otherNum = rat._num * _den;

    return thisNum == otherNum;
}

bool myRational::operator!=(const myRational &rat) {
    long thisNum = _num * rat._den;
    long otherNum = rat._num * _den;

    return thisNum != otherNum;
}


/* Assignment Operator Method */
myRational& myRational::operator=(const myRational &rat) {
    _num = rat._num / gcd(abs(rat._num), rat._den);
    _den = rat._den / gcd(abs(rat._num), rat._den);

    return (*this);
}

myRational& myRational::operator+=(const myRational &rat) {
    (*this) = (*this) + rat;
    return (*this);
}

myRational& myRational::operator-=(const myRational &rat) {
    (*this) = (*this) - rat;
    return (*this);
}

myRational& myRational::operator*=(const myRational &rat) {
    (*this) = (*this) * rat;
    return (*this);
}

myRational& myRational::operator/=(const myRational &rat) {
    (*this) = (*this) / rat;
    return (*this);
}


/* Stream Operator Method */
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


/* Member method */
myRational myRational::reciprocal() const {
    return myRational(getDenominator(), getNumerator());
}

long myRational::gcd(long m, long n) const {
    int c;

    while (n != 0) {
        c = m % n;
        m = n;
        n = c;
    }

    return m;
}

void myRational::reduce()
{
    if (_num == 0 || _den == 0) {
        _num = 0;
        _den = 1;
        return;
    }

    if (_den < 0) {
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