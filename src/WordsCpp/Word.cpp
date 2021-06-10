#include "Word.h"
Word::Word(const std::string & word, const sf::Texture& tex,
	const sf::Vector2u& imgCount, const sf::Vector2u& loc)
		:m_word(word),BaseObject(tex,imgCount,loc){}
