//---------------------------------------------------------------------------

#pragma hdrstop

#include "Bus.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#include <vcl.h>

int Bus :: GetNumber(){
   return number;
}

void Bus :: SetNumber(int number){

   this->number = number;


}

AnsiString Bus :: GetType(){
   return type;
}

void Bus :: SetType(AnsiString type){
   this->type = type;
}

AnsiString Bus :: GetPoint(){
   return point;
}

void Bus :: SetPoint(AnsiString point){
   this->point = point;
}

int Bus :: GetHourOt(){
   return hourOt;
}

void Bus :: SetHourOt(int hourOt){
   this->hourOt = hourOt;
}

int Bus :: GetMinOt(){
   return minOt;
}

void Bus :: SetMinOt(int minOt){
   this->minOt = minOt;
}
int Bus :: GetMinPr(){
   return minPr;
}

void Bus :: SetMinPr(int minPr){
   this->minPr = minPr;
}
int Bus :: GetHourPr(){
   return hourPr;
}

void Bus :: SetHourPr(int hourPr){
   this->hourPr = hourPr;
}




