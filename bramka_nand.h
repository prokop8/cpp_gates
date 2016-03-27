#ifndef BRAMKA_NAND_H_INCLUDED
#define BRAMKA_NAND_H_INCLUDED
#include <stdio.h>
#include <iostream>
#include "bramka.h"

class bramka_nand : public bramka
{
public:
	bramka_nand(bool stan1 = true, bool stan2 = true);
	~bramka_nand();
	bool funk() ;
};
#endif