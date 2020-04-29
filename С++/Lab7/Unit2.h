//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
#include <vcl.h>
#define tab_size 15
//---------------------------------------------------------------------------
struct Node
 {
	int key;
	Node *next;
};
 Node *hash_table[tab_size];

class HashTab
{
public:
   HashTab();
   int hash_tableFunction(int key);
   void insertmynode(Node **hash_table, int key);
   void deletemynode(Node **hash_table, int key);
   Node* searchmynode(Node **hash_table, int key);
};

class Counting : public HashTab
{
public:
   int countaverage(Node **hash_table);
   int countamount(Node **hash_table);
};

#endif
