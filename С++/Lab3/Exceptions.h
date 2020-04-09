//---------------------------------------------------------------------------

#ifndef ExceptionsH
#define ExceptionsH
//---------------------------------------------------------------------------
#endif
#include <iostream>
#include <exception>
using namespace std;

class MyExcept : public exception
{
	public :
		MyExcept(char* msg) : exception(msg)
		{

		}

};

class SecondExcept : public exception
{
	public :
		SecondExcept(char* msg) : exception(msg)
		{

        }
};
