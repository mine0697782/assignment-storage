#include "myTerm.h"

/* Constructor & Copy Constructor */
myTerm::myTerm(int c, unsigned int e) : coeff(c), exp(e) {}
myTerm::myTerm(const myTerm &term) : coeff(term.coeff), exp(term.exp) {}


/* Getter & Setter Method */
int myTerm::getCoeff() const {
    return coeff;
}

unsigned myTerm::getExp() const {
    return exp;
}

void myTerm::setCoeff(int c) {
    coeff = c;
}

void myTerm::setExp(unsigned e) {
    exp = e;
}


/* Stream Operator Overloading */
ostream& operator <<(ostream &outStream, const myTerm& term)
{
    if (term.exp == 0) {
        if (term.coeff == 0) // nothing to output
            return outStream;
        else
            return outStream << term.coeff;
    }

    if (term.coeff == 1)
        outStream << "x";
    else if (term.coeff == -1)
        outStream << "-x";
    else
        outStream << term.coeff << "x";

    if (term.exp == 1)
        return outStream;
    else
        return outStream << "^" << term.exp;
}

/* Arithmetic Operator Overloading */
myTerm myTerm::operator*(const myTerm &term) const {
    return myTerm(coeff * term.coeff, exp + term.exp);
}


/* Logic Operator Overloading */
bool myTerm::operator==(const myTerm &term) const {
    return coeff == term.coeff &&
           exp == term.exp;
}

bool myTerm::operator!=(const myTerm &term) const {
    return !(term == *this);
}

bool myTerm::operator<(const myTerm &term) const {
    return exp > term.exp;
}

myTerm myTerm::operator-() const {
    return myTerm(-coeff, exp);
}


/* Other Function Method */
myTerm myTerm::ddx() const {
    if (exp == 0)
        return myTerm(0, 0);
    else
        return myTerm(coeff * exp, exp - 1);
}
