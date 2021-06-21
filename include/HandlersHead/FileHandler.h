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


	bool set_Map();	//sets the map on vector returns false if failed
	char what_In_Location(const sf::Vector2u cur_Loc)const;// reuturns elemnt on board 
	bool rebuild_Map();

	//--------------private--------functions-----------------------//
private:
	void file_close();


	//------------------members-----------------------//
private:
	
	level m_fileHandler;
	std::ifstream m_Cf;
	int m_Time;
};