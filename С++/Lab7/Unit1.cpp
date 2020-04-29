//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	try
	{
		int key = (EditKey->Text).ToInt();
		AnsiString string;
		if(hashhash.searchmynode(hash_table, key) != nullptr) string = "was found";
		else string = "was not found";
        Label6->Caption = string;
	}
	catch(EConvertError&)
	{
		Application->MessageBox(String("Key can not be a symbol").c_str(), MB_OK);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	try
	{
		Label6->Caption = "-------------";
		int tkey = (EditKey->Text).ToInt();
		while(hashhash.searchmynode(hash_table, tkey) != nullptr)
		{
		   hashhash.deletemynode(hash_table, tkey);
		}
		Memo1->Lines->Clear();
		for(int i = 0; i < tab_size; i++)
		{
		   if(hash_table[i] != nullptr)
		   {
			  for(Node * ptr = hash_table[i]; ptr!=NULL;ptr=ptr->next)
			  {
				 Memo1->Lines->Add("Key: " + (AnsiString)ptr->key + " Index in hash table: " + i);
			  }
		   }
		}
	}
	catch(EConvertError&)
	{
		Application->MessageBox(String("Key can not be a symbol").c_str(), MB_OK);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
   int tkey, ind, nums_cnt;
   nums_cnt = StrToInt(Edit1->Text);
   for(int i = 0; i < nums_cnt; i++)
   {
	  tkey = rand();
	  hashhash.insertmynode(hash_table, tkey);
	  ind = hashhash.hash_tableFunction(tkey);
	  Memo1->Lines->Add("Key: " + (AnsiString)hash_table[hashhash.hash_tableFunction(tkey)]->key +
	   " Index in hash table: " + ind);
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
  Label7->Caption = FloatToStrF(hashhash.countaverage(hash_table),ffGeneral,3,2);
  Label10->Caption = hashhash.countamount(hash_table);
}
//---------------------------------------------------------------------------
