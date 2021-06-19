#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <memory>
#include "Command.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "Controller.h"
#include"NewGame.h"
#include "Header.h"
#include<sstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::pair;
using std::unique_ptr;
typedef unique_ptr<Command> option;

class Menu {
public:
	void add(unique_ptr<Command> c);
	void activate();
	Menu();
	~Menu() {}
private:
	void setView();
private:
	vector<option> m_options;
	sf::RenderWindow m_menuWindow;
	std::shared_ptr<Controller> m_cntrl;
	sf::RectangleShape m_startGameButton;
	sf::RectangleShape m_exitGameButton;
	Header m_babaIsU;

	

};