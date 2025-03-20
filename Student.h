#pragma once
#include <string>
#include <vector>

#define MAX_STREET_LENGTH 64
#define MAX_CITY_LENGTH 32
#define MAX_STUDENT_LETTERS 32
#define FACULTY_NUMBER_SYMBOLS 10


enum StudyField {
    Informatics = 1,
    ComputerScience,
    Math,
    Engineering
};

enum StudyYear
{
    First = 1,
    Second,
    Third,
    Fourth,
};

enum Major
{
    Cybersecurity = 1,
    SoftwareDevelopment,
    ArtificialIntelligence,
    DataScience,
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
    StudyField studyField;
    char facultyNum[FACULTY_NUMBER_SYMBOLS+1];
    char email[MAX_STUDENT_LETTERS];
    StudyYear year;
    Major major;
    int group;
    int passedExams;
    float* grades;

};

Student CreateStudent(std::vector<Student>& students);
void PrintStudent(const Student& student);
std::string StudyFieldToString(const StudyField& study);
std::string MajorToString(const Major& major);
std::string StudyYearToString(const StudyYear& year);
Student RandomStudent();
float CalculateAverageGrade(const Student& student);
std::vector <Student> TopStudents(const std::vector<Student>& students, float threshold);
