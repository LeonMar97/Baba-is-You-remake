#pragma once
#include "Board.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include "FileHandler.h"

class Controller {

public:
	Controller();
	void startGame();//the game loop
	//~~~~~~~~~~~~~~~~~~~~~~~~~~private functions~~~~~~~~~~//
private:
	//creates the window and the outlines
	void generateBackgrounds();
	void updateDataStructures();
	bool newLvl();
	void printNextLvlTex();
	void printEndGameTex();
	//~~~~~~~~~~~~~~~~~~~~~~~~~~private members~~~~~~~~~~//
private:
	sf::RenderWindow m_gameWindow;
	sf::Sprite m_background;
	std::map<char, GameTextures>m_charToTexConverter;
	FileHandler m_map;
	std::unique_ptr<Board>m_mapOnScreen;
	int m_level = 1;

	//sf::Sprite m_bgMenu;
	//sf::Text m_timeText;
	//sf::Text m_lvlText;
	//sf::Sound m_finishedLvlSound;
	//sf::Clock m_clock;
};