#include <stdio.h>
#include <iostream>
#include <limits>
#include "bramka_nand.h"
#include "urzadzenie_oscyloskop.h"
#include "urzadzenie_generator.h"
#include "uklad.h"


oscyloskop osc,osc1(2);
generator gener(1, 1);
uklad uklad1(6);

int odp, odp1, odp2;
int czes, il_bram, otkuda, kuda, num_wej, num_gen, num_osc;
int wyb, numer_tora;

void uloz_ukl();
int cheking(std::string);
void test();
void inter();

int main()
{
	inter();
	return 0;
}

void inter()
{
    while(1)
    {
	std::cout << "Prosze wybrac cos z meniu" << std::endl;
	std::cout << "1)Uruchomic uklad testujacy" << std::endl << "2)Zlozyc swoj uklad" << std::endl << "3)Zakoncz dzialanie programu" << std::endl;
	std::cout << std::endl;
        int x = cheking("1/3"); std::cout << std::endl;
        switch (x)
        {
            case 1: test();break;
            case 2: uloz_ukl();break;
            case 3: std::cout << "Dowiedzenia!" << std::endl; break;
        }
        if(x==3)
            break;
    }
}

void test(){
	for (int i = 0; i < 10; i++){
		gener.funk(i);
		uklad1.plytka_standartowa();

		uklad1.dodaj_sygnal_1(gener.getVal_1(), 0);
		uklad1.dodaj_sygnal_2(gener.getVal_2(), 0);
		uklad1.dodaj_sygnal_1(gener.getVal_1(), 1);
		uklad1.dodaj_sygnal_2(gener.getVal_2(), 1);
		uklad1.dodaj_sygnal_1(gener.getVal_1(), 2);
		uklad1.dodaj_sygnal_2(gener.getVal_2(), 2);

		uklad1.dodaj_bramka(0, 3, 1);
		uklad1.dodaj_bramka(1, 3, 2);
		uklad1.dodaj_bramka(2, 4, 2);
		uklad1.dodaj_bramka(3, 5, 1);
		uklad1.dodaj_bramka(4, 5, 2);

		osc1.podaj_sygnal(uklad1.zwroc_sygnal(5)->funk(), 0);
		osc1.podaj_sygnal(uklad1.zwroc_sygnal(4)->funk(), 1);
		osc1.funk();
	}
	osc1.wypisz();
	std::cout << std::endl;
}

