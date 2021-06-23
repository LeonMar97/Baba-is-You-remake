#include"DefeatWord.h"
#include "Factory.h"
bool DefeatWord::m_registerit = Factory::registerit('d',
	[](const sf::Vector2u& loc, Board& board) -> PairObjData {
		auto obj = std::make_shared<DefeatWord>(loc, board);
		auto dh = std::make_unique<DataHolder>(obj);
		return std::make_pair(obj, std::move(dh));
	});

DefeatWord::DefeatWord(const sf::Vector2u& loc, Board& board)
	:Attribute("Defeat",Resources::instance().animationData(defeatword_t), Direction::Stay, loc, DEFEAT_COLOR,
		DEFEAT_LIGHTER_COLOR, std::make_shared<PropertyDefeat>(board))
{}
