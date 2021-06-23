#include "MenuControls.h"
MenuControls::MenuControls(sf::RenderWindow& gameWindeow)
	:
	Menu(gameWindeow)
	
{
	m_background.setTexture(&Resources::instance().texture(controlBackGround_t));
	m_background.setSize(SCREEN_SIZE);
	//~~~~~~~~~~~~creating the buttons (the order of the adding is importent!!!!!!!!!)~~~~~~~~~~~~~~~~~
	add(std::make_unique <Resume>(std::make_unique <sf::RectangleShape>(sf::Vector2f(430, 48))));
	
	setView();

	setButtonsTextures();
	

}
void MenuControls::draw() {
	auto deltaTime = m_animationClock.restart();
	
	m_menuWindow.draw(m_background);
	for (auto& cur : m_options) {
		m_menuWindow.draw((cur)->getRect());
	}


}
void MenuControls::setButtonsTextures() {
	auto texRect = MAIN_MENU_BUTTONS_START;
	auto pos = FIRST_BUTTON_REC+sf::Vector2f(0,140.f);
	auto& curRec = m_options[0];
		curRec-> getRect().setTexture(&Resources::instance().texture(2));
		curRec->getRect().setTextureRect(texRect);
		curRec->getRect().setPosition(pos);
		texRect = sf::IntRect(texRect.left, (texRect.top + MAIN_MENU_BUTTON_HEIGHT), texRect.width, texRect.height);
		
}
void MenuControls::activate() {
	setView();


	auto deltaTime = m_animationClock.restart();
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
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Tab)
					return;
			case sf::Event::MouseButtonPressed:
				mousepos = m_menuWindow.mapPixelToCoords(sf::Mouse::getPosition() - m_menuWindow.getPosition());
				if (event.key.code == sf::Mouse::Left) {
					for (auto& curOption : m_options) {
						if (curOption->contains(mousepos)) {// sf::Vector2f(sf::Mouse::getPosition()))) {
							curOption->execute();
							return;
						}
					}
					//else if (m_exitGameButton.getGlobalBounds().contains(sf::Vector2f(mousepos)))
						//return;
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
