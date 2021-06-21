#pragma once
#include "Board.h"
#include <unordered_set>
#include"Attribute.h"

class Flag : public BaseObject{
public:
	//--------------public--------functions-----------------------//
	Flag(const sf::Vector2u& loc);//constractor for static member
	std::type_index wordTypeId()override;

								  //--------------private--------functions-----------------------//		
	//------------------members-----------------------------------//
	static std::unordered_set<Attribute*>m_flagAttributes;//static attributes for all babas
	std::set<std::shared_ptr<CollisionStrategy>> & getStatic() override;
private:
	static bool m_registerit;
};
