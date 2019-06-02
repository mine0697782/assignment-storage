#ifndef UNTITLED_MYTERM_H
#define UNTITLED_MYTERM_H

#include <iostream>
using namespace std;

class myPolynomial;

class myTerm {
private:
    int coeff;              // 항의 계수
    unsigned exp;           // 지수

public:
    // friend 선언
    friend myPolynomial;

    // 생성자 및 복사 생성자
    myTerm(int c = 0, unsigned e = 0);
    myTerm(const myTerm& term);

    // 접근 메소드 & 수정 메소드
    int getCoeff() const;
    unsigned getExp() const;
    void setCoeff(int c);
    void setExp(unsigned e);

    // 논리 연산자 오버로딩
    bool operator==(const myTerm &term) const;
    bool operator!=(const myTerm &term) const;
    bool operator<(const myTerm &term) const;
    myTerm operator-() const;

    // 산술 연산자 오버로딩
    myTerm operator*(const myTerm &term) const;

    // 스트림 연산자 오버로딩
    friend ostream& operator<<(ostream& outStream, const myTerm& term);

    // 기능 메소드들
    myTerm ddx() const;             //미분 함수
};


#endif //UNTITLED_MYTERM_H
