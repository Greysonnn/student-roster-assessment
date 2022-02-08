#include"Student.h"
#include<iostream>

using namespace std;

class Roster
{
private:
	Student* classRosterArray;
	int numStudents;

public:
	Roster();
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeprogram);
	int getNumStudents();
	string getStudentID(int id);
	~Roster();
};