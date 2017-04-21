#pragma once
#include "json.hpp"
#include <string>

using json = nlohmann::json;
class Stadium
{
public:
	Stadium();
	Stadium(std::string name, int id);
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
	int qualityCoef;//between 0 and 100
	int length;//possible values: 100,200,500,1000,2000,5000
	//std::string weatherType;
	void fromJson(const json& data);
};

