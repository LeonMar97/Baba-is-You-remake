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
	m_mapOnScreen = std::make_unique<Board>();
	updateDataStructures(levelNum);
}

void Controller::startGameLoop() {
	Menu2 miniMenu(*this, m_gameWindow) ;
	Direction dir;
	//for making board visible entirely independent of screen size
	 setView();
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
					else if (event.key.code == sf::Keyboard::Tab) {
					miniMenu.activate();
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
		}
		if (!newLvl())
			break;
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
bool Controller::newLvl() {
	//checking if there is a new lvl
	//m_mapOnScreen.reset();

	if (m_map.rebuild_Map()) {
		loadLevel(++m_level);//when i get to this point the map already build and inside the levels vector
		
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
void Controller::restart() {
	m_mapOnScreen->restartBoard();
}
