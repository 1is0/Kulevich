#include <vcl.h>
#pragma hdrstop
#include "Main.h"
#include "Stack.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
St MyStack;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
  MyStack.initialize();
  AnsiString text = EditExercise->Text;
  MyStack.f_str = text.c_str();
  MyStack.check();
  if(MyStack.err_code == all_true)
  {
	  MyStack.put_spaces();
	  MyStack.f_str = MyStack.s_str;
	  MyStack.postfix();
	  EditTranslated->Text = MyStack.f_str;
  }
  MyStack.f_str = text.c_str();
  if(MyStack.err_code == all_true)
  {
	  MyStack.put_spaces();
	  MyStack.f_str = MyStack.s_str;
	  MyStack.postfix();
	  EditTranslated->Text = MyStack.f_str;
	  float rez = MyStack.calc(StrToFloat(EditA->Text), StrToFloat(EditB->Text),
	  StrToFloat(EditC->Text), StrToFloat(EditD->Text), StrToFloat(EditE->Text));
	  EditAnswer->Text = FloatToStr(rez);
  }
  else MyStack.find_errors();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
   EditExercise->Text="";
   EditAnswer->Text="";
   EditTranslated->Text="";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
   EditExercise->Text="";
   EditAnswer->Text="";
   EditTranslated->Text="";
   EditA->Text="";
   EditB->Text="";
   EditC->Text="";
   EditD->Text="";
   EditE->Text="";
}
//---------------------------------------------------------------------------


