// This program demonstrates the overloaded = operator returning a value.
#include <iostream>
#include "StudentTestScores.h"
using namespace std;

// Function prototype
void displayStudent(StudentTestScores&);

int main()
{
	cout << "Use default constructor to create student1 object.\n";
	StudentTestScores student1 = StudentTestScores();
	cout << "student1 object:\n";
	displayStudent(student1);
    cout << endl;

	cout << "Use overloaded constructor to create student2 object.\n";
	StudentTestScores student2 = StudentTestScores("John Doe", 5);
	cout << "student2 object:\n"; 
	displayStudent(student2);
    cout << endl;

	cout << "Assign values to student2's test scores.\n";
	student2[0] = 100.0;
	student2[1] = 95.0;
	student2[2] = 80.0;
	student2[3] = 90.0;
	student2[4] = 85.0;
	cout << "student2 object after assigning test scores:\n";
	displayStudent(student2);
	cout << endl;	

	cout << "Use copy constructor to create student3 object.\n";
	StudentTestScores student3 = StudentTestScores(student2);
	cout << "student3 object after copy constructor:\n"; 
	displayStudent(student3);
	cout << endl;

	cout << "Use overloaded = operator to assign student2 to student1.\n";
	student1 = student2;
	cout << "student1 object after assignment:\n";
	displayStudent(student1);
	cout << endl;

	cout << "Assign an out-of-bounds value to student1's test scores.\n";
	try {
		cout << "Attempting to assign a value to student1[5]...\n";
		student1[5] = 100.0;
	}
	catch (const std::out_of_range& e) {
		cout << "Error: " << e.what() << endl;
	}
	cout << endl;

	cout << "Access an out-of-bounds value from student1's test scores.\n";
	try {
		cout << "Attempting to access student1[5]...\n";
		double score = student1[5];
	}
	catch (const std::out_of_range& e) {
		cout << "Error: " << e.what() << endl;
	}
	cout << endl;

	cout << "Change student2's name to Jane Smith and test scores to 70, 75, 80, 85, 90.\n";
	student2.setStudentName("Jane Smith");
	student2[0] = 70.0;
	student2[1] = 75.0;
	student2[2] = 80.0;
	student2[3] = 85.0;
	student2[4] = 90.0;
	cout << "student2 object after changes:\n";
	displayStudent(student2);
	cout << endl;

	cout << "Change student1's name to Bob Johnson and test scores to 60, 65, 70, 75, 80.\n";
	student1.setStudentName("Bob Johnson");
	student1[0] = 60.0;
	student1[1] = 65.0;
	student1[2] = 70.0;
	student1[3] = 75.0;
	student1[4] = 80.0;
	cout << "student1 final state:\n";
	displayStudent(student1);
	cout << endl;
	cout << "student2 final state:\n";
	displayStudent(student2);
	cout << endl;
	cout << "student3 final state:\n";
	displayStudent(student3);
	cout << endl;

	return 0;
}

// displayStudent function
void displayStudent(StudentTestScores& s)
{
    cout << "Name: " << s.getStudentName() << endl;
    cout << "Test Scores: ";
    for (int i = 0; i < s.getNumTestScores(); i++)
        cout << s[i] << " ";
    cout << endl;
}