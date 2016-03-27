#ifndef UKLAD_H_INCLUDED
#define UKLAD_H_INCLUDED
#include <stdio.h>
#include <iostream>
#include <vector>
#include "bramka_nand.h"

class uklad
{
	std::vector<bramka*>plytka;
public:
	uklad(int rozmiar = 10);
	~uklad();
	void dodaj_sygnal_1(bool s1, int num); // podaje otrzymany sygal na wejscie 1
	void dodaj_sygnal_2(bool s1, int num); // podaje otrzymany sygal na wejscie 2
	void dodaj_bramka(int s1, int s2, int stan);//przenosi sygnal s jednej bramki na druga
	void plytka_standartowa();//defoltowo ustawia nandy w ukladzie
	int zwroc_rozmiar();//zwraca rozmiar vectora
	bramka* zwroc_sygnal(int num);

	//funkcji ktore nie zostale zdefinjowane,ale mogo sie przydac
	friend std::ostream &operator+(const uklad &, const uklad &);//sklejanie ukladow
	void nowa_bramka(int num, std::string nazwa);//zamiana bramek w ukladzie na inne typy(np and i td)
	void sum_uklad(uklad , uklad ,int,int);//z jakego uklada z ktorej bramki na jaki uklad i na ktora bramke
};

#endif
