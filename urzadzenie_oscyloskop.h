#ifndef URZADZENIE_OSCYLOSKOP_H_INCLUDED
#define URZADZENIE_OSCYLOSKOP_H_INCLUDED
#include <stdio.h>
#include <iostream>
#include <vector>
#include "urzadzenie.h"

class oscyloskop : public urzadzenie
{
	std::vector<std::string>sygnal;
	std::vector<bool>wyjscie;//wector sygnalow 
public:
	oscyloskop(int stan = 1);
	~oscyloskop();
	void funk(int = 0);//przetwarzanie sygnalow z ukladu w wykres
	void podaj_sygnal(bool element, int num);//ustawienie sygnalu z ukladu
	void wypisz() const;
};
#endif
