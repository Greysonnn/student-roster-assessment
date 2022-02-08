#include"degree.h"
#include<iostream>
using namespace std;
class Student
{
private:
	string studentID,firstName, lastName , Email;
	int Age , Courses[3];
	DegreeProgram Degree;

public:
	string getStudentID();
	void setStudentID(string studentid);
	string getFirstName();
	void setFirstName(string firstname);
	string getLastName();
	void setLastName(string lastname);
	string getEmail();
	void setEmail(string email);
	int getAge();
	void setAge(int age);
	int* getCourses();
	void setCourses(int courses[]);
	DegreeProgram getDegreeProgram();	
	void setDegreeProgram(DegreeProgram degree);
	Student(string studentid, string firstname, string lastname, string email, int age, int courses[], DegreeProgram degree);
	Student();
	void print();
};