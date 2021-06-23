#include "PushWord.h"

PropertySet Word::m_wordAttributes = PropertySet{};

Word::Word(const std::string& word, const AnimationData& animationData,
	Direction dir, const sf::Vector2u& loc, const sf::Color& darkerColor, const sf::Color& lighterColor)
	: m_word(word), BaseObject(animationData, dir, loc, darkerColor), m_colorWordInRule(lighterColor)
{}
PropertySet& Word::getStatic() {
	return Word::m_wordAttributes;
}
void Word::setLighterColor() {
	m_sprite.setColor(m_colorWordInRule);
}
void Word::setDarkerColor() {
	setDefaultColor();
}
void Word::resetStatic() {
	
	auto &staticVec = this->getStatic();

	staticVec.clear();
	staticVec.insert(std::make_shared<PropertyPush>());
}