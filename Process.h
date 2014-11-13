class Process {
private:
	float duration;
	float startTime;
	float requiredEndTime;
public:
	virtual float getDuration();
	virtual float getStartTime();
	virtual float getRequiredEndTime();
	Process(float duration, float requiredEndTime);
	virtual float startTime(); //?
};
