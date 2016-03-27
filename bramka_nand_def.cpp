#include <stdio.h>
#include <iostream>
#include "bramka_nand.h"

bramka_nand::bramka_nand(bool stan1, bool stan2) : bramka(stan1, stan2) { };
bramka_nand::~bramka_nand() { };
bool bramka_nand::funk()  { return !(getVal_1() && getVal_2()); }
