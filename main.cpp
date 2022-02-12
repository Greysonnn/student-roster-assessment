#include"Roster.h"
#include<iostream>
#include<string>

using namespace std;

Student getStudentObject(string line)
{
	string data[9];
	int index = 0;
	int prev = 0;
	string temp;
	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] == ',')
		{
			temp = line.substr(prev, i-prev);
			prev = i+1;
			data[index] = temp;
			index++;
		}
		
	}

	temp = line.substr(prev, line.length()-1);
	data[index] = temp;

	int age = stoi(data[4]);
	int course[3] = { stoi(data[5]),stoi(data[6]) , stoi(data[7]) };
	DegreeProgram deg = SECURITY;
	if (data[8] == "SECURITY")
		deg = SECURITY;
	else if (data[8] == "NETWORK")
		deg = NETWORK;
	else if (data[8] == "SOFTWARE")
		deg = SOFTWARE;

	Student newStd(data[0], data[1], data[2], data[3], age , course , deg);
	return newStd;
}

int main()
{
	cout << "Course Title: Scripting and Programming - Applications\n"
		<< "Programming Language : C++\n"
		<< "Student ID : 000021268\n"
		<< "Student Name : Greysonnn\n\n";

	
	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Greyson,Smith,gsmith@comcast.edu,29,60,33,13,SOFTWARE" };


	Roster classRoster;

	for (int i = 0; i < 5; i++)
	{
		Student stdObj = getStudentObject(studentData[i]);
		classRoster.add(stdObj.getStudentID(), stdObj.getFirstName(), 
			stdObj.getLastName(), stdObj.getEmail(), stdObj.getAge(), 
			stdObj.getCourses()[0], stdObj.getCourses()[1], stdObj.getCourses()[2], stdObj.getDegreeProgram());
	}

	cout << "All Students in Class Roster are : \n";
	classRoster.printAll();

	cout << "\nInvalid Email of student are :\n";
	classRoster.printInvalidEmails();

	cout << "\nAverage days of courses of all classRoster are: \n";
	for (int i = 0; i < classRoster.getNumStudents(); i++)
	{
		string temp = classRoster.getStudentID(i);
		classRoster.printAverageDaysInCourse(temp);  
	}

	cout << "\nAll student with SOFTWARE as course are:\n";
	classRoster.printByDegreeProgram(SOFTWARE);

	classRoster.remove("A3");
	cout << "\nAll Students in classRoster after removing A3 are : \n";
	classRoster.printAll();

	cout << "\nTrying to remove A3 again:";
	classRoster.remove("A3");
}
