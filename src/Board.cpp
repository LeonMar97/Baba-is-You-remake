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
		//setting the pointing direction of the vertex represnted by the texture
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
	
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void Board::lookForRules() {
	std::array<Word*, 2>horizontal;
	std::array<Word*, 2>vertical;
	std::vector<ruleTuple> newRules;

	for (auto &cur : m_dataHolder[conjunctions_t]) {
		Conjunction* obj = dynamic_cast<Conjunction*>(cur);
		auto conjuntionPos = obj->returnPos();//getting conjunction position
		horizontal.fill(NULL);
		vertical.fill(NULL);
		//this two for's adding potenitial rules around current conjunction into the vectors
		for (auto& curNoun : m_dataHolder[nouns_t]) {
			enterInVec(conjuntionPos, dynamic_cast<Word*>(curNoun), vertical, horizontal);
		}
		for (auto& curAtr : m_dataHolder[attributes_t]) {
			enterInVec(conjuntionPos, dynamic_cast<Word*>(curAtr), vertical, horizontal);
		}
		createRule(*obj, vertical, newRules);
		createRule(*obj, horizontal, newRules);

		updateRules(newRules);


	}
}

void Board::createRule(Conjunction& c, std::array<Word*, 2>& potentialRule, std::vector<ruleTuple>& m_currentRules) {
	Noun* ptrNoun;
	Word* ptrWord;
	if ((ptrNoun = dynamic_cast <Noun*>(potentialRule[0])) != NULL) {//first we check if the first is noun
		//then we check if the second is atribute or noun
		if ((ptrWord = dynamic_cast <Noun*>(potentialRule[1])) != NULL || (ptrWord = dynamic_cast <Attribute*>(potentialRule[1])) != NULL) {
			ruleTuple(*ptrNoun, c, *ptrWord);
			m_currentRules.push_back(ruleTuple(*ptrNoun, c, *ptrWord));
		}
		return;
	}
}

/// <summary>
/// creating a temporary new rule set and updates the current rule set dynamically
/// </summary>
/// <param name="newRules"></param>
void Board::updateRules(std::vector<ruleTuple>& newRules) {
	bool ruleAlreadyExists = false;
	for (auto ruleIndex = 0; ruleIndex < m_Rules.size(); ruleIndex++) {
		for (auto newRuleIndex = 0; newRuleIndex < newRules.size(); newRuleIndex++) {
			if (m_Rules[ruleIndex] == newRules[newRuleIndex]) {
				newRules.erase(newRules.begin() + newRuleIndex); //remove new rule because it already exists
				ruleAlreadyExists = true;
				break;
			}
		}
		if (!ruleAlreadyExists) {
			if (auto atrPtr = dynamic_cast<Attribute*>(&(std::get<2>(m_Rules[ruleIndex])))){
				std::get<0>(m_Rules[ruleIndex]).removeAttributes(atrPtr);
				m_Rules.erase(m_Rules.begin() + ruleIndex); //remove old rule because it is no longer on map
			}
		}
	}
	//triggerRules(newRules);
}

/*
void Board::triggerRules(std::vector<ruleTuple>& newRules) {
	for (auto& newRule : newRules) {
		std::get<0>(newRule).triggerRule(std::get<2>(newRule));
	}kk
}*/
/* <summary>
gets two empty array which represnt the current conjunction area,
and sets the objects arround him regarding only words.
we are making it this way to save 6 loops, even though it looks ugly, its usful.
 </summary>
 
 <param name="curObj"> current suspisious object, might be arround the conjunction</param>
 <param name="horizontal">vector for horizontal rule </param>
 <param name=""></param>
*/
void Board::enterInVec(sf::Vector2f conPos,Word * curObj, std::array<Word*,2>&vertical, std::array<Word*,2>&horizontal) {
	auto pos = curObj->returnPos();
	
	if (pos.x - conPos.x == OBJECT_SIZE && pos.y == conPos.y) { //obj on the right
		horizontal[1] = curObj;
	}
	else if (pos.x - conPos.x == -OBJECT_SIZE && pos.y == conPos.y) { //obj on the left
		horizontal[0] = curObj;
	}
	else if (pos.x == conPos.x  && pos.y -conPos.y==-OBJECT_SIZE) { //obj abbove
		vertical[0] = curObj;
	}
	else if (pos.x == conPos.x && pos.y - conPos.y == OBJECT_SIZE) { //obj bellow
		vertical[1] = curObj;
	}
	else {//the  object isnt in the area of the conjunction
		return;
	}
	
}

