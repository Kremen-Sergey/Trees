#pragma once
#include "stdafx.h"
#include "AVLTree.h"
#include "iostream"
using namespace std;

//public

//Constructor
template<class Tkey, class Tvalue>
AVLTree<Tkey, Tvalue>::AVLTree(Tkey(*getK)(Tvalue value), int(*compareKey)(Tkey x, Tkey y)) :BinaryTree(getK/*, compareKey*/), SearhTree(getK, compareKey)
{
	root = NULL;
}

//Destructor
template<class Tkey, class Tvalue>
AVLTree<Tkey, Tvalue>::~AVLTree()
{
	//DestroyTree();//!!!!!!!!!!!!!!
}

//Add value
template<class Tkey, class Tvalue>
void AVLTree<Tkey, Tvalue>::Add(Tvalue value)
{
	//cout << "Add in AVLTree" << endl;
	root = add(value, root);
}

//Balance
template<class Tkey, class Tvalue>
void AVLTree<Tkey, Tvalue>::Balance()
{
	root = balance(root);
}

//Height
template<class Tkey, class Tvalue>
int AVLTree<Tkey, Tvalue>::Height()
{
	return height(root);
}

//private

//Height of AVL Tree
template<class Tkey, class Tvalue>
int AVLTree<Tkey, Tvalue>::height(Node<Tkey, Tvalue> *leaf)
{
	int h = 0;
	if (leaf!=NULL)
	{
		int l_height = height(leaf->left);
		int r_height = height(leaf->right);
		//int max_height = (int)max(l_height, r_height);
		int max_height;
		if (l_height > r_height) max_height = l_height; else max_height = r_height;
		h = max_height + 1;
	}
	return h;
}

//Height Difference
template<class Tkey, class Tvalue>
int AVLTree<Tkey, Tvalue>::diff(Node<Tkey, Tvalue> *leaf)
{
	int l_height = height(leaf->left);
	int r_height = height(leaf->right);
	int b_factor = l_height - r_height;
	return b_factor;
}

//Right-right rotation
template<class Tkey, class Tvalue>
Node<Tkey, Tvalue> *AVLTree<Tkey, Tvalue>::rr_rotation(Node<Tkey, Tvalue> *leaf)
{
	Node<Tkey, Tvalue> *temp;
	temp = leaf->right;
	leaf->right = temp->left;
	temp->left = leaf;
	return temp;
}

//Left-left rotation
template<class Tkey, class Tvalue>
Node<Tkey, Tvalue> *AVLTree<Tkey, Tvalue>::ll_rotation(Node<Tkey, Tvalue> *leaf)
{
	Node<Tkey, Tvalue> *temp;
	temp = leaf->left;
	leaf->left = temp->right;
	temp->right = leaf;
	return temp;
}

//Lefr-right rotation
template<class Tkey, class Tvalue>
Node<Tkey, Tvalue> *AVLTree<Tkey, Tvalue>::lr_rotation(Node<Tkey, Tvalue> *leaf)
{
	Node<Tkey, Tvalue> *temp;
	temp = leaf->left;
	leaf->left = rr_rotation(temp);
	return ll_rotation(leaf);
}

//Right-left rotation
template<class Tkey, class Tvalue>
Node<Tkey, Tvalue> *AVLTree<Tkey, Tvalue>::rl_rotation(Node<Tkey, Tvalue> *leaf)
{
	Node<Tkey, Tvalue> *temp;
	temp = leaf->right;
	leaf->right = ll_rotation(temp);
	return rr_rotation(leaf);
}

//Balancing AVL tree
template<class Tkey, class Tvalue>
Node<Tkey, Tvalue> *AVLTree<Tkey, Tvalue>::balance(Node<Tkey, Tvalue> *leaf)
{
	///cout << "Balance " << endl;
	int bal_factor = diff(leaf);
	if (bal_factor > 1)
	{
		if (diff(leaf->left) > 0)
			leaf = ll_rotation(leaf);
		else
			leaf = lr_rotation(leaf);
	}
	else if (bal_factor < -1)
	{
		if (diff(leaf->right) > 0)
			leaf = rl_rotation(leaf);
		else
			leaf = rr_rotation(leaf);
	}
	return leaf;
}

//add element to AVL tree
template<class Tkey, class Tvalue>
Node<Tkey, Tvalue> *AVLTree<Tkey, Tvalue>::add(Tvalue value, Node<Tkey, Tvalue> *leaf)
{
	Tkey key = getK(value);
	if (leaf == NULL)
	{
		leaf = new Node<Tkey, Tvalue>;
		leaf->value = value;
		leaf->left = NULL;
		leaf->right = NULL;
		return leaf;
	}
	if ((compareKey(key, leaf->getKey(getK))<0))
	{
		leaf->left = add(value, leaf->left);
		leaf = balance(leaf);
	}
	else
	{
		leaf->right = add(value, leaf->right);
		leaf = balance(leaf);
	}
	return leaf;
}

//template<class Tkey, class Tvalue>
//bool AVLTree<Tkey, Tvalue>::checkBalance()
//{
//	if (abs(height(root->left) - height(root->right))<=1)
//	return true;
//	else return false;
//}
//
