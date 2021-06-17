#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Macros.h"
#include <typeinfo>
#include <typeindex>
#include "Direction.h"
#include <stack>

#include "Resources.h"
#include<unordered_set>
//base class for every object on the screen
class Attribute;
class Board;
class BaseObject {

public:

	
	//BaseObject(const AnimationData& animationData, Direction dir, const sf::Vector2u& loc);
	//constructor for initializing with color
	BaseObject(const AnimationData& animationData, Direction dir, const sf::Vector2u& loc, const sf::Color&);
	//constructor for multiple animations using same sprite
	BaseObject(const AnimationData& animData1,
		const AnimationData& animData2,
		const AnimationData& animData3,
		const AnimationData& animData4,
		Direction dir, const sf::Vector2u& loc, const sf::Color& color);

	virtual std::unordered_set<Attribute*>& getStatic() = 0;
	void draw(sf::RenderWindow& window, sf::Time deltaTime);
	void move(const Direction&);
	bool collidesWith(BaseObject*);
	Direction getDir();
	virtual bool handleCollision(BaseObject*, BaseObject* obj);
	virtual std::type_index baseTypeId();
	sf::Vector2f returnPos()const;
	sf::Vector2f returnLastPos()const;
	bool triggerAttribute(BaseObject*);
	virtual std::type_index wordTypeId();
	sf::Vector2u castToLoc(sf::Vector2f spritePos);
	void setDefaultColor();
	void updateLocOnStack();
	void setLastLoc();
	void removeTopLocStack(){ m_previousLoc.pop(); }
protected:
	sf::Sprite m_sprite;
	std::vector<Animation> m_animation;
	std::vector<Animation>::iterator m_currentAnimation;
	sf::Vector2f m_lastPos;
private:
	sf::Color m_defaultColor;
	std::stack<sf::Vector2f> m_previousLoc;
};
