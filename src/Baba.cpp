#include "Baba.h" 
std::unordered_set<Attribute*>Baba::m_babaAtributes = std::unordered_set<Attribute*>();

Baba::Baba(const sf::Vector2u& loc)
:BaseObject(Textures::instance().get_Textures(babas_t), BABA_IMG_COUNT, loc)
{
	
}

/*
bool Baba::move(Board* board, BaseObject* you, const sf::Vector2i& dir) {
	return you->onMove(board, dir);
}
*/

bool Baba::onMove(Board* board, const sf::Vector2i& dir) {
	return true;
}
