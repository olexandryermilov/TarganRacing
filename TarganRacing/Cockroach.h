#pragma once
#include "json.hpp"

using json = nlohmann::json;

class Cockroach
{
public:
	Cockroach(std::string name, int id, std::string teamName);
	Cockroach(const json& data);
	Cockroach(std::string name, int id, std::string teamName, int amountOfLegs, int experience, int glory);
	~Cockroach();
	json toJson();
	int calculateSpeed(/*smth about weather, length of stadium,quality of stadium and other parameters that will influence speed*/);
	void updateExperience(const int place, const int length, const int quality);
	void updateLegs(const int quality, const int length);
	//getters start here
	std::string getName() const { return name; }
	int getId()const { return id; }
	std::string getTeamName()const { return teamName; }
	int getAmountOfLegs()const { return amountOfLegs; }
	int getGlory()const { return glory; }

private:
	std::string name;//shows cockroach name
	int id;
	std::string teamName;
	int amountOfLegs;//more legs - better speed, between 0 and 10
	int experience;//more exp - better speed, 
	int glory;//more glory - less coefs in betcompanys, more gamblers will put money on it,
			  //between 0 and 175, includes 3 last racings, 100+50+25 
	void fromJson(const json& data);
	//smth about weather?
};

