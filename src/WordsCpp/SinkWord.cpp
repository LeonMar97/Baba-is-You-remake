#include"SinkWord.h"
#include "OperationRemove.h"
#include "OperationMove.h"
#include "Factory.h"

bool SinkWord::m_registerit = Factory::registerit('l',
	[](const sf::Vector2u& loc, Board& board) -> PairObjData {
		auto obj = std::make_shared<SinkWord>(loc, board);
		auto dh = std::make_unique<DataHolder>(obj);
		return std::make_pair(obj, std::move(dh));
	});
SinkWord::SinkWord(const sf::Vector2u& loc, Board& board)
	:Attribute("Sink",Resources::instance().animationData(sinkword_t), Direction::Stay, loc, WATER_COLOR,
		WATER_LIGHTER_COLOR, std::make_shared<CollisionStrategySink>(board))
{}

