#include "Student.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;


Student CreateStudent(vector<Student>& students) {
    Student student = {};
    int studyField = 0;
    int studyYear = 0;
    
    
    //Sets Student name
    cout << "Enter student first name: ";
    cin.getline(student.name, MAX_STUDENT_LETTERS);

    //Sets Student middle name
    cout << "Enter student middle name: ";
    cin.getline(student.middleName, MAX_STUDENT_LETTERS);

    //Sets Student surname
    cout << "Enter student surname: ";
    cin.getline(student.surname, MAX_STUDENT_LETTERS);

    //Sets student address
    cout << "\nEnter student address\n";
    cout << "----------------------\n";
    cout << "Enter city: ";
    cin.getline(student.address.city, MAX_CITY_LENGTH);
    cout << "Enter city postcode: ";
    cin >> student.address.postcode;
    cin.ignore();
    cout << "Enter street name: ";
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


    //Sets student StudyField
    cout << "Choose student Study Field: \n";
    cout << "1. Informatics\n";
    cout << "2. Computer Science\n";
    cout << "3. Math\n";
    cout << "4. Engineering\n";

    while (true) {
        cin >> studyField;
        if (studyField >= 1 && studyField <= 4) {
            break;
        }
        cout << "Invalid Option! Try again: ";
    }

    if (studyField == 1) {
        student.studyField = StudyField::Informatics;
    }
    else if (studyField == 2) {
        student.studyField = StudyField::ComputerScience;
    }
    else if (studyField == 3) {
        student.studyField = StudyField::Math;
    }
    else {
        student.studyField = StudyField::Engineering;
    }

    //Sets Student faculty number
    cin.ignore();
    cout << "Enter Student Facutly Number: ";
    cin.getline(student.facultyNum, FACULTY_NUMBER_SYMBOLS);

    //Sets Student Email
    cout << "Enter Student Email: ";
    cin.getline(student.email, MAX_STUDENT_LETTERS);

    //Sets Student Study Year
    cout << "Choose Student Year of study\n";
    cout << "1. First year\n";
    cout << "2. Second year\n";
    cout << "3. Third year\n";
    cout << "4. Fourth year\n";

    while (true) {
        cin >> studyYear;
        if (studyYear >= 1 && studyYear <= 4) {
            break;
        }
        cout << "Invalid Option! Try again: ";
    }
    if (studyYear == 1) {
        student.year == StudyYear::First;
    }
    else if(studyYear == 2) {
        student.year == StudyYear::Second;
    }
    else if (studyYear == 3) {
        student.year == StudyYear::Third;
    }
    else {
        student.year == StudyYear::Fourth;
    }


    

    students.push_back(student);

    return student;
}