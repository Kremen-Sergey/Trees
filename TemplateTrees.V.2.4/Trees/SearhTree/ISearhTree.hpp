#pragma once
#include <vector>

template<class Tkey, class Tvalue>
class ISearhTree: public virtual IBinaryTree<Tkey, Tvalue>
{
public:
	virtual vector<Tvalue> GetAsSortedArray() = 0;
};