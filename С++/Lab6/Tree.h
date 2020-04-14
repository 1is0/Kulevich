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
} *Root; // Root – указатель на корень

void Make(int);
void Print (Tree*, int);
void Del(int);
void Del_All(Tree*);
Tree* List(int);

int main() {
int b, found, key;
// b – для ввода ключей, found – код поиска, key – удаляемый ключ
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
//============ Создание дерева ==========================
void Make(int kod) {
Tree *Prev, *t, *t1;
int b,found;
if ( kod == 0 ) { // Формирование первого элемента
puts( "\n Input Root :");
scanf("%d", &b);
Root = List(b); // Установили указатель корня
}
//============= Вставка остальных элементов ===============
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
t1 = List(b); // Создаем новый узел
if ( b < Prev -> info ) Prev -> Left = t1;
else Prev -> Right = t1;
}
} // Конец цикла
}
//============= Удаление элемента по ключу (не корень) ===============
void Del(int key) {
Tree *Del,*Prev_Del,*R,*Prev_R;
// Del, Prev_Del - удаляемый элемент и его предок;
// R, Prev_R - элемент, на который заменяется удаленный и его предок;
Del = Root; Prev_Del = NULL;
//-------- Поиск удаляемого элемента и его предка по ключу key---------------------
while (Del != NULL && Del -> info != key) {
Prev_Del = Del;
if (Del->info >key) Del=Del->Left;
else Del=Del->Right;
}
if (Del==NULL){ // В дереве такого ключа нет
puts ( "\n NO Key!");
return;
}
//--------------------- Поиск элемента для замены R ----------------------------------------
//----------1. Если удаляемый элемент имеет одного потомка, или ЛИСТ -----------
if (Del -> Right == NULL) R = Del->Left;
else
if (Del -> Left == NULL) R = Del->Right;
else {
//----------------Иначе, ищем самый правый узел в левом поддереве------------------
Prev_R = Del;
R = Del->Left;
while (R->Right != NULL) {
Prev_R=R;
R=R->Right;
}
//------------------2. Если удаляемый элемент имеет одного потомка------------------
if( Prev_R == Del) R->Right=Del->Right;
else {
//------------------3. Если удаляемый элемент имеет двух потомков ------------------
R->Right=Del->Right;
Prev_R->Right=R->Left;
R->Left=Prev_R;
}
}
// Устанавливаем связь с предком удаляемого (Prev_Del) и заменой (R):
if (Prev_Del==NULL) { Root = Prev_Del = R; }
else
if (Del->info < Prev_Del->info) Prev_Del->Left=R;
else Prev_Del->Right=R;
printf("\n Delete %d element ",Del->info);
delete Del;
}
//============= Формирование (создание) элемента - листа =============
Tree* List(int i) {
Tree *t = new Tree; // Захват памяти
t -> info = i;
t -> Left = t -> Right = NULL;
return t;
}
//=========== Функция вывода на экран ========================
void Print ( Tree *p, int level ) {
if ( p ) {
Print ( p -> Right , level+1); // Вывод левого поддерева
for ( int i=0; i<level; i++) printf(" ");
printf("%d \n", p->info);
Print( p -> Left , level+1); // Вывод правого поддерева
}
}
//===================== Освобождение памяти ==================
void Del_All(Tree *t) {
if ( t != NULL) {
Del_All ( t -> Left);
Del_All ( t -> Right);
delete t;
}
}
