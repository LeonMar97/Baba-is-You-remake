#pragma once
#include "Menu.h"
#include "ExitGame.h"
#include"NewGame.h"
#include"LoadLevel.h"
#include "Controls.h"
class MainMenu:public Menu{
public:
	
	MainMenu(sf::RenderWindow&);
	void draw()override;
	void activate()override;
	void setButtonsTextures()override;

private:
	std::shared_ptr<Controller> m_cntrl;
	std::vector<std::unique_ptr<Header>>m_babaIsU;
	std::vector<std::unique_ptr<Header>>m_creators;

};