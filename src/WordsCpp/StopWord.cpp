#include"StopWord.h"
#include "Factory.h"
bool StopWord::m_registerit = Factory::registerit('s',
	[](const sf::Vector2u& loc, Board&) -> PairObjData {
		auto obj = std::make_shared<StopWord>(loc);
		auto dh = std::make_unique<DataHolder>(obj);
		return std::make_pair(obj, std::move(dh));
	});

StopWord::StopWord(const sf::Vector2u& loc)
	:Attribute("Stop",Resources::instance().animationData(stopword_t), Direction::Stay, loc, STOP_COLOR,
		STOP_LIGHTER_COLOR, std::make_shared<PropertyStop>())
{}


