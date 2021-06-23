#pragma once
#include <string>
#include "BaseObject.h"
#include "Macros.h"

class Noun;
class Word:public BaseObject {
public:
	//constructor for initializing with 2 colors for word for detecting rules
	Word(const std::string& word,
		const AnimationData& animationData,
		Direction dir,
		const sf::Vector2u& loc,
		const sf::Color&,
		const sf::Color&);
	virtual bool operator==(const Word& word) { return this == &word; }
	std::type_index wordTypeId() override { return typeid(Word); } //need to check if can make this prettier

	static PropertySet m_wordAttributes;
	PropertySet& getStatic()override;

	void setLighterColor();
	void setDarkerColor();

protected:
	std::string m_word;//for displaying
private:
	sf::Color m_colorWordInRule;
};