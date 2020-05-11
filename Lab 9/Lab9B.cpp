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

//prototype of function length
double length(Coord3D *p);

Coord3D * fartherFromOrigin(Coord3D * p1, Coord3D * p2);

int main()
{
    Coord3D pointP1 = {10, 20, 30};  //defines coordinates
    Coord3D * p1 = &pointP1;          //defines a pointer which refers 
                                    //to the defined pointP
    Coord3D pointP2 = {-20, 21, -22};  //defines coordinates
    Coord3D * p2 = &pointP2;          //defines a pointer which refers 
                                    //to the defined pointP

    cout << "Address of 1: " << &pointP1 << endl;
    cout << "Address of 2: " << &pointP2 << endl;

    Coord3D * ans = fartherFromOrigin(&pointP1, &pointP2);
    cout << "ans = " << ans << endl;    
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