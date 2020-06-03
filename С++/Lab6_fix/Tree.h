//---------------------------------------------------------------------------
#ifndef TreeH
#define TreeH
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
	void addNode(int, AnsiString);
	int addToMassFromTree(PointerNode, int*, AnsiString*, int&);
	PointerNode findNewNode(int, PointerNode);
	void balance();
	void deleteTree();
	void deleteTreeRecursively(PointerNode);
	void deleteNode(int);
	void createTreeByMass(int*, AnsiString*, int);
	PointerNode createTreeMassRecursively(int*, AnsiString*, int, int);
	void showTree(TTreeView*);
	void showTreeRecursively(PointerNode, TTreeView*, int&);
	AnsiString findByKey(int);
	void preOrder(TListBox*);
	void postOrder(TListBox*);
	void inOrder(TListBox*);
	void preOrderRecursively(PointerNode, TListBox*);
	void postOrderRecursively(PointerNode, TListBox*);
	void inOrderRecursively(PointerNode, TListBox*);
};

class Solution : public MyTree
{
public:
	float exercisesolution();
	void sumRecursively(PointerNode, int&, int&);
	int findMaxDifference(int);
	void findMaxDifferenceUtil(PointerNode, int, int&, int&);
};
#endif
