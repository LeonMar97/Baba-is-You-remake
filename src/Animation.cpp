#include "Animation.h"
#include"Macros.h"

Animation::Animation(sf::Texture& tex, const sf::Vector2u imageCount)
	: m_imgCount(imageCount), m_switchTime(SWITCH_TIME), m_totalTime(0.0f)
{
	m_curImg.x = 0; //initial image to be the first

	//initialize rectangle that will be the mask on the main texture
	texRect.width = tex.getSize().x / float(m_imgCount.x);
	texRect.height = tex.getSize().y / float(m_imgCount.y);
}

void Animation::update(int row, float deltaTime) {

	m_curImg.y = row; //set the desired row of animations in textures
	m_totalTime += deltaTime;

	if (m_totalTime >= m_switchTime) {
		m_totalTime -= m_switchTime; //could set to 0, smoother this way

		m_curImg.x++; //if switch time is up, set next image in row
		if (m_curImg.x >= m_imgCount.x) {
			m_curImg.x = 0; ///reset if row is over
		}
	}
	//update IntRect
	texRect.left = m_curImg.x * texRect.width;
	texRect.top = m_curImg.y * texRect.height;
}
