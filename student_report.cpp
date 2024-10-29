/**
 * @file student_report.cpp
 * @brief This program manages student reports by capturing and displaying student details and their marks.
 *
 * The program defines three classes: `student`, `test`, and `result`.
 * - The `student` class captures and displays the student's name and roll number.
 * - The `test` class, derived from `student`, captures and displays marks for three subjects.
 * - The `result` class, derived from `test`, calculates the total marks and displays the complete student report.
 *
 * The `main` function demonstrates the usage of these classes by creating an instance of `result`,
 * capturing student details and marks, and displaying the final report.
 *
 * @author Krishna Chauhan
 * @date 2024-10-29
 */

#include <bits/stdc++.h>
using namespace std;

class student
{
protected:
    string name;
    int rolno;

public:
    void getstud()
    {
        cout << "Enter the roll number of the student: ";
        cin >> rolno;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear any leftover newline in the input buffer

        cout << "Enter the name of the student: ";
        getline(cin, name);
    }

    void putstud() const
    {
        cout << "Student name: " << name << endl;
        cout << "Roll number: " << rolno << endl;
    }
};

class test : public student
{
protected:
    float sub1, sub2, sub3;

public:
    void readmark()
    {
        cout << "Enter the marks for subject 1: ";
        cin >> sub1;
        cout << "Enter the marks for subject 2: ";
        cin >> sub2;
        cout << "Enter the marks for subject 3: ";
        cin >> sub3;
    }

    void putmark() const
    {
        cout << "Subject 1: " << sub1 << endl;
        cout << "Subject 2: " << sub2 << endl;
        cout << "Subject 3: " << sub3 << endl;
    }
};

class result : public test
{
    float total;

public:
    void display()
    {
        cout << "******* STUDENT REPORT ********" << endl;
        total = sub1 + sub2 + sub3;
        putstud();
        putmark();
        cout << "Total marks: " << total << endl;
    }
};

int main()
{
    result r;
    r.getstud();
    r.readmark();
    r.display();
    return 0;
}
