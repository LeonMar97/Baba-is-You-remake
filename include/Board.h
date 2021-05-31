#pragma once
#include"FileHandler.h"
#include "Tile.h"

class Board{
public:
	void drawBoard(sf::RenderWindow& game_Window);
	Board(sf::Vector2u mapSize);
	void initialize(FileHandler &map);
	bool isLvlFinished();
	
	void addGameObj(char p, sf::Vector2u loc);

private:
	std::vector<std::vector<Tile>> m_map;

};