#include"Roster.h"

Roster::Roster()
{
	classRosterArray = new Student[10];
	numStudents = 0;
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
	int arr[3] = { daysInCourse1,daysInCourse2,daysInCourse3 };
	Student obj(studentID, firstName, lastName, emailAddress, age, arr, degreeprogram);
	classRosterArray[numStudents++] = obj;
}

void Roster::printAll()
{
	for (int i = 0; i < numStudents; i++)
	{
		classRosterArray[i].print();
	}
}

void Roster::remove(string studentID)
{
	bool isThere = false;
	for (int i = 0; i < numStudents; i++)
	{
		if (classRosterArray[i].getStudentID() == studentID)
			isThere=true;
	}

	int size = numStudents;
	if (!isThere)
		cout << "\nStudent not found, Sorry!\n";
	else
	{
		for (int i = 0; i < size; i++)
		{
			if (classRosterArray[i].getStudentID() == studentID)
			{
				for (int j = i; j < (size - 1); j++)
					classRosterArray[j] = classRosterArray[j + 1];

				numStudents--;
			}

		}		
	}
}

void Roster::printAverageDaysInCourse(string studentID)
{
	bool isThere = false;
	for (int i = 0; i < numStudents; i++)
	{
		if (classRosterArray[i].getStudentID() == studentID)
		{
			int* arr = classRosterArray[i].getCourses();
			double sum = arr[0] + arr[1] + arr[2];
			double avg = sum / 3.0;

			cout << "Average of number of days of 3 courses of Student : " << classRosterArray[i].getStudentID() << " is : " << avg << endl;
			isThere = true;
		}
	}

	if (!isThere)
		cout << "\nStudent not found, Sorry!\n";
}


void Roster::printInvalidEmails()
{
	for (int i = 0; i < numStudents; i++)
	{
		string text = classRosterArray[i].getEmail();
		bool isAtRate = false;
		bool IsDot = false;
		bool IsSpace = false;
		for (int j = 0; j < text.length(); j++)
		{
			if (text[j] == '@') 
				isAtRate = true;
			else if (text[j] == '.') 
				IsDot = true;
			else if (text[j] == ' ') 
			{ 
				IsSpace = true;
				break;
			}
		}

		if (IsSpace || (!isAtRate || !IsDot))
		{
			cout << text << endl;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeprogram)
{
	bool isThere = false;
	for (int i = 0; i < numStudents; i++)
	{
		if (classRosterArray[i].getDegreeProgram() == degreeprogram)
		{
			classRosterArray[i].print();
			isThere = true;
		}
	}

	if (!isThere)
		cout << "\nStudent not found, Sorry!\n";
}

int Roster::getNumStudents()
{
	return numStudents;
}

string Roster::getStudentID(int id)
{
	return classRosterArray[id].getStudentID();
}

Roster::~Roster()
{
	delete[] classRosterArray;
}