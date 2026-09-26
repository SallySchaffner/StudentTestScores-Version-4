#ifndef STUDENTTESTSCORES_H
#define STUDENTTESTSCORES_H
#include <string>
using namespace std;

const double DEFAULT_SCORE = 0.0;
const int MAX_TEST_SCORES = 10;

class StudentTestScores
{
private:
    string studentName;  // The student's name
    double* testScores;  // Points to array of test scores
    int numTestScores;   // Number of test scores

    // Private member function to create an
    // array of test scores.
    void createTestScoresArray(int size)
    {
        numTestScores = size;
        testScores = new double[size];
        for (int i = 0; i < size; i++)
            testScores[i] = DEFAULT_SCORE;
    }

public:
    // Constructor
    StudentTestScores(string name = "", int numScores = MAX_TEST_SCORES)
    {
        studentName = name;
        createTestScoresArray(numScores);
    }

    // Copy constructor
    StudentTestScores(const StudentTestScores& obj)
    {
        studentName = obj.studentName;
        numTestScores = obj.numTestScores;
        testScores = new double[numTestScores];
        for (int i = 0; i < numTestScores; i++)
            testScores[i] = obj.testScores[i];
    }

    // Destructor
    ~StudentTestScores()
    {
		cout << "Destructor called for " << studentName << endl;
        delete[] testScores;
    }

    // Set the student's name.
    void setStudentName(string name)
    {
        studentName = name;
    }

    // Get the student's name.
    string getStudentName() const
    {
        return studentName;
    }

    // Get the number of test scores.
    int getNumTestScores()
    {
        return numTestScores;
    }

	// Get a specific test score.
    double& operator[](int index)
    {
        if (index < 0 || index >= numTestScores)
            throw out_of_range("Invalid test score index");

        return testScores[index];
    }

	// Get a specific test score (const version).
    const double& operator[](int index) const
    {
        if (index < 0 || index >= numTestScores)
            throw out_of_range("Invalid test score index");

        return testScores[index];
    }

    // Overloaded = operator
    const StudentTestScores operator=(const StudentTestScores& right)
    {
        delete[] testScores;
        studentName = right.studentName;
        numTestScores = right.numTestScores;
        testScores = new double[numTestScores];
        for (int i = 0; i < numTestScores; i++)
            testScores[i] = right.testScores[i];
        return *this;
    }

};
#endif