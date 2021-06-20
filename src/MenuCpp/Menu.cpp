#include"Menu.h"
void Menu::add(unique_ptr<Command> c){
	m_options.emplace_back(option(move(c)));
}

Menu::Menu(sf::RenderWindow &window)
:
	m_menuWindow(window)
{
	
	
}


void Menu::setView() {

	m_menuWindow.setView(m_menuWindow.getDefaultView());
	sf::View view = m_menuWindow.getView();
	view.setCenter(sf::Vector2f(DEFAULT_SCREEN_WIDTH / 2.f, DEFAULT_SCREEN_HEIGHT / 2.f));
	auto prop = DEFAULT_SCREEN_WIDTH * DEFAULT_SCREEN_HEIGHT / float(m_menuWindow.getSize().x * m_menuWindow.getSize().y);
	view.zoom(prop);
	m_menuWindow.setView(view);



}


