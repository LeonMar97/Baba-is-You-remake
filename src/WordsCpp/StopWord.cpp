#include"StopWord.h"
#include "Factory.h"
bool StopWord::m_registerit = Factory::registerit('s',
	[](const sf::Vector2u& loc) -> std::pair<std::shared_ptr<BaseObject>, std::unique_ptr<DataHolder>> {
		auto obj = std::make_shared<StopWord>();
		auto dh = std::make_unique<DataHolder>(obj);
		return std::make_pair(obj, dh);
	});

StopWord::StopWord(const sf::Vector2u& loc)
	:Attribute("Stop",Resources::instance().animationData(stopword_t), Direction::Stay, loc, STOP_COLOR,
		STOP_LIGHTER_COLOR)
{}

StopWord::StopWord()
	: Attribute("Stop", Resources::instance().animationData(stopword_t), Direction::Stay, {0,0}, sf::Color(144, 103, 62),
		sf::Color::Red)
{}

bool StopWord::handleCollision(BaseObject* passiveObj, BaseObject* activeObj) {
	//activeObj->undoOperation();
	activeObj->undoOperation();
	activeObj->executeOperation(new NoOperation()); //if hit a wall - act as if no operation was done
	return false; //it acts as if nothing was moved at all - so no further actions are needed
}
