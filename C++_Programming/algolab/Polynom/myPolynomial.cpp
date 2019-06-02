#include "myPolynomial.h"
#include <cmath>

/* Constructor & Copy Constructor */
myPolynomial::myPolynomial(int c, unsigned int e) {
    terms.push_back(myTerm(c, e));
    degree = e;
}

myPolynomial::myPolynomial(int nTerms, int *mono) {
    terms.resize(nTerms);

    for(int i = 0; i < nTerms; i++) {
        terms[i] = myTerm(mono[2 * i], mono[2 * i + 1]);

        for (int j = i; j > 0; j--) {
            if (terms[j - 1] < terms[j]) {
                myTerm temp = terms[j - 1];
                terms[j - 1] = terms[j];
                terms[j] = temp;
            }
        }
    }

    degree = terms[nTerms - 1].getExp();         // Get Max Exp
}

myPolynomial::myPolynomial(const myPolynomial &poly) {
    int termCnt = poly.terms.size();

    terms.resize(termCnt);

    for (int i = 0; i < termCnt; i++) {
        terms[i] = poly.terms[i];
    }

    degree = terms[termCnt - 1].getExp();
}

int myPolynomial::getDegree() const {
    if (terms.at(0).coeff == 0)
        return -1;

    return degree;
}

unsigned myPolynomial::getNumTerms() const {
    return terms.size();
}


/* Unary Operator */
myPolynomial myPolynomial::operator-() const {
    myPolynomial minus(*this);

    for (int i = getNumTerms() - 1; i >= 0; i--)
        minus.terms[i] = -minus.terms[i];

    return minus;
}


/* Arithmetic Operator */
myPolynomial myPolynomial::operator*(int k) const {
    // Call copy constructor
    myPolynomial newPoly(*this);

    // Return 0 if inputed ZERO
    if (k == 0)
        return myPolynomial::ZERO;

    // Multiply coefficient
    for (int i = getNumTerms() - 1; i >= 0; i--)
        newPoly.terms[i].coeff *= k;

    return newPoly;
}

myPolynomial operator*(int k, const myPolynomial &poly) {
    return poly * k;
}

myPolynomial myPolynomial::operator*(const myPolynomial &poly) const {
    myPolynomial total(0);
    for (int i = getNumTerms() - 1; i >= 0; i--) {
        for (int j = poly.getNumTerms() - 1; j >= 0; j--) {
            myPolynomial temp(terms[i].coeff * poly.terms[j].coeff, terms[i].exp + poly.terms[j].exp);
            total = total + temp;
        }
    }
    return total;
}

myPolynomial myPolynomial::operator+(const myPolynomial &poly) const {
    myPolynomial newPoly;
    vector<myTerm> sum;

    int thisLen = getNumTerms();
    int otherLen = poly.getNumTerms();

    // Pivot for loop
    int pivotMe = 0;
    int pivotOther = 0;
    int curr = 0;
    int newCoeff;
    int newExp;

    // resizing
    sum.resize(thisLen + otherLen);

    while (pivotMe < thisLen && pivotOther < otherLen) {
        if (((terms[pivotMe].coeff == 0) && (terms[pivotMe].exp == 0))
        || ((poly.terms[pivotOther].coeff == 0) && (poly.terms[pivotOther].exp == 0))) {
            newCoeff = terms[pivotMe].coeff + poly.terms[pivotOther].coeff;
            newExp = terms[pivotMe].exp + poly.terms[pivotOther].exp;

            // ignore term when term is zero
            if (newCoeff != 0)
                sum[curr++] = myTerm(newCoeff, newExp); // <=

            pivotMe++;
            pivotOther++;
        } else {
            if (terms[pivotMe].exp < poly.terms[pivotOther].exp) {
                sum[curr++] = terms[pivotMe++];
            } else if (poly.terms[pivotOther].exp < terms[pivotMe].exp) {
                sum[curr++] = poly.terms[pivotOther++];
            } else {
                newCoeff = terms[pivotMe].coeff + poly.terms[pivotOther].coeff;

                // ignore term when term is zero
                if (newCoeff != 0)
                    sum[curr++] = myTerm(newCoeff, terms[pivotMe].exp); // <=

                pivotMe++;
                pivotOther++;
            }
        }
    }

    if (pivotMe == thisLen) {
        while (pivotOther < otherLen)
            sum[curr++] = poly.terms[pivotOther++];
    } else {
        while (pivotMe < thisLen)
            sum[curr++] = terms[pivotMe++];
    }

    if (curr == 0)
        return myPolynomial(0);

    sum.resize(curr);
    newPoly.terms = sum;

    return newPoly;
}

myPolynomial myPolynomial::operator-(const myPolynomial &poly) const {
    return (*this) + -poly;
}

myPolynomial myPolynomial::ddx() const {
    myPolynomial ddxPoly(*this);

    for (int i = getNumTerms() - 1; i >= 0; i--) {
        ddxPoly.terms[i] = terms[i].ddx();
    }

    return ddxPoly;
}


ostream& operator <<(ostream &outStream, const myPolynomial &poly) {
    int len = poly.getNumTerms();

    if (poly == myPolynomial::ZERO) {
        cout << 0;
    } else {
        cout << poly.terms[len - 1];
        for (int i = len - 2; i >= 0; i--) {
            if (poly.terms[i].getCoeff() > 0) {
                cout << '+' << poly.terms[i];
            } else {
                cout << poly.terms[i];
            }
        }
    }
    return outStream;
}

bool myPolynomial::operator==(const myPolynomial &poly) const {
    return (terms == poly.terms) && (degree == poly.degree);
}

bool myPolynomial::operator!=(const myPolynomial &poly) const {
    return !((*this) == poly);
}

long myPolynomial::operator()(int x) const {
    long result = 0;

    for (int i = getNumTerms() - 1; i >= 0; i--)
        result = result + terms[i].coeff * pow(x, terms[i].exp);

    return result;
}

myPolynomial& myPolynomial::operator+=(const myPolynomial &poly) {
    (*this) = (*this) + poly;
    return (*this);
}

myPolynomial& myPolynomial::operator-=(const myPolynomial &poly) {
    (*this) = (*this) - poly;
    return (*this);
}

myPolynomial& myPolynomial::operator*=(const myPolynomial &poly) {
    (*this) = (*this) * poly;
    return *this;
}

myPolynomial& myPolynomial::operator*=(int k) {
    (*this) = (*this) * k;
    return *this;
}

const myPolynomial myPolynomial::ZERO(0); // the zero polynomial P(x) = 0
const myPolynomial myPolynomial::ONE(1, (unsigned)0); // the monomial P(x) = 1
const myPolynomial myPolynomial::X(1, 1); // the monomial P(x) = x