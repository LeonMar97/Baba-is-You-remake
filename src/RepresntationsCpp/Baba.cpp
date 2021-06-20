#include "Baba.h" 
#include "Factory.h"
std::unordered_set<Attribute*>Baba::m_babaAttributes = std::unordered_set<Attribute*>();
bool Baba::m_registerit = Factory::registerit('B',
	[](const sf::Vector2u& loc) -> std::pair<std::shared_ptr<BaseObject>, std::unique_ptr<DataHolder>> { 
		auto obj = std::make_shared<Baba>();
		auto dh = std::make_unique<DataHolder>(obj);
		return std::make_pair(obj, dh);
	});


Baba::Baba(const sf::Vector2u& loc)
	:BaseObject(
		Resources::instance().animationData(babas_t),
		Resources::instance().animationData(babas1_t),
		Resources::instance().animationData(babas2_t),
		Resources::instance().animationData(babas3_t),
		Direction::Right, loc, sf::Color::White)
{}
std::type_index Baba::wordTypeId() {
	return typeid(BabaWord);
}

std::unordered_set<Attribute*>& Baba::getStatic() {
	return Baba::m_babaAttributes;
}
