#pragma once
#include "Word.h"
class Conjunction :public Word {
public:
	using Word::Word;
	std::type_index baseTypeId()override;
};

