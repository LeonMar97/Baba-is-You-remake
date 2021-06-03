#include <cstdlib>
#include "Board.h"
#include "Textures.h"
#include "Baba.h"
#include "Is.h"
#include "BabaWord.h"
#include "YouWord.h"


Board::Board()
{
	for (auto i = 0; i < MAP_SIZE.x; i++) {
		m_map.push_back(std::vector<std::vector<BaseObject*>>());
		for (auto j = 0; j < MAP_SIZE.y; j++) {
			m_map[i].push_back(std::vector<BaseObject*>());
		}
	}
	//m_you = std::make_unique<Baba>();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void Board::addGameObj(char p, sf::Vector2u loc){
	switch (p)
	{
	case 'B':
		m_map[loc.x][loc.y].push_back(new Baba(loc));
		//setting the pointing direction of the vertex represnted by the texture
		break;
	case ' ':
		break;
	case 'i':
		m_map[loc.x][loc.y].push_back(new Is(loc));

		break;
	case 'b':
		m_map[loc.x][loc.y].push_back(new BabaWord(loc));

		break;
	case 'y':
		m_map[loc.x][loc.y].push_back(new YouWord(loc));

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
			if (!m_map[i][j].empty())
			m_map[i][j].front()->draw(game_Window, deltaTime);
		}
	}
}

/*
void Board::move(const sf::Vector2i& dir) {
	for (auto itRow = m_map.begin(); itRow < m_map.end(); itRow++) {
		for (auto itCol = itRow->begin(); itCol < itRow->end(); itCol++) {
			if (!itCol->empty()) {
				if (itCol->front()->move(this, m_you.get(), dir)) {
					auto temp = itCol->front();
					itCol->pop_front();
					(itCol + 1)->push_back(temp);
					break;
				}
			}
		}
	}
}
*/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
