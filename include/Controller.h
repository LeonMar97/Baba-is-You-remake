#pragma once
#include "Board.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include "FileHandler.h"
#include "BaseObject.h"
#include "Direction.h"
//#include "Menu.h"
#include <stack>

class Controller {

public:
	Controller(sf::RenderWindow&);
	void startGame();//the game loop
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~private functions~~~~~~~~~~//
private:
	//creates the window and the outlines
	//void generateBackgrounds();
	void updateDataStructures();
	bool newLvl();
	//void printNextLvlTex();
	//void printEndGameTex();
	//~~~~~~~~~~~~~~~~~~~~~~~~~~private members~~~~~~~~~~//
private:
	sf::RenderWindow& m_gameWindow;
	//sf::Sprite m_background;
	std::map<char, GameObjects>m_charToTexConverter;
	FileHandler m_map;
	std::unique_ptr<Board>m_mapOnScreen;
	int m_level = 1;

	std::vector<BaseObject*> m_you;
	sf::Clock m_animationClock;
	bool m_endLevel = false;

	void setView();
	void moveYou(sf::Vector2i dir);

	//sf::Sprite m_bgMenu;
	//sf::Text m_timeText;
	//sf::Text m_lvlText;
	//sf::Sound m_finishedLvlSound;
	//sf::Clock m_clock;
};