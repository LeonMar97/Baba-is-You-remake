#include "Menu2.h"
Menu2::Menu2(Controller& con, sf::RenderWindow& gameWindeow)
	:
	m_cntrl(con),
	Menu(gameWindeow)
{
	//~~~~~~~~~~~~creating the buttons (the order of the adding is importent!!!!!!!!!)~~~~~~~~~~~~~~~~~
	add(std::make_unique <Resume>(std::make_unique <sf::RectangleShape>(sf::Vector2f(430, 48))));
	add(std::make_unique <Restart>(m_cntrl, std::make_unique <sf::RectangleShape>(sf::Vector2f(430, 48))));

	add(std::make_unique <Controls>( std::make_unique <sf::RectangleShape>(sf::Vector2f(430, 48)), m_menuWindow));
	add(std::make_unique <ReturnToMenu>(m_cntrl, std::make_unique <sf::RectangleShape>(sf::Vector2f(430, 48))));

	m_settings.push_back(std::make_unique<Header>(std::stringstream("SETTINGS"), sf::Vector2f(850,400 ), sf::Vector2f(1.f, 2.f), sf::Color::White));
	

	setView();
	
	
	
	setButtonsTextures();




}
void Menu2::draw() {
	auto deltaTime = m_animationClock.restart();
	
	for (auto& cur : m_settings) {
		cur->draw(m_menuWindow, deltaTime);
	}
	for (auto& cur : m_options) {
		m_menuWindow.draw((cur)->getRect());
	}


}
void Menu2::setButtonsTextures() {
	auto texRect = MAIN_MENU_BUTTONS_START;
	auto pos = FIRST_BUTTON_REC;
	for (auto& curRec : m_options) {
		curRec->getRect().setTexture(&Resources::instance().texture(2));
		curRec->getRect().setTextureRect(texRect);
		curRec->getRect().setPosition(pos);
		texRect = sf::IntRect(texRect.left, (texRect.top + MAIN_MENU_BUTTON_HEIGHT), texRect.width, texRect.height);
		pos += MAIN_MENU_POS_DIF;

	}


}
void Menu2::activate() {
	setView();

	sf::Time deltaTime = {};

	while (m_menuWindow.isOpen())
	{
		sf::Event event;
		sf::Vector2f mousepos;
		//deltaTime = m_animationClock.restart();

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
							//deltaTime = m_animationClock.restart();
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
