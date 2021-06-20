#pragma once
#include "BaseObject.h"
#include "DataHolder.h"
#include "Board.h"
#include <map>

static PairObjData setSpace(const sf::Vector2u&, Board&) {
	return std::make_pair(nullptr, nullptr);
}

class Factory {
public:
	using pFnc = PairObjData(*)(const sf::Vector2u&, Board& board);
	static PairObjData create(char c, const sf::Vector2u& loc, Board& board);
	static bool registerit(char c, pFnc);
private:
	static auto& getMap() {
		static std::map<char, pFnc> map = std::map<char, pFnc>({ {' ', &setSpace} });
		return map;
	}
};