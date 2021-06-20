#include "Factory.h"
std::pair<std::shared_ptr<BaseObject>, std::unique_ptr<DataHolder>> Factory::create(char c, const sf::Vector2u& loc) {
	auto it = Factory::getMap().find(c);
	if (it == Factory::getMap().end())
		return std::make_pair(nullptr, nullptr);
	return it->second(loc);
}

bool Factory::registerit(char c, pFnc f) {
	Factory::getMap().emplace(c, f);
	return true;
}

