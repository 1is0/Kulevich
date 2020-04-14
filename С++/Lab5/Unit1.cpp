//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <time.h>
#include "Query.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
List<int> queue;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
queue.clear();
ListBox1->Clear();
ListBox2->Clear();
int item;
	for (int i = 0; i < 10; i++) {

	item = rand() % 100;

	ListBox1->Items->Add(item);

	queue.push_back(item);
	}
}


//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	srand(time(NULL));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{

 ListBox2->Clear();
 queue.replace();

 	for (int i = 0; i < queue.GetSize() ; i++)
	{

		ListBox2->Items->Add(queue[i]);
	}

  /*	int max, min, i_min, i_max;
	max = queue[0];
	min = queue[0];


	for (int i = 0; i < queue.GetSize(); i++)
	{
		if (min > queue[i])
		{
		 min = queue[i];
		 i_min = i;
		}   else
		if (max < queue[i])
		{
		 max = queue[i];
		 i_max = i;
		}
	}

    for (int i = 0; i < queue.GetSize(); i++)
	{
	if (i == i_min)
		{
		ListBox2->Items->Add(queue[i_max]);
		}
	else if (i == i_max)
		{
		 ListBox2->Items->Add(queue[i_min]);
		}
	else
		{
		ListBox2->Items->Add(queue[i]);
		}
	}
	  */

}
	/*int check, repeat = 0;

	for (int i = 0; i < queue.GetSize(); i++)
	{

		repeat = 0;
		check = queue[i];

		for (int j = i+1; j < queue.GetSize(); j++)
		{
			 if (check == queue[j])
			 {
				repeat++;
			 }
			 if (check == queue[j] && repeat > 1)
			 {
				queue.removeAt(j);
				//j--;
			 }

		}
	}
    for (int i = 0; i < queue.GetSize(); i++)
	{

		repeat = 0;
		check = queue[i];

		for (int j = i+1; j < queue.GetSize(); j++)
		{
			 if (check == queue[j])
			 {
				repeat++;
			 }
			 if (check == queue[j] && repeat > 1)
			 {
				queue.removeAt(j);

			 }

		}
	}





	for (int i = 0; i < queue.GetSize() ; i++)
	{

		ListBox2->Items->Add(queue[i]);
	}
	queue.clear();
		   */

//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
queue.clear();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button4Click(TObject *Sender)
{
queue.pop_front();
ListBox1->Clear();
	for (int i = 0; i < queue.GetSize() ; i++)
	{

		ListBox1->Items->Add(queue[i]);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
int k = StrToInt(Edit1->Text);

queue.push_back(k);
ListBox1->Clear();
	for (int i = 0; i < queue.GetSize() ; i++)
	{

		ListBox1->Items->Add(queue[i]);
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
Panel1->Caption = queue.GetSize();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
ListBox2->Clear();
}
//---------------------------------------------------------------------------

