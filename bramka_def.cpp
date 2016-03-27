#include <stdio.h>
#include <iostream>
#include "bramka.h"

bramka::bramka(bool stan1 , bool stan2 ) : wejscie_1(stan1), wejscie_2(stan2) { };
bramka::~bramka() { };
bool bramka::getVal_1() { return wejscie_1; }
bool bramka::getVal_2() { return wejscie_2; }
void bramka::setVal_1(bool value) { wejscie_1 = value;}
void bramka::setVal_2(bool value) { wejscie_2 = value;}
bool bramka::funk()  { return 1; }
