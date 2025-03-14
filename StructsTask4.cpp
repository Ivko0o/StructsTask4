/*
������ 4.
�� �� ��������� ���������, ����� ��������� �����. ��� �� ������ �� ���� (�������� ��� � �� ������ �� 32 �������); �������� ��� (���� ����� ��� ����); ����� (�������� ��� � �� ������ �� 64 �������);
����� (���� ����� ��� ����); ���� ����� (��� ������); ����, ����, ���������� (����� ���� ����� ��� ����). �������� ����� �� ���: "�����", 1234, "��. ��� ������", 10 �, ��. 2, ��. 7, ��. 30.
�� �� ������� ������, ����������� ��������� � ��������� �� ����� �� ����������� ���� / �����.

�� �� ��������� ���������, ����� ������������ �������. ��� �� ������ ��:
���, �������, ������� - ����� �� ��� �������� ��� � �� ������ �� 32 �������; ����� - �� ������ ���; ����������� - ���� �� ������������� �������� ����� (������� ���); 
���������� ����� - �������� ��� � 10 �������; e-mail - �������� ��� � �� ��-���� �� 32 �������;
����, �����, �����, ���� ������� �������� ������, ������ �� ���� ������ - �� ��� ��������� ��������� ������.

�� ���������� ������������ ��������������� ��:
- ��������� �� ����� �� ������� �� ����������� ����
- ��������� �� ����� �� ������� �� ����������� ����
- ���������� �� ��������, �� ������� ����� �� �������
- ���������� �� ������� ����� �� ���������� ������
�������� �������, �������� � ����� �� ������ �� ��������, �����:
- ������ � ����� ���� �������� ������ ��������, ����� ���� ����� ��-����� �� ����� ���� (�������� ���������).
- ������ ��������� ���� �������� �� ������ ����������� � ���������� �����, ����� ���� ���� ����� ���� ������� �������� �����.
- ������� ���������� �� ����������, �������� ���� ������ �� ���� ��� ������� �� ��������: ���, �������, �������, ���������� �����.
��������� ���������� �� �������� �� ���� ���� ����� �� ������ � ��������� ����� ���������, ���������� ����� ������ ����� �� ����� ���������� ��� ���������.

*/

/*
Task 4.
Implement a structure that represents an address. It consists of a city (a string of no more than 32 characters); a postal code (an unsigned integer); a street (a string of no more than 64 characters);
a number (an unsigned integer); a letter (appended to the number); an entrance, a floor, an apartment (unsigned small integers). An example address would be. 10 a, entrance 2, floor. 7, app. 30.
Write methods to allow input and output of address from standard input/output.

To implement a structure that represents a student. It consists of:
First name, last name, last name - each of them a string of no more than 32 characters; Address - of the above type; Major - one of the predefined options (enumerated type);
Faculty number - a string of 10 characters; E-mail - a string of no more than 32 characters;
Course, stream, group, number of successful exams, grades from these exams - for them select appropriate types.

For students, implement functionalities for:
- reading student data from the standard input
- display student data on the standard input
- generate random but valid student data
- calculation of the average grade in the exams taken
Write functions working with an array of student records that:
- finds and returns as a result all students who have a grade greater than a given threshold (e.g., high achievers).
- finds a given number of students for a given major with a maximum grade who have at least a given number of passes.
- Outputs information about the students found among all by one or more of the fields: first name, last name, last name, faculty number. Allow the criterion submission to be as an array of strings and appropriate other parameters specifying exactly what fields will be used in the search.

*/


#include <iostream>
#include <string>
#include <vector>


#define MAX_STREET_LENGTH 64
#define MAX_CITY_LENGTH 32
#define MAX_STUDENT_LETTERS 32
#define FACULTY_NUMBER_SYMBOLS 10

using namespace std;



enum studyField {
    Informatics,
    ComputerScience,
    Math,
    Engineering
};

enum studyYear
{
    First = 1,
    Second,
    Third,
    Fourth,
};

enum studyStream
{
    Cybersecurity,
    SoftwareDevelopment,
    ArtificialIntelligence,
    DataScience,
};

enum Group
{
    One = 1,
    Two,
    Three,
    Four,
    Five
};

struct Address
{
    char street[MAX_STREET_LENGTH];
    char city[MAX_CITY_LENGTH];
    int postcode;
    int numStreet;
    short entrance;
    short floor;
    short numApp;
    char streetLetter;
};

struct Student
{
    char name[MAX_STUDENT_LETTERS];
    char middleName[MAX_STUDENT_LETTERS];
    char surname[MAX_STUDENT_LETTERS];
    Address address;
    studyField major;
    char facultyNum[FACULTY_NUMBER_SYMBOLS];
    char email[MAX_STUDENT_LETTERS];
    studyYear year;
    studyStream stream;
    Group group;
    int passedExams;
    float* grades;
   
};

Student CreateStudent();

int main()
{
 

}

Student CreateStudent() {
    Student student;
    cout << "Enter student name: ";
    cin.getline(student.name, MAX_STUDENT_LETTERS);
    cout << "Enter student middle name: ";
    cin.getline(student.middleName, MAX_STUDENT_LETTERS);
    cout << "Enter student surname: ";
    cin.getline(student.surname, MAX_STUDENT_LETTERS);
    cout << "Enter student address\n";
    cout << "Enter city: ";
    cin.getline(student.address.city, MAX_CITY_LENGTH);
    cout << "Enter postcode: ";
    cin >> student.address.postcode;
    cout << "Enter street: ";
    cin.getline(student.address.street, MAX_STREET_LENGTH);
    cout << "Enter street number: ";
    cin >> student.address.numStreet;
    cout << "Enter street letter: ";
    cin >> student.address.streetLetter;
    cout << "Enter entrance: ";
    cin >> student.address.entrance;
    cout << "Enter floor: ";
    cin >> student.address.floor;
    cout << "Enter appartment: ";
    cin >> student.address.numApp;


    return student;
}

