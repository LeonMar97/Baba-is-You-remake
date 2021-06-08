#pragma once
#include <vector>
#include"BaseDataHolder.h"
template<typename T>
class DataHolder:public BaseDataHolder {
	public:
	friend class BaseDataHolder;
	friend class Board;
	std::vector<T>m_objects;
};