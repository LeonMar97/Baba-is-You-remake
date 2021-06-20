#include"SinkWord.h"
#include "OperationRemove.h"
#include "OperationMove.h"
#include "Factory.h"

bool SinkWord::m_registerit = Factory::registerit('l',
	[](const sf::Vector2u& loc) -> std::pair<std::shared_ptr<BaseObject>, std::unique_ptr<DataHolder>> {
		auto obj = std::make_shared<SinkWord>();
		auto dh = std::make_unique<DataHolder>(obj);
		return std::make_pair(obj, dh);
	});
SinkWord::SinkWord(const sf::Vector2u& loc, Board& board)
	:Attribute("Sink",Resources::instance().animationData(sinkword_t), Direction::Stay, loc, WATER_COLOR,
		WATER_LIGHTER_COLOR), m_board(board)
{}

bool SinkWord::handleCollision(BaseObject* passiveObj, BaseObject* activeObj) {
	activeObj->undoOperation(); //for active object positioning after redo
	//remove both objects from board using operationRemove
	activeObj->executeOperation(new OperationRemove(m_board)); 
	passiveObj->executeOperation(new OperationRemove(m_board));
	return false;
}
