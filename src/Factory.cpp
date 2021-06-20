#include "Factory.h"
PairObjData Factory::create(char c, const sf::Vector2u& loc, Board& board) {
	auto it = Factory::getMap().find(c);
	if (it == Factory::getMap().end())
		throw std::invalid_argument(((std::string(1,c) 
						+ " is not a supprorted command, to see supported commands please go to README\n")).data());
	return it->second(loc, board);
}

bool Factory::registerit(char c, pFnc f) {
	Factory::getMap().emplace(c, f);
	return true;
}

