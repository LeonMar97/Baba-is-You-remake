#pragma once
#include"FileHandler.h"
#include "BaseObject.h"
#include<array>
#include <functional>
#include"Word.h"
#include <cstdlib>
#include "Resources.h"
#include "Direction.h"
#include "Baba.h"
#include "Is.h"
#include "Wall.h"
#include "Rock.h"
#include "RockWord.h"
#include "WallWord.h"
#include "BabaWord.h"
#include "YouWord.h"
#include "StopWord.h"
#include "WinWord.h"
#include "PushWord.h"
#include"DataHolder.h"
#include"BaseDataHolder.h"
#include "RuleHandling.h"
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
	/*
	void insert(GameObjects, BaseObject*);
	void createRule(Conjunction& c, std::array<Word*, 2>& potentialRule, std::vector<ruleTuple>& m_currentRules);
	void lookForRules();
	void replace(GameObjects objectToAdd, GameObjects objectToRemove, char objectToCreate);
	*/
	//--------------private--------members-----------------------//
private:
	std::vector<ruleTuple> m_Rules;
	std::array<std::vector<Word*>, WORD_TYPES>m_words;

	std::vector<BaseObject*> m_map;
	sf::Vector2f screenSize;
	RuleHandling m_ruleHandler;
	
	sf::RectangleShape m_background;
	//--------------private--------functions-----------------------//
	//void enterInVec(sf::Vector2f conPos, Word* curObj, std::array<Word*, 2>& vertical, std::array<Word*, 2>& horizontal);
	void updateRules(std::vector<ruleTuple>& currentRules);
	void searchTriples(std::vector<baseObjTuple>& vec,
		std::function<float(const sf::Vector2f&)> mainCoordinate,
		std::function<float(const sf::Vector2f&)> secondaryCoordinate);
};
