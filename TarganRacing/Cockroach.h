#pragma once
#include "json.hpp"

using json = nlohmann::json;

class Cockroach
{
public:
	Cockroach();
	Cockroach(const json& data);
	Cockroach(std::string name, int id, std::string teamName, int amountOfLegs, int experience, int glory);
	~Cockroach();
	json toJson();
	int calculateSpeed(/*smth about weather, length of stadium,quality of stadium and other parameters that will influence speed*/);
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
	int amountOfLegs;//more legs - better speed
	int experience;//more exp - better speed
	int glory;//more glory - less coefs in betcompanys, more gamblers will put money on it
	void fromJson(const json& data);
	//smth about weather?
};

