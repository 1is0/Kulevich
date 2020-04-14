//---------------------------------------------------------------------------

#ifndef TreeH
#define TreeH
//---------------------------------------------------------------------------
#endif

#include <stdio.h>
#include <conio.h>
using namespace std;

struct Tree
{
	int info;
	Tree *Left, *Right;
} *Root; // Root � ��������� �� ������

void Make(int);
void Print (Tree*, int);
void Del(int);
void Del_All(Tree*);
Tree* List(int);

int main() {
int b, found, key;
// b � ��� ����� ������, found � ��� ������, key � ��������� ����
while(1) {
puts(" Creat - 1\n View - 2\n Add - 3 \nDel Key - 4\n EXIT - 0");
switch (getch()) {
case '1': Make(0); break;
case '2': if( Root ==NULL ) puts ("\t END TREE !");
else Print(Root, 0);
break;
case '3': if(Root==NULL) Make(0);
else Make(1);
break;
case '4': puts("\n Input Del Info "); scanf("%d", &key);
Del(key);
break;
case '0': Del_All(Root);
puts("\n Tree Delete!");
return 0;
} // End switch
} // End while(1)
}
//============ �������� ������ ==========================
void Make(int kod) {
Tree *Prev, *t, *t1;
int b,found;
if ( kod == 0 ) { // ������������ ������� ��������
puts( "\n Input Root :");
scanf("%d", &b);
Root = List(b); // ���������� ��������� �����
}
//============= ������� ��������� ��������� ===============
while(1) {
puts( "\n Input Info :"); scanf("%d", &b);
if (b<0) break;
t = Root;
found = 0;
while ( t && !found ) {
Prev = t;
if( b == t->info) found = 1;
else
if ( b < t -> info ) t = t -> Left;
else t = t -> Right;
}
if (!found) {
t1 = List(b); // ������� ����� ����
if ( b < Prev -> info ) Prev -> Left = t1;
else Prev -> Right = t1;
}
} // ����� �����
}
//============= �������� �������� �� ����� (�� ������) ===============
void Del(int key) {
Tree *Del,*Prev_Del,*R,*Prev_R;
// Del, Prev_Del - ��������� ������� � ��� ������;
// R, Prev_R - �������, �� ������� ���������� ��������� � ��� ������;
Del = Root; Prev_Del = NULL;
//-------- ����� ���������� �������� � ��� ������ �� ����� key---------------------
while (Del != NULL && Del -> info != key) {
Prev_Del = Del;
if (Del->info >key) Del=Del->Left;
else Del=Del->Right;
}
if (Del==NULL){ // � ������ ������ ����� ���
puts ( "\n NO Key!");
return;
}
//--------------------- ����� �������� ��� ������ R ----------------------------------------
//----------1. ���� ��������� ������� ����� ������ �������, ��� ���� -----------
if (Del -> Right == NULL) R = Del->Left;
else
if (Del -> Left == NULL) R = Del->Right;
else {
//----------------�����, ���� ����� ������ ���� � ����� ���������------------------
Prev_R = Del;
R = Del->Left;
while (R->Right != NULL) {
Prev_R=R;
R=R->Right;
}
//------------------2. ���� ��������� ������� ����� ������ �������------------------
if( Prev_R == Del) R->Right=Del->Right;
else {
//------------------3. ���� ��������� ������� ����� ���� �������� ------------------
R->Right=Del->Right;
Prev_R->Right=R->Left;
R->Left=Prev_R;
}
}
// ������������� ����� � ������� ���������� (Prev_Del) � ������� (R):
if (Prev_Del==NULL) { Root = Prev_Del = R; }
else
if (Del->info < Prev_Del->info) Prev_Del->Left=R;
else Prev_Del->Right=R;
printf("\n Delete %d element ",Del->info);
delete Del;
}
//============= ������������ (��������) �������� - ����� =============
Tree* List(int i) {
Tree *t = new Tree; // ������ ������
t -> info = i;
t -> Left = t -> Right = NULL;
return t;
}
//=========== ������� ������ �� ����� ========================
void Print ( Tree *p, int level ) {
if ( p ) {
Print ( p -> Right , level+1); // ����� ������ ���������
for ( int i=0; i<level; i++) printf(" ");
printf("%d \n", p->info);
Print( p -> Left , level+1); // ����� ������� ���������
}
}
//===================== ������������ ������ ==================
void Del_All(Tree *t) {
if ( t != NULL) {
Del_All ( t -> Left);
Del_All ( t -> Right);
delete t;
}
}
