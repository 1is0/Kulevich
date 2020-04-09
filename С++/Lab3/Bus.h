//---------------------------------------------------------------------------

#ifndef BusH
#define BusH
//---------------------------------------------------------------------------
#endif

//#include "List.h"
#include "Main.h"
#include "Exceptions.h"

#include <iostream>
#include <string.h>
#include <vcl.h>
using namespace std;

class Bus
{
	int number;
	AnsiString type;
	AnsiString point;
	int hourOt;
	int hourPr;
	int minOt;
	int minPr;

	public :

	int GetNumber();
	void  SetNumber(int);
	AnsiString GetType();
	void SetType(AnsiString);
	AnsiString GetPoint();
	void SetPoint(AnsiString);
	int GetHourOt();
	void SetHourOt(int);
	int GetHourPr();
	void SetHourPr(int);
	int GetMinOt();
	void SetMinOt(int);
	int GetMinPr();
	void SetMinPr(int);

//	void Show(Bus obj);
//
//	void TimeSearch(Bus obj);
//
//	void PointSearch(Bus obj);







};
