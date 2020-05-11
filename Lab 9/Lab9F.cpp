/*
Author: Leonardo Matone
Instructor: Katherine Howitt
Assignment: Lab 9F (bonus)

Task:
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

//defining the class which holds the position and velocity of a particle
class Particle{
public:
    Coord3D pos;
    Coord3D vel;
};



//dynamically allocate memory for a particle and initialize it:
Particle * createParticle(double x, double y, double z,
                        double vx, double vy, double vz);

//'createCoord3D' takes an x, y, and z value and allocates and initializes a coordinate object in dynamic memory
Coord3D *createCoord3D(double x, double y, double z);

//sets velocity of the particle to vx, vy, vz
void setVelocity(Particle *p, double vx, double vy, double vz);

//gets current position
Coord3D getPosition(Particle *p);

//update particle's position after dt
void move(Particle *p, double dt);

//deletes all allocated memory for the particle in the passed pointer
void deleteParticle(Particle *p);


int main()
{
    double x, y, z, vx, vy, vz;

    cout << "Enter position: ";
    cin >> x >> y >> z;
    cout << endl;

    cout << "Enter velocity: ";
    cin >> vx >> vy >> vz;
    cout << endl;

    Particle *p = createParticle(x, y, z, vx, vy, vz);
    double time = 0.0;
    double dt = 0.1;
    while(time < 3.0)
    {
        setVelocity(p, vx, vy, vz);

        move(p, dt);
        time += dt;

        cout << "Time: " << time << "\t";
        cout << "Position" 
             << getPosition(p).x << ', ' 
             << getPosition(p).y << ', ' 
             << getPosition(p).z << endl;
    }
    deleteParticle(p);
    return 0;
}

Particle * createParticle(double x, double y, double z,
                        double vx, double vy, double vz)
{
    Coord3D * ppos = createCoord3D(x,y,z);
    // Coord3D position = ppos->
}

Coord3D * createCoord3D(double x, double y, double z)
{
    Coord3D *ppos;
    ppos = new Coord3D;
    *ppos = {x, y, z};

    return ppos;
}