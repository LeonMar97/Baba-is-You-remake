#include "Board.h"
#include<array>

Board::Board()
{
	m_background = sf::RectangleShape(sf::Vector2f(MAP_SIZE.y, MAP_SIZE.x) * OBJECT_SIZE);
	m_background.setFillColor(BOARD_COLOR);
	m_background.setOutlineThickness(3);
	m_background.setOutlineColor(sf::Color::Black);
	Word::m_wordAttributes.insert(new PushWord()); //all words can be pushed
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void Board::addGameObj(char character, sf::Vector2u loc){
	BaseObject* baseObj;
	Word* wordObj;
	switch (character)
	{
	case 'B': 
		m_dataHolder.push_back(std::make_unique<DataHolder<Baba>>(std::make_unique<Baba>(loc)));
		m_map.push_back(baseObj);
		
		break;
	case 'R':
		m_dataHolder.push_back(std::make_unique<DataHolder<Rock>>(std::make_unique<Rock>(loc)));
		m_map.push_back(baseObj);
		break;
	case 'K':
		m_dataHolder.push_back(std::make_unique<DataHolder<Wall>>(std::make_unique<Wall>(loc)));
		m_map.push_back(baseObj);
		break;
	case 'F':
		m_dataHolder.push_back(std::make_unique<DataHolder<Flag>>(std::make_unique<Flag>(loc)));
		m_map.push_back(baseObj);
		break;
	case 'G':
		m_dataHolder.push_back(std::make_unique<DataHolder<Skull>>(std::make_unique<Skull>(loc)));
		m_map.push_back(baseObj);
		break;
	case 'M':
		m_dataHolder.push_back(std::make_unique<DataHolder<Water>>(std::make_unique<Water>(loc)));
		m_map.push_back(baseObj);
		break;
	case ' ':
		break;
	case 'i':
		m_dataHolder.push_back(std::make_unique<DataHolder<Is>>(std::make_unique<Is>(loc)));
		m_map.push_back(wordObj);
		break;
	case 'b':
		m_dataHolder.push_back(std::make_unique<DataHolder<BabaWord>>(std::make_unique<BabaWord>(loc)));
		m_map.push_back(wordObj);
		break;
	case 'g':
		m_dataHolder.push_back(std::make_unique<DataHolder<SkullWord>>(std::make_unique<SkullWord>(loc)));
		m_map.push_back(wordObj);
		break;
	case 'k':
		m_dataHolder.push_back(std::make_unique<DataHolder<WallWord>>(std::make_unique<WallWord>(loc)));
		m_map.push_back(wordObj);
		break;
	case 'f':
		m_dataHolder.push_back(std::make_unique<DataHolder<FlagWord>>(std::make_unique<FlagWord>(loc)));
		m_map.push_back(wordObj);
		break;
	case 'r':
		m_dataHolder.push_back(std::make_unique<DataHolder<RockWord>>(std::make_unique<RockWord>(loc)));
		m_map.push_back(wordObj);
		break;
	case 'm':
		m_dataHolder.push_back(std::make_unique<DataHolder<WaterWord>>(std::make_unique<WaterWord>(loc)));
		m_map.push_back(wordObj);
		break;
	case 'y':
		m_dataHolder.push_back(std::make_unique<DataHolder<YouWord>>(std::make_unique<YouWord>(loc)));
		m_map.push_back(wordObj);
		break;
	case 'w':
		m_dataHolder.push_back(std::make_unique<DataHolder<WinWord>>(std::make_unique<WinWord>(loc, *this)));
		m_map.push_back(wordObj);
		break;
	case 'd':
		m_dataHolder.push_back(std::make_unique<DataHolder<DefeatWord>>(std::make_unique<DefeatWord>(loc, *this)));
		m_map.push_back(wordObj);
		break;
	case 'l':
		m_dataHolder.push_back(std::make_unique<DataHolder<SinkWord>>(std::make_unique<SinkWord>(loc, *this)));
		m_map.push_back(wordObj);
		break;
	case 'p':
		m_dataHolder.push_back(std::make_unique<DataHolder<PushWord>>(std::make_unique<PushWord>(loc)));
		m_map.push_back(wordObj);
		break;
	case 's':
		m_dataHolder.push_back(std::make_unique<DataHolder<StopWord>>(std::make_unique<StopWord>(loc)));
		m_map.push_back(wordObj);
		break;
	default:
		throw std::invalid_argument(((std::string(1, character)
						+ " is not a supprorted command, to see supported commands please go to README\n")).data());
		break;
	}
}


void Board::initialize(FileHandler& map) {
	sf::Vector2u loc;
	char currentChar;
	//initializing data map
	for (loc.x = 0; loc.x < MAP_SIZE.x; loc.x++) {
		for (loc.y = 0; loc.y < MAP_SIZE.y; loc.y++) {
			currentChar = map.what_In_Location(loc);
			 addGameObj(currentChar, loc);
		}
	}
	//initializing interaction map
	for (auto& dataHolder : m_dataHolder) {
		m_map.push_back(dataHolder.get()->getPtr());
	}
	lookForRules();
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
			if (obj->triggerAttribute(cur)) {
				checkCollisions(obj);//check collision as a result of current collision handling
				//return; maybe this is not supposed to be here
			}
		}
	}
}

//check for triples of sprites in board using pre-defined functions
void Board::searchTriples(std::vector<baseObjTuple>& vec,
	std::function<float(const sf::Vector2f&)> mainCoordinate, 
	std::function<float(const sf::Vector2f&)> secondaryCoordinate)
	{
	//sort based on main coordinates
	std::sort(m_map.begin(), m_map.end(), [&](BaseObject* baseObj1, BaseObject* baseObj2) {
		return mainCoordinate(baseObj1->returnPos()) < mainCoordinate(baseObj2->returnPos()); });

	//sorting secondary coordinates without changing previous order based on main coordinates
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

				//check if the triple is on same row/col and consecutive cols/ rows accordingly
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
	m_ruleHandler.processCollision(potentialNewRuleVec, *this);
}
void Board::replaceObjects(Noun& toReplace, Noun& toReplaceWith) {
	const auto& replaceWithId = typeid(toReplace);
	for (auto& cur : m_map) {
		//necessary to check because BABA OBJECT needs to be changed to "baba word" first, 
			//then to check wheter it is the same noun for creating the replacement noun- 
				//-representation Object, and replacing the current on board 

		auto curId = cur->wordTypeId();
		if (curId == replaceWithId)
			toReplaceWith.replaceObjInLocation(cur);
	}
}

void Board::setPreviousLocations() {
	for (auto& obj : m_map) {
		obj->setLastLoc();
	}
}

void Board::moveYou(const Direction& dir) {
	std::vector<BaseObject*> whatMoved;
	for (auto& curObj : m_map) {
		auto &attributes = curObj->getStatic();
		for (auto &it : attributes) {
			if (it->move(*curObj, dir)) {
				whatMoved.push_back(curObj);
				break;
			}
		}
	}
	for (auto moved = whatMoved.begin(); moved != whatMoved.end(); moved++)
		for (auto& moved : whatMoved)
			checkCollisions(moved);
}

void Board::removeObject(BaseObject* objToRemove) {
	delete objToRemove;
	m_map.erase(std::find(m_map.begin(), m_map.end(), objToRemove));
}

void Board::endLevel() {
	m_endLevel = true;
}

bool Board::isLvlFinished() {
	return m_endLevel;
}