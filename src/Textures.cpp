#include "Textures.h" 

Textures& Textures::instance() {
	static Textures all_So;
	return all_So;
}

void Textures::loadPic(sf::Texture& tex, const std::string& texName, gameTextures curTex) {
	if (!tex.loadFromFile(texName)) throw std::exception((texName +
		" does not exist, please check CMake or give a valid file name\n").data());
	tex.setSmooth(true);
}

//set textures for all object in the game once
//all textures created here in a temporary variable, and are inserted into the map using copy constructors
Textures::Textures() {
	sf::Texture pic;
	auto texName = std::string();



}