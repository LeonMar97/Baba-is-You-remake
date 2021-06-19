#include"Menu.h"
void Menu::add(unique_ptr<Command> c){
	m_options.emplace_back(option(move(c)));
}

Menu::Menu()
	:
	m_babaHead(std::stringstream("BABA"),sf::Vector2f(500,100),sf::Vector2f(5.f,15.f),sf::Color(217,57,106)),
	m_isHead(std::stringstream("IS"), m_babaHead.wordEnd(), sf::Vector2f(5.f, 15.f), sf::Color(217, 57, 106)),
	m_uHead(std::stringstream("U"), m_isHead.wordEnd(), sf::Vector2f(5.f, 15.f), sf::Color(217, 57, 106)),

	m_menuWindow(sf::VideoMode(1920, 1080), "Baba is you", sf::Style::Fullscreen),
	m_startGameButton(sf::Vector2f(430, 48)),
	m_exitGameButton(sf::Vector2f(430, 48)),

	m_cntrl(std::make_shared<Controller>(m_menuWindow))
{
	setView();
	
	m_startGameButton.setPosition(sf::Vector2f(750, 570));
	
	m_exitGameButton.setPosition(sf::Vector2f(750, 624));
	
	m_startGameButton.setFillColor(sf::Color(35, 41, 67));
	m_startGameButton.setOutlineThickness(2.f);
	m_startGameButton.setOutlineColor(sf::Color(78,90,148));
	

	m_exitGameButton.setFillColor(sf::Color(35,41,67));
	m_exitGameButton.setOutlineThickness(2.f);
	m_exitGameButton.setOutlineColor(sf::Color(78, 90, 148));
	//~~~~~~~~adding commands~~~~~~~~~~~~~
	add(std::make_unique <NewGame>(m_cntrl));
	
}
void Menu::activate() {
	
	sf::Time deltaTime = {};

	while (m_menuWindow.isOpen())
	{
		sf::Event event;
		sf::Vector2f mousepos;
		deltaTime = m_animationClock.restart();

		while (m_menuWindow.pollEvent(event))
		{

			switch (event.type)
			{
			case sf::Event::MouseButtonPressed:
				mousepos = m_menuWindow.mapPixelToCoords(sf::Mouse::getPosition() - m_menuWindow.getPosition());
				if (event.key.code == sf::Mouse::Left) {
					if (m_startGameButton.getGlobalBounds().contains(mousepos)) {// sf::Vector2f(sf::Mouse::getPosition()))) {
						m_options[START_NEW_GAME]->execute();
						setView();
					}
					else if (m_exitGameButton.getGlobalBounds().contains(sf::Vector2f(mousepos)))
						return;
				}
			default:
				break;
			}
		
			
		}
		m_menuWindow.clear(WINDOW_COLOR);
		draw(deltaTime);
		m_menuWindow.display();
	}
}

void Menu::setView() {

	sf::View view = m_menuWindow.getView();
	view.setCenter(sf::Vector2f(DEFAULT_SCREEN_WIDTH / 2.f, DEFAULT_SCREEN_HEIGHT / 2.f));
	auto prop = DEFAULT_SCREEN_WIDTH * DEFAULT_SCREEN_HEIGHT / float(m_menuWindow.getSize().x * m_menuWindow.getSize().y);
	view.zoom(prop);
	m_menuWindow.setView(view);



}
void Menu::draw(sf::Time &deltaTime) {
	m_babaHead.draw(deltaTime, m_animationClock, m_menuWindow);
	m_isHead.draw(deltaTime, m_animationClock, m_menuWindow);
	m_uHead.draw(deltaTime, m_animationClock, m_menuWindow);

	m_menuWindow.draw(m_exitGameButton);
	m_menuWindow.draw(m_startGameButton);

}