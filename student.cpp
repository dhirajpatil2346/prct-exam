#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
struct student
{
	int roll;
	char name[20];
	char div;
	char add[20];
} s[10];
void getdata(int n)
{

	for (int i = 0; i < n; i++)
	{
		cout << "Enter the roll number of student :";
		cin >> s[i].roll;
		cout << "Enter the Name of student:";
		cin >> s[i].name;
		cout << "enter the  division of student:";
		cin >> s[i].div;
		cout << "Enter the Addresss of student :";
		cin >> s[i].add;

		cout << "\n\n\n";
	}
}
void putdata(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\nroll Number of student :" << s[i].roll;
		cout << "\n Name of student is:" << s[i].name;
		cout << "\n Division is:" << s[i].div;
		cout << "\nAddress of student is:" << s[i].add;
		cout << "\n\n\n";
	}
}
int del(int n, int x, char ch[10])
{
	int flag = 0, pos;
	for (int i = 0; i < n - 1; i++)
	{
		if (s[i].roll == x && !(strcmp(s[i].name, ch)))
		{
			flag = 1;
			pos = i;
		}
	}

	if (flag == 1)
	{

		for (int i = pos; i < n; i++)
		{
			s[i].roll = s[i + 1].roll;
			strcpy(s[i].name, s[i + 1].name);
			s[i].div = s[i + 1].div;
			strcpy(s[i].add, s[i + 1].add);
		}
		cout << "Student Information is Succesfully deleted";
	}
	else
		cout << "Student roll Numbered is not found";
	return (n - 1);
}
void modify(int n, int x)
{
	int p;
	char ch;
	for (int i = 0; i < n - 1; i++)
	{

		if (s[i].roll == x)
		{

			do
			{
				cout << "\n 1:Modify name \n2.Modify division\n3.Modify Address\n ";

				cout << "Enter the choice :";
				cin >> p;
				switch (p)
				{
				case 1:
					cin >> s[i].name;
					break;
				case 2:

					cin >> s[i].div;
					break;
				case 3:
					cin >> s[i].add;
					break;
				}
				cout << "Do You want to continue:";
				cin >> ch;
			} while (ch == 'Y' || ch == 'y');
		}
	}
}

void search(int x, int n)
{
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i].roll == x)
		{
			flag = 1;
		}
	}
	if (flag == 1)
		cout << "Record is Found ";
	else
		cout << "Record is not found ";
}
int main()
{

	// struct student *s;
	int n;
	int x, c;
	char ch;
	char a[10];

	do
	{

		cout << "\n 1.Insert the Information\n2.Delete the Information\n3.Search the Information     \n4.Modify Student \n 5.Print the Student Information ";
		cout << "Enter your choice";
		cin >> c;

		switch (c)
		{
		case 1:
			cout << "Enter the number of student :";
			cin >> n;

			getdata(n);
			break;
		case 2:
			cout << "Enter the roll number to be delete :";
			cin >> x;
			cout << "\nEnter the name of student:";
			cin >> a;
			n = del(n, x, a);
			break;
		case 3:
			cout << "Enter the roll number which to be find ";
			cin >> x;
			search(x, n);
			break;
		case 4:
			cout << "Enter the roll Number of student :";
			cin >> x;
			modify(n, x);
			break;
		case 5:
			putdata(n);
		}
		cout << "\n Do You want to continue:(y/n)";
		cin >> ch;
	} while (ch == 'Y' || ch == 'y');

	ofstream out;
	out.open("STUDENT INFORMATION");
	for (int i = 0; i < n; i++)
	{
		out << "\nroll Number of student :" << s[i].roll;
		out << "\n Name of student is:" << s[i].name;
		out << "\n Division is:" << s[i].div;
		out << "\nAddress of student is:" << s[i].add;
		out << "\n\n\n";
	}
}
