#include "pch.h"
#include "Header.h"	

int Sum(int a, int b)
{
	return a + b;
}


int Sub(int a, int b)
{
	return a - b;
}

int Mult(int a, int b)
{
	return a * b;
}


float Div(int a, int b)
{
	if (b != 0)
		return (float)a /(float) b;
	else
		return 0;
}

int Mod(int a, int b)
{
	return a % b;
}
