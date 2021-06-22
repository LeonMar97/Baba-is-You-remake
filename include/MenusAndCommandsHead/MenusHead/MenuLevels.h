#pragma once
#include "Menu.h"
#include "ExitGame.h"
#include"NewGame.h"
#include"Controller.h"
#include "Resume.h"
class MenuLevels:public Menu{
public:
	
	MenuLevels(sf::RenderWindow&gameWindow, std::shared_ptr<Controller>& c);
	void draw()override;
	void activate()override;
	void setButtonsTextures()override;

private:
	
};