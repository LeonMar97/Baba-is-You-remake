#pragma once
#include "Noun.h"
#include "Board.h"
Noun::Noun(const std::string& word, const sf::Texture& tex, const sf::Vector2u& imgCount,
	const sf::Vector2u& loc,  char objectCreationChar, GameObjects objectCreationEnum)
	: m_objectCreationChar(objectCreationChar), m_objectCreationEnum(objectCreationEnum), Word(word, tex, imgCount, loc)
{}

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
