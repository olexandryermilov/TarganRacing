#include "Stadium.h"
#include "json.hpp"
#include "Random.h"

using json = nlohmann::json;

Stadium::Stadium()
{

}

Stadium::Stadium(std::string name, int id)
{
	(*this).name = name;
	(*this).id = id;
	qualityCoef = Random::getRandomInteger(100);
	int lengthValues[6] = { 100,200,500,1000,2000,5000 };
	lengthType = Random::getRandomInteger(5);
	length = lengthValues[lengthType];
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

void Stadium::updateQuality()
{
	//todo::change reducing quality
	int delta = 0;
	delta = qualityCoef / 10;
	qualityCoef -= delta;
	printf("Stadium %d: Quality changed from %d to %d\n", id, qualityCoef+delta, qualityCoef);
}

void Stadium::printInfo()
{
	printf("Stadium ");
	std::cout << name;
	printf(": quality is %d, length is %d\n", qualityCoef, length);
}