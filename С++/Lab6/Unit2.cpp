//---------------------------------------------------------------------------

#pragma hdrstop

#include "Unit2.h"
MyTree::MyTree()
{
	root = NULL;
	nodesamount = 0;
}

void MyTree::addNode(int newkey, AnsiString newname)
{
	PointerNode wNode;
	if(root == NULL)
	{
		root = new MyNode;
		root->key = newkey;
		root->name = newname;
		root->left = NULL;
		root->right = NULL;
		nodesamount++;
	}
	else
	{
		wNode = findNewNode(newkey, root);
		if(wNode == NULL)
		{
			Application->MessageBox(String("Ýëåìåíò ñ òàêèì êëþ÷îì ñóùåñòâóåò").c_str(), String("Îøèáêà").c_str(), MB_OK);
		}
		else
		{
			wNode->key = newkey;
			wNode->name = newname;
			nodesamount++;
		}
	}
}

PointerNode MyTree::findNewNode(int tkey, PointerNode ptr)
{
	if(tkey == ptr->key) return NULL;
	if(tkey < ptr->key)
	{
		if(ptr->left == NULL)
		{
			ptr->left = new MyNode;
			ptr->left->left = NULL;
			ptr->left->right = NULL;
			return ptr->left;
		}
		else
		{
			return findNewNode(tkey, ptr->left);
		}
	}
	else
	{
		if(ptr->right == NULL)
		{
			ptr->right = new MyNode;
			ptr->right->left = NULL;
			ptr->right->right = NULL;
			return ptr->right;
		}
		else
		{
			return findNewNode(tkey, ptr->right);
		}
	}

}

void MyTree::balance()
{
	if(nodesamount > 1)
	{
		int inMass = 0;
		int *keys = new int[nodesamount];
		AnsiString *names = new AnsiString[nodesamount];
		addToMassFromTree(root, keys, names, inMass);
		createTreeByMass(keys, names, nodesamount);
		delete[] keys;
	}
}

int MyTree::addToMassFromTree(PointerNode ptr, int *keys, AnsiString *names, int &inMass)
{
	if(ptr->left != NULL) inMass = addToMassFromTree(ptr->left, keys, names, inMass);
	keys[inMass] = ptr->key;
	names[inMass] = ptr->name;
	inMass++;
	if(ptr->right != NULL) inMass = addToMassFromTree(ptr->right, keys, names, inMass);
	return inMass;
}

void MyTree::createTreeByMass(int *keys, AnsiString *names, int endborder)
{
	delTree();
	root = createTreeMassRec(keys, names, 0, endborder);
}

PointerNode MyTree::createTreeMassRecursively(int *keys, AnsiString *names, int beg, int endborder)
{
	PointerNode Tree;
	int border1, border2;
	if (endborder == 0) return NULL;
	Tree = new MyNode;
	Tree->key = keys[beg + endborder/2];
	Tree->name = names[beg + endborder/2];
	nodesamount++;
	border1 = endborder / 2;
	border2 = endborder - border1 - 1;
	Tree->left = createTreeMassRec(keys, names, beg, border1);
	Tree->right = createTreeMassRec(keys, names, beg + border1 + 1, border2);
	return Tree;
}

void MyTree::deleteTree()
{
	delTreeRec(root);
	nodesamount = 0;
}

void MyTree::deleteTreeRecursively(PointerNode ptr)
{
	if(ptr != NULL)
	{
		delTreeRec(ptr->left);
		delTreeRec(ptr->right);
		ptr->left = NULL;
		ptr->right = NULL;
		if(ptr == root) root = NULL;
		else delete ptr;
	}
}

void MyTree::deleteNode(int key)
{
	PointerNode ptr = root, prevptr = NULL;
	while(ptr != NULL && ptr->key != key)
	{
		prevptr = ptr;
		if(key < ptr->key) ptr = ptr->left;
		else ptr = ptr->right;
	}
	if(ptr == NULL)
	{
		Application->MessageBox(String("Ýëåìåíòf ñ òàêèì êëþ÷îì íåò").c_str(), String("Îøèáêà").c_str(), MB_OK);
		nodesamount++;
	}
	else if(ptr == root && ptr->left == NULL && ptr->right == NULL)
	{
		root = NULL;
	}
	else if(ptr == root && ptr->left != NULL && ptr->right == NULL)
	{
		root = ptr->left;
	}
	else if(ptr == root && ptr->left == NULL && ptr->right != NULL)
	{
		root = ptr->right;
	}
	else if(ptr->left == NULL && ptr->right == NULL)
	{
		if(prevptr->right == ptr) prevptr->right = NULL;
		else prevptr->left = NULL;
	}
	else if(ptr->left == NULL && ptr->right != NULL)
	{
		if(prevptr->right == ptr) prevptr->right = ptr->right;
		else prevptr->left = ptr->right;
	}
	else if(ptr->left != NULL && ptr->right == NULL)
	{
		if(prevptr->right == ptr) prevptr->right = ptr->left;
		else prevptr->left = ptr->left;
	}
	else
	{
		PointerNode newptr = ptr->left, newprevptr = ptr;
		while(newptr->right != NULL)
		{
			newprevptr = newptr;
			newptr = newptr->right;
		}
		if(newprevptr == ptr)
		{
			newprevptr->left = newptr->left;
		}
		else
		{
			newprevptr->right = newptr->left;
		}
		ptr->key = newptr->key;
		ptr->name = newptr->name;
	}
	nodesamount--;
}

