#pragma once
#include "Word.h"
class Conjunction :public Word {
public:
	using Word::Word;
	const std::type_index& baseTypeId()override;
};

