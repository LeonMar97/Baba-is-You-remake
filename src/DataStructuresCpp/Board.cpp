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
		m_map.push_back(baseObj);
		m_you.push_back(baseObj);
		break;
	case 'R':
		baseObj = new Rock(loc);
		m_map.push_back(baseObj);
		break;
	case ' ':
		break;
	case 'i':
		wordObj = new Is(loc);
		m_map.push_back(wordObj);
		break;
	case 'b':
		wordObj = new BabaWord(loc);
		m_map.push_back(wordObj);
		break;
	case 'r':
		wordObj = new RockWord(loc);
		m_map.push_back(wordObj);
		break;
	case 'y':
		wordObj = new YouWord(loc);
		m_map.push_back(wordObj);
		break;
	case 'w':
		wordObj = new WinWord(loc);
		m_map.push_back(wordObj);
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
void Board::drawBoard(sf::RenderWindow& game_Window, sf::Time deltaTime) {
	game_Window.draw(m_background);
	for(auto &obj:m_map){
		obj->draw(game_Window, deltaTime);
	}
}

void Board::checkCollisions(BaseObject* cur) {
	for (auto& obj : m_map) {
		if (cur->collidesWith(obj) && obj != cur) {
			obj->handleCollision(this, cur);
			checkCollisions(obj);//check collision as a result of current collision handling
			return;
		}
	}
}

//check for triples of sprites in board using pre-defined functions to
void Board::searchTriples(std::vector<baseObjTuple>& vec,
	std::function<float(const sf::Vector2f&)> mainCoordinate,
	std::function<float(const sf::Vector2f&)> secondaryCoordinate)
	{
	std::sort(m_map.begin(), m_map.end(), [&](BaseObject* baseObj1, BaseObject* baseObj2) {
		return mainCoordinate(baseObj1->returnPos()) < mainCoordinate(baseObj2->returnPos()); });

	std::stable_sort(m_map.begin(), m_map.end(),
		[&](BaseObject* baseObj1, BaseObject* baseObj2) {
			if (mainCoordinate(baseObj1->returnPos()) == mainCoordinate(baseObj2->returnPos()))
				return secondaryCoordinate(baseObj1->returnPos()) < secondaryCoordinate(baseObj2->returnPos());
			else return mainCoordinate(baseObj2->returnPos()) < mainCoordinate(baseObj2->returnPos()); });

	sf::Vector2f firstPos, secondPos, thirdPos;
	for (auto first = m_map.begin(); first < m_map.end() - 2; first++) {
		firstPos = (*first)->returnPos();
		for (auto second = first; second < m_map.end() - 1; second++) {
			secondPos = (*second)->returnPos();
				//if second coordinate is not on same col/row as first or is farther than 1 unit
			if (mainCoordinate(firstPos) != mainCoordinate(secondPos) || 
				secondaryCoordinate(firstPos) + 1*OBJECT_SIZE < secondaryCoordinate(secondPos)) break;
			for (auto third = second; third < m_map.end(); third++) {
				thirdPos = (*third)->returnPos();

				//if third coordinate is not on same col/row as second or is farther than 1 unit
				if (mainCoordinate(secondPos) != mainCoordinate(thirdPos) ||
					secondaryCoordinate(secondPos) + 1*OBJECT_SIZE < secondaryCoordinate(thirdPos))
					break;

				//check if the triple is on same row and consecutive cols / same col consecutive rows
				if (mainCoordinate(secondPos) - mainCoordinate(firstPos) == 0 &&
					mainCoordinate(thirdPos) - mainCoordinate(firstPos) == 0 &&
					secondaryCoordinate(secondPos) - secondaryCoordinate(firstPos) == OBJECT_SIZE &&
					secondaryCoordinate(thirdPos) - secondaryCoordinate(secondPos) == OBJECT_SIZE){

					vec.emplace_back(baseObjTuple(*first, *second, *third)); //a valid triple is found
				}
			}
		}
	}
}

void Board::lookForRules() {

	auto getXCoordinate = [&](const sf::Vector2f& vec) {return vec.x; };
	auto getYCoordinate = [&](const sf::Vector2f& vec) {return vec.y; };
	auto potentialNewRuleVec = std::vector<baseObjTuple>();
	searchTriples(potentialNewRuleVec, getXCoordinate, getYCoordinate);
	searchTriples(potentialNewRuleVec, getYCoordinate, getXCoordinate);
	//perform stable sort on position of vectors (first x coordinate, then y coordinate)
	m_ruleHandler.processCollision(potentialNewRuleVec, *this);
}

/*
void Board::replace(GameObjects objectToAdd, GameObjects objectToRemove, char objectToCreate) {
	for (auto& removeObj : m_map[objectToRemove]) {
		auto removeObjPos = removeObj->returnPos() / OBJECT_SIZE;
		addGameObj(objectToCreate, sf::Vector2u(removeObjPos.y, removeObjPos.x));
		delete removeObj;
	}
	m_map[objectToRemove].clear();
}
	
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void Board::lookForRules() {
	std::array<Word*, 2>horizontal;
	std::array<Word*, 2>vertical;
	std::vector<ruleTuple> newRules;

	for (auto &cur : m_map[conjunctions_t]) {
		Conjunction* obj = dynamic_cast<Conjunction*>(cur);
		auto conjuntionPos = obj->returnPos();//getting conjunction position
		horizontal.fill(NULL);
		vertical.fill(NULL);
		//this two for's adding potenitial rules around current conjunction into the vectors
		for (auto& curNoun : m_map[nouns_t]) {
			enterInVec(conjuntionPos, dynamic_cast<Word*>(curNoun), vertical, horizontal);
		}
		for (auto& curAtr : m_map[attributes_t]) {
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
	for (auto& newRule : newRules) {
		std::get<2>(newRule).putRuleIntoAffect(std::get<0>(newRule), *this);
	}
}
*/

/* <summary>
gets two empty array which represnt the current conjunction area,
and sets the objects arround him regarding only words.
we are making it this way to save 6 loops, even though it looks ugly, its usful.
 </summary>
 
 <param name="curObj"> current suspisious object, might be arround the conjunction</param>
 <param name="horizontal">vector for horizontal rule </param>
 <param name=""></param>
*/
/*
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

*/
