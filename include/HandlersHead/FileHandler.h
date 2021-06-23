#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "Macros.h"
typedef std::vector<std::string>level;
class FileHandler{
	//--------------public--------functions-----------------------//
public:
	FileHandler();
	~FileHandler();

	bool mapAlreadyBuilt(unsigned int mapNum);
	
	bool set_Map();	//sets the map on vector returns false if failed
	char what_In_Location(const unsigned int& mapNum, const sf::Vector2u cur_Loc)const;// reuturns elemnt on board 
	bool rebuild_Map();

	unsigned int numOfLevels() const;
	
	//--------------private--------functions-----------------------//
private:
	void file_close();


	//------------------members-----------------------//
private:
	std::vector<level>m_levels;
	std::ifstream m_Cf;
	
};