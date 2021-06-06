#include <cstdlib>
#include "Board.h"
#include "Textures.h"
#include "Baba.h"
#include "Is.h"
#include "BabaWord.h"
#include "YouWord.h"
#include "WinWord.h"


Board::Board(std::vector<BaseObject*>& you)
	: m_you(you)
{
	m_background = sf::RectangleShape(sf::Vector2f(MAP_SIZE.y, MAP_SIZE.x) * OBJECT_SIZE);
	m_background.setFillColor(BOARD_COLOR);
	m_background.setOutlineThickness(3);
	m_background.setOutlineColor(sf::Color::Black);

	//m_you = std::make_unique<Baba>();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void Board::addGameObj(char p, sf::Vector2u loc){
	BaseObject* a;
	switch (p)
	{
	case 'B':
		a = new Baba(loc);
		m_map.push_back(a);
		m_you.push_back(a);
		//setting the pointing direction of the vertex represnted by the texture
		break;
	case ' ':
		break;
	case 'i':
		m_map.push_back(new Is(loc));
		break;
	case 'b':
		m_map.push_back(new BabaWord(loc));
		break;
	case 'y':
		m_map.push_back(new YouWord(loc));
		break;
	case 'w':
		m_map.push_back(new WinWord(loc));

		break;
	default:
		throw std::invalid_argument(((std::string(1, p)
						+ " is not a supprorted command, to see supported commands please go to README\n")).data());
		break;
	}
}

void Board::initialize(FileHandler& map) {
	sf::Vector2u loc;
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
	game_Window.draw(m_background);
	for(auto &obj:m_map){
			obj->draw(game_Window, deltaTime);
		}
}

//checking collision with every pair of objects in map. if collision found, the correct handling
//for this collision is executed, and then re-check for another collision as a result of previous handling
/*
void Board::checkCollisions() {
	for (auto obj1 = m_you.begin(); obj1 != m_you.end(); obj1++) {
		for (auto obj2 = obj1+1; obj2 != m_map.end(); obj2++) {
			if (obj1->collidesWith(obj2)) {
				obj1->handleCollision(*this, obj2);
				checkCollisions(obj2); //check collision as a result of current collision handling
				return;
			}
		}
	}
}
*/

void Board::checkCollisions(BaseObject* cur) {
	for (auto obj = m_map.begin(); obj != m_map.end(); obj++) {
		if (cur->collidesWith(*obj) && *obj != cur) {
			(*obj)->handleCollision(this, cur);
			checkCollisions(*obj); //check collision as a result of current collision handling
			return;
		}
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
