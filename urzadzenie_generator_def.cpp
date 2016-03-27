#include <stdio.h>
#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include "urzadzenie_generator.h"

generator::generator(bool stan1, bool stan2)
{
	bool sygnal1=stan1;
	bool sygnal2=stan2;
}
generator::~generator() { };
void generator::funk(int takt) 
{
	for (int j = 0; j < takt;j++)//ilosc taktow
	{
		sygnal1 = 1 - sygnal1;
		sygnal2 = 1 - sygnal2;
	}
}
bool generator::getVal_1()
{
	return sygnal1;
}
bool generator::getVal_2()
{
	return sygnal2;
}

