class fallingObject
{
private:
	float mass;
	float surfaceArea;
	float bungeeSpringConstant;
	float bungeeUnstretchedLength;
	float fallDistance = 0.0f;
	float velocity = 0.0f;
	float acceleration = 0.0f;
	float deltaT;
	float deltaV;
	float deltaD;
	float Ffriction;
	float Fspring;
	float Fweight;
	float Ftotal;
	float g = 9.81f;
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
