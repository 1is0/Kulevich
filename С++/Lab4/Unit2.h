//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
#include "Unit1.h"
#include "Unit2.h"
#include <vcl.h>
#include <math.h>
using namespace std;
//---------------------------------------------------------------------------
class reversePolishEntry
{
public:
	struct Stack
	{
		char info;
		Stack* next;
	};
	typedef Stack* PStack;
	PStack begin;

	reversePolishEntry()
	{
		begin = NULL;
	}

	void StringGridInitialization()
	{
		char a = 'a';
		Form1->StringGrid1->Cells[0][0] ="Имя";
		Form1->StringGrid1->Cells[1][0] ="Значение";
		for(int i = 1; i < 6; i++, a++)
			Form1->StringGrid1->Cells[0][i] = a;
		 Form1->StringGrid1->Cells[1][1] = 0.3;
		 Form1->StringGrid1->Cells[1][2] = 6.7;
		 Form1->StringGrid1->Cells[1][3] = 8.4;
		 Form1->StringGrid1->Cells[1][4] = 9.5;
		 Form1->StringGrid1->Cells[1][5] = 1.2;
	}

	int Priority(char a)
	{
		switch(a)
		{
			case '*': return 3;
			case '/': return 3;
			case '-': return 2;
			case '+': return 2;
			case '(': return 1;
		}
		return 0;
	}
	// push
	PStack InStack(PStack p, char in)
	{
		PStack newElement = new Stack;
		newElement->info = in;
		newElement->next = p;
		return newElement;
	}
	// pop
	PStack OutStack(PStack p, char* out)
	{
		PStack t = p;
		*out = p->info;
		p = p->next;
		delete t;
		return p;
	}

	void toPolishEntry()
	{
		PStack t;
		begin = NULL;
		char symbol, temp;
		String InStr, OutStr; // Входная и выходная строки
		InStr = Form1->Edit1->Text;
		int lenght = InStr.Length();
		for(int k = 1; k <= lenght; k++)
		{
			symbol = InStr[k];
			if (symbol >= 'a' && symbol <= 'z')
				OutStr += symbol;
			/* Если знак операции, то переписываем из стека в выходную строку все
			операции с большим или равным приоритетом */
			if (symbol == '*' || symbol == '/' || symbol == '-' || symbol == '+')
			{
				while (begin != NULL && Priority(begin->info) >= Priority(symbol))
				{
					begin = OutStack(begin, &temp);
					OutStr += temp;
				}
				begin = InStack(begin, symbol);
			}
			// Открывающую скобку записываем в стек
			if (symbol == '(')
				begin = InStack(begin, symbol);
			if (symbol == ')')
			{
				while ((begin->info) != '(')
				{
					begin = OutStack(begin, &temp);
					OutStr += temp;
				}
				begin = OutStack(begin, &temp);
			}
		}
		while (begin != NULL)
		{
			begin = OutStack(begin, &temp);
			OutStr += temp;
		}
		Form1->Edit2->Text = OutStr;
	}

	void Result()
	{
		String Str = Form1->Edit2->Text;
		char symbol, s1, s2;
		double operand1, operand2, answer;
		char symbolForArray = 'z'+1;
		double arrayForValues[200]; // Массив для вычисления
		// Инициализация массива, хранящего значения переменных и промежуточных вычислений
		for (int i = 1; i < 6; i++)
		{
			symbol = Form1->StringGrid1->Cells[0][i][1];
			arrayForValues[int(symbol)]=StrToFloat(Form1->StringGrid1->Cells[1][i]);
		}
		// Вычисление значения выражения
		for (int i = 1; i <= Str.Length(); i++)
		{
			symbol = Str[i];
			if (symbol != '/' && symbol != '*' && symbol != '-' && symbol != '+')
				begin = InStack(begin, symbol);
			else
			{
				begin = OutStack(begin, &s1);
				begin = OutStack(begin, &s2);
				operand1 = arrayForValues[int(s1)];
				operand2 = arrayForValues[int(s2)];
				switch (symbol)
				{
					case '+' : answer = operand2 + operand1; break;
					case '-' : answer = operand2 - operand1; break;
					case '*' : answer = operand2 * operand1; break;
					case '/' : answer = operand2 / operand1; break;
				}
				arrayForValues[int(symbolForArray)] = answer;
				begin = InStack(begin, symbolForArray);
				symbolForArray++;
			}
		}
		Form1->Edit3->Text = FloatToStr(answer);
	}
};


#endif
