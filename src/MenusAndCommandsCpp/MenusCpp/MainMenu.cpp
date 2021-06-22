#include "MainMenu.h"
MainMenu::MainMenu(sf::RenderWindow& gameWindeow)
:
	Menu(gameWindeow),
	//~~~~~~~~adding commands~~~~~~~~~~~~~
	m_cntrl(std::make_shared<Controller>(m_menuWindow))
	

{
	//~~~~~~~~~~~~creating the buttons (the order of the adding is importent!!!!!!!!!)~~~~~~~~~~~~~~~~~
	add(std::make_unique <NewGame>(m_cntrl, std::make_unique <sf::RectangleShape>(sf::Vector2f(430, 48))));
	add(std::make_unique <LoadLevel>( std::make_unique <sf::RectangleShape>(sf::Vector2f(430, 48)),m_menuWindow,m_cntrl));
	add(std::make_unique <ExitGame>(m_menuWindow, std::make_unique <sf::RectangleShape>(sf::Vector2f(430, 48))));



	m_creators.push_back(std::make_unique<Header>(std::stringstream("GAME"), sf::Vector2f(650, 850), sf::Vector2f(1.f, 2.f), sf::Color::White));
	m_creators.push_back(std::make_unique<Header>(std::stringstream("CREATORS"), m_creators[0]->wordEnd(), sf::Vector2f(1.f, 2.f), sf::Color::White));
	m_creators.push_back(std::make_unique<Header>(std::stringstream("I"), m_creators[1]->wordEnd(), sf::Vector2f(1.f, 2.f), sf::Color::Red));
	m_creators[2]->m_sprites[0]->setRotation(90);
	m_creators[2]->m_sprites[0]->setPosition(m_creators[2]->m_sprites[0]->getPosition() + sf::Vector2f(50.f, 15));

	m_creators.push_back(std::make_unique<Header>(std::stringstream("LEON"), sf::Vector2f(850, 950), sf::Vector2f(1.f, 2.f), sf::Color(217, 57, 106)));
	m_creators.push_back(std::make_unique<Header>(std::stringstream("AND"), m_creators[3]->wordEnd(), sf::Vector2f(1.f, 2.f), sf::Color::Red));
	m_creators.push_back(std::make_unique<Header>(std::stringstream("RONEN"), m_creators[4]->wordEnd(), sf::Vector2f(1.f, 2.f), sf::Color(217, 57, 106)));


	m_babaIsU.push_back(std::make_unique<Header>(std::stringstream("BABA"), sf::Vector2f(400, 100), sf::Vector2f(5.f, 15.f), sf::Color(217, 57, 106)));
	m_babaIsU.push_back(std::make_unique<Header>(std::stringstream("IS"), m_babaIsU[0]->wordEnd(), sf::Vector2f(5.f, 15.f), sf::Color(255, 255, 255)));
	m_babaIsU.push_back(std::make_unique<Header>(std::stringstream("U"), m_babaIsU[1]->wordEnd(), sf::Vector2f(5.f, 15.f), sf::Color(217, 57, 106)));

	
	setView();
	setButtonsTextures();
}
void MainMenu::draw() {
	auto deltaTime = m_animationClock.restart();
	
	for (auto& cur : m_babaIsU) {
		cur->draw(m_menuWindow,deltaTime);
	}
	for (auto& cur : m_creators) {
		cur->draw(m_menuWindow, deltaTime);
	}
	for (auto& cur : m_options) {
		m_menuWindow.draw((cur)->getRect());
	}


}
void MainMenu::setButtonsTextures() {
	auto texRect = MAIN_MENU_BUTTONS_START;
	auto pos = FIRST_BUTTON_REC;
	for (auto& curRec : m_options) {
		curRec->getRect().setTexture(&Resources::instance().texture(1));
		curRec->getRect().setTextureRect(texRect);
		curRec->getRect().setPosition(pos);
		texRect = sf::IntRect(texRect.left, (texRect.top + MAIN_MENU_BUTTON_HEIGHT),texRect.width, texRect.height);
		pos += MAIN_MENU_POS_DIF;
	
	}


}
void MainMenu::activate() {

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
						if (curOption->contains(mousepos)) {// sf::Vector2f(sf::Mouse::getPosition()))) {
							curOption->execute();
							setView();
							deltaTime = m_animationClock.restart();
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
