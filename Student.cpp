#include"Student.h"

string Student::getStudentID()
{
	return studentID;
}

void Student::setStudentID(string studentid)
{ 
	studentID = studentID   ; 
}

string Student::getFirstName()
{
	return firstName;
}

void Student::setFirstName(string firstname) 
{ 
	firstName = firstname; 
}

string Student::getLastName()
{
	return lastName;
}

void Student::setLastName(string lastname)
{
	lastName = lastname;
}

string Student::getEmail() 
{ 
	return Email; 
}

void Student::setEmail(string email) 
{ 
	Email = email; 
}

int Student::getAge() 
{ 
	return Age; 
}

void Student::setAge(int age) 
{ 
	Age = age; 
}

int* Student::getCourses() 
{ 
	return Courses; 
}

void Student::setCourses(int courses[]) 
{ 
	Courses[0] = courses[0]; 
	Courses[1] = courses[1]; 
	Courses[2] = courses[2]; 
}


DegreeProgram Student::getDegreeProgram() 
{ 
	return Degree; 
}

void Student::setDegreeProgram(DegreeProgram degree) 
{ 
	Degree = degree; 
}



Student::Student(string studentid, string firstname, string lastname, string email, int age, int courses[], DegreeProgram degree)
{
	studentID = studentid;
	firstName = firstname;
	lastName = lastname;
	Email = email;
	Age = age;
	Courses[0] = courses[0]; 
	Courses[1] = courses[1]; 
	Courses[2] = courses[2];
	Degree = degree;
}

Student::Student()
{

}

void Student::print()
{
	cout << studentID << "\t";
	cout << "First Name: " << firstName << "\t";
	cout << "Lase Name: " << lastName << "\t";
	cout << "Age: " << Age << " \t";
	cout << "DaysInCourses: {" << Courses[0] << ", " << Courses[1] << ", " << Courses[2] << "} ";
	if (Degree == 0)
		cout << "Degree Program: SECURITY" << endl;
	else if(Degree == 1)
		cout << "Degree Program: NETWORk" << endl;
	else if(Degree == 2)
		cout << "Degree Program: SOFTWARE" << endl;
}