//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TTreeView *TreeView1;
	TStringGrid *StringGrid1;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TEdit *Edit1;
	TMemo *Memo1;
	TButton *Button6;
	TButton *Button7;
	TEdit *Edit2;
	TButton *Button8;
	TButton *Button9;
	TButton *Button10;
	TEdit *Edit3;
	TButton *Button12;
	TEdit *Edit4;
	TEdit *Edit5;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall Button12Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

struct TInf {

int key;

String fio;

};

struct TTree {

TInf Inf;

unsigned char height;

TTree *A1;

TTree *A2;

TTree(int k, String filo) { Inf.key = k; Inf.fio = filo; A1 = A2 = 0; height = 1; }

};

unsigned char height(TTree* p)
{
	return p?p->height:0;
}
int bfactor(TTree* p)
{
	return height(p->A2)-height(p->A1);
}

void fixheight(TTree* p)
{
	unsigned char hl = height(p->A1);
	unsigned char hr = height(p->A2);
	p->height = (hl>hr?hl:hr)+1;
}

TTree* rotateright(TTree* p) // правый поворот вокруг p
{
	TTree* q = p->A1;
	p->A1 = q->A2;
	q->A2 = p;
	fixheight(p);
	fixheight(q);
	return q;
}

TTree* rotateleft(TTree* q) // левый поворот вокруг q
{
	TTree* p = q->A2;
	q->A2 = p->A1;
	p->A1 = q;
	fixheight(q);
	fixheight(p);
	return p;
}

TTree* balance(TTree* p) // балансировка узла p
{
	fixheight(p);
	if( bfactor(p)==2 )
	{
		if( bfactor(p->A2) < 0 )
			p->A2 = rotateright(p->A2);
		return rotateleft(p);
	}
	if( bfactor(p)==-2 )
	{
		if( bfactor(p->A1) > 0  )
			p->A1 = rotateleft(p->A1);
		return rotateright(p);
	}
	return p; // балансировка не нужна
}

TTree* insert(TTree* p, TInf infa ) // вставка ключа k в дерево с корнем p
{
	if( !p ) return new TTree(infa.key,infa.fio);
	if( infa.key < p->Inf.key )
		p->A1 = insert(p->A1,infa);
	else
		p->A2 = insert(p->A2,infa);
	return balance(p);
}


