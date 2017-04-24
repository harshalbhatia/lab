#include<iostream>
using namespace std;


class COMPLEX
{
	float x, y;
	public:
	void read();
	void display();
	COMPLEX add(int);
	COMPLEX add(COMPLEX);
};


void COMPLEX::read()
{
	cout<<"Enter the real part:\n";
	cin>>x;
	cout<<"Enter the imaginary part:\n";
	cin>>y;
}

void COMPLEX::display()
{
	cout<<x<<" + i "<<y<<endl;
}

COMPLEX COMPLEX::add(int a)
{
	COMPLEX s2;
	s2.x = x + a;
	s2.y = y;
	return s2;
}

COMPLEX COMPLEX::add(COMPLEX s2)
{
	COMPLEX s3;
	s3.x = x + s2.x;
	s3.y = y + s2.y;
	return s3;
}

int main()
{
	COMPLEX s1, s2, s3;
	int a;
	s1.read();
	cout<<"Enter an integer value:\n";
	cin>>a;
	s2 = s1.add(a);
	s3 = s1.add(s2);
	s1.display();
	s2.display();
	s3.display();
}

/*
$ g++ 3.cpp
$ ./a.out
Enter the real part:
3
Enter the imaginary part:
43
Enter an integer value:
12
3 + i 43
15 + i 43
18 + i 86
*/