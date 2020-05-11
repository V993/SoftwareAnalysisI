/*
Author: Leonardo Matone
Instructor: Katherine Howitt
Assignment: Lab 9A

Goal:

*/

#include <iostream>
#include <cmath>
using namespace std;

class Coord3D{
public:
    double x;
    double y;
    double z;
};

double length(Coord3D *p);

int main()
{
    Coord3D pointP = {10, 20, 30};
    Coord3D * p = &pointP;
    cout << length(p) << endl;
}

double length(Coord3D *p)
{
    double X = p->x;
    double Y = p->y;
    double Z = p->z;

    double summath = pow(X, 2) + pow(Y, 2) + pow (Z, 2);

    double len = sqrt(summath);

    return len;
}