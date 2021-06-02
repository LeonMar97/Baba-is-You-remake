#pragma once
#include"FileHandler.h"
#include "Tile.h"

class Board{
public:
	void drawBoard(sf::RenderWindow& game_Window, float deltaTime);
	Board();
	void initialize(FileHandler &map);
	bool isLvlFinished();
	
	void addGameObj(char p, sf::Vector2u loc);

private:
	std::vector<std::vector<Tile>> m_map;
	sf::Vector2f screenSize;

};
