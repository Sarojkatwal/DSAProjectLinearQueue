#include<SFML/Graphics.hpp>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<sstream>
#include "graphics.h"
#include "queuestatus.h"
using namespace std;
const int MAX = 8;
class FULL {};
class EMPTY {};
template<class T>
class queqe
{
private:
	int fronts, rear;
	T arr[MAX];
public:
	queqe()
	{
		fronts = 0;
		rear = 0;
	}
	void enqueue(T a)
	{
		if (rear == MAX)
		{
			throw FULL();
		}
		else
		{
			arr[rear++] = a;
			INSERTDELETE<T> A;
			A.show(arr, fronts, rear-1,MAX,1);
			cout << "Pushed element:" << a << endl;
		}
	}
	T dequeue()
	{
		if (rear == fronts)
		{
			throw EMPTY();
		}
		else
		{
			fronts = fronts + 1;
			INSERTDELETE<T> A;
			A.show(arr, fronts-1, rear, MAX,0);
			return arr[fronts-1];
		}
	}
	void printfr()
	{
		cout << "Front=" << fronts << "  Rear=" << rear << endl;
	}
};
int main()
{
	queqe<int> s1;
	int i, data;
	while (true)
	{
		try
		{
			cout << "1.ENQUEUE\n2.DEQUEUE\n3.Exit\n";
			cout << "Enter your choice:";
			cin >> i;
			if (i == 1)
			{
				cout << "Enter the data :";
				cin >> data;
				s1.enqueue(data);
				s1.printfr();
			}
			else if (i == 2)
			{
				cout << "DEQUEUEED data:" << s1.dequeue() << endl;
				s1.printfr();
			}
			else if (i == 3)
			{
				exit(0);
			}
			else
			{
				exit(0);
			}
		}
		catch (EMPTY)
		{
			EMPTYORFULL B;
			B.show("QUEUE EMPTY");
		}
		catch (FULL)
		{
			EMPTYORFULL B;
			B.show("QUEUE FULL");
		}
		cin.get();
		cin.get();
		system("cls");
	}
	return 0;
}


