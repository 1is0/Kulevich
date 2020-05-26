#pragma hdrstop
#include "string.h"
#include "stdlib.h"
#include "Unit2.h"
#pragma package(smart_init)


//---------------------------------------------------------------------------
void St::initialize()
{
  pointer1 = 0;
  pointer2 = 0;
  f_str = new char[100];
  s_str = new char[100];
  err_code = all_true;
}
//-------------------------------------------------------------------------
St::~St()
{
  delete[] f_str; delete[] s_str;
}
//---------------------------------------------------------------------------
void St::op_create(char ch)
{
  Operations* pv = new Operations;
  pv->ch = ch;
  pv->prev = 0;
  pointer1 = pv;
}
//---------------------------------------------------------------------------
void St::op_push(char ch)
{
  Operations* pv = new Operations;
  pv->ch = ch;
  pv->prev = pointer1;
  pointer1 = pv;
}
//--------------------------------------------------------------------------
char St::op_pop()
{
  char symbol = pointer1->ch;
  Operations* pv = pointer1;
  pointer1 = pointer1->prev;
  delete pv;
  return symbol;
}
//--------------------------------------------------------------------------
void St::num_create(float ch)
{
  Numerals* pv = new Numerals;
  pv->ch = ch;
  pv->prev = 0;
  pointer2 = pv;
}
//---------------------------------------------------------------------------
void St::num_push(float ch)
{
  Numerals* pv = new Numerals;
  pv->ch = ch;
  pv->prev = pointer2;
  pointer2 = pv;
}
//--------------------------------------------------------------------------
float St::num_pop()
{
  float val = pointer2->ch;
  Numerals* pv = pointer2;
  pointer2 = pointer2->prev;
  delete pv;
  return val;
}
//--------------------------------------------------------------------------
bool St::operand_true(char ch)
{
  if((ch >= '0' && ch <= '9') ||
  (ch >= 'A' && ch <= 'Z') ||
  (ch >= 'a' && ch <= 'z') ||
  ch == '.') return true;
  else return false;
}
//---------------------------------------------------------------------------
int St::pr_stack()
{
  if(pointer1->ch == '(') return 3;
  if(pointer1->ch == '+' || pointer1->ch == '-') return 1;
  else return 2;
}
//---------------------------------------------------------------------------
void St::find_errors()
{
   switch(err_code)
   {
	 case all_true: {ShowMessage("Input was succesful!"); break;}
	 case fault: {ShowMessage("Something happened! Look!"); break;}
   };
}
//---------------------------------------------------------------------------
void St::postfix()
{
  int i, j = 0, pr = 0, length = strlen(f_str);
  for(i = 0;i < length;i++)
  {
	if(f_str[i]==' ')
	{
	  s_str[j++] = f_str[i];
	  continue;
	}
	if((f_str[i]>='('&&f_str[i]<='+')||f_str[i]=='-'||f_str[i]=='/')
	{
	  switch(f_str[i])
	  {
		 case '(':
		 {
		   if(!pointer1) {op_create(f_str[i]);}
		   else {op_push(f_str[i]);}
		   break;
		 }
		 case '*':
		 case '/':
		 {
		   if(!pointer1)
		   {
			 op_create(f_str[i]);
			 break;
		   }
		   pr = pr_stack();
		   if(pr == 3 || pr == 1)
		   {
			 op_push(f_str[i]);
			 break;
		   }
		   if(pointer1->ch == '/') s_str[j++] = op_pop();
		   if(pointer1)
		   {
			 op_push(f_str[i]);
			 break;
		   }
		   else
		   {
			 op_create(f_str[i]);
			 break;
		   }
		 }
		 case '+':
		 case '-':
		 {
		   if(!pointer1)
		   {
			 op_create(f_str[i]);
			 break;
		   }
		   pr = pr_stack();
		   if(pr == 3)
		   {
			 op_push(f_str[i]);
			 break;
		   }
		   else
		   {
			 while(pr < 3 && pointer1)
			 {
			   s_str[j++] = op_pop();
			   if(pointer1) pr = pr_stack();
			 }
		   }
		   if(pointer1)
		   {
			 op_push(f_str[i]);
			 break;
		   }
		   else
		   {
			 op_create(f_str[i]);
			 break;
		   }
		 }
		 case ')':
		 {
		   pr = pr_stack();
		   while(pr != 3)
		   {
			 s_str[j++]=op_pop();
			 pr=pr_stack();
		   }
		   s_str[j] = op_pop();
		 }
	  }
	}
	else
	{
	  s_str[j++] = f_str[i];
	  continue;
	}
  }
  if(pointer1)
  {
	while(pointer1) s_str[j++]=op_pop();
  }
  s_str[j]='\0';
  strcpy(f_str,s_str);
}
//-------------------------------------------------------------------------
float St::calc(float a, float b, float c, float d, float e)
{
  int i, j = 0, length = strlen(f_str);
  char sc[10];
  float a1, b1;
  for(i = 0;i < length;i++)
  {
	if(f_str[i] == ' ') continue;
	else
	if(f_str[i] == '+' || f_str[i] == '-' || f_str[i] == '*' || f_str[i] == '/')
	{
	   a1 = num_pop();
	   b1 = num_pop();
	   switch(f_str[i])
	   {
		 case '+': {a1 = a1 + b1; break;}
		 case '-': {a1 = b1 - a1; break;}
		 case '*': {a1 = a1 * b1; break;}
		 case '/': {a1 = b1 / a1; break;}
	   }
	   if(!pointer2) num_create(a1);
	   else num_push(a1);
	}
	else
	{
	   while(operand_true(f_str[i]) && f_str[i] != '\0')
	   {
		 if (f_str[i] == 'a' || f_str[i] == 'A') a1 = a; else
		 if (f_str[i] == 'b' || f_str[i] == 'B') a1 = b; else
		 if (f_str[i] == 'c' || f_str[i] == 'C') a1 = c; else
		 if (f_str[i] == 'd' || f_str[i] == 'D') a1 = d; else
		 if (f_str[i] == 'e' || f_str[i] == 'E') a1 = e;
		 i++;
	   }

	  j=0;
	  if(!pointer2) num_create(a1);
	  else num_push(a1);
	}
  }
  return num_pop();
}
//-------------------------------------------------------------------------
void St::check()
{
  int skobka = 0, rang = 0, i, length = strlen(f_str);
  if(f_str[0] == ')')
  {
	err_code = fault;
	return;
  }
  if(f_str[0] == '*' || f_str[0] == '/')
  {
	err_code = fault;
	return;
  }
  for(i = 0; i < length; i++)
  {
	if(f_str[i] == '(')
	{
	   if(i > 0 && operand_true(f_str[i-1]))
	   {
		 err_code = fault;
		 return;
	   }
	   if(f_str[i+1] == '*' || f_str[i+1] == '/' || f_str[i+1] == ')')
	   {
		 err_code = fault;
		 return;
	   }
	   skobka++;
	   continue;
	}
	if(f_str[i] == ')')
	{
	   if((i > 0) && (f_str[i-1] == '*' || f_str[i-1] == '+' ||
	   f_str[i-1] == '-' || f_str[i-1] == '/'))
	   {
		 err_code = fault;
		 return;
	   }
	   if(operand_true(f_str[i+1]) || f_str[i+1] == '(')
	   {
		 err_code = fault;
		 return;
	   }
	   skobka--;
	   continue;
	}
	if(f_str[i] == '*' || f_str[i] == '/' || f_str[i] == '+' || f_str[i] == '-')
	{
	  rang++;
	  continue;
	}
	if(operand_true(f_str[i]))
	{
	  while (operand_true(f_str[++i]));
	  i--;
	  rang--;
	}
	else
	{
	  err_code = fault;
	  return;
	}
  }
  f_str[i]='\0';
  if(rang > -1)
  {
	err_code = fault;
	return;
  }
  if(rang < -1)
  {
	err_code = fault;
	return;
  }
  if(skobka > 0)
  {
	err_code = fault;
	return;
  }
  if(skobka < 0)
  {
	err_code = fault;
	return;
  }
}
//--------------------------------------------------------------------------
void St::put_spaces()
{
  int length = strlen(f_str), i, j = 0;
  for(i = 0;i < length;i++)
  {
	if((f_str[i] >= '(' && f_str[i] <= '+') || f_str[i] == '-' || f_str[i] == '/')
	{
	  s_str[j++] = f_str[i];
	  s_str[j++] = ' ';
	  continue;
	}
	else
	{
	  s_str[j++] = f_str[i];
	  while(operand_true(f_str[++i]) == 1 && f_str[i] != '\0')
	  s_str[j++] = f_str[i];
	  s_str[j++] = ' ';
	}
	i--;
  }
  s_str[j]='\0';
}
//-------------------------------------------------------------------------

