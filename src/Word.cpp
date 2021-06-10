#include "Word.h"
Word::Word(const std::string& word, const AnimationData& animationData,
	Direction dir, const sf::Vector2u& loc)
	: m_word(word), BaseObject(animationData, dir, loc)
{}
