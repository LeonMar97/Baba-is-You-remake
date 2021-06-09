#include "Word.h"
Word::Word(const std::string & word, const sf::Texture& tex,
	const sf::Vector2u& imgCount, const sf::Vector2u& loc, GameObjects id)
		:m_word(word),BaseObject(tex,imgCount,loc, id){}
