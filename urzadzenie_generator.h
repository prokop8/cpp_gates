#ifndef URZADZENIE_GENERATOR_H_INCLUDED
#define URZADZENIE_GENERATOR_H_INCLUDED
#include <stdio.h>
#include <iostream>
#include <vector>
#include "urzadzenie.h"

class generator : public urzadzenie
{
	bool sygnal1;
	bool sygnal2;
public:
	generator(bool stan1=true,bool stan2=true);
	~generator();
	bool getVal_1();//zwraca sygnal 1
	bool getVal_2();//zwraca sygnal 2
	void funk(int takt);//generowanie sygnalu prostokatego
};
#endif
