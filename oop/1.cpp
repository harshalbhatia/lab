#include<iostream>
using namespace std;

class STUDENT
{
	static int count;
	char name[25];
	int marks1, marks2, marks3;
	int rollno;
	float average;
	public:
	void read();
	void display();
	void avg();
};

int STUDENT::count;

void STUDENT::read()
{
	cout<<"Enter name:\n";
	cin>>name;
	rollno = ++count;
	cout<<"Enter marks 1:\n";
	cin>>marks1;
	cout<<"Enter marks 2:\n";
	cin>>marks2;
	cout<<"Enter marks 3:\n";
	cin>>marks3;
}

void STUDENT::avg()
{
	if (marks1 > marks3 && marks2 > marks3)
		average = (marks1 + marks2)/2;
	else if (marks1 > marks2 && marks3 > marks2)
		average = (marks1 + marks3)/2;
	else
		average = (marks2 + marks3)/2;
}

void STUDENT::display()
{
	cout<<"\nName:"<<name;
	cout<<"\nRoll no:"<<rollno;
	cout<<"\nAverage:"<<average<<endl;
}

int main()
{
	STUDENT s[10];
	int n, i;
	cout<<"Enter the no. of students:\n";
	cin>>n;
	for(i=0; i<n; i++)
	{
		s[i].read();
		s[i].avg();
		s[i].display();
	}
	return(0);
}



/*
$  g++ 1.cpp
$ ./a.out
Enter the no. of students:
2 
Enter name:
Name   
Enter marks 1:
24
Enter marks 2:
21
Enter marks 3:
19

Name:Name
Roll no:1
Average:22
Enter name:
Naam
Enter marks 1:
23
Enter marks 2:
25
Enter marks 3:
17

Name:Naam
Roll no:2
Average:24
*/