int cheking(std::string what){
	if (what == "liczba"){
		while (1){
			std::cin >> odp;
			try{
				if (!std::cin.good()) throw 1;
				else if (odp == 0) throw 2;
				else if (odp < 0) throw 0;
				else break;
			}
			catch (const int& i){
				if (i == 0) std::cout << "Nie moze byc ujemna liczba" << std::endl;
				else if (i == 1) std::cout << "Prosze wpisac liczbe" << std::endl;
				else if (i == 2) std::cout << "Nie moze nie byc zero" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}//koniec while
		return odp;
	}//koniec if
	else if (what == "1/2"){
		while (1){
			std::cin >> odp1;
			try{
				if (odp1 == 1 || odp1 == 2) break;
				else if (!std::cin.good()) throw 1;
				else if (odp1 == 0) throw 2;
				else  throw 0;
			}
			catch (const int& i){
				if (i == 0) std::cout << "Wpisz 1 lub 2" << std::endl;
				else if (i == 1) std::cout << "Prosze wpisac liczbe" << std::endl;
				else if (i == 2) std::cout << "Nie moze nie byc zero" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}//koniec while
		return odp1;
	}//koniec elseif
	else if (what == "1/3"){
		while (1){
			std::cin >> odp1;
			try{
				if (odp1 == 1 || odp1 == 2 || odp1 == 3) break;
				else if (!std::cin.good()) throw 1;
				else if (odp1 == 0) throw 2;
				else  throw 0;
			}
			catch (const int& i){
				if (i == 0) std::cout << "Wpisz 1,2 lub 3" << std::endl;
				else if (i == 1) std::cout << "Prosze wpisac liczbe" << std::endl;
				else if (i == 2) std::cout << "Nie moze nie byc zero" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}//koniec while
		return odp1;
	}//koniec elseif

}//koniec f-cji cheking

void uloz_ukl(){

	std::cout << "Prosze wprowadzic ilosc taktow dla generatora" << std::endl;
	czes = cheking("liczba");//liczba taktow
	gener.funk(czes);//generuemy sygnal na wprowadzonej ilosci taktow

	std::cout << std::endl << "Prosze wprowadzic liczbe bramek do ukladu" << std::endl;
	il_bram = cheking("liczba");//ilosc bramek w ukladzie
	uklad uklad(il_bram);
	uklad.plytka_standartowa();//uzepelniamy uklad bramkami NAND

	while (1){//wybor generatora
		while (1){
			std::cout << std::endl << "Podaj bramke dla generatora" << std::endl;
			num_gen = cheking("liczba");//bramka dla generatora
			if (num_gen <= uklad.zwroc_rozmiar()) break;//sprawdzanie czy jest taka bramka w ukladzie
			else std::cout << "Bramek jest mnej,niz wpisales" << std::endl;
		}

		std::cout << std::endl << "Na jake wejscie?" << std::endl;
		odp1 = cheking("1/2");//wybor wejscia dla bramki
		if (odp1 == 1){ uklad.dodaj_sygnal_1(gener.getVal_1(), num_gen - 1); }
		else if (odp1 == 2){ uklad.dodaj_sygnal_2(gener.getVal_2(), num_gen - 1); }


		std::cout << std::endl << "Czy jeszcze bedziesz ukladal bramki?" << std::endl << "1)Tak" << std::endl << "2)Nie" << std::endl;
		odp = cheking("1/2");
		if (odp == 2)break;
	}//konic while na wybor bramki dla generatora

	while (1){//ukladanie bramek w ukladzie
		if (il_bram == 1) break;//jezeli w ukladzie tylko 1 bramka-nie trzeba ja ukladac
		else{
			std::cout << std::endl << "Teraz trzeba ulozyc bramki" << std::endl;
			while (1){

				while (1){
					std::cout << std::endl << "Wpisz numer bramki od ktorej prowadzisz sygnal" << std::endl;
					otkuda = cheking("liczba");//bramka od ktorej prowadzisz sygnal
					if (otkuda <= uklad.zwroc_rozmiar()) break;
					else std::cout << std::endl << "Bramek jest mnej,niz wpisales" << std::endl;
				}
				bool sig_from = uklad.zwroc_sygnal(otkuda - 1)->funk();//sygnal z bramki od ktorej prowadzisz

				std::cout << std::endl << "Wpisz numer wejscia" << std::endl;
				num_wej = cheking("1/2");//numer wejscia na ktore pojdzie sygnal

				while (1){
					std::cout << std::endl << "Wpisz numer bramki na ktora prowadzisz sygnal" << std::endl;
					kuda = cheking("liczba");//bramka na ktora prowadzisz sygnal
					if (kuda <= uklad.zwroc_rozmiar()) break;
					else std::cout << std::endl << "Bramek jest mnej,niz wpisales" << std::endl;
				}

				if (num_wej == 1){ uklad.zwroc_sygnal(kuda - 1)->setVal_1(sig_from); }
				else if (num_wej == 2){ uklad.zwroc_sygnal(kuda - 1)->setVal_2(sig_from); }

				std::cout << std::endl << "Czy jeszcze bedziesz ukladal bramki?" << std::endl << "1)Tak" << std::endl << "2)Nie" << std::endl;
				odp = cheking("1/2");
				if (odp == 2)break;
			}
		}//koniec else
		break;
	}//koniec while na ukladanie bramek

	std::cout << "Prosze podac numer bramki dla oscylatora" << std::endl;
	num_osc = cheking("liczba");//bramka od ktorej sygnal pojdzie na oscyloskop
	bool sig = uklad.zwroc_sygnal(num_osc - 1)->funk();

	osc.podaj_sygnal(sig, 0);
	osc.funk();
	osc.wypisz();
}//koniec
