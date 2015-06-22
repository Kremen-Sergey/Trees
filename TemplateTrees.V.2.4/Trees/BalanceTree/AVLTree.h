#pragma once
#include "..\SearhTree\SearhTree.h"
#include "..\BalanceTree\IBalanceTree.hpp"

template<class Tkey, class Tvalue>
class AVLTree : public virtual SearhTree <Tkey, Tvalue>, public virtual IBalanceTree <Tkey, Tvalue >
{
	public:
		AVLTree(Tkey(*getK)(Tvalue value), int(*compareKey)(Tkey x, Tkey y));
		virtual ~AVLTree();//destructor virtual for inheritance.
		void Add(Tvalue value);
		virtual void Balance();
		int Height();
		//bool checkBalance();
	private:
		virtual Node<Tkey, Tvalue>* balance(Node<Tkey, Tvalue> *leaf);
		virtual Node<Tkey, Tvalue>* add(Tvalue value, Node<Tkey, Tvalue> *leaf);										
		virtual Node<Tkey, Tvalue>* rr_rotation(Node<Tkey, Tvalue> *leaf);
		virtual Node<Tkey, Tvalue>* ll_rotation(Node<Tkey, Tvalue> *leaf);
		virtual Node<Tkey, Tvalue>* lr_rotation(Node<Tkey, Tvalue> *leaf);
		virtual Node<Tkey, Tvalue>* rl_rotation(Node<Tkey, Tvalue> *leaf);
		int height(Node<Tkey, Tvalue> *leaf);
		int diff(Node<Tkey, Tvalue> *);	
};


