/*
Author: Leonardo Matone
Instructor: Katherine Howitt
Assignment: Lab 9B

Goal: Takes coordinates of two points, and reutnrs the pointer of the point that is farther away from the origin.

*/

#include <iostream>
#include <cmath>
using namespace std;

//defining the class which holds our three coordinates
class Coord3D{
public:
    double x;
    double y;
    double z;
};

//'length' calculates the distance of a point from the origin
double length(Coord3D *p);

//'fartherFromOrigin' calculates which of two points is farther from the origin
Coord3D * fartherFromOrigin(Coord3D * p1, Coord3D * p2);

//'move' calculates the new position of a point after 'dt' time and substitutes this point back into the caller 
void move(Coord3D * ppos, Coord3D * pvel, double dt);

int main()
{
    Coord3D point = {0, 0, 0};    
    Coord3D velocity = {5, 5, 5};
    Coord3D * pointP = &point;
    Coord3D * vel = &velocity;

    double dt = 1.0;

    cout << point.x << " " << point.y << " " << point.z << endl;

    move(pointP, vel, dt);

    cout << point.x << " " << point.y << " " << point.z << endl;
}

void move(Coord3D * ppos, Coord3D * pvel, double dt)
{
    double X = ppos->x;
    double Y = ppos->y;
    double Z = ppos->z;

    double xVel = pvel->x;
    double yVel = pvel->y;
    double zVel = pvel->z;

    ppos->x = X + (xVel * dt);
    ppos->y = Y + (yVel * dt);
    ppos->z = Z + (zVel * dt);

}

Coord3D * fartherFromOrigin(Coord3D * p1, Coord3D * p2)
{
    double x1 = p1->x;
    double y1 = p1->y;
    double z1 = p1->z;

    double x2 = p2->x;
    double y2 = p2->y;
    double z2 = p2->z;

    double summath1 = pow(x1, 2) + pow(y1, 2) + pow(z1, 2);
    double summath2 = pow(x2, 2) + pow(y2, 2) + pow(z2, 2);

    double len1 = sqrt(summath1);
    double len2 = sqrt(summath2);

    if (len1 > len2)
    {
        return p1;
    }
    else 
    {
        return p2;
    }
}

//takes the address of a point using Coord3D 
double length(Coord3D *p)
{
    double X = p->x; //takes x from the address p
    double Y = p->y; //takes y from the address p
    double Z = p->z; //takes z from the address p

    //I split the operation to make it more legible. Summath
    //stores the summation of the squared x, y, and z coordinates.
    double summath = pow(X, 2) + pow(Y, 2) + pow (Z, 2);

    //takes the square root of summath, which is the length from
    //origin!
    double len = sqrt(summath);

    return len;
}