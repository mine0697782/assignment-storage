#include<cstdlib>
#include "My2Vector.h"

// constructors
My2Vector::My2Vector()// :x(0) y(0)
{
    x = 0;
    y = 0;
}

My2Vector::My2Vector(int coordX, int coordY)// :x(coordX), y(coordY)
{
    x = coordX;
    y = coordY;
}


My2Vector& My2Vector::operator + (const My2Vector &v1, const My2Vector &v2)
{
    return My2Vector(v1.x + v2.x, v1.y + v2.y);
}

My2Vector& My2Vector::operator * (const int cnum, const My2Vector &v)
{
    return My2Vector(cnum*v.x, cnum*v.y);
}

std::ostream& My2Vector::operator << (std::ostream &os, const My2Vector& v)
{
    os << "(" << v.x << "," << v.y << ")";
    return os;
}
