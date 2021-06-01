#include <cstdlib>
#include "Board.h"
#include "Textures.h"
#include "Baba.h"


Board::Board()
{
	m_map.resize(MAP_SIZE.x);
	for (unsigned int i = 0; i < MAP_SIZE.x;i++) {
		m_map[i].resize(MAP_SIZE.y);
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void Board::addGameObj(char p,sf::Vector2u loc){
	switch (p)
	{
	case 'B':
		m_map[loc.x][loc.y].addObj(&Baba::instance());
		//setting the pointing direction of the vertex represnted by the texture
		break;

	default:
		throw std::invalid_argument(((std::string(1, p)
						+ " is not a supprorted command, to see supported commands please go to README\n")).data());
		break;
	}
	
}

void Board::initialize(FileHandler& map) {
	sf::Vector2u loc;
	BaseObject* baseobj;

	
	char currentChar;

	for (loc.x = 0; loc.x < MAP_SIZE.x; loc.x++) {
		for (loc.y = 0; loc.y < MAP_SIZE.y; loc.y++) {
			currentChar = map.what_In_Location(loc);
			 addGameObj(currentChar, loc);
		}
	}

}

//drawing the board on requested screen..
void Board::drawBoard(sf::RenderWindow& game_Window, float deltaTime) {
	for (unsigned int i = 0; i < MAP_SIZE.x; i++) {
		for (unsigned int j = 0; j < MAP_SIZE.y; j++) {
			m_map[i][j].drawObj(game_Window, deltaTime);
		}
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
