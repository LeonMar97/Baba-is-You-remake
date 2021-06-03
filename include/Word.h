#pragma once
#include <string>
#include "BaseObject.h"
class Word:public BaseObject {
public:
	 Word(std::string word, const sf::Texture& tex, const sf::Vector2u& imgCount, const sf::Vector2u& loc);
protected:
	std::string m_word;//for displaying
};