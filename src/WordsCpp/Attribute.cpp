#include "Attribute.h"
#include "NoOperation.h"

void Attribute::putRuleIntoAffect(Noun& noun) {
	noun.fillAttributes(this);
}

std::type_index Attribute::baseTypeId() {
	return typeid(Attribute);
}

void Attribute:: deleteRule(Noun& curNoun) {
	curNoun.removeAttribute(this);
}

bool Attribute::move(BaseObject& baseObj, const Direction&) {
	baseObj.executeOperation(new NoOperation());
	return false;
}
