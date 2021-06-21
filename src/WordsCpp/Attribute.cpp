#include "Attribute.h"
#include "NoOperation.h"
Attribute::Attribute(const std::string& word,
	const AnimationData& animationData,
	Direction dir,
	const sf::Vector2u& loc,
	const sf::Color& defaultColor,
	const sf::Color& lighterColor,
	const std::shared_ptr<CollisionStrategy>& collisionStrategy)

	: Predicate(word, animationData, dir, loc, defaultColor, lighterColor),
	m_equipStrategy(collisionStrategy)
{}

void Attribute::putRuleIntoAffect(Noun& noun) {
	noun.fillAttributes(m_equipStrategy);
}

std::type_index Attribute::baseTypeId() {
	return typeid(Attribute);
}

void Attribute:: deleteRule(Noun& curNoun) {
	curNoun.removeAttribute(m_equipStrategy);
}

bool Attribute::move(BaseObject& baseObj, const Direction&) {
	//baseObj.executeOperation(new NoOperation());
	return false;
}
