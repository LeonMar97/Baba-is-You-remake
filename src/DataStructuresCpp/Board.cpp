#include "Board.h"
#include<array>

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
	BaseObject* baseObj;
	Word* wordObj;
	switch (p)
	{
	case 'B':
		baseObj = new Baba(loc);
		insert(babas_t, baseObj);
		m_you.push_back(baseObj);
		break;
	case 'R':
		baseObj = new Rock(loc);
		insert(rocks_t, baseObj);
		break;
	case ' ':
		break;
	case 'i':
		wordObj = new Is(loc);
		insert(conjunctions_t, wordObj);
		break;
	case 'b':
		wordObj = new BabaWord(loc);
		insert(nouns_t, wordObj);
		break;
	case 'r':
		wordObj = new RockWord(loc);
		insert(nouns_t, wordObj);
		break;
	case 'y':
		wordObj = new YouWord(loc);
		insert(attributes_t, wordObj);
		break;
	case 'w':
		wordObj = new WinWord(loc);
		insert(attributes_t, wordObj);
		break;
	default:
		throw std::invalid_argument(((std::string(1, p)
						+ " is not a supprorted command, to see supported commands please go to README\n")).data());
		break;
	}
}


void Board::insert(GameObjects gameObj_t, BaseObject* baseObj) {
	try {
		auto &pos = m_dataHolder.at(gameObj_t);
		pos.push_back(baseObj);
	}

	catch(std::out_of_range& e){
		std::vector<BaseObject*> temp = { baseObj };
		auto pos = m_dataHolder.insert(std::pair<GameObjects, std::vector<BaseObject*>>(gameObj_t, temp));
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
	for(auto &[key, vec]:m_dataHolder){
		for(auto &obj:vec)
			obj->draw(game_Window, deltaTime);
	}
}

void Board::checkCollisions(BaseObject* cur) {
	for (auto& [key, vec] : m_dataHolder) {
		for (auto& obj : vec) {
			if (cur->collidesWith(obj) && obj != cur) {
				obj->handleCollision(this, cur);
				checkCollisions(obj);//check collision as a result of current collision handling
				return;
			}
		}
	}
}



void Board::replace(GameObjects objectToAdd, GameObjects objectToRemove, char objectToCreate) {
	for (auto& removeObj : m_dataHolder[objectToRemove]) {
		auto removeObjPos = removeObj->returnPos() / OBJECT_SIZE;
		addGameObj(objectToCreate, sf::Vector2u(removeObjPos.y, removeObjPos.x));
		delete removeObj;
	}
	m_dataHolder[objectToRemove].clear();
}
