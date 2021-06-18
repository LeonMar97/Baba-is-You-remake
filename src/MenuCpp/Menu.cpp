#include"Menu.h"
void Menu::add(unique_ptr<Command> c){
	m_options.emplace_back(option(move(c)));
}

Menu::Menu()
	:
	m_menuWindow(sf::VideoMode(1920, 1080), "Baba is you", sf::Style::Fullscreen),
	m_startGameButton(sf::Vector2f(430, 48)),
	m_exitGameButton(sf::Vector2f(430, 48)),
	m_cntrl(std::make_shared<Controller>(m_menuWindow))
{
	sf::View view = m_menuWindow.getView();
	view.setCenter(sf::Vector2f(DEFAULT_SCREEN_WIDTH / 2.f, DEFAULT_SCREEN_HEIGHT / 2.f));
	auto prop = DEFAULT_SCREEN_WIDTH * DEFAULT_SCREEN_HEIGHT / float(m_menuWindow.getSize().x * m_menuWindow.getSize().y);
	view.zoom(prop);
	m_menuWindow.setView(view);
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
	auto b = sf::Mouse::getPosition();
	while (m_menuWindow.isOpen())
	{
		sf::Event event;
		while (m_menuWindow.pollEvent(event))
		{
			switch (event.type)
			{
				break;
			case sf::Event::MouseButtonPressed:
				 b = sf::Mouse::getPosition();
				if (event.key.code == sf::Mouse::Left) {
					auto k = sf::Mouse::getPosition();
					if (m_startGameButton.getGlobalBounds().contains(sf::Vector2f(b)))
						m_options[START_NEW_GAME]->execute();

					else if (m_exitGameButton.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition())))
						return;
				}
				//m_you->move(m_mapOnScreen,RIGHT_DIR);
				break;
			default:
				break;
			}
			m_menuWindow.clear(WINDOW_COLOR);
			m_menuWindow.draw(m_exitGameButton);
			m_menuWindow.draw(m_startGameButton);
			m_menuWindow.display();
		}
	}
}
