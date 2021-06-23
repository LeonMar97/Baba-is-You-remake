#pragma once
#include "FileHandler.h"
#include "Factory.h"
#include "BaseObject.h"
#include <functional>
#include <experimental/vector>
#include "Resources.h"
#include "Direction.h"
#include "DataHolder.h"
#include "RuleHandling.h"
#include "NoOperation.h"
#include "PropertyPush.h"
#include <utility>
class Board{
	//--------------public--------functions-----------------------//
public:
	Board();
	void drawBoard(sf::RenderWindow& game_Window, sf::Time deltaTime);

	//prevents mutating and iterating on a vector simultenously and causing exceptions and problems
	void eraseObjects(); //removes all objects that need to be erased in one place

	void initialize(FileHandler &map);
	void initialize(const unsigned int &mapNum,const FileHandler &map);
	bool isLvlFinished();
	void checkCollisions(BaseObject*);
	void lookForRules();
	void replaceObjects(Noun& toReplace, Noun& toReplaceWith);
	void moveYou(const Direction& dir);
	void endLevel();
	void removeObject(const std::shared_ptr<BaseObject>&);
	void addObject(const std::shared_ptr<BaseObject>&);
	void replaceObjectWith(std::shared_ptr<BaseObject>& replacedObject, std::shared_ptr<BaseObject>& replacingObject);
	void undoAllObjects();
	void restartBoard();
	//set all objects to do nothing
	//is needed because the interaction map only takes into account objects on board
	//and disregards ones that are dead
	//other operations are overwritten if needed
	void setDefaultOperation(); //set all objects to do nothing, override with other operations if needed
	//--------------private--------members-----------------------//
private:
	std::vector<std::unique_ptr<DataHolder>> m_dataHolder; //all data will be stored here
	std::vector<std::shared_ptr<BaseObject>> m_map; //all interactions will be done here
	std::vector<std::shared_ptr<BaseObject>> m_whatMoved;
	std::vector<std::shared_ptr<BaseObject>> m_whatToErase;

	RuleHandling m_ruleHandler;
	
	sf::RectangleShape m_background;
	bool m_endLevel = false;
	void sortTextures();

	//--------------private--------functions-----------------------//
	//void enterInVec(sf::Vector2f conPos, Word* curObj, std::array<Word*, 2>& vertical, std::array<Word*, 2>& horizontal);
	void searchTriples(std::vector<baseObjTuple>& vec,
		std::function<float(const sf::Vector2f&)> mainCoordinate,
		std::function<float(const sf::Vector2f&)> secondaryCoordinate);
};
