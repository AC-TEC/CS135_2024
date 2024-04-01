/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 9
DATE: 4/1/2024

Task F: Create a partice class
*/

#include <iostream>

class Coord3D {
public:
    double x;
    double y;
    double z;
};


//create particle class
class Particle{
    public:
    //set public data members
    double vx;
    double vy;
    double vz;

    //cordinate object for position
    Coord3D pos;
};



//Dynamically allocate memory for a particle and initialize it
Particle* createParticle(double x, double y, double z, double vx, double vy, double vz){
    //dynamically create a particle object
    Particle *new_object = new Particle();

    //Initialize variables of new object
    new_object->pos.x = x;
    new_object->pos.y = y;
    new_object->pos.z = z;
    new_object->vx = vx;
    new_object->vy = vy;
    new_object->vz = vz;

    //return dynamically allocated Particle
    return new_object;
}


//Set velocity to (vx,vy,vz)
void setVelocity(Particle* p, double vx, double vy, double vz){
    p->vx = vx;
    p->vy = vy;
    p->vz = vz;
}


//Get its current position
Coord3D getPosition(Particle *p){
    return p->pos;
}


//Update particle's position after elapsed time dt
void move(Particle *p, double dt){
    p->pos.x = p->pos.x + p->vx * dt;
    p->pos.y = p->pos.y + p->vy * dt;
    p->pos.z = p->pos.z + p->vz * dt;
}


//Delete all memory allocated for the particle passed by pointer
void deleteParticle(Particle *p){
    delete p;
}


int main() {
    // make new particle
    Particle *p = createParticle(1.0, 1.5, 2.0, 0.1, 0.2, 0.3);
    double time = 0.0;
    double dt = 0.1;
    while(time < 3.0) {
        // update its velocity
        setVelocity(p, 10.0 * time, 0.3, 0.1);

        // move the particle
        move(p, dt);
        time += dt;

        // reporting its coordinates
        std::cout << "Time: " << time << " \t";
        std::cout << "Position: " << getPosition(p).x << ", " << getPosition(p).y << ", " << getPosition(p).z << std::endl;
    }
    // remove the particle, deallocating its memory
    deleteParticle(p);

    return 0;
}