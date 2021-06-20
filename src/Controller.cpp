#include "Controller.h"
#include "Resources.h"
//#include "Sounds.h"
//#include "Fonts.h"
#include "Macros.h"
#include "Baba.h"

Controller::Controller(sf::RenderWindow& gameWindow)
	: m_gameWindow(gameWindow)
{
	m_gameWindow.setFramerateLimit(60);
}

void Controller::updateDataStructures() {
	m_mapOnScreen->initialize(m_map);
	//m_clock.restart();
}

/*
void Controller::openMenu() {
	auto menu = Menu(*this, m_gameWindow); //do i want to do this?
	menu.run();

}
*/
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
	deltaTime = m_animationClock.restart();//so the animations wont start bublin fast..

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
					if (event.key.code == sf::Keyboard::Z)
						m_mapOnScreen->undoAllObjects();
					else m_mapOnScreen->setDefaultOperation();

					if (event.key.code == sf::Keyboard::R)
						m_mapOnScreen->restartBoard();
					if (event.key.code == sf::Keyboard::Right)
						m_mapOnScreen->moveYou(Direction::Right);
					else if (event.key.code == sf::Keyboard::Left)
						m_mapOnScreen->moveYou(Direction::Left);
					else if (event.key.code == sf::Keyboard::Up)
						m_mapOnScreen->moveYou(Direction::Up);
					else if (event.key.code == sf::Keyboard::Down)
						m_mapOnScreen->moveYou(Direction::Down);
					else if (event.key.code == sf::Keyboard::Escape) {
						m_gameWindow.close();
						return;
					}
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
	auto animationClock = sf::Clock{};
	auto deltaTime = sf::Time{};
	auto header = Header(std::stringstream("CONGRATULATIONS"), { 0,0 }, { 1,1 }, sf::Color::Red);
	int i = 0;
	while (i < 1000) {
		m_gameWindow.clear();
		header.draw(deltaTime, m_gameWindow);
		deltaTime = animationClock.restart();
		m_gameWindow.display();
		i++;
	}

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