#pragma once //preprocessor directive-concrete source file when compiling is included exactly once. Analog-include guard

template<class Tkey, class Tvalue>//class<=>typename
class IBinaryTree//class is abstract if at least one function is virtual without realisation;
{
public:
	virtual void Add(Tvalue value) =0;//*-By passing a pointer to the variable in the function, we do not make a copy of the variable and edit it directly.Place in memory stands out in heap (dynamic memory)
	virtual void DestroyTree() = 0;//=0-abstract function
	virtual void PreOrder() = 0;
	virtual void InOrder() = 0;
	virtual void PostOrder() = 0;
	virtual Tvalue *SearchValueByKey(Tkey key) = 0;
};
