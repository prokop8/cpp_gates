#ifndef BRAMKA_H_INCLUDED
#define BRAMKA_H_INCLUDED
#include <stdio.h>
#include <iostream>

class bramka
{
	bool wejscie_1;
	bool wejscie_2;
public:
	bramka(bool stan1 = true, bool stan2 = true);
	virtual ~bramka();
	bool getVal_1();//zwraca sygnal z wejscia 1
	bool getVal_2();//zwraca sygnal z wejscia 2
	void setVal_1(bool value=0);//ustawia sygnal na wejscie 1
	void setVal_2(bool value=0);//ustawia sygnal na wejscie 2
	virtual bool funk() ;//obliczenie sygnalu z bramki
};
#endif
