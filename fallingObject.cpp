#include "fallingObject.h"
#include <math.h>


fallingObject::fallingObject(float mass, float surfaceArea, float bungeeSpringConstant, float bungeeUnstretchedLength){
	this->mass = mass;
	this->surfaceArea = surfaceArea;
	this->bungeeSpringConstant = bungeeSpringConstant;
	this->bungeeUnstretchedLength = bungeeUnstretchedLength;
}

void fallingObject::simulateTimeStep(float deltaT){
	this->deltaT = deltaT;
	float g = 9.81f;

	float Ffriction, Fspring, Fweight, Ftotal;
	float deltaV, deltaD;

	Ffriction = -0.65*surfaceArea*velocity*abs(velocity);
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

	Ftotal = Ffriction + Fspring + Fweight;
	acceleration = Ftotal / mass;
}
