#include <iostream>
#include <string>
#include <vector>
#include "fallingObject.h"
#include <fstream>

using namespace std;

void simulateBungeeJump(){
	fallingObject FallingObject(70.0f, 0.2f, 21.7f, 30.0f);
	ofstream out("Wu_Tony_100558100_Asmt2_simulation.txt");

	vector<float> elapsedTimes;
	vector<float> distances;
	vector<float> velocities;
	vector<float> accelerations;

	elapsedTimes.push_back(0.0f);
	distances.push_back(FallingObject.getFallDistance());
	velocities.push_back(FallingObject.getVelocity());
	accelerations.push_back(FallingObject.getAcceleration());

	float simulationTime = 10; // 60 seconds
	float deltaT = 0.001;       // 0.01 seconds
	int timeSteps = (int)(simulationTime / deltaT);

	for (unsigned int t = 1; t < timeSteps; t++) {
		FallingObject.simulateTimeStep(deltaT);
		elapsedTimes.push_back(t * deltaT);
		distances.push_back(FallingObject.getFallDistance());
		velocities.push_back(FallingObject.getVelocity());
		accelerations.push_back(FallingObject.getAcceleration());
	}

	for (unsigned int i = 0; i < timeSteps; i++){
		out << elapsedTimes[i] << " " << distances[i] << " " << velocities[i] << " " << accelerations[i] << endl;
	}
}

int main(){
	simulateBungeeJump();
	return 0;
}
