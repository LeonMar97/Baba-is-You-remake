#pragma once
#include"Noun.h"
#include"Conjunction.h"
#include "Attribute.h"

class Rule {

	Rule(Noun, Conjunction, Noun);
	Rule(Noun, Conjunction, Attribute);

};