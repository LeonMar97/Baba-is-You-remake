#include "Textures.h" 

Textures& Textures::instance() {
	static Textures all_So;
	return all_So;
}

void Textures::loadPic(sf::Texture& tex, const std::string& texName, GameTextures curTex) {
	if (!tex.loadFromFile(texName)) throw std::exception((texName +
		" does not exist, please check CMake or give a valid file name\n").data());
	tex.setSmooth(true);
	m_gameTex.insert(std::pair<GameTextures, sf::Texture>(curTex, tex));
}

//set textures for all object in the game once
//all textures created here in a temporary variable, and are inserted into the map using copy constructors
Textures::Textures() {
	sf::Texture pic;
	auto texName = std::string();

	texName = "Baba.png";
	loadPic(pic, texName, babas_t);

	texName = "rock.png";
	loadPic(pic, texName, rocks_t);

	texName = "flags.png";
	loadPic(pic, texName, flags_t);

	texName = "is.png";
	loadPic(pic, texName, is_t);

	texName = "Babaword.png";
	loadPic(pic, texName, babaword_t);
}