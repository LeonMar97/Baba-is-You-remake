#include "PushWord.h"

std::unordered_set<Attribute*> Word::m_wordAttributes = std::unordered_set<Attribute*>{};

Word::Word(const std::string& word, const AnimationData& animationData,
	Direction dir, const sf::Vector2u& loc, const sf::Color& darkerColor, const sf::Color& lighterColor)
	: m_word(word), BaseObject(animationData, dir, loc, darkerColor), m_colorWordInRule(lighterColor)
{}
std::unordered_set<Attribute*>& Word::getStatic() {
	return Word::m_wordAttributes;
}
void Word::setLighterColor() {
	m_sprite.setColor(m_colorWordInRule);
}
void Word::setDarkerColor() {
	setDefaultColor();
}
