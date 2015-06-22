#pragma once
#include "IBinaryTree.hpp"
#include "..\Nodes\Node.hpp"

//Only add, print and desroy. PreOrder, InOrder, PostOrder, DestroyTree - for all trees.
//Add only for non balance tree: SearhTree. In balance trees must be ather function.

template<class Tkey, class Tvalue>
class BinaryTree : public virtual IBinaryTree<Tkey, Tvalue>
{

private:
	//region variables fields
protected://protected: is open to children
	//protected fields
	Node<Tkey, Tvalue> *root;
	Tkey(*getK)(Tvalue value);
	int size;		//Only for this class. Children do not have access!
	//protected functions
	virtual void destroyTree(Node<Tkey, Tvalue> *&leaf);
	virtual void preOrder(Node<Tkey, Tvalue> *leaf);
	virtual void inOrder(Node<Tkey, Tvalue> *leaf);
	virtual void postOrder(Node<Tkey, Tvalue> *leaf);
	Tvalue *SearchValueByKey(Node<Tkey, Tvalue> *leaf, Tkey key, Tvalue **result);

	int count(Node<Tkey, Tvalue> * leaf);
	
public:
	BinaryTree(Tkey(*getK)(Tvalue value));
	virtual ~BinaryTree();//destructor virtual for inheritance
	//for IBinaryTree 
	void Add(Tvalue value);
	void DestroyTree();
	void PreOrder();
	void InOrder();
	void PostOrder();
	virtual Tvalue *SearchValueByKey(Tkey key);//for IBinaryTree end
	
};
