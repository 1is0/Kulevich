//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ToolWin.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:
	TEdit *EditExercise;
	TButton *Button1;
	TEdit *EditTranslated;
	TButton *Button3;
	TButton *Button2;
	TEdit *EditAnswer;
	TLabel *LabelTranslated;
	TLabel *LabelExercise;
	TEdit *EditA;
	TLabel *LabelA;
	TEdit *EditB;
	TLabel *LabelB;
	TEdit *EditC;
	TLabel *LabelC;
	TEdit *EditD;
	TLabel *LabelD;
	TEdit *EditE;
	TLabel *LabelE;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
private:
public:
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
