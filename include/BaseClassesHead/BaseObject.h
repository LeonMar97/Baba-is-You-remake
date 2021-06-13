#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Macros.h"
#include <typeinfo>
#include <typeindex>

#include "Resources.h"
#include<unordered_set>
//base class for every object on the screen
class Attribute;
class Board;
class BaseObject {

public:

	BaseObject(const AnimationData& animationData, Direction dir, const sf::Vector2u& loc);
	BaseObject(const AnimationData& animationData, Direction dir, const sf::Vector2u& loc, const sf::Color&);
	

	virtual std::unordered_set<Attribute*>& getStatic() = 0;
	void draw(sf::RenderWindow& window, sf::Time deltaTime);
	void move(const sf::Vector2i&);
	bool collidesWith(BaseObject*);
	virtual void handleCollision(BaseObject*, BaseObject* obj);
	virtual std::type_index baseTypeId();
	sf::Vector2f returnPos()const;
	sf::Vector2f returnLastPos()const;
	void triggerAttribute(BaseObject*);
	virtual std::type_index wordTypeId();
	sf::Vector2u castToLoc(sf::Vector2f spritePos);
protected:
	sf::Sprite m_sprite;
	Animation m_animation;
	sf::Vector2f m_lastPos;
private:
};
