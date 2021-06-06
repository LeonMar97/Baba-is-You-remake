#pragma once
#include "Noun.h"
//adds atribute if rull is made 
void Noun::fillAttributes(Attribute* atr) {
	this->getStatic().emplace(atr);
}
//removes all of the atributes of the current Noun refrences static member if its objects class 
void Noun::removeAttributes() {
	this->getStatic().clear();
}

