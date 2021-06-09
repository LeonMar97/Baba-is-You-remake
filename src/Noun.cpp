#pragma once
#include "Noun.h"
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
	board.replace(m_objectId, noun.m_objectId);
}
