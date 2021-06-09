#pragma once
#include"FileHandler.h"
#include "BaseObject.h"
#include<array>
#include"Word.h"
#include <cstdlib>
#include "Textures.h"
#include "Baba.h"
#include "Is.h"
#include "BabaWord.h"
#include "YouWord.h"
#include "WinWord.h"
#include"DataHolder.h"
#include"BaseDataHolder.h"
#include <tuple>
typedef std::tuple<Noun&, Conjunction&, Word&>ruleTuple;
class Board{
	//--------------public--------functions-----------------------//
public:
	void drawBoard(sf::RenderWindow& game_Window, float deltaTime);
	Board(std::vector<BaseObject*>&);
	void initialize(FileHandler &map);
	bool isLvlFinished();
	
	void addGameObj(char p, sf::Vector2u loc);

	void checkCollisions(BaseObject*);
	void insert(GameObjects, BaseObject*);
	void createRule(Conjunction& c, std::array<Word*, 2>& potentialRule, std::vector<ruleTuple>& m_currentRules);
	void lookForRules();
	//--------------private--------members-----------------------//
private:
	std::vector<ruleTuple> m_Rules;
	 std::array<std::vector<Word*>, WORD_TYPES>m_words;

	std::map<GameObjects, std::vector<BaseObject*>> m_dataHolder;
	sf::Vector2f screenSize;
	std::vector<BaseObject*>& m_you;
	
	sf::RectangleShape m_background;
	//--------------private--------functions-----------------------//
	void enterInVec(sf::Vector2f conPos, Word* curObj, std::array<Word*, 2>& vertical, std::array<Word*, 2>& horizontal);
	void updateRules(std::vector<ruleTuple>& currentRules);
};
