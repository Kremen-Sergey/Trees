#pragma once
#include "..\BinaryTree\BinaryTree.h"
#include "..\SearhTree\ISearhTree.hpp"
#include <vector>

template<class Tkey, class Tvalue>
class SearhTree : public virtual BinaryTree<Tkey, Tvalue >, public virtual ISearhTree <Tkey, Tvalue >
{
protected:
	int(*compareKey)(Tkey x, Tkey y);
	vector<Tvalue> inOrderForGetAsSortedArray(Node<Tkey, Tvalue> *leaf, vector<Tvalue> vect);

public:
	SearhTree(Tkey(*getK)(Tvalue value), int(*compareKey)(Tkey x, Tkey y));
	virtual ~SearhTree();
	//for IBinaryTree already define in BinaryTree	
	//for ISearhTree
	virtual Tvalue *SearchValueByKey(Tkey key);
	void Add(Tvalue value);
	vector<Tvalue> GetAsSortedArray();

private:
		virtual Node<Tkey, Tvalue> *searchByKey(Tkey key, Node<Tkey, Tvalue> *leaf);
		virtual Node<Tkey, Tvalue>* add(Tvalue value, Node<Tkey, Tvalue> *leaf);
};