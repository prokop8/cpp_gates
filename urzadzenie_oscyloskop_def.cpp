#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "urzadzenie_oscyloskop.h"

oscyloskop::oscyloskop(int stan1)
{
	sygnal.resize(stan1);
	wyjscie.resize(stan1);
}
oscyloskop::~oscyloskop() { };
void oscyloskop::funk(int x)
{
	for (int i = x; i < wyjscie.size(); i++)
	{
		if (wyjscie[i] == 0)
			sygnal[i] += "_";
		else
			sygnal[i] += "-";
	}
}
void oscyloskop::wypisz() const
{
	for (int i = 0; i < sygnal.size(); i++)
	{
		std::cout << sygnal[i] << std::endl;
	}
	std::ofstream fout("TEST.txt", std::ofstream::out);
	for (int i = 0; i < sygnal.size(); i++)
	{
		fout << sygnal[i] << std::endl;
	}
	fout << std::endl;
	fout.close();
}

void oscyloskop::podaj_sygnal(bool element, int num){
	wyjscie[num] = element;
}
