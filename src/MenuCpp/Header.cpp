#include "Header.h"
Header::Header(std::stringstream sentecnce) {

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


	while(sentecnce.rdbuf()->in_avail()){
		unsigned int latterLoc = 0;
		char curLetter;
		sentecnce >> curLetter;
		
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
	
}
/*

m_animations{
Animation(Resources::instance().animationData(letterA_t),Direction::Stay,m_sprites[0]),
Animation(Resources::instance().animationData(letterB_t),Direction::Stay,m_sprites[1]),
Animation(Resources::instance().animationData(letterC_t),Direction::Stay,m_sprites[2]),
Animation(Resources::instance().animationData(letterD_t),Direction::Stay,m_sprites[3]),
Animation(Resources::instance().animationData(letterE_t),Direction::Stay,m_sprites[4]),
Animation(Resources::instance().animationData(letterF_t),Direction::Stay,m_sprites[5]),
Animation(Resources::instance().animationData(letterG_t),Direction::Stay,m_sprites[6]),
Animation(Resources::instance().animationData(letterH_t),Direction::Stay,m_sprites[7]),
Animation(Resources::instance().animationData(letterI_t),Direction::Stay,m_sprites[8]),
Animation(Resources::instance().animationData(letterL_t),Direction::Stay,m_sprites[9]),
Animation(Resources::instance().animationData(letterM_t),Direction::Stay,m_sprites[10]),
Animation(Resources::instance().animationData(letterN_t),Direction::Stay,m_sprites[11]),
Animation(Resources::instance().animationData(letterO_t),Direction::Stay,m_sprites[12]),
Animation(Resources::instance().animationData(letterR_t),Direction::Stay,m_sprites[13]),
Animation(Resources::instance().animationData(letterS_t),Direction::Stay,m_sprites[14]),
Animation(Resources::instance().animationData(letterT_t),Direction::Stay,m_sprites[15]),
Animation(Resources::instance().animationData(letterU_t),Direction::Stay,m_sprites[16]),
Animation(Resources::instance().animationData(letterV_t),Direction::Stay,m_sprites[17]),
Animation(Resources::instance().animationData(letterW_t),Direction::Stay,m_sprites[18]),
Animation(Resources::instance().animationData(letterX_t),Direction::Stay,m_sprites[19])
	}
*/
