#include <iostream>
using namespace std;

const int MAX_STUDENTS = 100;

struct Student
{
    string name;
    int id;
};

class School
{
private:
    Student students[MAX_STUDENTS];
    int studentCount;

public:
    School() : studentCount(0)
    {
    }

    void addStudent(const Student& newStudent)
    {
        if (studentCount < MAX_STUDENTS)
        {
            students[studentCount++] = newStudent;
        }
        else
        {
            cout << "Limit reached, cannot add more students." << endl;
        }
    }

    void dropStudent(int studentId)
    {
        int foundIndex = -1;

        for (int i = 0; i < studentCount; ++i)
        {
            if (students[i].id == studentId)
            {
                foundIndex = i;
                break;
            }
        }

        if (foundIndex != -1)
        {

            for (int i = foundIndex; i < studentCount - 1; ++i)
            {
                students[i] = students[i + 1];
            }

            --studentCount;
            cout << "Student with ID " << studentId << " dropped successfully." << endl;
        }
        else
        {
            cout << "Student with ID " << studentId << " not found." << endl;
        }
    }

    int getStudentCount() const
    {
        return studentCount;
    }

    const Student& getStudent(int index) const
    {
        return students[index];
    }

    void printStudents() const
    {
        for (int i = 0; i < studentCount; ++i)
        {
            const Student& currentStudent = students[i];
            cout << "ID: " << currentStudent.id << ", Name: " << currentStudent.name << endl;
        }
    }
};

int main()
{
    School mySchool;

    mySchool.addStudent({ "Muazmmil", 1 });
    mySchool.addStudent({ "Bial", 2 });
    mySchool.addStudent({ "Adil", 3 });

    cout << "Students before dropping:" << endl;
    mySchool.printStudents();

    mySchool.dropStudent(3);

    cout << "Students after dropping:" << endl;
    mySchool.printStudents();

    return 0;
}
