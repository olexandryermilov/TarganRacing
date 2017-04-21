#include "Stadium.h"
#include "json.hpp"
#include "Random.h"

using json = nlohmann::json;

Stadium::Stadium()
{

}

Stadium::Stadium(std::string name, int id)
{
	Random random;
	(*this).name = name;
	(*this).id = id;
	qualityCoef = random.getRandomInteger(100);
	int lengthValues[6] = { 100,200,500,1000,2000,5000 };
	length = lengthValues[random.getRandomInteger(5)];
}

Stadium::Stadium(std::string name, int id, int qualityCoef, int length/*,std::string weatherType*/) :
	name(name), id(id), qualityCoef(qualityCoef), length(length) {}

Stadium::Stadium(const json& data)
{
	fromJson(data);
}

Stadium::~Stadium()
{
}

json Stadium::toJson()
{
	json r;
	r["name"] = name;
	r["id"] = id;
	r["qualityCoef"] = qualityCoef;
	r["length"] = length;
	return r;
}

void Stadium::fromJson(const json& data)
{
	//name = data["name"];
	id = data["id"];
	qualityCoef = data["qualityCoef"];
	length = data["length"];
	return;
}

void updateQuality()
{
	//todo:: reduce quality 
}