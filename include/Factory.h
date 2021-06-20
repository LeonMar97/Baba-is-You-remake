#pragma once
#include "BaseObject.h"
#include <map>
class Factory {
public:
	using pFnc = std::pair<std::shared_ptr<BaseObject>, std::unique_ptr<DataHolder>>(*)(const sf::Vector2u&);
	static std::pair<std::shared_ptr<BaseObject>, std::unique_ptr<DataHolder>> create(char c, const sf::Vector2u& loc);
	static bool registerit(char c, pFnc);
private:
	static auto& getMap() {
		static std::map<char, pFnc> map;
		return map;
	}
};
