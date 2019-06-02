#ifndef UNTITLED_MYPOLYNOMIAL_H
#define UNTITLED_MYPOLYNOMIAL_H

#include <vector>
#include "myTerm.h"

class myPolynomial {
private:
    vector<myTerm> terms;
    int degree;

public:
    // 클래스 변수
    static const myPolynomial ZERO; // P(x) = 0
    static const myPolynomial ONE; // P(x) = 1
    static const myPolynomial X; // P(x) = x

    // 생성자 및 복사 생성자
    myPolynomial(int c = 0, unsigned e = 0);
    myPolynomial(int nTerms, int mono[]);
    myPolynomial(const myPolynomial &poly);

    // 접근 메소드 & 수정 메소드
    int getDegree() const; // get a degree of the polynomial
    unsigned getNumTerms() const; // number of terms in the polynomial

    // 산술 연산자 오버로딩
    myPolynomial operator+(const myPolynomial &poly) const;
    myPolynomial operator-(const myPolynomial &poly) const;
    myPolynomial operator*(int k) const;
    myPolynomial operator*(const myPolynomial &poly) const;
    friend myPolynomial operator*(int k, const myPolynomial &poly);

    // 단항 연산자 오버로딩
    myPolynomial operator -() const;

    // 비교 연산자 오버로딩
    bool operator == (const myPolynomial &poly) const;
    bool operator != (const myPolynomial &poly) const;

    // Stream 오버로딩
    friend ostream& operator <<(ostream &outStream, const myPolynomial &poly);

    // 데이터 처리 메소드
    myPolynomial ddx() const; // derivative of a polynomial

    long operator() (int x) const; // evaluate the polynomial

    // 복합 대입 연산자 오버로딩
    myPolynomial& operator += (const myPolynomial &poly);
    myPolynomial& operator -= (const myPolynomial &poly);
    myPolynomial& operator *= (const myPolynomial &poly);
    myPolynomial& operator *= (int k);
};


#endif //UNTITLED_MYPOLYNOMIAL_H
