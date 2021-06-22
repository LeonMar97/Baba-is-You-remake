#include "FileHandler.h"
#include<stdlib.h>
//--------------------------------------------------
/*
distractor closing file.
*/
FileHandler::~FileHandler() {
	file_close();
}
//--------------------------------------------------

//-
/*
closing the txt file being open while the
progrem runs.
*/
void FileHandler::file_close() {
	(m_Cf).close();
}
//--------------------------------------------------

/*
constractor defult for game board
m_cf:file pointer.
*/
FileHandler::FileHandler()
{
	m_Cf.open("map.txt");
	if (!m_Cf.is_open()) {
		throw std::exception();
	}
	
	set_Map();

}
//--------------------------------------------------

//--------------------------------------------------
/*
*set the map
* m_board : the vector for the map.
* cur:local var for each string .
*/
bool FileHandler::set_Map() {
	std::string temp;
	level m_fileHandler;
	
	
	auto cur = std::string();
	for (unsigned int i = 0; i < MAP_SIZE.x; i++) {
		std::getline(m_Cf, cur);
		if (m_Cf.fail()) {
			return false;
		}
		m_fileHandler.push_back(cur);
	}
	m_levels.push_back(m_fileHandler);
	return true;
}
//--------------------------------------------------
/*
* returns charector in requestd location
* requestd: location from which to return
*/

char FileHandler::what_In_Location(const unsigned int& mapNum,const sf::Vector2u cur_Loc)const {
	return m_levels[mapNum][cur_Loc.x][cur_Loc.y];
}
//--------------------------------------------------

//--------------------------------------------------
/*
* loading new map for each lvl
*/
bool FileHandler::rebuild_Map() {
	
		return set_Map();
}

//--------------------------------------------------

bool FileHandler::mapAlreadyBuilt(unsigned int mapNum) {
	return (m_levels.size() > mapNum);
}

unsigned int FileHandler::numOfLevels() const {
	return m_levels.size();
}