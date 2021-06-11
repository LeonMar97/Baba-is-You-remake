#pragma once
#include <string>
#include "BaseObject.h"
#include "Macros.h"
class Noun;
class Word:public BaseObject {
public:
	Word(const std::string& word, const AnimationData& animationData, Direction dir, const sf::Vector2u& loc);
	Word(const std::string& word, const AnimationData& animationData, Direction dir, const sf::Vector2u& loc, const sf::Color&);
	virtual bool operator==(const Word& word) { return this == &word; }
	virtual void putRuleIntoAffect(Noun&, Board&) {}

protected:
	std::string m_word;//for displaying
private:
};