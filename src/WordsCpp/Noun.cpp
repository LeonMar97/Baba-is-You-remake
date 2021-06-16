#pragma once
#include "Noun.h"
#include "Board.h"

Noun::Noun(const std::string& word, const AnimationData& animationData,
	Direction dir, const sf::Vector2u& loc, const sf::Color& darker, const sf::Color& lighter)
	: Predicate(word, animationData, dir, loc, darker, lighter)
{}

std::type_index Noun::baseTypeId() {
	return typeid(Noun);
}
//adds atribute if rull is made 
void Noun::fillAttributes(Attribute* atr) {
	this->getStaticRepresentation().emplace(atr);
}
//removes all of the atributes of the current Noun refrences static member if its objects class 
void Noun::removeAttribute(Attribute* atr) {
	auto &attributes = this->getStaticRepresentation();
	auto del = attributes.find(atr);
	attributes.erase(del);
}


void Noun::putRuleIntoAffect(Noun& noun, Board& board) {
	//board.replace(m_objectCreationEnum, noun.m_objectCreationEnum, m_objectCreationChar);
}

