#include<iostream>
using namespace std;

class shape
{
	protected: int x, y;
	public:
		virtual void getdata() = 0;
		virtual void compute() = 0;
};

class circle:public shape
{
	void getdata()
	{
		cout<<"Enter the radius:\n";
		cin>>x;
	}
	void compute()
	{
		float a;
		a = x * x * 3.14;
		cout<<"Area of the given circle is: "<<a<<".\n";
	}
};

class rectangle:public shape
{
	void getdata()
	{
		cout<<"Enter breadth and length\n";
		cin>>x;
		cin>>y;
	}
	void compute()
	{
		float a;
		a = x * y;
		cout<<"Area is "<<a<<".\n";
	}
};

class square:public shape
{
	void getdata()
	{
		cout<<"Enter length:\n";
		cin>>x;
	}
	void compute()
	{
		float a;
		a = x * x;
		cout<<"Area is : "<<a<<".\n";
	}
};

int main()
{
	circle cir;
	rectangle rect;
	square sq;
	shape *p[3];
	p[0] = &cir;
	p[1] = &rect;
	p[2] = &sq;
	int choice;
	while(1)
	{
		cout<<"1.c 2.r 3.s\n";
		cout<<"choice\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				p[0] -> getdata();
				p[0] -> compute();
				break;
			case 2:
				p[1] -> getdata();
				p[1] -> compute();
				break;
			case 3:
				p[2] -> getdata();
				p[2] -> compute();
				break;
			default:
				return(0);
		}
	}
}
