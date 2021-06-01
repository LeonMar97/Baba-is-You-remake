#include "Tile.h"

void Tile::addObject(BaseObject* baseObj) {
	m_baseObjects.push_back(baseObj);
}

void Tile::drawObj(sf::RenderWindow& window, float deltaTime) {
	m_baseObjects[0]->draw(window, deltaTime);
}
