#include "Controller.h"
#include "Resources.h"
//#include "Sounds.h"
//#include "Fonts.h"
#include "Macros.h"
#include "Baba.h"
#include "Menu2.h"
Controller::Controller(sf::RenderWindow& gameWindow)
	:
	m_gameWindow(gameWindow)


{
	
	m_gameWindow.setFramerateLimit(60);
	
}

void Controller::updateDataStructures(const unsigned int& levelNum) {
	
	
	m_mapOnScreen->initialize(levelNum,m_map);
	//m_clock.restart();
}



//part of start game - maybe put in later
void Controller::loadLevel(const unsigned int& levelNum) {
	m_level = levelNum;
	m_mapOnScreen = std::make_unique<Board>();
	updateDataStructures(levelNum);
}

void Controller::startGameLoop() {
	Menu2 miniMenu(*this, m_gameWindow);
	Direction dir;
	//for making board visible entirely independent of screen size
	setView();
	sf::Time deltaTime = {};
	deltaTime = m_animationClock.restart();//so the animations wont start bublin fast..

	while (m_gameWindow.isOpen() )
	{
		deltaTime = m_animationClock.restart();

		sf::Event event;
		while (m_gameWindow.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Z|| event.key.code == sf::Keyboard::BackSpace)
					m_mapOnScreen->undoAllObjects();
				else m_mapOnScreen->setDefaultOperation();
				if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D)
					m_mapOnScreen->moveYou(Direction::Right);
				else if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A)
					m_mapOnScreen->moveYou(Direction::Left);
				else if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W)
					m_mapOnScreen->moveYou(Direction::Up);
				else if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)
					m_mapOnScreen->moveYou(Direction::Down);
				else if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::R) {
					restart();
					break;
				}
				else if (event.key.code == sf::Keyboard::Escape) {
					m_gameWindow.close();
					return;
				}
				else if (event.key.code == sf::Keyboard::Tab) {
					miniMenu.activate();
					if (m_RetToMain) {
						m_RetToMain = false;
						return;
					}
					setView();

					m_animationClock.restart();
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

		if (m_mapOnScreen->isLvlFinished()) {
			if (!newLvl())
				break;
		}
	}
	m_RetToMain = false;//setting it back to false incase we go back to menu without closing the window

}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
bool Controller::newLvl() {
	//checking if there is a new lvl
	//m_mapOnScreen.reset();
	if (m_map.mapAlreadyBuilt(++m_level) == false) {
		if (!m_map.rebuild_Map())
			return false;	
	}
	loadLevel(m_level);//when i get to this point the map already build and inside the levels vector
	return true;

}

void Controller::setView() {

	m_gameWindow.setView(m_gameWindow.getDefaultView());
	sf::View view = m_gameWindow.getView();
	view.setCenter(sf::Vector2f(OBJECT_SIZE * MAP_SIZE.y / 2.f, OBJECT_SIZE * MAP_SIZE.x / 2.f));
	auto prop = DEFAULT_SCREEN_WIDTH * DEFAULT_SCREEN_HEIGHT / float(m_gameWindow.getSize().x * m_gameWindow.getSize().y);
	view.zoom(prop);
	m_gameWindow.setView(view);
	
	}
void Controller::restart() {
	m_mapOnScreen->restartBoard();
}

void Controller::retToMainMenu() {
	m_RetToMain = true;
}

unsigned int Controller::numOfLevels() const {
	return m_map.numOfLevels();
}
