#include "Controller.h"
#include "Textures.h"
//#include "Sounds.h"
//#include "Fonts.h"
#include "Macros.h"
#include "Baba.h"

Controller::Controller()
	: m_gameWindow(sf::VideoMode(),"Baba is you", sf::Style::Fullscreen)
{

}

void Controller::updateDataStructures() {
	m_mapOnScreen->initialize(m_map);
	//m_clock.restart();
}

void Controller::openMenu() {
	auto menu = Menu(*this); //do i want to do this?
	menu.run();

	sf::RectangleShape temp(sf::Vector2f(720, 220));
	temp.setPosition(sf::Vector2f(180, 180));
	while (m_gameWindow.isOpen())
	{
		sf::Event event;
		while (m_gameWindow.pollEvent(event))
		{
			switch (event.type)
			{
				break;
			case sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::Right)
					//m_you->move(m_mapOnScreen,RIGHT_DIR);
				break;
			case sf::Event::Closed:
				m_gameWindow.close();
				break;
			}
		}
		m_gameWindow.clear(WINDOW_COLOR);
		m_gameWindow.draw(temp);
		m_gameWindow.display();
	}
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
	//m_m_gameWindow.draw(m_background);
	//m_m_gameWindow.draw(m_bgMenu);
	//m_timeText.setString("Time: " + std::to_string(int(m_clock.getElapsedTime().asSeconds())));
	//m_rotationText.setString("Rotations: " + std::to_string(m_numOfRotations));
	//m_lvlText.setString("Level: " + std::to_string(m_level));
	//m_m_gameWindow.draw(m_timeText);
	//m_m_gameWindow.draw(m_rotationText);
	//m_m_gameWindow.draw(m_lvlText);

	//for making board visible entirely independent of screen size
	sf::View view = m_gameWindow.getView();
	view.setCenter(sf::Vector2f(OBJECT_SIZE* MAP_SIZE.y/2.f, OBJECT_SIZE* MAP_SIZE.x/2.f));
	auto prop = DEFAULT_SCREEN_WIDTH * DEFAULT_SCREEN_HEIGHT / float(m_gameWindow.getSize().x * m_gameWindow.getSize().y);
	view.zoom(prop);
	m_gameWindow.setView(view);

	m_mapOnScreen = std::make_unique<Board>();
	updateDataStructures();
	float deltaTime = 0.0f;
	while (m_gameWindow.isOpen())
	{
		m_gameWindow.setView(m_gameWindow.getDefaultView());
		deltaTime = m_animationClock.restart().asSeconds();

		sf::Event event;
		while (m_gameWindow.pollEvent(event))
		{
			switch (event.type)
			{
				break;
			case sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::Right)
					//m_you->move(m_mapOnScreen,RIGHT_DIR);
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

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
/*
void Controller::printEndGameTex() {
	m_clock.restart();
	while (m_clock.getElapsedTime().asSeconds() < 2);
	sf::Sprite game_over;
	game_over.setTexture(Textures::instance().get_Textures(gameFinished));
	m_m_gameWindow.draw(game_over);
	m_m_gameWindow.display();
	m_clock.restart();
	while (m_clock.getElapsedTime().asSeconds() < 5);
}
void Controller::printNextLvlTex()
{
	sf::Text solved;
	solved.setFont(Fonts::instance().get_Fonts(PipedFont_t));
	solved.setString("Well Done level solved");
	solved.setPosition(sf::Vector2f(100, 400));
	solved.setCharacterSize(100);
	solved.setFillColor(sf::Color::Red);
	solved.setOutlineThickness(1);
	m_m_gameWindow.draw(solved);
	m_m_gameWindow.display();
	m_clock.restart();
	while (m_clock.getElapsedTime().asSeconds() < 3);
}
*/