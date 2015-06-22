#pragma once
#include "stdafx.h"
#include "Elephant.h"

//Comparison functions for Tkey

int compareElephantForName(Elephant x, Elephant y)
{
	return strcmp(x.getName(), y.getName());
}


int compareForInt(int x, int y)
{
	return (x - y);
}
