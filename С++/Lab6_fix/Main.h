//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Tree.h>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label4;
	TLabel *LabelFIO;
	TLabel *Label5;
	TLabel *Label6;
	TMemo *MemoKey;
	TButton *Button7;
	TMemo *MemoFIO;
	TEdit *EditNewNodeKey;
	TEdit *EditNewNodeFIO;
	TButton *Button1;
	TEdit *EditKey;
	TButton *Button6;
	TButton *Button3;
	TButton *Button2;
	TButton *Button5;
	TTreeView *TreeView;
	TListBox *ListBox;
	TButton *Button9;
	TButton *Button10;
	TButton *Button8;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TButton *Button4;
	TLabel *Label3;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);


private:	// User declarations
public:		// User declarations
	  Solution ThisTree;
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
