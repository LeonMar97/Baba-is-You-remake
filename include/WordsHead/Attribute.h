#pragma once
#include "Predicate.h"
#include "Noun.h"
#include "Property.h"
class Attribute :public Predicate {
public:
	//using Predicate::Predicate;
	Attribute(const std::string& word,
		const AnimationData& animationData,
		Direction dir,
		const sf::Vector2u& loc,
		const sf::Color&,
		const sf::Color&,
		const std::shared_ptr<Property>&);

	virtual void putRuleIntoAffect(Noun&);
	virtual void deleteRule(Noun&)override;
	std::type_index baseTypeId() override;
	virtual bool move(BaseObject&, const Direction&);
private:
//the relevant object is equipped with a property once the relevant rule is detected
	std::shared_ptr<Property> m_equipProperty; 
};
