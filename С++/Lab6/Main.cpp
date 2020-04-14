//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "Except.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------

// Доступ к удалению строки в стринггрид
class TExtStringGrid: public  TStringGrid
{
    public:
        using TStringGrid::DeleteRow;
};

 // поиск узла с минимальным ключом в дереве p
 TTree* findmin(TTree* p)
{
	return p->A1?findmin(p->A1):p;
}

 // удаление узла с минимальным ключом из дерева p
TTree* removemin(TTree* p)
{
	if( p->A1==0 )
		return p->A2;
	p->A1 = removemin(p->A1);
	return balance(p);
}

 // удаление ключа k из дерева p
TTree* Delete_Node_BinaryTree(TTree* p, int k)
{
	if( !p ) return 0;
	if( k < p->Inf.key )
		p->A1 = Delete_Node_BinaryTree(p->A1,k);
	else if( k > p->Inf.key )
		p->A2 = Delete_Node_BinaryTree(p->A2,k);
	else //  k == p->key
	{
		TTree* q = p->A1;
		TTree* r = p->A2;
		delete p;
		if( !r ) return q;
		TTree* min = findmin(r);
		min->A2 = removemin(r);
		min->A1 = q;
		return balance(min);
	}
	return balance(p);
}

  // Поиск ключа и вывод в мемо
void Search(TTree *p, int index)
{
if (p == NULL) return;

	if (p->Inf.key == index) {
		Form1->Memo1->Lines->Add(p->Inf.fio);
	}
	if (p->Inf.key > index) {
		Search(p->A1,index);
	}
	if (p->Inf.key < index ) {
		Search(p->A2,index);
	}
}

 // Вывод дерева в ТриВью
void ViewTree(TTree *p, int kl)

{

if (p == NULL) return;

if (kl == -1)

Form1->TreeView1->Items->AddFirst(NULL,p->Inf.fio+"= "+IntToStr(p->Inf.key));

else

Form1->TreeView1->Items->AddChildFirst(Form1->
TreeView1->Items->Item[kl], p->Inf.fio+" = "+IntToStr(p->Inf.key));

kl++;

ViewTree(p->A1,kl);

ViewTree(p->A2,kl);

kl--;

}
  // Полное удаление дерева
void DeleteTree(TTree *p)

{

if (p == NULL)return;

DeleteTree(p->A1);

DeleteTree(p->A2);

delete(p);

p=NULL;

}

 // Обход 1
void WrtTree(TTree*p) {

if (p == NULL)return;

Form1->Memo1->Lines->Add(p->Inf.fio+" "+p->Inf.key);

WrtTree(p->A1);

WrtTree(p->A2);

}
  // Обход 2
void WrtTreeB(TTree*p) {

if (p == NULL)return;

WrtTreeB(p->A1);

Form1->Memo1->Lines->Add(p->Inf.fio+" "+p->Inf.key);


WrtTreeB(p->A2);

}
  // Обход 3
void WrtTreeP(TTree*p) {

 if (p == NULL)return;
WrtTreeP(p->A1);

WrtTreeP(p->A2);

Form1->Memo1->Lines->Add(p->Inf.fio+" "+p->Inf.key);


}

double counter = 0,sum = 0;

// Вычисление суммы ключей
void Task(TTree *p)
{
	if (p == NULL) return;

	counter++;
	sum+=(p)->Inf.key;
	Task(p->A1);
	Task(p->A2);

}


int n = 9; TTree *proot;

void __fastcall TForm1::FormCreate(TObject *Sender)
{

	StringGrid1->FixedCols=0;

	StringGrid1->ColCount=2;

	StringGrid1->RowCount=10;

	StringGrid1->Cells[0][0] = "Name";

	StringGrid1->Cells[1][0]="Code";

	StringGrid1->Cells[0][1]="Nastya"; StringGrid1->Cells[1][1]="4";

	StringGrid1->Cells[0][2]="Alex"; StringGrid1->Cells[1][2]="7";

	StringGrid1->Cells[0][3]="Lexa"; StringGrid1->Cells[1][3]="8";

	StringGrid1->Cells[0][4]="Maks"; StringGrid1->Cells[1][4]="1";

	StringGrid1->Cells[0][5]="Ivan"; StringGrid1->Cells[1][5]="2";

	StringGrid1->Cells[0][6]="Polina"; StringGrid1->Cells[1][6]="6";

	StringGrid1->Cells[0][7]="Masha"; StringGrid1->Cells[1][7]="9";

	StringGrid1->Cells[0][8]="Danik"; StringGrid1->Cells[1][8]="0";

	StringGrid1->Cells[0][9]="Nikita"; StringGrid1->Cells[1][9]="3";


}

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//«Отобразить дерево»

	int kl=-1;

	TreeView1->Items->Clear();

	ViewTree(proot,kl);

	TreeView1->FullExpand();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
//«Удалить дерево»
	sum = 0;
	DeleteTree(proot);

	Memo1->Clear();

	TreeView1->Items->Clear();


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
//«Заполнить дерево»
	TInf A;
	sum = 0;
	try{
	for (int i = 2; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			if (StringGrid1->Cells[1][i]==StringGrid1->Cells[1][j]) {
				throw MyException("fiasko");
			}
		}
	}
	}
	catch(const MyException &exc){
		ShowMessage("Equal keys are not allowed.");
	}


	for (int i = 1; i <= n; i++)
	{

		A.fio = StringGrid1->Cells[0][i];

		A.key = StrToInt(StringGrid1->Cells[1][i]);
		proot = insert(proot,A);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{

	Memo1->Clear();

	WrtTree(proot);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
 // Добавление строк
	int n = StrToInt(Edit1->Text);

	StringGrid1->RowCount = n+1;

}
//---------------------------------------------------------------------------
//--------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	Memo1->Clear();
	Task(proot);

	double avg = sum/counter;

	int *mas = new int[counter];

	double *temp = new double[counter];

	for (int i = 0; i < counter; i++)
	{
		mas[i] =  StrToInt(StringGrid1->Cells[1][i+1]);

		temp[i] = abs(mas[i] - avg );
	}

	double min = temp[0];
	int index = 0;

	for (int i = 0; i < counter; i++)
	{
		if(temp[i] < min)
		{
			min = temp[i];
			index = i;
		}
	}

	Form1->Memo1->Lines->Add("Average key is : ");
	Form1->Memo1->Lines->Add(avg);
	Search(proot,mas[index]);


	counter = 0;
	sum = 0;




}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	Memo1->Clear();

	WrtTreeB(proot);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
 // Поиск
int k = StrToInt(Edit2->Text);

Form1->Memo1->Clear();

Search(proot,k);



}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
Memo1->Clear();

	WrtTreeP(proot);

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button10Click(TObject *Sender)
{
	sum = 0;
	int data = StrToInt(Edit3->Text);
	proot = Delete_Node_BinaryTree(proot,data);

	int kl=-1;

	TreeView1->Items->Clear();

	ViewTree(proot,kl);

	TreeView1->FullExpand();

	for (int i = 0; i < n; i++) {
		if (data == StringGrid1->Cells[1][i+1]) {
		  ((TExtStringGrid*)StringGrid1)->DeleteRow(i+1);
		  n--;
		}
	}
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
TInf A;
		A.fio = Edit4->Text;

		A.key = StrToInt(Edit5->Text);
		proot = insert(proot,A);
		n++;

		StringGrid1->RowCount = n+1;
		StringGrid1->Cells[0][n] = A.fio;
		StringGrid1->Cells[1][n] = A.key;

}
//---------------------------------------------------------------------------


