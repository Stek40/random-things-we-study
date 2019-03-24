#include<iostream>

using namespace std;

template <typename T>
struct node
{
	T value;
	node* previous;
};

template <typename T>
class Stack
{
	node<T>* last;

public:
	Stack(): last(NULL){}
	void push(T element)
	{
		node<T>* temp = new node<T>();
		temp->value = element;
		temp->previous = last;
		last = temp;
	}
	T top()
	{
		return last->value;
	}
	T pop()
	{
		if (last)
		{
			T result = last->value;
			node<T>* temp = last;
			last = last->previous;
			delete temp;
			return result;
		}
		cout << "EMPTY"<<endl;
		return 0;

	}
	~Stack()
	{
		while (last->previous)
		{
			pop();
		}
		pop();
	}
	bool is_empty()
	{
		if (last)return true;
		return false;
	}
};




int main()
{
	Stack<int> integers;
	cout<<integers.is_empty()<<endl;
	integers.push(4);

	cout<<integers.is_empty() << endl;

	cout << integers.pop()<<endl;

	cout << integers.is_empty() << endl;

	cout << integers.pop();



	system("pause");
	return 0;
}