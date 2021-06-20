#include"Menu.h"
void Menu::add(unique_ptr<Command> c){
	m_options.emplace_back(option(move(c)));
}

Menu::Menu()
	:
		m_menuWindow(sf::VideoMode(1920, 1080), "Baba is you", sf::Style::Fullscreen),
		m_ButtonsRectangles{sf::RectangleShape(sf::Vector2f(430, 48)),sf::RectangleShape(sf::Vector2f(430, 48)), sf::RectangleShape(sf::Vector2f(430, 48))},
		m_cntrl(std::make_shared<Controller>(m_menuWindow))
{

	

	setView();
	setButtonsTextures();

	
	m_creators.push_back(std::make_unique<Header>(std::stringstream("GAME"), sf::Vector2f(650, 850), sf::Vector2f(1.f, 2.f), sf::Color::White));
	m_creators.push_back(std::make_unique<Header>(std::stringstream("CREATORS"), m_creators[0]->wordEnd(), sf::Vector2f(1.f, 2.f), sf::Color::White));
	m_creators.push_back(std::make_unique<Header>(std::stringstream("I"), m_creators[1]->wordEnd(), sf::Vector2f(1.f, 2.f), sf::Color::Red));
	m_creators[2]->m_sprites[0]->setRotation(90);
	m_creators[2]->m_sprites[0]->setPosition(m_creators[2]->m_sprites[0]->getPosition()+sf::Vector2f(50.f,15));

	m_creators.push_back(std::make_unique<Header>(std::stringstream("LEON"), sf::Vector2f(850, 950), sf::Vector2f(1.f, 2.f), sf::Color(217, 57, 106)));
	m_creators.push_back(std::make_unique<Header>(std::stringstream("AND"), m_creators[3]->wordEnd(), sf::Vector2f(1.f, 2.f), sf::Color::Red));
	m_creators.push_back(std::make_unique<Header>(std::stringstream("RONEN"), m_creators[4]->wordEnd(), sf::Vector2f(1.f, 2.f), sf::Color(217, 57, 106)));

	
	m_babaIsU.push_back(std::make_unique<Header>(std::stringstream("BABA"), sf::Vector2f(400, 100), sf::Vector2f(5.f, 15.f), sf::Color(217, 57, 106)));
	m_babaIsU.push_back(std::make_unique<Header>(std::stringstream("IS"), m_babaIsU[0]->wordEnd(), sf::Vector2f(5.f, 15.f), sf::Color(255, 255, 255)));
	m_babaIsU.push_back(std::make_unique<Header>(std::stringstream("U"), m_babaIsU[1]->wordEnd(), sf::Vector2f(5.f, 15.f), sf::Color(217, 57, 106)));






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
						deltaTime = m_animationClock.restart();
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

	m_menuWindow.setView(m_menuWindow.getDefaultView());
	sf::View view = m_menuWindow.getView();
	view.setCenter(sf::Vector2f(DEFAULT_SCREEN_WIDTH / 2.f, DEFAULT_SCREEN_HEIGHT / 2.f));
	auto prop = DEFAULT_SCREEN_WIDTH * DEFAULT_SCREEN_HEIGHT / float(m_menuWindow.getSize().x * m_menuWindow.getSize().y);
	view.zoom(prop);
	m_menuWindow.setView(view);



}
void Menu::draw(sf::Time &deltaTime) {
	
	for (auto & cur  : m_babaIsU) {
		cur->draw(deltaTime, m_animationClock, m_menuWindow);
	}
	for (auto& cur : m_creators) {
		cur->draw(deltaTime, m_animationClock, m_menuWindow);
	}
	m_menuWindow.draw(m_startGameButton);
	m_menuWindow.draw(m_loadLevelGameButton);
	m_menuWindow.draw(m_exitGameButton);


}
void Menu::setButtonsTextures() {
	auto texRect = sf::IntRect(0,0,428,48);
	auto pos = sf::Vector2f(750, 570);
	for (auto & curRec : m_ButtonsRectangles) {
		curRec.setTexture(&Resources::instance().texture(1));
		curRec.setTextureRect(texRect);
		curRec.setPosition(pos);
		texRect += sf::IntRect(0, 53, 0, 0);
			

		m_loadLevelGameButton.setTexture(&Resources::instance().texture(1));
		m_loadLevelGameButton.setTextureRect(sf::IntRect(0, 53, 428, 48));
		m_loadLevelGameButton.setPosition(sf::Vector2f(750, 624));


		m_exitGameButton.setTexture(&Resources::instance().texture(1));
		m_exitGameButton.setTextureRect(sf::IntRect(0, 107, 428, 48));
		m_exitGameButton.setPosition(sf::Vector2f(750, 678));


	}
}
