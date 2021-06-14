#include "Attribute.h"

void Attribute::putRuleIntoAffect(Noun& noun) {
	noun.fillAttributes(this);
}

std::type_index Attribute::baseTypeId() {
	return typeid(Attribute);
}

void Attribute:: deleteRule(Noun& curNoun) {
	curNoun.removeAttribute(this);
}
