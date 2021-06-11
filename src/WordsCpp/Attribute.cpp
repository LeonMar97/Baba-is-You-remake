#include "Attribute.h"

void Attribute::putRuleIntoAffect(Noun& noun, Board& board) {
	noun.fillAttributes(this);
}
void Attribute::removeRule(Noun* noun) {
	noun->removeAttributes(this);
}

const std::type_index& Attribute::baseTypeId() {
	return typeid(Attribute);
}