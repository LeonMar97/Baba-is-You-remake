#pragma once
#include"FileHandler.h"
#include "BaseObject.h"

class Board{
public:
	void drawBoard(sf::RenderWindow& game_Window, float deltaTime);
	Board();
	void initialize(FileHandler &map);
	bool isLvlFinished();
	
	void addGameObj(char p, sf::Vector2u loc);
	void move(const sf::Vector2i& dir);

private:
	std::vector<BaseObject*> m_map;
	sf::Vector2f screenSize;
	
	sf::RectangleShape m_background;
};
