#pragma once
#include "stdafx.h"
#include "BinaryTree.h"
#include <iostream>
using namespace std;

//protected

template<class Tkey, class Tvalue>
void BinaryTree<Tkey, Tvalue>::destroyTree(Node<Tkey, Tvalue> *&leaf) //*leaf passing by pointer, & - operation of taking address, *&leaf - pointer come by adress, means pointer can be changed. We delete object not copy so we need to change the real address
{
	if (leaf != NULL)
	{
		destroyTree(leaf->left);
		destroyTree(leaf->right);
		delete leaf;
	}
}

//preorder
template<class Tkey, class Tvalue>
void BinaryTree<Tkey, Tvalue>::preOrder(Node<Tkey, Tvalue> *leaf)
{
	if (leaf != NULL)
	{
		leaf->print(getK);
		preOrder(leaf->left);
		preOrder(leaf->right);
	}
}

//inorder
template<class Tkey, class Tvalue>
void BinaryTree<Tkey, Tvalue>::inOrder(Node<Tkey, Tvalue> *leaf)
{
	if (leaf != NULL)
	{
		inOrder(leaf->left);
		leaf->print(getK);
		inOrder(leaf->right);
	}
}

//postorder
template<class Tkey, class Tvalue>
void BinaryTree<Tkey, Tvalue>::postOrder(Node<Tkey, Tvalue> *leaf)
{
	if (leaf != NULL)
	{
		postOrder(leaf->left);
		postOrder(leaf->right);
		leaf->print(getK);
	}
}

template<class Tkey, class Tvalue>
Tvalue *BinaryTree<Tkey, Tvalue>::SearchValueByKey(Node<Tkey, Tvalue> *leaf, Tkey key, Tvalue **result)
{
	if (*result) return (*result);
	if (leaf != NULL)
	{
		Tkey k = getK(leaf->value);
		if (k == key) {

			*result = &(leaf->value);

			return (*result);
		}
		SearchValueByKey(leaf->left, key, result);
		SearchValueByKey(leaf->right, key, result);
	}
	if (*result) return (*result); else 	return NULL;
}

//count
template<class Tkey, class Tvalue>
int BinaryTree<Tkey, Tvalue>::count(Node<Tkey, Tvalue> * leaf)
{
	if (leaf == NULL)
		return 0;
	return count(leaf->right) + count(leaf->left) + 1;
}

//public

//constructor
template<class Tkey, class Tvalue>
BinaryTree<Tkey, Tvalue>::BinaryTree(Tkey(*getK)(Tvalue value))
{
	root = NULL;
	size = 0;
	this->getK = getK;
}

//destructor
template<class Tkey, class Tvalue>
BinaryTree<Tkey, Tvalue>::~BinaryTree()
{
	if (root != NULL)
	{
		DestroyTree();
	}
}

//Add value
template<class Tkey, class Tvalue>
void BinaryTree<Tkey, Tvalue>::Add(Tvalue value)
{	
	Node<Tkey, Tvalue>** ptrNode = &root;
	int index = ++size;
	while (index != 1)
	{
		ptrNode = &((index % 2) == 0 ? (*ptrNode)->left : (*ptrNode)->right);
		index /= 2;
	}
	*ptrNode = new Node<Tkey, Tvalue>(value);  
	(*ptrNode)->left = NULL;
	(*ptrNode)->right = NULL;
}

template<class Tkey, class Tvalue>
void BinaryTree<Tkey, Tvalue>::DestroyTree()
{
	if (root != NULL)
		destroyTree(root);
}

template<class Tkey, class Tvalue>
void BinaryTree<Tkey, Tvalue>::PreOrder()
{
	if (root == NULL)
	{
		cout << "Tree is empty" << endl;
		return;
	}
	preOrder(root);
}

template<class Tkey, class Tvalue>
void BinaryTree<Tkey, Tvalue>::InOrder()
{
	if (root == NULL)
	{
		cout << "Tree is empty" << endl;
		return;
	}
	inOrder(root);
}

template<class Tkey, class Tvalue>
void BinaryTree<Tkey, Tvalue>::PostOrder()
{
	if (root == NULL)
	{
		cout << "Tree is empty" << endl;
		return;
	}
	postOrder(root);
}

template<class Tkey, class Tvalue>
Tvalue *BinaryTree<Tkey, Tvalue>::SearchValueByKey(Tkey key)
{
	if (root == NULL)
	{
		cout << "Tree is empty" << endl;
		return NULL;
	}
	Tvalue  *result = NULL;
	return SearchValueByKey(root, key, &result);
}

