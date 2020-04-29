//---------------------------------------------------------------------------

#ifndef QueryH
#define QueryH
//---------------------------------------------------------------------------
#endif
using namespace std;

template <typename T>
class List
{
public:

	int GetSize() { return Size; }

	void replace(); /////////////////////////////////

	void clear();
	void push_back(T data);
	void pop_front();
	void pop_back();
	void removeAt(int index);

	T & operator [] (const int index);

	List <T>();
	~List <T>();

protected:

	template <typename S>
	class Node
	{
	public:
		Node (T data = T(), Node *pNext = nullptr, Node *pPrev = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
			this->pPrev = pPrev;
		}

		T data;
		Node *pNext;
		Node *pPrev;
	};

	Node <T> *head;
	Node <T> *tail;
	int Size;

};

	   template <typename T>
 List <T>::List()
{
	head = nullptr;
	tail = nullptr;
	Size = 0;
}

template <typename T>
List <T>::~List()
{
	clear();
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template <typename T>
void List <T>::push_back(T data)
{
	if (Size > 1)
	{
		Node <T> *temp = tail;
		tail = new Node <T>(data, nullptr, tail);
		temp->pNext = tail;
	}

	else if (Size == 1)
	{
		tail = new Node <T>(data, nullptr, tail);
		head->pNext = this->tail;
	}

	else
	{
		head = tail = new Node <T>(data, head, tail);
	}
	Size++;
}

template <typename T>
void List <T>::pop_front()
{
	if (Size > 1)
	{
		Node <T> *temp = head;
		head = head->pNext;
		delete temp;
	}
	else if (Size == 1)
	{
		Node <T> *temp = head;
		tail = head = head->pNext;
		delete temp;
	}

	Size--;
}

template <typename T>
void List <T>::pop_back()
{
	if (Size > 1)
	{
		Node <T> *temp = tail;
		tail = tail->pPrev;
		delete temp;
	}
	else if (Size == 1)
	{
		Node <T> *temp = tail;
		tail = head = tail->pPrev;
		delete temp;
	}

	Size--;
}

template <typename T>
void List <T>::removeAt(int index)
{
	if (index == 0) pop_front();

	else if (index == Size - 1  || index > Size) pop_back();

	else if (index <= Size / 2)
	{
		Node<T> *previous = this->head;
		for (int i = 0; i < index-1 ; i++)

		{
			previous = previous->pNext;
		}

		Node<T> *toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		Node<T> *next = toDelete->pNext;
		delete toDelete;
		next->pPrev = previous;

		Size--;
	}

	else if (index > Size / 2)
	{
		Node<T> *next = this->tail;
		for (int i = Size - 1; i > index + 1; i--)
		{
			next = next->pPrev;
		}

		Node<T> *toDelete = next->pPrev;
		next->pPrev = toDelete->pPrev;
		Node<T> *previous = toDelete->pPrev;
		delete toDelete;
		previous->pNext = next;
		Size--;
	}
}

template <typename T>
T & List <T>::operator[] (const int index)
{
	if (index <= Size / 2)
	{
		int counter = 0;
		Node <T> *current = this->head;

		while (current != nullptr)
		{
			if (counter == index)
				return current->data;

			current = current -> pNext;
			counter++;
		}
	}
	else
	{
		int counter = Size - 1;
		Node <T> *current = this->tail;

		while (current != nullptr)
		{
			if (counter == index)
				return current->data;

			current = current -> pPrev;
			counter--;
		}
	}
}




 template <typename T>
void List <T>:: replace()
{
	Node <T> *t = this -> head;
	int min=t -> data;
	int max=t -> data;
	Node <T> *Qmin=t;
	Node <T> *Qmax=t;
	while( t != nullptr)
	{
		if(t -> data > max)
		{
		max = t -> data;
		Qmax = t;
		}
		if(t -> data < min)
		{
		min = t -> data;
		Qmin=t;
		}
		t = t -> pNext;
	}
	Qmax -> data=min;
	Qmin -> data=max;
}


template <typename T>
class Queue : List<T>
{

public :
List<T> list;
	Queue() : List<T>() {}

	void GetSize()
	{
		list.GetSize();
	}

	void clear()
	{
		list.clear();
	}
	template<typename S>
	void push_back(S data)
	{
		list.push_back(data);
    }
	void pop_front()
	{
		list.pop_front();
	}
	void pop_back()
	{
		list.pop_back;
    }
	void removeAt(int index)
	{
		list.removeAt(index);
	}

	void replace()
	{
		list.replace();
    }


};
