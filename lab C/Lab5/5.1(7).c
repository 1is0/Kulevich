#include <stdio.h>
#include <math.h>
#include <stdlib.h>


typedef struct item {
    struct item* next;
    struct item* prev;
    int digit;
}Item;

typedef struct list {
    Item* head;
    Item* tail;
    int amount;
}List;

List Calculation(List number) {
    List num = number;

    Item* temp = num.tail;
    while (num.tail) {
        num.tail->digit *= 3;
        num.tail = num.tail->prev;
    }
    num.tail = temp;
    while (num.tail->prev) {
        if (num.tail->digit / 10 > 0) {
            int tmp = num.tail->digit / 10;
            num.tail->prev->digit += tmp;
            num.tail->digit %= 10;
        }
        num.tail = num.tail->prev;
    }
    num.tail = temp;

    if (num.head->digit / 10 > 0) {
        Item* p = (Item*)malloc(sizeof(Item));
        p->digit = num.head->digit / 10;
        p->prev = NULL;
        num.head->digit %= 10;
        p->next = num.head;
        num.head->prev = p;
        num.head = p;
        num.amount++;
    }
    return num;
}


List CreateNum(int pow) {
    List number = { NULL,NULL,0 };
    for (int i = 0; i < pow; i++)
    {
        if (!number.head) {
            Item* n = (Item*)malloc(sizeof(Item));
            n->digit = 3;
            n->next = n->prev = NULL;
            number.head = number.tail = n;
            number.amount++;
        }
        else {
            number = Calculation(number);
        }
    }
    return number;
}

void Print(List num) {
    Item* p = num.head;
    while (p) {
        printf("%d", p->digit);
        p = p->next;
    }

}

int main()
{
    int n;
    while (true)
    {
        printf("Enter the pomer of the numper 3: n =");
        while ((!scanf_s("%d", &n)) || (n <= 0))
        {
            printf("Wrong input! Try again. n =\n");
            rewind(stdin);
        } 
        List num = CreateNum(n);
        Print(num);
        printf("\n\n");
    }
    return 0;
}
