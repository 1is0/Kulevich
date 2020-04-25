#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int a = 0;

struct tnode
{
    int field;
    struct tnode* left;
    struct tnode* right;
};

void treeprintrise(tnode* tree)
{
    if (tree != NULL) {
        treeprintrise(tree->left);
        printf("%d ", tree->field);
        treeprintrise(tree->right);
    }
}

void treeprintfall(tnode* tree)
{
    if (tree != NULL) {
        treeprintfall(tree->right);
        printf("%d ", tree->field);
        treeprintfall(tree->left);
    }
}
struct tnode* addnode(int x, tnode* tree) {
    if (tree == NULL)
    {
        tree = new tnode;
        tree->field = x;
        tree->left = NULL;
        tree->right = NULL;
    }
    else
        if (x < tree->field)
            tree->left = addnode(x, tree->left);
        else
            tree->right = addnode(x, tree->right);
    return(tree);
}

void freemem(tnode* tree)
{
    if (tree != NULL)
    {
        freemem(tree->left);
        freemem(tree->right);
        delete tree;
    }
}

int lengthchar(char* str)
{
    int i = 0;
    while (str[i]) i++;
    return i;
}

int arrayint(char* str, int* arr)
{
    int n = 0;
    int m = 0; 
    for (int i = lengthchar(str) - 1; i >= 0; i--)
    {
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == ' ')
        {

            if (str[i] != ' ')
            {
                int l = 1;
                for (int i = 0; i < m; i++)
                {
                    l = l * 10;
                }
                n = (str[i] - '0') * l + n;
                m++;
            }
            if (str[i] == ' ')
            {
                arr[a] = n;
                a++;
                n = 0;
                m = 0;
            }
        }
        else
        {
            printf("Wrong input\n");
            return 0;
        }
    }
    arr[a] = n;
    return *arr;
}

int main()
{
    struct tnode* root = 0;
    char str[80];
    int* arr = (int*)malloc(10 * sizeof(int));
    printf("Enter a string containing numbers: ");
    gets(str);
    if (!arrayint(str, arr)) {
        return 0;
    }

    for (int i = 0; i < a + 1; i++)
    {
        root = addnode(arr[i], root);
    }
    printf("Entered numbers in ascending order: ");
    treeprintrise(root);
    printf("\nEntered numbers in descending order: ");
    treeprintfall(root);
    freemem(root);
    return 0;
}
