//---------------------------------------------------------------------------

#ifndef StackH
#define StackH
template <typename T>
class Stack
{
private:
	T *stackPtr; //on first el
        int size;
	int top;

public:
       Stack(int n );
       Stack(const Stack<T>&);
       ~Stack();

       void push(const T&);
       T pop();
       void printStack();
       const T &Peek(int n);
       int getTop();
       T* getPtr();
       int getStackSize();
       void clear();
       AnsiString Output();
       bool isEmpty();


};
//---------------------------------------------------------------------------
#endif


