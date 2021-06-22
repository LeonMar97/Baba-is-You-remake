#pragma once
#include "Board.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include "FileHandler.h"
#include "BaseObject.h"
#include "Direction.h"


class Menu2;
class Controller {

public:
	
	

	

	Controller(sf::RenderWindow&);
	void startGameLoop();//the game loop
	void loadLevel(const unsigned int& levelNum);
	void restart();
	void retToMainMenu();


	//~~~~~~~~~~~~~~~~~~~~~~~~~~private functions~~~~~~~~~~//
private:
	//creates the window and the outlines
	//void generateBackgrounds();
	void updateDataStructures(const unsigned int & levelNumber);
	bool newLvl();
	void printCongratulations();
	void setView();
	void moveYou(sf::Vector2i dir);
	//void printNextLvlTex();
	//void printEndGameTex();
	//~~~~~~~~~~~~~~~~~~~~~~~~~~private members~~~~~~~~~~//
private:
	sf::RenderWindow& m_gameWindow;
	FileHandler m_map;
	std::unique_ptr<Board>m_mapOnScreen;
	int m_level = 0;
	sf::Clock m_animationClock;
	bool m_endLevel = false;


	bool m_RetToMain = false;

	//sf::Sprite m_bgMenu;
	//sf::Text kText;
	//sf::Text m_lvlText;
	//sf::Sound m_finishedLvlSound;
	//sf::Clock m_clock;

};