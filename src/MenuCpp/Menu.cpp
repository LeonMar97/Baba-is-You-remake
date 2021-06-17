#include"Menu.h"
void Menu::add(unique_ptr<Command> c){
	m_options.emplace_back(option(move(c)));
}

Menu::Menu()
	:
	m_menuWindow(sf::VideoMode(1920, 1080), "Baba is you", sf::Style::Fullscreen),
	m_startGameButton(sf::Vector2f(720, 220)),
	m_exitGameButton(sf::Vector2f(720, 220)),
	m_cntrl(std::make_shared<Controller>(m_menuWindow))
{
	sf::View view = m_menuWindow.getView();
	view.setCenter(sf::Vector2f(DEFAULT_SCREEN_WIDTH / 2.f, DEFAULT_SCREEN_HEIGHT / 2.f));
	auto prop = DEFAULT_SCREEN_WIDTH * DEFAULT_SCREEN_HEIGHT / float(m_menuWindow.getSize().x * m_menuWindow.getSize().y);
	view.zoom(prop);
	m_menuWindow.setView(view);

	m_exitGameButton.setPosition(sf::Vector2f(180, 180));
	m_startGameButton.setPosition(sf::Vector2f(500, 500));

	m_exitGameButton.setFillColor(sf::Color::Red);
	m_startGameButton.setFillColor(sf::Color::Green);
	
	//~~~~~~~~adding commands~~~~~~~~~~~~~
	add(std::make_unique <NewGame>(m_cntrl));
	
}
void Menu::activate() {
	while (m_menuWindow.isOpen())
	{
		sf::Event event;
		while (m_menuWindow.pollEvent(event))
		{
			switch (event.type)
			{
				break;
			case sf::Event::MouseButtonPressed:
				if (event.key.code == sf::Mouse::Left)
					if (m_startGameButton.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition())))
						m_options[START_NEW_GAME]->execute();

					else if (m_exitGameButton.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition())))
						return;
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
