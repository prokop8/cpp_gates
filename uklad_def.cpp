#include <stdio.h>
#include <iostream>
#include <vector>
#include "uklad.h"

uklad::uklad(int rozmiar)
{
	plytka.resize(rozmiar);
	for (int i = 0; i < rozmiar; i++)
	{
		plytka[i] = new bramka;
	}
}
uklad::~uklad() 
{
	for (int i = 0; i < plytka.size(); i++)
		delete(plytka[i]);
}
bramka* uklad::zwroc_sygnal(int num)
{
	return plytka[num];
}
void uklad::plytka_standartowa(){
	for (int i = 0; i < plytka.size(); i++){
		plytka[i] = new bramka_nand;
	}
}
void uklad::dodaj_bramka(int s1, int s2, int stan)//podlocza na bramku wyjscie z innej bramki
{
	if (stan == 1)
	{
		plytka[s2]->setVal_1(plytka[s1]->funk());
	}
	else if (stan==2)
	{
		plytka[s2]->setVal_2(plytka[s1]->funk());
	}
}
void uklad::dodaj_sygnal_1(bool s1, int num)//ustaw sygnal na wejscie 1
{
	plytka[num]->setVal_1(s1);
}
void uklad::dodaj_sygnal_2(bool s1, int num)//ustaw sygnal na wejscie 2
{
	plytka[num]->setVal_2(s1);
}

int uklad::zwroc_rozmiar()
{
	return plytka.size();
}
