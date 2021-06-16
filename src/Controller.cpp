#include "Controller.h"
#include "Resources.h"
//#include "Sounds.h"
//#include "Fonts.h"
#include "Macros.h"
#include "Baba.h"

Controller::Controller()
	: m_gameWindow(sf::VideoMode(1920,1080),"Baba is you",sf::Style::Fullscreen)
{
	m_gameWindow.setFramerateLimit(60);
}

void Controller::updateDataStructures() {
	m_mapOnScreen->initialize(m_map);
	//m_clock.restart();
}

void Controller::openMenu() {
	auto menu = Menu(*this, m_gameWindow); //do i want to do this?
	menu.run();

}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
/*
void Controller::settingFontsAndSounds() {
	m_timeText.setFont(Fonts::instance().get_Fonts(PipedFont_t));
	m_timeText.setString("Time: " + std::to_string(int(m_clock.getElapsedTime().asSeconds())));
	m_timeText.setPosition(MENU_POS);
	m_timeText.setCharacterSize(50);
	m_timeText.setFillColor(sf::Color::Black);
	m_lvlText.setFont(Fonts::instance().get_Fonts(PipedFont_t));
	m_lvlText.setString("Level: " + std::to_string(m_level));
	m_lvlText.setPosition(MENU_POS + sf::Vector2f(0, 200));
	m_lvlText.setCharacterSize(50);
	m_lvlText.setFillColor(sf::Color::Black);
	m_finishedLvlSound.setBuffer(Sounds::instance().get_Sounds(cheers_t));
	m_finishedLvlSound.setVolume(5);
}
*/
//part of start game - maybe put in later

void Controller::startGame() {
	Direction dir;
	//for making board visible entirely independent of screen size
	 setView();
	
	m_mapOnScreen = std::make_unique<Board>();
	updateDataStructures();
	sf::Time deltaTime = {};

	while (m_gameWindow.isOpen())
	{
		while (!m_mapOnScreen->isLvlFinished()) {
			deltaTime = m_animationClock.restart();

			sf::Event event;
			while (m_gameWindow.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Right)
						dir = Direction::Right;
					else if (event.key.code == sf::Keyboard::Left)
						dir = Direction::Left;
					else if (event.key.code == sf::Keyboard::Up)
						dir = Direction::Up;
					else if (event.key.code == sf::Keyboard::Down)
						dir = Direction::Down;

					if (event.key.code == sf::Keyboard::Escape) {
						m_gameWindow.close();
						break;
					}

					m_mapOnScreen->moveYou(dir);


					m_mapOnScreen->lookForRules();
					break;
				case sf::Event::Closed:
					m_gameWindow.close();
					break;
				}
			}
			m_gameWindow.clear(WINDOW_COLOR);
			m_mapOnScreen->drawBoard(m_gameWindow, deltaTime);
			m_gameWindow.display();
		}
		if (!newLvl())
			break;
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
bool Controller::newLvl() {
	//checking if there is a new lvl
	if (m_map.rebuild_Map()) {
		m_mapOnScreen.reset();
		m_mapOnScreen = std::make_unique<Board>();
		updateDataStructures();
		m_level++;
		//m_clock.restart();
		return true;
	}
	return false;
}

void Controller::setView() {

	m_gameWindow.setView(m_gameWindow.getDefaultView());
	sf::View view = m_gameWindow.getView();
	view.setCenter(sf::Vector2f(OBJECT_SIZE * MAP_SIZE.y / 2.f, OBJECT_SIZE * MAP_SIZE.x / 2.f));
	auto prop = DEFAULT_SCREEN_WIDTH * DEFAULT_SCREEN_HEIGHT / float(m_gameWindow.getSize().x * m_gameWindow.getSize().y);
	view.zoom(prop);
	m_gameWindow.setView(view);
}