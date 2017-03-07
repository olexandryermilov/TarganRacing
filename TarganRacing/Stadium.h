#pragma once
#include "json.hpp"
#include <string>

using json = nlohmann::json;
class Stadium
{
public:
	Stadium();
	Stadium(const json& data);
	Stadium(std::string name, int id, int qualityCoef, int length/*,std::string weatherType*/);
	~Stadium();
	std::string getName() const { return name; }
	int getId() const { return id; }
	int getQuality() const { return qualityCoef; }
	int getLength() const { return length; }
	json toJson();
	//std::string getWeather() const { return weatherType; }
private:
	std::string name;
	int id;
	int qualityCoef;
	int length;
	//std::string weatherType;
	void fromJson(const json& data);
};

