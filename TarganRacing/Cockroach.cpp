#include "Cockroach.h"
#include "json.hpp"




Cockroach::Cockroach(std::string name, int id, std::string teamName, int amountOfLegs, int experience, int glory):
	name(name),id(id),teamName(teamName),amountOfLegs(amountOfLegs),experience(experience),glory(glory)
{
}

Cockroach::Cockroach(const json& data)
{
	fromJson(data);
}

Cockroach::Cockroach()
{

}

Cockroach::~Cockroach()
{
}

json Cockroach::toJson()
{
	json r;
	r["name"] = name;
	r["id"] = id;
	r["teamName"] = teamName;
	r["amontOfLegs"] = amountOfLegs;
	r["experience"] = experience;
	r["glory"] = glory;
	return r;
}

int Cockroach::calculateSpeed()
{
	const int legsInfluence = 65;
	const int experienceInfluence=35;

	return amountOfLegs*legsInfluence + experience*experienceInfluence;
}

void Cockroach::fromJson(const json& data)
{
	//name = data["name"];
	id = data["id"];
	//teamName = data["teamName"];
	amountOfLegs = data["amountOfLegs"];
	experience = data["experience"];
	glory = data["glory"];
}
