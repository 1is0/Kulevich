//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <iomanip>

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
    void __fastcall TForm1::Button7Click(TObject *Sender)
{
	ThisTree.delTree();
	try
	{
		for(int i = 0; !(MemoKey->Lines->Strings[i]).IsEmpty() && !(MemoFIO->Lines->Strings[i]).IsEmpty(); i++)
		{
			int tkey = (MemoKey->Lines->Strings[i]).ToInt();
			ThisTree.addNode(tkey, MemoFIO->Lines->Strings[i]);
		}
	}
	catch(EConvertError&)
	{
		Application->MessageBox(String("Ключ должен быть числом!").c_str(), String("Ошибка").c_str(), MB_OK);
	}
	ThisTree.showTree(TreeView);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	try
	{
		int tkey = (EditNewNodeKey->Text).ToInt();
		ThisTree.addNode(tkey, EditNewNodeFIO->Text);
		ThisTree.showTree(TreeView);
	}
	catch(EConvertError&)
	{
		Application->MessageBox(String("Ключ должен быть числом!").c_str(), String("Ошибка").c_str(), MB_OK);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	ThisTree.balanceTree();
	ThisTree.showTree(TreeView);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	try
	{
		int tkey = (EditKey->Text).ToInt();
		ThisTree.delNode(tkey);
		ThisTree.showTree(TreeView);
	}
	catch(EConvertError&)
	{
		Application->MessageBox(String("Ключ должен быть числом!").c_str(), String("Ошибка").c_str(), MB_OK);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	try
	{
		int tkey = (EditKey->Text).ToInt();
		LabelFIO->Caption = ThisTree.findByKey(tkey);
	}
	catch(EConvertError&)
	{
		Application->MessageBox(String("Ключ должен быть числом!").c_str(), String("Ошибка").c_str(), MB_OK);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
	ThisTree.preOrder(ListBox);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
	ThisTree.postOrder(ListBox);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
	ThisTree.inOrder(ListBox);
	ThisTree.showTree(TreeView);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{

  float ans = ThisTree.exercisesolution();
  Label11->Caption = FloatToStrF(ans,ffGeneral,3,2);
  Label13->Caption = ThisTree.findByKey(ThisTree.maxDiff((int)ans));

}
//---------------------------------------------------------------------------
