#include<SFML/Graphics.hpp>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<sstream>
#include "graphics.h"
#include "queuestatus.h"
#include "Mainmenu.h"
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
			cout << "Popped element:" << arr[fronts-1] << endl;
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
	sf::RenderWindow window;
	mainmenu M;
	INPUT A;
	int x, num;
	queqe<int> s1;
	while (true)
	{
		try
		{
			x = M.draw();
			switch (x)
			{
			case 1:
				num = A.inputs(&window);
				if (num != -1)
				{
					s1.enqueue(num);
				}
				break;
			case 2:
				s1.dequeue();
				break;
			case 3:
				break;
			case 4:
				return 1;
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
			B.show("QUEUE fULL");
		}
	}
}


