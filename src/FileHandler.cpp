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
	
	
	auto cur = std::string();
	for (unsigned int i = 0; i < MAP_SIZE.x; i++) {
		std::getline(m_Cf, cur);
		if (m_Cf.fail()) {
			return false;
		}
		m_fileHandler.push_back(cur);
	}
	return true;
}
//--------------------------------------------------
/*
* returns charector in requestd location
* requestd: location from which to return
*/

char FileHandler::what_In_Location(const sf::Vector2u cur_Loc)const {
	return m_fileHandler[cur_Loc.x][cur_Loc.y];
}
//--------------------------------------------------

//--------------------------------------------------
/*
* loading new map for each lvl
*/
bool FileHandler::rebuild_Map() {
	m_fileHandler.clear();//clrearing the string first then adding new char map
		return set_Map();
}

//--------------------------------------------------


