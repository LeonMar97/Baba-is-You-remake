#pragma once
#include "Menu.h"
#include "ExitGame.h"
#include"NewGame.h"
#include"Restart.h"
#include"Resume.h"
#include"Controls.h"
#include"ReturnToMenu.h"
#include "Controller.h"


class MiniMenu :public Menu {

public:

	MiniMenu(Controller &con, sf::RenderWindow& gameWindeow);

	void draw()override;
	void activate()override;
	void setButtonsTextures()override;
private:
	Controller &m_cntrl;
	std::vector<std::unique_ptr<Header>>m_settings;


};