//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
//---------------------------------------------------------------------------
HashTab::HashTab()
{
   for (int i = 0; i < tab_size; i++) hash_table[i] = NULL;
}
//---------------------------------------------------------------------------
int HashTab :: hash_tableFunction(int key)
{
   return key % tab_size;
}
//------------------------------------------------------------------------------
void HashTab :: insertmynode(Node **hash_table, int key)
 {
	int i;
	Node *ptr = new Node();
	i = hash_tableFunction(key);
	if(ptr != NULL)
	{
	  ptr->key = key;
	  ptr->next = hash_table[i];
	  hash_table[i] = ptr;
	}
}
//------------------------------------------------------------------------------
void HashTab :: deletemynode(Node **hash_table, int key)
{
	int i;
	Node *oldptr = NULL;
	i = hash_tableFunction(key);
	Node *ptr = hash_table[i];
	while(ptr != NULL)
	{
		if (ptr->key == key)
		 {
			if (oldptr == NULL) hash_table[i] = ptr->next;
			else oldptr->next = ptr->next;
			ptr = NULL;
			return;
		 }
		 oldptr = ptr;
		 ptr = ptr->next;
	}
}
//------------------------------------------------------------------------------
Node* HashTab :: searchmynode(Node **hash_table, int key)
{
	Node *ptr;
	ptr = hash_table[hash_tableFunction(key)];
	while (ptr)
	{
	  if(ptr->key == key) return ptr;
	  ptr = ptr->next;
	}
	if(ptr == NULL) return NULL;
}

int Counting :: countaverage(Node **hash_table)
{
	int cnt = 0, sum = 0;
	for(int i = 0; i < tab_size; i++)
	{
	   if(hash_table[i] != nullptr)
	   {
		  for(Node* ptr = hash_table[i]; ptr!=NULL;ptr=ptr->next)
		  {
			  sum+=ptr->key;
			  cnt++;
		  }
	   }
	}
	return (float)sum / cnt;

}
int Counting :: countamount(Node **hash_table)
{
  int counter = 0;
  for(int i = 0; i < tab_size; i++)
  {
	 if(hash_table[i] != nullptr)
	 {
		for(Node* ptr = hash_table[i]; ptr!=NULL;ptr=ptr->next)
		{
		   if(ptr->key < countaverage(hash_table))
		   {
			 counter++;
		   }
		}
	 }
  }
  return counter;
}
  //------------------------------------------------------------------------------

#pragma package(smart_init)
