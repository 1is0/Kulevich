//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Stack.cpp"
#include "Unit1.h"
#include "string.h"
#include <cstring>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;




//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}

int prior(char c)
{
    if(c=='(' || c ==')') return 3;
    if(c == '*' || c == '/') return 2;
    if(c == '-' || c == '+')return 1;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        Memo1->Clear();

	Stack<char> operations(10);
	Stack<char> output(10);


	AnsiString temp = Edit1->Text.c_str();
	std::string str = temp.c_str();

	////Translate to OPZ

        int i = 0;
	while(i<temp.Length())
	{
	     if(str[i] == '('||str[i]==')' || str[i]=='*' || str[i]=='/'|| str[i]=='+' || str[i]=='-')
	     {
		 if(str[i]==')')
		 {
		    while(operations.Peek(1)!='(')
		    {
		    output.push(operations.Peek(1));

		    operations.pop();
                    }
		    operations.pop();
		    i++;
                    continue;
                 }
		 if(operations.getTop()!=0 && prior(str[i]) <= prior(operations.Peek(1)) && operations.Peek(1)!='(' )
		 {
		     output.push( operations.Peek(1));
		     operations.pop();
		     operations.push(str[i]);

		 }
		 else
		 {
		     operations.push(str[i]);
		 }
	     }

	     else
	     {
		output.push(str[i]);
	     }

             i++;
	}

	while(operations.isEmpty() == false)
	{
	output.push( operations.Peek(1));
        operations.pop();
	}
	output.push('\0');

	////Calculations

	AnsiString expr = output.Output();

	int indexA = expr.Pos("a");
	expr.Delete(indexA,1);
	expr.Insert(Edit2->Text+ " ",indexA);

	int indexB = expr.Pos("b");
	expr.Delete(indexB,1);
	expr.Insert(Edit3->Text+ " ",indexB);

	int indexC = expr.Pos("c");
	expr.Delete(indexC,1);
	expr.Insert(Edit4->Text + " ",indexC);

	int indexD = expr.Pos("d");
	expr.Delete(indexD,1);
	expr.Insert(Edit5->Text+ " ",indexD);

	int indexE = expr.Pos("e");
	expr.Delete(indexE,1);
	expr.Insert(Edit6->Text+ " ",indexE);

	expr.Insert(" ",expr.Pos("-") + 1 );
	expr.Insert(" ",expr.Pos("+") + 1 );
	expr.Insert(" ",expr.Pos("/") + 1 );
	expr.Insert(" ",expr.Pos("*") + 1 );

	Memo1->Lines->Add(expr);



	Stack <double> final(10);

	char* pch  = strtok(expr.c_str()," ");

	while(pch!=NULL)
	{
	    switch(*pch)
	    {
		case '+':
		{
		double oper1 = final.Peek(1);
		final.pop();
		double oper2 = final.Peek(1);
		final.pop();
		final.push(oper1+oper2);
		break;
		}

		case '-':
		{
		double oper1 = final.Peek(1);
		final.pop();
		double oper2 = final.Peek(1);
		final.pop();
		final.push(oper2-oper1);
		break;
		}

		case '*':
		{
		double oper1 = final.Peek(1);
		final.pop();
		double oper2 = final.Peek(1);
		final.pop();
		final.push(oper1*oper2);
		break;
		}

		case '/':
		{
		double oper1 = final.Peek(1);
		final.pop();
		double oper2 = final.Peek(1);
		final.pop();
		if (oper1==0)
		  {
		  Application->MessageBox(String("Нельзя делить на ноль!").c_str(), String("Ошибка").c_str(), MB_OK);
		  }
		 else
		  {
		  final.push(oper2/oper1);
		  }
		break;
		}

		default:
		{
		    final.push(std::atof(pch));
		}
	    }
	    pch= strtok(NULL," ");
	}

	double cd = final.Peek(1);

	delete [] pch;
	 operations.clear();
	 output.clear();
         final.clear();

	Memo1->Lines->Add("Answer: " + FloatToStr(cd));


}


//---------------------------------------------------------------------------

