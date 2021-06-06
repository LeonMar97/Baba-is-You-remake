#include "Menu.h"
#include "Controller.h"

Menu::Menu(Controller& ctrl, sf::RenderWindow& menuWindow)
	:m_ctrl(ctrl),
	m_menuWindow(menuWindow),
	m_startGameButton(sf::Vector2f(720, 220)),
	m_exitGameButton(sf::Vector2f(720, 220))
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

}

void Menu::run() {
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
						m_ctrl.startGame();

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