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
	std::type_index wordTypeId() override { return typeid(Word); } //need to check if can make this prettier

	static std::unordered_set<Attribute*> m_wordAttributes;
	std::unordered_set<Attribute*>& getStatic()override;
	

protected:
	std::string m_word;//for displaying
private:
};