AnsiString MyTree::findByKey(int key)
{
	PointerNode ptr = root;
	while(ptr != NULL && ptr->key != key)
	{
		if(key < ptr->key) ptr = ptr->left;
		else ptr = ptr->right;
	}
	if(ptr == NULL)
	{
		Application->MessageBox(String("Ýëåìåíòa ñ òàêèì êëþ÷îì íåò").c_str(), String("Îøèáêà").c_str(), MB_OK);
		return ".....";
	}
	else return ptr->name;
}

void MyTree::showTree(TTreeView *TreeView)
{
	int index = 0;
	TreeView->Items->Clear();
	if(root != NULL)
	{
		TreeView->Items->Add(NULL, root->name);
		showTreeRec(root, TreeView, index);
	}
}

void MyTree::showTreeRecursively(PointerNode ptr, TTreeView *TreeView, int &index)
{
	int nowindex = index;
	if(ptr->left != NULL)
	{
		TreeView->Items->AddChild(TreeView->Items->Item[nowindex], ptr->left->name);
		index++;
		showTreeRec(ptr->left, TreeView, index);
	}
	if(ptr->right != NULL)
	{
		TreeView->Items->AddChild(TreeView->Items->Item[nowindex], ptr->right->name);
		index++;
		showTreeRec(ptr->right, TreeView, index);
	}
}

void MyTree::preOrder(TListBox *ListBox)
{
	ListBox->Items->Clear();
	if(root != NULL)
		preOrderRec(root, ListBox);
}

void MyTree::preOrderRecursively(PointerNode ptr, TListBox *ListBox)
{
	ListBox->Items->Add(AnsiString(ptr->key) + " " + ptr->name);
	if(ptr->left != NULL) preOrderRec(ptr->left, ListBox);
	if(ptr->right != NULL) preOrderRec(ptr->right, ListBox);
}

void MyTree::postOrder(TListBox *ListBox)
{
	ListBox->Items->Clear();
	if(root != NULL)
		postOrderRec(root, ListBox);
}

void MyTree::postOrderRecursively(PointerNode ptr, TListBox *ListBox)
{
	if(ptr->left != NULL) postOrderRec(ptr->left, ListBox);
	if(ptr->right != NULL) postOrderRec(ptr->right, ListBox);
	ListBox->Items->Add(AnsiString(ptr->key) + " " + ptr->name);
}

void MyTree::inOrder(TListBox *ListBox)
{
	ListBox->Items->Clear();
	balanceTree();
	if(root != NULL)
		inOrderRec(root, ListBox);
}

void MyTree::inOrderRecursively(PointerNode ptr, TListBox *ListBox)
{
	if(ptr->left != NULL) inOrderRec(ptr->left, ListBox);
	ListBox->Items->Add(AnsiString(ptr->key) + " " + ptr->name);
	if(ptr->right != NULL) inOrderRec(ptr->right, ListBox);
}
float Solution::exercisesolution()
{

	balanceTree();
	float mid = 0;
	int sum = 0;
	int counter = 0;
	if(root != NULL)
		 findSumRec(root, sum, counter);
	mid = (float)sum/counter;
	return mid;

}
void Solution::sumRecursively(PointerNode ptr, int &sum, int&counter)
{
	if(ptr->left != NULL) findSumRec(ptr->left, sum, counter);
	sum+=ptr->key;
	counter++;
	if(ptr->right != NULL) findSumRec(ptr->right, sum, counter);
}

void Solution::findMaxDifferenceUtil(PointerNode ptr, int key, int &min_diff, int &min_diff_key)
{
	if (ptr == NULL)  return ;
	if (ptr->key == key)
	{
		min_diff_key = key;
		return;
	}
	if (min_diff > abs(ptr->key - key))
	{
		min_diff = abs(ptr->key - key);
		min_diff_key = ptr->key;
	}
	if (key < ptr->key) maxDiffUtil(ptr->left, key, min_diff, min_diff_key);
	else maxDiffUtil(ptr->right, key, min_diff, min_diff_key);
}

int Solution::findMaxDifference(int key)
{
	PointerNode ptr = root;
	int min_diff = INT_MAX, min_diff_key = -1;
	maxDiffUtil(ptr, key, min_diff, min_diff_key);
	return min_diff_key;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
