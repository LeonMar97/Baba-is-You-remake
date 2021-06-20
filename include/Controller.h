#pragma once
#include "Board.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include "FileHandler.h"
#include "BaseObject.h"
#include "Direction.h"
#include "Header.h"
//#include "Menu.h"

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
	void printCongratulations();
	//void printNextLvlTex();
	//void printEndGameTex();
	//~~~~~~~~~~~~~~~~~~~~~~~~~~private members~~~~~~~~~~//
private:
	sf::RenderWindow& m_gameWindow;
	FileHandler m_map;
	std::unique_ptr<Board>m_mapOnScreen;
	int m_level = 1;
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