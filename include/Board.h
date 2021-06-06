#pragma once
#include"FileHandler.h"
#include "BaseObject.h"

class Board{
public:
	void drawBoard(sf::RenderWindow& game_Window, float deltaTime);
	Board(std::vector<BaseObject*>&);
	void initialize(FileHandler &map);
	bool isLvlFinished();
	
	void addGameObj(char p, sf::Vector2u loc);

	void checkCollisions(BaseObject*);

private:
	std::vector<BaseObject*> m_map;
	sf::Vector2f screenSize;
	std::vector<BaseObject*>& m_you;
	
	sf::RectangleShape m_background;
};
