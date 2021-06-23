#pragma once
#include "Menu.h"
#include"Resume.h"


class MenuControls :public Menu {

public:

	MenuControls(sf::RenderWindow& gameWindeow);

	void draw()override;
	void activate()override;
	void setButtonsTextures()override;
private:
	sf::RectangleShape m_background;

	

};