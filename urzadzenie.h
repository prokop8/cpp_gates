#ifndef URZADZENIE_H_INCLUDED
#define URZADZENIE_H_INCLUDED
#include <stdio.h>
#include <iostream>
#include <vector>

class urzadzenie
{
public:
	virtual ~urzadzenie();
	virtual void funk(int) = 0 ;
};
#endif
