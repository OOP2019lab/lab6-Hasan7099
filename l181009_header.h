#pragma once
#pragma once
class student
{
private:
	static int counter;
	int ID;
	float * quiz_scores;
	int quiz_capacity;
	int quiz_taken;
	float GPA;

public:
	student();
	student(int quiz_capacity, float gpa);
	student(const student & A);
	~student();
	void add_quizScore(float marks);
	void setGPA(float gpa);
	void  print() const;
	float getGPA() const;
	bool isbetter(student A);
	void update_score(int quiz_index, float marks);

};

int student::counter = 0;
