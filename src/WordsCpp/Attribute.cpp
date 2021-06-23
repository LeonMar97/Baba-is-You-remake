#include "Attribute.h"
#include "NoOperation.h"
Attribute::Attribute(const std::string& word,
	const AnimationData& animationData,
	Direction dir,
	const sf::Vector2u& loc,
	const sf::Color& defaultColor,
	const sf::Color& lighterColor,
	const std::shared_ptr<Property>& Property)

	: Predicate(word, animationData, dir, loc, defaultColor, lighterColor),
	m_equipProperty(Property)
{}

void Attribute::putRuleIntoAffect(Noun& noun) {
	noun.fillAttributes(m_equipProperty);
}

std::type_index Attribute::baseTypeId() {
	return typeid(Attribute);
}

void Attribute:: deleteRule(Noun& curNoun) {
	curNoun.removeAttribute(m_equipProperty);
}

bool Attribute::move(BaseObject& baseObj, const Direction&) {
	//baseObj.executeOperation(new NoOperation());
	return false;
}
