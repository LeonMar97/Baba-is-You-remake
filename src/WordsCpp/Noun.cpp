#pragma once
#include "Noun.h"
#include "Board.h"
Noun::Noun(const std::string& word, const AnimationData& animationData,
	Direction dir, const sf::Vector2u& loc,
	char objectCreationChar, GameObjects objectCreationCharEnum)
	: m_objectCreationChar(objectCreationChar), m_objectCreationEnum(objectCreationCharEnum), Predicate(word, animationData, dir, loc)
{}

Noun::Noun(const std::string& word, const AnimationData& animationData,
	Direction dir, const sf::Vector2u& loc, const sf::Color& color,
	char objectCreationChar, GameObjects objectCreationCharEnum)
	: m_objectCreationChar(objectCreationChar), m_objectCreationEnum(objectCreationCharEnum), Predicate(word, animationData, dir, loc, color)
{}

std::type_index Noun::baseTypeId() {
	return typeid(Noun);
}
//adds atribute if rull is made 
void Noun::fillAttributes(Attribute* atr) {
	this->getStatic().emplace(atr);
}
//removes all of the atributes of the current Noun refrences static member if its objects class 
void Noun::removeAttributes(Attribute* atr) {
	auto del = this->getStatic().find(atr);
	this->getStatic().erase(del);
}


void Noun::putRuleIntoAffect(Noun& noun, Board& board) {
	//board.replace(m_objectCreationEnum, noun.m_objectCreationEnum, m_objectCreationChar);
}
