#include "Header.h"
Header::Header(std::stringstream word, const sf::Vector2f& startPosOfSentence, const sf::Vector2f& scaling, const sf::Color& cr){
	m_charToEnum.insert(std::pair<char, GameObjects >('A', letterA_t));
	m_charToEnum.insert(std::pair<char, GameObjects >('B', letterB_t));
	m_charToEnum.insert(std::pair<char, GameObjects >('C', letterC_t));
	m_charToEnum.insert(std::pair<char, GameObjects >('D', letterD_t));
	m_charToEnum.insert(std::pair<char, GameObjects >('E', letterE_t));
	m_charToEnum.insert(std::pair<char, GameObjects >('F', letterF_t));
	m_charToEnum.insert(std::pair<char, GameObjects >('G', letterG_t));
	m_charToEnum.insert(std::pair<char, GameObjects >('H', letterH_t));
	m_charToEnum.insert(std::pair<char, GameObjects >('I', letterI_t));
	m_charToEnum.insert(std::pair<char, GameObjects >('L', letterL_t));
	m_charToEnum.insert(std::pair<char, GameObjects >('M', letterM_t));
	m_charToEnum.insert(std::pair<char, GameObjects >('N', letterN_t));
	m_charToEnum.insert(std::pair<char, GameObjects >('O', letterO_t));
	m_charToEnum.insert(std::pair<char, GameObjects >('R', letterR_t));
	m_charToEnum.insert(std::pair<char, GameObjects >('S', letterS_t));
	m_charToEnum.insert(std::pair<char, GameObjects >('T', letterT_t));
	m_charToEnum.insert(std::pair<char, GameObjects >('U', letterU_t));
	m_charToEnum.insert(std::pair<char, GameObjects >('V', letterV_t));
	m_charToEnum.insert(std::pair<char, GameObjects >('W', letterW_t));
	m_charToEnum.insert(std::pair<char, GameObjects >('X', letterX_t));

	//m_sprites.resize(sentecnce.str().size());

	unsigned int latterLoc = 0;

	while(word.rdbuf()->in_avail()){
		char curLetter;
		word >> curLetter;
		
		auto curEnumData = m_charToEnum.find(curLetter);
		if (curEnumData == m_charToEnum.end()) {
			throw std::invalid_argument("the requested key doesnt exicts in the list of sprites or invalid letter");
		}
		else {
			m_sprites.push_back(std::make_unique<sf::Sprite>());
			m_animations.emplace_back(Animation(Resources::instance().animationData(curEnumData->second), Direction::Stay, *(m_sprites[latterLoc])));
			latterLoc++;
		}

	}
	setArt(startPosOfSentence, scaling,cr);
}
//creates the requetsed art of the current header ~ starting pos,size,color..
void Header::setArt(const sf::Vector2f & startPosOfSentence, const sf::Vector2f & scaling, const sf::Color& cr) {
	
	for (int i = 0; i < m_animations.size(); i++){
		m_sprites[i]->setScale(scaling);
		m_sprites[i]->setColor(cr);
		//auto letterSize = m_sprites[i]->getScale();
		m_sprites[i]->setPosition(startPosOfSentence + sf::Vector2f(i * (OBJECT_SIZE/2*scaling.x),0));
	}

}
//draws the sentence with animataion in current window
void Header::draw(const sf::Time& deltaTime, sf::Clock& m_animClock, sf::RenderWindow &drawingToWindow) {
	for (int i = 0; i < m_animations.size(); i++) {
		m_animations[i].update(deltaTime);
		drawingToWindow.draw(*m_sprites[i]);
	}

}
//function returns the last letter pos
const sf::Vector2f Header::wordEnd() {
	//auto r = m_sprites.size() - 1;
	auto s = m_sprites[0]->getScale().x;

	auto x = m_sprites[0]->getPosition() + sf::Vector2f((m_sprites.size()+1) * OBJECT_SIZE/2*s , 0);
	return (x);
}
