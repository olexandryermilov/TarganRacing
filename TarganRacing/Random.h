#pragma once
class Random
{
public:
	Random();
	~Random();
	static double getRandomDouble();//returns random number between 0.000000 and 1.0
	static int getRandomInteger(int bound);//return random number in [0,bound], maximum possible is 1073676289S;
};

