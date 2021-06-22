#pragma once
#include "Menu.h"
#include "ExitGame.h"
#include"NewGame.h"
#include"Controller.h"
#include "Resume.h"
#include "LvlLoadCommand.h"
class MenuLevels:public Menu{
public:
	
	MenuLevels(sf::RenderWindow&gameWindow, std::shared_ptr<Controller>& c);
	void draw()override;
	void activate()override;
	void setButtonsTextures()override;

private:
	std::shared_ptr<Controller>m_cntrl;

};