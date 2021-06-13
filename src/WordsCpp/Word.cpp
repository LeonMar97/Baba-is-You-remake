#include "PushWord.h"

std::unordered_set<Attribute*> Word::m_wordAttributes = std::unordered_set<Attribute*>{ new PushWord({0,0}) };

Word::Word(const std::string& word, const AnimationData& animationData,
	Direction dir, const sf::Vector2u& loc)
	: m_word(word), BaseObject(animationData, dir, loc)
{}

Word::Word(const std::string& word, const AnimationData& animationData,
	Direction dir, const sf::Vector2u& loc, const sf::Color& color)
	: m_word(word), BaseObject(animationData, dir, loc, color)
{}
std::unordered_set<Attribute*>& Word::getStatic() {
	return Word::m_wordAttributes;
}
