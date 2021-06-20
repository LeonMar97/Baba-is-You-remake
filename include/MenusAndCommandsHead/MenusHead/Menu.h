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
	 virtual void add(unique_ptr<Command> c);
	virtual void activate()=0;
	Menu(sf::RenderWindow &window);
	~Menu() {}

protected:
	virtual void setView();
	virtual void draw()=0;
	virtual void setButtonsTextures()=0;

protected:
	sf::Clock m_animationClock;
	vector<option> m_options;
	sf::RenderWindow &m_menuWindow;
	


};