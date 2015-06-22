#pragma once
#include "stdafx.h"
#include "SearhTree.h"
#include <vector>

//public

//constructor
template<class Tkey, class Tvalue>
SearhTree<Tkey, Tvalue>::SearhTree(Tkey(*getK)(Tvalue value), int(*compareKey)(Tkey x, Tkey y)) :BinaryTree(getK) 
{
	this->compareKey = compareKey;
	root = NULL;
}

//destructor
template<class Tkey, class Tvalue>
SearhTree<Tkey, Tvalue>::~SearhTree()
{
	//destructor BinaryTree is called. root is variable of  BinaryTree. The memory is cleared.
}

//Add value
template<class Tkey, class Tvalue>
void SearhTree<Tkey, Tvalue>::Add(Tvalue value)
{
	root = add(value, root);
}

//SearchValueByKey
template<class Tkey, class Tvalue>
Tvalue *SearhTree<Tkey, Tvalue>::SearchValueByKey(Tkey key)
{
	Node <Tkey, Tvalue >* tempNode = searchByKey(key, root);
	return &tempNode->value;
}

//Get as sorted array
template<class Tkey, class Tvalue>
vector<Tvalue> SearhTree<Tkey, Tvalue>::GetAsSortedArray()
{
	vector<Tvalue> v = inOrderForGetAsSortedArray(root, v);
	return v;
}

//inOrderForGetAsSortedArray
template<class Tkey, class Tvalue>
vector<Tvalue> SearhTree<Tkey, Tvalue>::inOrderForGetAsSortedArray(Node<Tkey, Tvalue> *leaf, vector<Tvalue> vect)
{
	if (leaf != NULL)
	{
		vect=inOrderForGetAsSortedArray(leaf->left, vect);
		vect.push_back(leaf->value);
		vect=inOrderForGetAsSortedArray(leaf->right, vect);
	}
	return vect;
}


//private

template<class Tkey, class Tvalue>
Node<Tkey, Tvalue> *SearhTree<Tkey, Tvalue>::searchByKey(Tkey key, Node<Tkey, Tvalue> *leaf)
{
	if (leaf != NULL)
	{
		if (key == leaf->getKey(getK))
			return leaf;
		if (compareKey(key, leaf->getKey(getK))<0)
			return searchByKey(key, leaf->left);
		else
			return searchByKey(key, leaf->right);
	}
	else return NULL;
}

//add element to searhTree tree
template<class Tkey, class Tvalue>
Node<Tkey, Tvalue>* SearhTree<Tkey, Tvalue>::add(Tvalue value, Node<Tkey, Tvalue> *leaf)
{
	Tkey key = getK(value);
	if (leaf == NULL)
	{
		leaf = new Node<Tkey, Tvalue>(value);  //<=> leaf = new Node();leaf->key = key;leaf->value = value;
		leaf->left = NULL;
		leaf->right = NULL;
		return leaf;
	}
	else if (compareKey(key, leaf->getKey(getK))<0)
	{
		leaf->left = add(value, leaf->left);
	}
	else
	{
		leaf->right = add(value, leaf->right);
	}
	return leaf;
}






	




