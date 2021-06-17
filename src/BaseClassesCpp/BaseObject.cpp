#include "BaseObject.h"
#include <SFML/Graphics.hpp>
#include"Attribute.h"

BaseObject::BaseObject(const AnimationData& animData1,
	const AnimationData& animData2,
	const AnimationData& animData3,
	const AnimationData& animData4,
	Direction dir, const sf::Vector2u& loc, const sf::Color& defaultColor) 
	: m_lastPos(loc.y*OBJECT_SIZE, loc.x * OBJECT_SIZE),
		m_defaultColor(defaultColor){
	m_sprite.setPosition(m_lastPos);
	m_sprite.setColor(defaultColor);
	m_animation.push_back(Animation(animData1, dir, m_sprite));
	m_animation.push_back(Animation(animData2, dir, m_sprite));
	m_animation.push_back(Animation(animData3, dir, m_sprite));
	m_animation.push_back(Animation(animData4, dir, m_sprite));
	m_currentAnimation = m_animation.begin();
}

BaseObject::BaseObject(const AnimationData& animationData, Direction dir, const sf::Vector2u& loc, const sf::Color& defaultColor)
	: m_lastPos(loc.y* OBJECT_SIZE, loc.x* OBJECT_SIZE),
	m_defaultColor(defaultColor)
{
	m_sprite.setPosition(m_lastPos);
	m_sprite.setColor(defaultColor);
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
	//for making baba look like he walks, the animation is changed and iterator is set accordingly
	(m_currentAnimation == m_animation.end() || m_currentAnimation == m_animation.end() - 1) //if not at the end
		? m_currentAnimation = m_animation.begin() : (m_currentAnimation++);
	m_currentAnimation->direction(dir);

	auto pos = castToLoc(m_sprite.getPosition());
	
	if (pos.x < 0 || pos.y < 0 || pos.x > MAP_SIZE.x - 1 ||  pos.y > MAP_SIZE.y - 1) {
		move(opposite(dir));
	}
	updateLocOnStack();
}

void BaseObject::updateLocOnStack() {
	m_previousLoc.push(m_sprite.getPosition());
}

void BaseObject::setLastLoc() {
	if (!m_previousLoc.empty()) {
		m_sprite.setPosition(m_previousLoc.top());
		m_previousLoc.pop();
	}
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
	bool isMoved = false;
	auto& attributes = getStatic();
	//dont forget to make sure the set is sorted
	for (auto& atr : attributes) {
		if (atr->handleCollision(this, objectMoved))
			isMoved = true;
	}
	return isMoved;
}


//~~~~~~~~~~~~~~~~~~~~~~~~collisions~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool BaseObject::collidesWith(BaseObject* obj) {
	return m_sprite.getGlobalBounds().intersects(obj->m_sprite.getGlobalBounds());
}

bool BaseObject::handleCollision(BaseObject* passiveObject, BaseObject* activeObject) {
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

void BaseObject::setDefaultColor() {
	m_sprite.setColor(m_defaultColor);
}