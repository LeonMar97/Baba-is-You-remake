#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Macros.h"
#include <typeinfo>
#include <typeindex>
#include "Direction.h"
#include <stack>
#include "BaseOperation.h"

#include "Resources.h"
#include<unordered_set>
//base class for every object on the screen
class Attribute;
class Board;
class DataHolder;
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
	void initializeDataHolder(DataHolder*);
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
	void setLastLoc();
	void executeOperation(BaseOperation*);
	void undoOperation();
	void removeOperation();
	BaseOperation* lastOp();
	void setNotOnBoard() { m_notOnBoard = true; }
	void setOnBoard() { m_notOnBoard = false; }
protected:
	sf::Sprite m_sprite;
	std::vector<Animation> m_animation;
	std::vector<Animation>::iterator m_currentAnimation; //to access animations more easily
	sf::Vector2f m_lastPos;
private:
	sf::Color m_defaultColor;
	DataHolder *m_dataHolder;
	bool m_notOnBoard = false;
};
