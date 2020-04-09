//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Mask.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TButton *Button1;
	TRichEdit *RichEdit1;
	TButton *Button2;
	TButton *Button3;
	TLabel *Label6;
	TEdit *Edit6;
	TButton *Button4;
	TLabel *Label7;
	TEdit *Edit7;
	TRichEdit *RichEdit2;
	TButton *Button5;
	TLabel *Label8;
	TEdit *Edit8;
	TButton *Button6;
	TLabel *Label9;
	TEdit *Edit9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TButton *Button7;
	TMaskEdit *Edit4;
	TMaskEdit *Edit5;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall OutPut();
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
    void __fastcall InPut();
	void __fastcall Button6Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
