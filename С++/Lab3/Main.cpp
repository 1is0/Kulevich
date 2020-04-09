//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "Bus.h"
#include "List.h"
//#include "Exceptions.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
List<Bus> spisokIn;
List<Bus> spisokOut;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
Bus race;

 try
 {


	if (Edit1->Text == "" || Edit2->Text == "" || Edit3->Text == "" ||
		Edit4->Text == "  :  " || Edit5->Text == "  :  " || Edit4->Text == " :")
		{
			throw MyExcept("Error");
		}

	for(char sym : Edit2->Text)
	{
		if (sym > 122 || (sym < 97 && (sym >90 || sym < 65))) {
		throw SecondExcept("Error");
		}
	}
	for(char sym : Edit3->Text)
	{
		if (sym > 122 || (sym < 97 && (sym >90 || sym < 65))) {
		throw SecondExcept("Error");
		}
	}



	race.SetNumber(StrToInt(Edit1->Text));
	race.SetType(Edit2->Text);
	race.SetPoint(Edit3->Text);

	int hour;
	hour = StrToInt(Edit4->Text[1]) * 10  + StrToInt(Edit4->Text[2]);

	int min;
	min = StrToInt(Edit4->Text[4]) * 10  + StrToInt(Edit4->Text[5]);

	if (hour>=24 || min > 59 )
	{
		throw SecondExcept("Error");
	}

	race.SetHourOt(hour);
	race.SetMinOt(min);

	hour = StrToInt(Edit5->Text[1]) * 10  + StrToInt(Edit5->Text[2]);


	min = StrToInt(Edit5->Text[4]) * 10  + StrToInt(Edit5->Text[5]);

	if (hour>=24 || min > 59 )
	{
		throw SecondExcept("Error");
	}

	race.SetHourPr(hour);
	race.SetMinPr(min);

	spisokIn.push_back(race);
 }
	catch(MyExcept &exception)
	{
		ShowMessage("Input all info.");
	}
	catch(SecondExcept &exception)
	{
		ShowMessage("Incorrect input");
    }


}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
RichEdit1->Clear();
RichEdit2->Clear();
InPut();
OutPut();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
RichEdit1->Clear();
for (int i = 0; i < spisokIn.GetSize(); i++)
{
	if (Edit6->Text > spisokIn[i].GetHourOt())
	{
		RichEdit1->Lines->Add("");
		RichEdit1->SelText = ( spisokIn[i].GetNumber() );
		RichEdit1->SelText=" ";
		RichEdit1->SelText = ( spisokIn[i].GetType() );
		RichEdit1->SelText=" ";
		RichEdit1->SelText = ( spisokIn[i].GetPoint() );
		RichEdit1->SelText=" ";
		RichEdit1->SelText = ( spisokIn[i].GetHourOt() );
		RichEdit1->SelText=":";
		RichEdit1->SelText = ( spisokIn[i].GetMinOt() );
		RichEdit1->SelText=" ";
		RichEdit1->SelText =( spisokIn[i].GetHourPr() );
		RichEdit1->SelText=":";
		RichEdit1->SelText = ( spisokIn[i].GetMinPr() );
	}
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1 :: OutPut(){
for (int i = 0; i < spisokOut.GetSize() ; i++)
{
	//RichEdit2->Lines->Add("");
	RichEdit2->SelText=i;
	RichEdit2->SelText=".";
	RichEdit2->SelText=" ";
	RichEdit2->SelText = ( spisokOut[i].GetNumber() );
	RichEdit2->SelText=" ";
	RichEdit2->SelText = ( spisokOut[i].GetType() );
	RichEdit2->SelText=" ";
	RichEdit2->SelText = ( spisokOut[i].GetPoint() );
	RichEdit2->SelText=" ";
	RichEdit2->SelText = ( spisokOut[i].GetHourOt() );
	RichEdit2->SelText=":";
	RichEdit2->SelText = ( spisokOut[i].GetMinOt() );
	RichEdit2->SelText=" ";
	RichEdit2->SelText =( spisokOut[i].GetHourPr() );
	RichEdit2->SelText=":";
	RichEdit2->SelText = ( spisokOut[i].GetMinPr() );
	RichEdit2->Lines->Add("");
}
}

void __fastcall TForm1 :: InPut()
{
for (int i = 0; i < spisokIn.GetSize() ; i++)
{
	//RichEdit1->Lines->Add("");
	RichEdit1->SelText=i;
	RichEdit1->SelText=".";
	RichEdit1->SelText=" ";
	RichEdit1->SelText = ( spisokIn[i].GetNumber() );
	RichEdit1->SelText=" ";
	RichEdit1->SelText = ( spisokIn[i].GetType() );
	RichEdit1->SelText=" ";
	RichEdit1->SelText = ( spisokIn[i].GetPoint() );
	RichEdit1->SelText=" ";
	RichEdit1->SelText = ( spisokIn[i].GetHourOt() );
	RichEdit1->SelText=":";
	RichEdit1->SelText = ( spisokIn[i].GetMinOt() );
	RichEdit1->SelText=" ";
	RichEdit1->SelText =( spisokIn[i].GetHourPr() );
	RichEdit1->SelText=":";
	RichEdit1->SelText = ( spisokIn[i].GetMinPr() );
	RichEdit1->Lines->Add("");
}



}
void __fastcall TForm1::Button4Click(TObject *Sender)
{
RichEdit1->Clear();
for (int i = 0; i < spisokIn.GetSize(); i++)
{
	if (Edit7->Text == spisokIn[i].GetPoint()) {
		 RichEdit1->Lines->Add("");
		RichEdit1->SelText = ( spisokIn[i].GetNumber() );
		RichEdit1->SelText=" ";
		RichEdit1->SelText = ( spisokIn[i].GetType() );
		RichEdit1->SelText=" ";
		RichEdit1->SelText = ( spisokIn[i].GetPoint() );
		RichEdit1->SelText=" ";
		RichEdit1->SelText = ( spisokIn[i].GetHourOt() );
		RichEdit1->SelText=":";
		RichEdit1->SelText = ( spisokIn[i].GetMinOt() );
		RichEdit1->SelText=" ";
		RichEdit1->SelText =( spisokIn[i].GetHourPr() );
		RichEdit1->SelText=":";
		RichEdit1->SelText = ( spisokIn[i].GetMinPr() );

	}
}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
try
{

		if (Edit8->Text=="") {
			throw SecondExcept("Error");
		}

	int Index = StrToInt(Edit8->Text);


	if (Index >= spisokIn.GetSize())
	{

	throw MyExcept("Index if Out of bounds");

	}


	spisokOut.push_back(spisokIn[Index]);

	spisokIn.removeAt(Index);


}
catch(MyExcept &exception)
{
	ShowMessage(("Index is Out of bounds"));
}
catch(SecondExcept &exception)
{
	ShowMessage("Incorrect input");
}

}


//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{

try
{
	if (Edit9->Text=="")
	{
			throw SecondExcept("Error");
	}
	int Index = StrToInt(Edit9->Text);

	if (Index >= spisokOut.GetSize())
	{
		throw MyExcept("Error");
	}

spisokIn.push_back(spisokOut[Index]);

spisokOut.removeAt(Index);

}
catch(MyExcept &exception){

    ShowMessage("Index is Out of bounds");
}
catch(SecondExcept &exception){

	ShowMessage("Incorrect input");
}


}
//---------------------------------------------------------------------------




