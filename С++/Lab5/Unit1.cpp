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
	for (int i = 0; i < 10; i++)
	{
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
 if (queue.GetSize() != 0)
 {

	ListBox2->Clear();
	queue.replace();

	for (int i = 0; i < queue.GetSize() ; i++)
	{
		ListBox2->Items->Add(queue[i]);
	}
 }
	else
	{
		Application->MessageBox(String("Ваша очередь пуста!").c_str(), String("Ошибка").c_str(), MB_OK);
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	queue.clear();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button4Click(TObject *Sender)
{

	if (queue.GetSize() != 0)
	{
	  queue.pop_front();
	  ListBox1->Clear();
		for (int i = 0; i < queue.GetSize() ; i++)
		{
			ListBox1->Items->Add(queue[i]);
		}

	}
	else
	{
		Application->MessageBox(String("Ваша очередь пуста!").c_str(), String("Ошибка").c_str(), MB_OK);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	if (Edit1->Text!="")
	{
		try
		{
			int k = StrToInt(Edit1->Text);
			queue.push_back(k);
			ListBox1->Clear();
			for (int i = 0; i < queue.GetSize() ; i++)
			{
			ListBox1->Items->Add(queue[i]);
			}
		}
		catch(...)
		{
			ShowMessage("Введите число");
			Edit1->Text = "";
		}
	}
	else
	{
		Application->MessageBox(String("Вы ничего не ввели!").c_str(), String("Ошибка").c_str(), MB_OK);
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



