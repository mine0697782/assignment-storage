#ifndef _MY_2Vector_H_
#define _MY_2Vector_H_

#include<iostream>

class My2Vector
{
    private:
        int x, y;
    public:
        // constructors
        My2Vector();
        My2Vector(int coordX, int coordY);

        // operators
        My2Vector& operator + (const My2Vector &v1, const My2Vector &v2);
        My2Vector& operator * (const int cnum, const My2Vector &v);
        std::ostream& operator << (std::ostream &os, const My2Vector& v);

};

#endif // _MY_2Vector_H_
