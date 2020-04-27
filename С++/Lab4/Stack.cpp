//---------------------------------------------------------------------------

#pragma hdrstop

#include "Stack.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


template <typename T>
Stack <T>::Stack(int maxSize)
{
       size = maxSize;
       stackPtr = new T[size];
       top=0;

}

template <typename T>
Stack <T>::Stack(const Stack<T> &otherStack)
{
	size = otherStack.size;
	stackPtr = new T[size];
	top = otherStack.getTop();

	for (int i = 0; i < top; i++) {
	    stackPtr[i] = otherStack.getPtr()[i];
	}
}

template <typename T>
Stack <T>::~Stack()
{
    delete [] stackPtr;
}

template <typename T>
void Stack <T>::push(const T &value)
{
    if(top<size)
    {
	stackPtr[top++] = value;
    }
}

template <typename T>
T Stack <T>::pop()
{

      top--;

}

template <typename T>
const T &Stack <T>::Peek(int num)
{
   if(num<=top)
   {
       return stackPtr[top-num];
   }

}

template <typename T>
int Stack <T>::getStackSize()
{
    return size;
}

template <typename T>
T *Stack<T>::getPtr()
{
    return stackPtr;
}

template <typename T>
int Stack<T>::getTop()
{
    return top;
}

template <typename T>
void Stack<T>::clear()
{
    delete [] stackPtr;
}

template <typename T>
AnsiString Stack<T>::Output()
{
    AnsiString str = stackPtr;
    return str;
}

template <typename T>
bool Stack<T>::isEmpty()
{
    if(top==0)
    return true;
    else
    return false;
}
