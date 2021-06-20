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
	std::shared_ptr<BaseObject> baseObj;
	std::unique_ptr<DataHolder> dataholder;
	switch (character)
	{
	case 'B': 
		baseObj = std::make_shared<Baba>(loc);
		m_dataHolder.emplace_back(std::make_unique<DataHolder>(baseObj));
		m_map.push_back(baseObj);
		break;
	case 'R':
		baseObj = std::make_shared<Rock>(loc);
		m_dataHolder.emplace_back(std::make_unique<DataHolder>(baseObj));
		m_map.push_back(baseObj);
		break;
	case 'K':
		baseObj = std::make_shared<Wall>(loc);
		m_dataHolder.emplace_back(std::make_unique<DataHolder>(baseObj));
		m_map.push_back(baseObj);
		break;
	case 'F':
		baseObj = std::make_shared<Flag>(loc);
		m_dataHolder.emplace_back(std::make_unique<DataHolder>(baseObj));
		m_map.push_back(baseObj);
		break;
	case 'G':
		baseObj = std::make_shared<Skull>(loc);
		m_dataHolder.emplace_back(std::make_unique<DataHolder>(baseObj));
		m_map.push_back(baseObj);
		break;
	case 'M':
		baseObj = std::make_shared<Water>(loc);
		m_dataHolder.emplace_back(std::make_unique<DataHolder>(baseObj));
		m_map.push_back(baseObj);
		break;
	case ' ':
		break;
	case 'i':
		baseObj = std::make_shared<Is>(loc);
		m_dataHolder.emplace_back(std::make_unique<DataHolder>(baseObj));
		m_map.push_back(baseObj);
		break;
	case 'b':
		baseObj = std::make_shared<BabaWord>(loc);
		m_dataHolder.emplace_back(std::make_unique<DataHolder>(baseObj));
		m_map.push_back(baseObj);
		break;
	case 'g':
		baseObj = std::make_shared<SkullWord>(loc);
		m_dataHolder.emplace_back(std::make_unique<DataHolder>(baseObj));
		m_map.push_back(baseObj);
		break;
	case 'k':
		baseObj = std::make_shared<WallWord>(loc);
		m_dataHolder.emplace_back(std::make_unique<DataHolder>(baseObj));
		m_map.push_back(baseObj);
		break;
	case 'f':
		baseObj = std::make_shared<FlagWord>(loc);
		m_dataHolder.emplace_back(std::make_unique<DataHolder>(baseObj));
		m_map.push_back(baseObj);
		break;
	case 'r':
		baseObj = std::make_shared<RockWord>(loc);
		m_dataHolder.emplace_back(std::make_unique<DataHolder>(baseObj));
		m_map.push_back(baseObj);
		break;
	case 'm':
		baseObj = std::make_shared<WaterWord>(loc);
		m_dataHolder.emplace_back(std::make_unique<DataHolder>(baseObj));
		m_map.push_back(baseObj);
		break;
	case 'y':
		baseObj = std::make_shared<YouWord>(loc);
		m_dataHolder.emplace_back(std::make_unique<DataHolder>(baseObj));
		m_map.push_back(baseObj);
		break;
	case 'w':
		baseObj = std::make_shared<WinWord>(loc, *this);
		m_dataHolder.emplace_back(std::make_unique<DataHolder>(baseObj));
		m_map.push_back(baseObj);
		break;
	case 'd':
		baseObj = std::make_shared<DefeatWord>(loc, *this);
		m_dataHolder.emplace_back(std::make_unique<DataHolder>(baseObj));
		m_map.push_back(baseObj);
		break;
	case 'l':
		baseObj = std::make_shared<SinkWord>(loc, *this);
		m_dataHolder.emplace_back(std::make_unique<DataHolder>(baseObj));
		m_map.push_back(baseObj);
		break;
	case 'p':
		baseObj = std::make_shared<PushWord>(loc);
		m_dataHolder.emplace_back(std::make_unique<DataHolder>(baseObj));
		m_map.push_back(baseObj);
		break;
	case 's':
		baseObj = std::make_shared<StopWord>(loc);
		m_dataHolder.emplace_back(std::make_unique<DataHolder>(baseObj));
		m_map.push_back(baseObj);
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
	for (loc.x = 0; loc.x < MAP_SIZE.x; loc.x++) {
		for (loc.y = 0; loc.y < MAP_SIZE.y; loc.y++) {
			currentChar = map.what_In_Location(loc);
			auto p = Factory::create(currentChar, loc, *this);
			if (p.second && p.first) {
				m_dataHolder.push_back(std::move(p.second));
				m_map.push_back(std::move(p.first));
			}
			 //addGameObj(currentChar, loc);
		}
	}
	lookForRules(); //immediately detect rules and put them into play
}

//drawing the board on requested screen..
void Board::drawBoard(sf::RenderWindow& game_Window, sf::Time deltaTime) {
	sortTextures();
	game_Window.draw(m_background);
	for(auto &obj:m_map){
		obj->draw(game_Window, deltaTime);
	}
}

