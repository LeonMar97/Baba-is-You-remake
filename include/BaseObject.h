#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Macros.h"
#include "Textures.h"
#include<unordered_set>
//base class for every object on the screen
class Attribute;
class Board;
class BaseObject {

public:

	BaseObject(const sf::Texture& tex, const sf::Vector2u& imgCountAnim, const sf::Vector2u&);
	/// <summary>
	///DONT FORGET TO MAKE IT DUCKING ABSTRCUT STUPID !!!!!!!!
	/// !!!!!!!!!!!!
	/// !!!!!!!!!!!!!!
	/// !!!!!!!!!!!
	/// !!!!!!!!!!!!!!
	/// !!!!!!!!!!!
	/// 
	/// </summary>
	/// <returns></returns>
	virtual std::unordered_set<Attribute*>& getStatic() { return *(new std::unordered_set<Attribute*>()); } //returns spesific static varible which located at each derived class
	void draw(sf::RenderWindow& window, float deltaTime);
	void move(const sf::Vector2i&);
	bool collidesWith(BaseObject*);
	void handleCollision(Board *board, BaseObject* obj);

	sf::Vector2f returnPos()const;

	bool operator<(const BaseObject&) const;
protected:
	sf::RectangleShape m_character;
	Animation m_animation;
private:
	sf::Vector2f m_lastPos;
};