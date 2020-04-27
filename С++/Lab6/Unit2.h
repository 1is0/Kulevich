//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
#include <vcl.h>
//---------------------------------------------------------------------------
struct MyNode
{
	int key;
	AnsiString name;
	MyNode* left;
	MyNode* right;
};
typedef MyNode* PointerNode;

class MyTree
{
 public:
	PointerNode root;
	int nodesamount;
	MyTree();
	void addNode(int newkey, AnsiString newname);
	int addToMassFromTree(PointerNode ptr, int* keys, AnsiString* name, int &inMass);
	PointerNode findNewNode(int thiskey, PointerNode ptr);

	void balanceTree();

	void delTree();
	void delTreeRec(PointerNode ptr);
	void delNode(int key);

	void createTreeByMass(int* keys, AnsiString* name, int endborder);
	PointerNode createTreeMassRec(int* keys, AnsiString* name, int beg, int endborder);

	void showTree(TTreeView *TreeView);
	void showTreeRec(PointerNode ptr, TTreeView *TreeView, int &index);

	AnsiString findByKey(int key);

	void preOrder(TListBox *ListBox);
	void postOrder(TListBox *ListBox);
	void inOrder(TListBox *ListBox);
	void preOrderRec(PointerNode ptr, TListBox *ListBox);
	void postOrderRec(PointerNode ptr, TListBox *ListBox);
	void inOrderRec(PointerNode ptr, TListBox *ListBox);
};

class Solution : public MyTree
{
public:
	float exercisesolution();
	void findSumRec(PointerNode root, int &sum, int& counter);
	int maxDiff(int key);
	void maxDiffUtil(PointerNode ptr, int key, int &min_diff, int &min_diff_key);
};
#endif