void Board::checkCollisions(BaseObject* cur) {
	for(auto it = m_map.begin(); it < m_map.end(); it++){
		if (cur->collidesWith(it->get()) && it->get() != cur) {
			if (it->get()->triggerAttribute(cur)) {
				checkCollisions(it->get());//check collision as a result of current collision handling
				//return; maybe this is not supposed to be here
			}
		}
	}
}

//check for triples of sprites in board using pre-defined functions
//Algorithm: sort the map by locations of x/y values, and then by y/x values accordingly
//using stable sort. Using the correct equivalnce functions, the vector is sorted by both coordinates
//which one of them is the primary one and the other one is the secondary one.

//horizontal rules are found by using Y as main coordinate and X as secondary
//Vertical rules are found by using X as main coordinate and Y as secondary

void Board::searchTriples(std::vector<baseObjTuple>& vec,
	std::function<float(const sf::Vector2f&)> mainCoordinate, //lambda function
	std::function<float(const sf::Vector2f&)> secondaryCoordinate)
	{
	//sort based on main coordinates
	std::sort(m_map.begin(), m_map.end(), [&](const std::shared_ptr<BaseObject>& baseObj1, const std::shared_ptr<BaseObject>& baseObj2) {
		return mainCoordinate(baseObj1->returnPos()) < mainCoordinate(baseObj2->returnPos()); });

	//sorting secondary coordinates without changing previous order based on main coordinates
	std::stable_sort(m_map.begin(), m_map.end(),
		[&](const std::shared_ptr<BaseObject>& baseObj1, const std::shared_ptr<BaseObject>& baseObj2) {
			if (mainCoordinate(baseObj1->returnPos()) == mainCoordinate(baseObj2->returnPos()))
				return secondaryCoordinate(baseObj1->returnPos()) < secondaryCoordinate(baseObj2->returnPos());
			else return mainCoordinate(baseObj2->returnPos()) < mainCoordinate(baseObj2->returnPos()); });

	sf::Vector2f firstPos, secondPos, thirdPos; //readability
	BaseObject* firstPtr, *secondPtr, *thirdPtr;
	for (auto first = m_map.begin(); first < m_map.end() - 2; first++) {
		firstPos = (*first)->returnPos();
		firstPtr = (*first).get();
		for (auto second = first; second < m_map.end() - 1; second++) {
			secondPos = (*second)->returnPos();
			secondPtr = (*second).get();
				//if second coordinate is not on same col/row as first or is farther than 1 unit
			if (mainCoordinate(firstPos) != mainCoordinate(secondPos) || 
				secondaryCoordinate(firstPos) + 1*OBJECT_SIZE < secondaryCoordinate(secondPos)) break;
			for (auto third = second; third < m_map.end(); third++) {
				thirdPtr = (*third).get();
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

					vec.emplace_back(baseObjTuple(firstPtr, secondPtr, thirdPtr)); //a valid triple is found
				}
			}
		}
	}
}

void Board::lookForRules() {
	//lambda functions are needed for extraction of valuable coordinates
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
		if (curId == replaceWithId) {
			//can send directly to function below, but need to record action in 
			toReplaceWith.replaceObjInLocation(cur, *this);
		}
	}
}

void Board::replaceObjectWith(std::shared_ptr<BaseObject>& replacedObject, std::shared_ptr<BaseObject>& replacingObject) {
	auto replacingPos = std::find(m_map.begin(), m_map.end(), replacedObject);
	(*replacingPos)->replaceDataHolderPtr(replacingObject);
	(*replacingPos) = replacingObject;
}

void Board::setDefaultOperation() {
	for (auto& dataHolder : m_dataHolder) {
		dataHolder->execute(new NoOperation());
	}
}

void Board::undoAllObjects() {
	for (auto& obj : m_dataHolder) {
		obj->undo();
	}
}

void Board::moveYou(const Direction& dir) {
	m_whatMoved.clear();
	
	for (auto& curObj : m_map) {
		auto& attributes = curObj->getStatic();
		for (auto& it : attributes) {
			if (it->move(*curObj, dir)) {
				m_whatMoved.push_back(curObj);
				break;
			}
		}
	}
	for (auto& moved : m_whatMoved)
		checkCollisions(moved.get());
	
	
}
//sorting the textures so the object which moved will appear on top of everything
void Board:: sortTextures() {
	for (auto &moved : m_whatMoved) {
		auto temp = moved;
		auto cur = std::find(m_map.begin(), m_map.end(), moved);
		if (cur != m_map.end()) {//making sure the object didnt die in middle of game and no appeared on map 
			m_map.erase(std::find(m_map.begin(), m_map.end(), moved));
			m_map.push_back(temp);
		}
	}
}

void Board::removeObject(const std::shared_ptr<BaseObject>& objToRemove) {
	std::experimental::erase_if(m_map, 
		[&](const std::shared_ptr<BaseObject>& baseObj) {return baseObj == objToRemove; });
}

void Board::addObject(const std::shared_ptr<BaseObject>& objToAdd) {
	m_map.push_back(std::shared_ptr<BaseObject>(objToAdd));
}

void Board::endLevel() {
	m_endLevel = true;
}

bool Board::isLvlFinished() {
	return m_endLevel;
}

void Board::restartBoard() {
	for (auto& dataholder : m_dataHolder)
		while (dataholder->undo()); //empty all histories
}		