#include "MenuLevels.h"
MenuLevels::MenuLevels(sf::RenderWindow& gameWindow, std::shared_ptr<Controller>& c)
:
	Menu(gameWindow)
	//~~~~~~~~adding commands~~~~~~~~~~~~~
	
	

{
	//~~~~~~~~~~~~creating the buttons (the order of the adding is importent!!!!!!!!!)~~~~~~~~~~~~~~~~~
	add(std::make_unique <Resume>(std::make_unique <sf::RectangleShape>(sf::Vector2f(430, 48))));


	setView();
	setButtonsTextures();
}
void MenuLevels::draw() {
	auto deltaTime = m_animationClock.restart();
	for (auto& cur : m_options) {
		m_menuWindow.draw((cur)->getRect());
	}


}
void MenuLevels::setButtonsTextures() {
	auto texRect = MAIN_MENU_BUTTONS_START;
	auto pos = FIRST_BUTTON_REC;
	for (auto& curRec : m_options) {
		curRec->getRect().setTexture(&Resources::instance().texture(MenuLevelSheet_t));
		curRec->getRect().setTextureRect(texRect);
		curRec->getRect().setPosition(pos);
		texRect = sf::IntRect(texRect.left, (texRect.top + MAIN_MENU_BUTTON_HEIGHT),texRect.width, texRect.height);
		pos += MAIN_MENU_POS_DIF;
	
	}


}
void MenuLevels::activate() {

	sf::Time deltaTime = {};

	while (m_menuWindow.isOpen())
	{
		sf::Event event;
		sf::Vector2f mousepos;
		
		while (m_menuWindow.pollEvent(event))
		{
			

			switch (event.type)
			{
			case  sf::Event::MouseMoved:
				mousepos = m_menuWindow.mapPixelToCoords(sf::Mouse::getPosition() - m_menuWindow.getPosition());
					for (auto& curOption : m_options) {
						curOption->mouseHover(mousepos);
					}

			case sf::Event::MouseButtonPressed:
				mousepos = m_menuWindow.mapPixelToCoords(sf::Mouse::getPosition() - m_menuWindow.getPosition());
				if (event.key.code == sf::Mouse::Left) {
					for (auto& curOption:m_options) {
						if (curOption->contains(mousepos)) {
							curOption->execute();
							setView();
							deltaTime = m_animationClock.restart();
							return;
						}
					}
				}
			default:
				break;
			}


		}
		m_menuWindow.clear(WINDOW_COLOR);
		draw();
		m_menuWindow.display();
	}
}
