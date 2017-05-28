#pragma once
#include "json.hpp"
#include "Stadium.h"

using json = nlohmann::json;

class Cockroach
{
public:
	Cockroach(std::string name, int id, std::string teamName);
	Cockroach(const json& data);
	Cockroach(std::string name, int id, std::string teamName, int amountOfLegs, int experience, int glory);
	Cockroach();
	~Cockroach();
	json toJson();
	int calculateSpeed(Stadium stadium);
	void updateExperience(const int place, Stadium stadium);
	void updateLegs(Stadium stadium);
	void update(const int place, Stadium stadium);
	void printInfo();
	static const int maxLegs = 10;
	static int minExp;
	static int maxExp;
	//getters start here
	std::string getName() const { return name; }
	int getId()const { return id; }
	std::string getTeamName()const { return teamName; }
	int getAmountOfLegs()const { return amountOfLegs; }
	int getGlory()const { return glory; }
	int getExperience()const { return experience; }

private:
	std::string name;//shows cockroach name
	int id;
	std::string teamName;
	int amountOfLegs;//more legs - better speed, between 0 and 10
	int experience;//more exp - better speed, 
	int glory;//more glory - less coefs in betcompany, more gamblers will put money on it,
			  //between 0 and 175, includes 3 last racings, 100+50+25 
	void fromJson(const json& data);
};

