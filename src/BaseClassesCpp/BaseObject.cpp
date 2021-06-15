#include "BaseObject.h"
#include <SFML/Graphics.hpp>
#include"Attribute.h"

BaseObject::BaseObject(const AnimationData& animationData, Direction dir, const sf::Vector2u& loc)
	: m_lastPos(loc.y* OBJECT_SIZE, loc.x* OBJECT_SIZE)
{
	m_sprite.setPosition(m_lastPos);
	m_animation.push_back(Animation(animationData, dir, m_sprite));
	m_currentAnimation = m_animation.begin();

}
BaseObject::BaseObject(const AnimationData& animData1,
	const AnimationData& animData2,
	const AnimationData& animData3,
	const AnimationData& animData4,
	Direction dir, const sf::Vector2u& loc) {

	m_sprite.setPosition(m_lastPos);
	m_animation.push_back(Animation(animData1, dir, m_sprite));
	m_animation.push_back(Animation(animData2, dir, m_sprite));
	m_animation.push_back(Animation(animData3, dir, m_sprite));
	m_animation.push_back(Animation(animData4, dir, m_sprite));
	m_currentAnimation = m_animation.begin();
}

BaseObject::BaseObject(const AnimationData& animationData, Direction dir, const sf::Vector2u& loc, const sf::Color& color)
	: m_lastPos(loc.y* OBJECT_SIZE, loc.x* OBJECT_SIZE)
{
	m_sprite.setPosition(m_lastPos);
	m_sprite.setColor(color);
	m_animation.push_back(Animation(animationData, dir, m_sprite));
	m_currentAnimation = m_animation.begin();
}

void BaseObject::draw(sf::RenderWindow& window, sf::Time deltaTime) {
	m_currentAnimation->update(deltaTime);
	window.draw(m_sprite);
}

void BaseObject::move(const Direction& dir) {
	m_lastPos = m_sprite.getPosition();
	m_sprite.move(50.f * toVector(dir));
	(m_currentAnimation == m_animation.end() - 1) ? (m_currentAnimation++) : m_currentAnimation = m_animation.begin();
	m_currentAnimation->direction(dir);

}

Direction BaseObject::getDir() {
	return m_currentAnimation->getDir();
}

sf::Vector2f BaseObject:: returnPos()const {
	return m_sprite.getPosition();
}
sf::Vector2f BaseObject:: returnLastPos()const {
	return m_lastPos;
}

//triggeting attributes once a collision is detected
bool BaseObject::triggerAttribute(BaseObject* objectMoved) {
	auto& attributes = getStatic();
	//dont forget to make sure the set is sorted
	if (!attributes.empty()) {
		return((*attributes.begin())->handleCollision(this, objectMoved));
		
	}
	return false;
}


//~~~~~~~~~~~~~~~~~~~~~~~~collisions~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool BaseObject::collidesWith(BaseObject* obj) {
	return m_sprite.getGlobalBounds().intersects(obj->m_sprite.getGlobalBounds());
}

bool BaseObject::handleCollision(BaseObject* passiveObject, BaseObject* activeObject) {
	//obj->m_sprite.setPosition(obj->m_lastPos);
	return false;
}
std::type_index BaseObject::baseTypeId() {
	 return typeid(BaseObject);
}

std::type_index BaseObject::wordTypeId() {
	return typeid(*this);
}
sf::Vector2u BaseObject::castToLoc(sf::Vector2f spritePos) {
	return sf::Vector2u(spritePos.y / OBJECT_SIZE, spritePos.x / OBJECT_SIZE);
}