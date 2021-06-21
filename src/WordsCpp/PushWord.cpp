#include"PushWord.h"
#include "OperationMove.h"
#include "NoOperation.h"
#include "Factory.h"
bool PushWord::m_registerit = Factory::registerit('p',
	[](const sf::Vector2u& loc, Board&) -> PairObjData {
		auto obj = std::make_shared<PushWord>(loc);
		auto dh = std::make_unique<DataHolder>(obj);
		return std::make_pair(obj, std::move(dh));
	});

PushWord::PushWord(const sf::Vector2u& loc)
	:Attribute("Push",Resources::instance().animationData(pushword_t), Direction::Stay, loc, PUSH_COLOR,
		PUSH_LIGHTER_COLOR, std::make_shared<CollisionStrategyPush>(CollisionStrategyPush()))
{}