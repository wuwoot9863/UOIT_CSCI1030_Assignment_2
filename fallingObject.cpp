#include "fallingObject.h"
#include <math.h>

/*fallingObject 
 *
 *Constructor that creates an object that assigns constants to the object
 *
 *@param mass
 *@param surfaceArea
 *@param bungeeSpringConstant
 *@param bungeeUnstretchedLength
 */
fallingObject::fallingObject(float mass, float surfaceArea, float bungeeSpringConstant, float bungeeUnstretchedLength){
	this->mass = mass;
	this->surfaceArea = surfaceArea;
	this->bungeeSpringConstant = bungeeSpringConstant;
	this->bungeeUnstretchedLength = bungeeUnstretchedLength;
}

/*getMass
 *
 *Method that returns the mass of the object
 *
 *@return mass The mass of the object
 */
float fallingObject::getMass(){
	return mass;
}

/*getSurfaceArea
*
*Method that returns the surface area of the object
*
*@return surfaceArea The surface area of the object
*/
float fallingObject::getSurfaceArea(){
	return surfaceArea;
}

/*getBungeeSpringConstant
*
*Method that returns the spring constant of the bungee cord
*
*@return bungeeSpringConstant The spring constant of the bungee cord
*/
float fallingObject::getBungeeSpringConstant(){
	return bungeeSpringConstant;
}

/*getBungeeUnstretchedLength
*
*Method that returns the length of the bungee cord
*
*@return bungeeUnstretchedLength The length of the bungee cord
*/
float fallingObject::getBungeeUnstretchedLength(){
	return bungeeUnstretchedLength;
}

/*getFallDistance
*
*Method that returns the falling distance of the object
*
*@return fallDistance The falling distance of the object
*/
float fallingObject::getFallDistance(){
	return fallDistance;
}

/*getVelocity
*
*Method that returns the velocity of the object
*
*@return velocity The velocity of the object
*/
float fallingObject::getVelocity(){
	return velocity;
}

/*getAcceleration
*
*Method that returns the acceleration of the object
*
*@return acceleration The acceleration of the object
*/
float fallingObject::getAcceleration(){
	return acceleration;
}


/*simulateTimeStep
*
*Method that simulates the bungee jump of Julie-Ann if she were to take it
*/
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
