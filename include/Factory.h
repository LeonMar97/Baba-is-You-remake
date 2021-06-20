#pragma once
#include "BaseObject.h"
#include "DataHolder.h"
#include "Board.h"
#include <map>

//for allowing spaces, every letter that is not created by one of the objects or space
//will throw an exception
static PairObjData setSpace(const sf::Vector2u&, Board&) {
	return std::make_pair(nullptr, nullptr);
}

class Factory {
public:
	//pairObj data is pair of BaseObject and DataHolder. Both are connected together and created together
	using pFnc = PairObjData(*)(const sf::Vector2u&, Board& board);
	static PairObjData create(char c, const sf::Vector2u& loc, Board& board);
	static bool registerit(char c, pFnc);
private:
	static auto& getMap() {
		static std::map<char, pFnc> map = std::map<char, pFnc>({ {' ', &setSpace} });
		return map;
	}
};