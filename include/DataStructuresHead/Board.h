#pragma once
#include"FileHandler.h"
#include "BaseObject.h"
#include <experimental/vector>
#include <functional>
#include"Word.h"
#include <cstdlib>
#include "Resources.h"
#include "Direction.h"
#include "Baba.h"
#include "BabaWord.h"
#include "Is.h"
#include "Wall.h"
#include "WallWord.h"
#include "Rock.h"
#include "RockWord.h"
#include "Water.h"
#include "WaterWord.h"
#include "Flag.h"
#include "FlagWord.h"
#include "SkullWord.h"
#include "Skull.h"
#include "WinWord.h"
#include "StopWord.h"
#include "PushWord.h"
#include "YouWord.h"
#include "DefeatWord.h"
#include "SinkWord.h"
#include"DataHolder.h"
#include "RuleHandling.h"
#include "NoOperation.h"
class Board{
	//--------------public--------functions-----------------------//
public:
	void drawBoard(sf::RenderWindow& game_Window, sf::Time deltaTime);
	Board();
	void initialize(FileHandler &map);
	bool isLvlFinished();
	
	void addGameObj(char p, sf::Vector2u loc);

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
	//void isLevelOver();
	/*
	void insert(GameObjects, BaseObject*);
	void createRule(Conjunction& c, std::array<Word*, 2>& potentialRule, std::vector<ruleTuple>& m_currentRules);
	void lookForRules();
	void replace(GameObjects objectToAdd, GameObjects objectToRemove, char objectToCreate);
	*/
	//--------------private--------members-----------------------//
private:
	//std::vector<ruleTuple> m_Rules;

	std::vector<std::unique_ptr<DataHolder>> m_dataHolder; //all data will be stored here
	std::vector<std::shared_ptr<BaseObject>> m_map; //all interactions will be done here

	sf::Vector2f screenSize;
	RuleHandling m_ruleHandler;
	
	sf::RectangleShape m_background;
	bool m_endLevel = false;

	//--------------private--------functions-----------------------//
	//void enterInVec(sf::Vector2f conPos, Word* curObj, std::array<Word*, 2>& vertical, std::array<Word*, 2>& horizontal);
	void updateRules(std::vector<ruleTuple>& currentRules);
	void searchTriples(std::vector<baseObjTuple>& vec,
		std::function<float(const sf::Vector2f&)> mainCoordinate,
		std::function<float(const sf::Vector2f&)> secondaryCoordinate);
};
