#pragma once
#include <string>
#include "BaseObject.h"
#include "Macros.h"
class Noun;
class Word:public BaseObject {
public:
	 Word(const std::string& word, const sf::Texture& tex, const sf::Vector2u& imgCount, const sf::Vector2u& loc, GameObjects id);
	virtual bool operator==(const Word& word) { return this == &word; }
	virtual void putRuleIntoAffect(Noun&, Board&) {}

protected:
	std::string m_word;//for displaying
};