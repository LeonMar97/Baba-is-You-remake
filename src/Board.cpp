#include "Board.h"


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
		//setting the pointing direction of the vertex represnted by the texture
		break;
	case ' ':
		break;
	case 'i':
		wordObj = new Is(loc);
		insert(is_t, wordObj);
		m_words[CONJUNCTION_VECTOR].push_back(wordObj);
		break;
	case 'b':
		wordObj = new BabaWord(loc);
		insert(babaword_t, wordObj);
		m_words[NOUN_VECTOR].push_back(wordObj);
		break;
	case 'y':
		wordObj = new YouWord(loc);
		insert(youword_t, wordObj);
		m_words[ATTRIBUTE_VECTOR].push_back(wordObj);
		break;
	case 'w':
		wordObj = new WinWord(loc);
		insert(winword_t, wordObj);
		m_words[ATTRIBUTE_VECTOR].push_back(wordObj);
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
	
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void Board::lookForRule() {
	bool youMightHasChanged;
	for (auto n : m_words[NOUN_VECTOR]) {

		dynamic_cast<Noun*>(n);

	}
}
//searchFolowingConjunction