#include "RuleHandling.h"


void  RuleHandling::processCollision(BaseObject& object1, BaseObject& object2, BaseObject& object3)
{
    if (auto phf = lookup(typeid(object1), typeid(object2), typeid(object3)))
    {
        //the current tuple is a rule 

    }
    //else it does nothing because the current rule 

}


RuleToFunctionMap RuleHandling:: initializeCollisionMap(){
    RuleToFunctionMap map;
    map[Key( typeid(Noun), typeid(Conjunction), typeid(Attribute) )] = &NounConAtr;
    map[Key( typeid(Noun), typeid(Conjunction), typeid(Noun)      )] = &NounConNoun;
    return map;
}

FunctionPtr RuleHandling::lookup(const std::type_index& class1, const std::type_index& class2, const std::type_index& class3) {
    static RuleToFunctionMap ruleMap = initializeCollisionMap();
    auto mapEntry = ruleMap.find(std::make_tuple(class1, class2,class3));
    if (mapEntry == ruleMap.end()){
        return nullptr;
    }
    return mapEntry->second;
}
