#pragma once
#include <vector>
#include"BaseDataHolder.h"
template<typename T>
class DataHolder:public BaseDataHolder {
	//friend class BaseDataHolder; 
	private:
	std::vector<T>m_objects;
};