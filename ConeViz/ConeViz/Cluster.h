#pragma once
class Cluster
{
private:

	//Boundaries of a cluster
	int minFrequency;
	int maxFrequency;



public:
	Cluster(void);
	~Cluster(void);

	Cluster(int minFrequency, int maxFrequency);
	
	//getters
	int getMinFrequency();
	int getMaxFrequency();

	//setters
	void setMinFrequency(int newFrequency);
	void setMaxFrequency(int newFrequency);

};

