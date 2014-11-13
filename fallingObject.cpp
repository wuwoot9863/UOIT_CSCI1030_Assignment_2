#include "fallingObject.h"
#include <math.h>


fallingObject::fallingObject(float mass, float surfaceArea, float bungeeSpringConstant, float bungeeUnstretchedLength){
	this->mass = mass;
	this->surfaceArea = surfaceArea;
	this->bungeeSpringConstant = bungeeSpringConstant;
	this->bungeeUnstretchedLength = bungeeUnstretchedLength;
}


float fallingObject::getMass(){
	return mass;
}

float fallingObject::getSurfaceArea(){
	return surfaceArea;
}

float fallingObject::getBungeeSpringConstant(){
	return bungeeSpringConstant;
}

float fallingObject::getBungeeUnstretchedLength(){
	return bungeeUnstretchedLength;
}

float fallingObject::getFallDistance(){
	return fallDistance;
}

float fallingObject::getVelocity(){
	return velocity;
}

float fallingObject::getAcceleration(){
	return acceleration;
}


void fallingObject::simulateTimeStep(float deltaT){
	this->deltaT = deltaT;

	Ffriction = -0.65f*surfaceArea*velocity*abs(velocity);
	Fweight = mass * g;

	if (fallDistance < bungeeUnstretchedLength){
		Fspring = 0;
	}
	else Fspring = -bungeeSpringConstant*(fallDistance - bungeeUnstretchedLength);

	Ftotal = Ffriction + Fspring + Fweight;
	acceleration = Ftotal / mass;

	deltaV = acceleration * deltaT;
	velocity += deltaV;

	deltaD = velocity * deltaT;
	fallDistance += deltaD;
}
