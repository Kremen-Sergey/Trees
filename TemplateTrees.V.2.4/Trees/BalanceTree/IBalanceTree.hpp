#pragma once
//#include "ISearhTree.hpp"

template<class Tkey, class Tvalue>
class IBalanceTree : public  virtual ISearhTree <Tkey, Tvalue >
{
public:
	virtual void Balance() = 0;
};