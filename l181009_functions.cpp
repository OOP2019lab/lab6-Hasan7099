#include <iostream>
#include "l181009_header.h"

using namespace std;

student::student()
{
	ID = counter;
	quiz_capacity = 3;
	quiz_taken = 0;
	quiz_scores = new float[quiz_capacity];
	GPA = 0;
	counter++;
}

student::student(int capacity, float gpa)
{
	ID = counter;
	quiz_capacity = capacity;
	quiz_taken = 0;
	quiz_scores = new float[quiz_capacity];
	GPA = gpa;
	counter++;

}

student::student(const student & A)
{
	ID = A.ID;
	quiz_capacity = A.quiz_capacity;
	quiz_taken = A.quiz_taken;
	quiz_scores = new float[quiz_capacity];
	GPA = A.GPA;
	for (int i = 0; i < quiz_capacity; i++)
	{
		quiz_scores[i] = A.quiz_scores[i];
	}
	counter++;

}

student::~student()
{
	ID = NULL;
	quiz_taken = 0;
	for (int i = 0; i < quiz_capacity; i++)
	{
		quiz_scores[i] = NULL;
	}
	delete[] quiz_scores;
	quiz_scores = nullptr;
	quiz_capacity = NULL;
	GPA = NULL;
}

void student::add_quizScore(float marks)
{
	if (quiz_taken == (quiz_capacity))
	{
		cout << "Array is Full." << endl;
	}
	else
	{
		quiz_scores[quiz_taken] = marks;
		quiz_taken++;
	}
}

void student::setGPA(float gpa)
{
	GPA = gpa;
}

float student::getGPA() const
{
	//cout << "GPA is : " << GPA << endl;
	return GPA;
}

void student::print() const
{
	cout << " -> Student ID : " << ID << endl;
	cout << " -> Student GPA : " << GPA << endl;
	cout << " -> Quizzes Taken : " << quiz_taken << endl;
	if (quiz_taken > 0)
	{
		cout << "Details of Quizzes : " << endl;
		for (int i = 0; i < quiz_capacity; i++)
		{
			cout << "Quiz " << i + 1 << " Marks : " << quiz_scores[i];
			cout << endl;
		}
	}

}

bool student::isbetter(student A)
{
	if (GPA > A.GPA)
		return true;
	else
		return false;
}

void student::update_score(int index, float score)
{
	if (index > quiz_taken)
		cout << "-> This quiz has not been taken \n";
	else
		quiz_scores[index - 1] = score;
}

