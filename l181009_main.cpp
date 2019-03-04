#include <iostream>
#include "l181009_header.h"

using namespace std;


void display_students(student * students, int size)
{
	for (int i = 0; i < size; i++)
	{
		students[i].print();
		cout << "----------------------------------------\n";
	}
}

void sort_by_gpa(student students[], int size)
{
	student temp;
	float a;
	float b;

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size - 1; j++)
		{
			a = students[j].getGPA();
			b = students[i].getGPA();
			if (a< b)
			{
				temp = students[i];
				students[i] = students[j];
				students[j] = temp;
			}
		}
	}
}

void gpa_above_two(student * students, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (students[i].getGPA() > 2.0)
			students[i].print();
	}
}


int main()
{
	student B;		//ID and counter  = 0
	student A;		//ID and counter = 1

	int size = 3;		//size of array
	float marks = 4.5;
	A.add_quizScore(marks);
	cout << "Run 1" << endl;
	A.add_quizScore(marks);
	cout << "Run 2" << endl;
	A.add_quizScore(marks);
	cout << "Run 3" << endl;
	A.add_quizScore(marks);
	cout << "Run 4" << endl;
	A.setGPA(1.5);
	B.setGPA(2.4);
	A.update_score(3, 3.7);
	A.print();
	cout << "----------------------------------------\n";
	student C(A);
	C.setGPA(1.8);
	C.print();
	cout << "----------------------------------------\n";
	cout << A.isbetter(C) << endl;
	cout << "________________________________________________\n";
	//student students[3] = { {A},{B},{C} };
	student * students = new student[3];
	students[0] = A;
	students[1] = B;
	students[2] = C;
	display_students(students, size);
	cout << endl;
	sort_by_gpa(students, size);
	cout << endl;
	cout << "SORTED" << endl << endl;
	display_students(students, size);
	cout << endl;
	cout << "GPA Above 2" << endl << endl;
	gpa_above_two(students, size);
	cout << endl;
	system("pause");
}

