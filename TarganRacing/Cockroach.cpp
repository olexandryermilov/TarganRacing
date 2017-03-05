#include "Cockroach.h"
#include "json.hpp"




Cockroach::Cockroach(std::string name, int id, std::string teamName, int amountOfLegs, int experience, int glory):
	name(name),id(id),teamName(teamName),amountOfLegs(amountOfLegs),experience(experience),glory(glory)
{
}

Cockroach::Cockroach(const json& data)
{
	*this=fromJson(data);
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

Cockroach Cockroach::fromJson(const json& data)
{
	Cockroach c = new Cockroach();
	//c.name = data["name"];
	c.id = data["id"];
	//c.teamName = data["teamName"];
	c.amountOfLegs = data["amountOfLegs"];
	c.experience = data["experience"];
	c.glory = data["glory"];
	return c;
}
