#include "Textures.h" 

Textures& Textures::instance() {
	static Textures all_So;
	return all_So;
}

void Textures::loadPic(sf::Texture& tex, const std::string& texName,pipeTextures curpipe) {
	if (!tex.loadFromFile(texName)) throw std::exception((texName +
							" does not exist, please check CMake or give a valid file name\n").data());
	tex.setSmooth(true);
	m_pipeTex.insert(std::pair<pipeTextures, sf::Texture>(curpipe, tex));
}

//set textures for all object in the game once
//all textures created here in a temporary variable, and are inserted into the map using copy constructors
Textures::Textures() {
	sf::Texture pic;
	auto texName = std::string();

	texName = "CurvedPipe2.png";
	loadPic(pic, texName, curvedPipe_t);
	

	texName = "straightPipe - Copy.png";
	loadPic(pic, texName, straightPipe_t);
	

	texName = "bg2.png";
	loadPic(pic, texName, background_t);
	

	texName = "menu.png";
	loadPic(pic, texName, menu_t);
	pic.setRepeated(true);
	
	
	texName = "threePipe.png";
	loadPic(pic, texName, threeWayPipe_t);
	
	texName = "k.png";
	loadPic(pic, texName, sink_t);


	texName = "b.png";
	loadPic(pic, texName, tap_t);

	texName = "gameFinished.png";
	loadPic(pic, texName, gameFinished);
}
