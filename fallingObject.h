class fallingObject
{
private:
	float mass; //Mass of the object
	float surfaceArea; //Surface area of the object
	float bungeeSpringConstant; //Spring constant of the bungee cord
	float bungeeUnstretchedLength; //Length of the bungee cord
	float fallDistance = 0.0f; //Falling distance of the object
	float velocity = 0.0f; //Velocity of the object
	float acceleration = 0.0f; //Acceleration of the object
	float deltaT; //Time increment change as the object is in motion
	float deltaV; //Change in velocity at a time increment
	float deltaD; //Change in distance at a time increment
	float Ffriction; //Force of air friction acting on the object
	float Fspring; //Force of the spring acting on the object
	float Fweight; //Force of gratvity acting on the object
	float Ftotal; //Net force acting on the object
	float g = 9.81f; //Magnitude of gravity
public:
	virtual float getMass();
	virtual float getSurfaceArea();
	virtual float getBungeeSpringConstant();
	virtual float getBungeeUnstretchedLength();
	fallingObject(float mass, float surfaceArea, float bungeeSpringConstant, float bungeeUnstretchedLength);
	virtual void simulateTimeStep(float deltaT);
	virtual float getFallDistance();
	virtual float getVelocity();
	virtual float getAcceleration();
};
