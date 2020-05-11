/*
Author: Leonardo Matone
Instructor: Katherine Howitt
Assignment: Lab 9E

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

//'createCoord3D' takes an x, y, and z value and allocates and initializes a coordinate object in dynamic memory
Coord3D *createCoord3D(double x, double y, double z);

void deleteCoord3D(Coord3D * p);

int main()
{
    double x, y, z;
    cout << "Enter position: ";
    cin >> x >> y >> z;
    Coord3D *ppos = createCoord3D(x,y,z); //create posiiton

    cout << "Enter velocity: ";
    cin >> x >> y >> z;
    Coord3D *pvel = createCoord3D(x,y,z);

    move(ppos, pvel, 10.0);

    cout << "Coordinates after 10 seconds: "
         << (*ppos).x << " " << (*ppos).y 
         << " " << (*ppos).z << endl;

    deleteCoord3D(ppos); //release memory for position
    deleteCoord3D(pvel); //release memory for velocity
}

void deleteCoord3D(Coord3D * p)
{
    delete p;
}

Coord3D * createCoord3D(double x, double y, double z)
{
    Coord3D *ppos;
    ppos = new Coord3D;
    *ppos = {x, y, z};

    return ppos;
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