#include "Student.h"
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;


string StudyFieldToString(const StudyField& study) {
    switch (study) {
    case StudyField::Informatics: return "Informatics";
    case StudyField::ComputerScience: return "Computer Science";
    case StudyField::Math: return "Math";
    case StudyField::Engineering: return "Engineering";
    default: return "Unknown";
    }
}

string MajorToString(const Major& major) {
    switch (major) {
    case Major::Cybersecurity: return "Cyber Security";
    case Major::SoftwareDevelopment: return "Software Development";
    case Major::ArtificialIntelligence: return "Artificial Intelligence";
    case Major::DataScience: return "Data Science";
    default: return "Unknown";
    }
}


string StudyYearToString(const StudyYear& year) {
    switch (year) {
    case StudyYear::First: return "First Year";
    case StudyYear::Second: return "Second Year";
    case StudyYear::Third: return "Third Year";
    case StudyYear::Fourth: return "Fourth Year";
    default: return "Unknown";
    }
}


Student CreateStudent(vector<Student>& students) {
    Student student = {};
    int studyField = 0;
    int studyYear = 0;
    int major = 0;
    
    
    //Sets Student name
    cout << "Enter student First name: ";
    cin.getline(student.name, MAX_STUDENT_LETTERS);

    //Sets Student middle name
    cout << "Enter student Middle name: ";
    cin.getline(student.middleName, MAX_STUDENT_LETTERS);

    //Sets Student surname
    cout << "Enter student Surname: ";
    cin.getline(student.surname, MAX_STUDENT_LETTERS);

    //Sets student address
    cout << "\nEnter student address\n";
    cout << "----------------------\n";
    cout << "Enter City: ";
    cin.getline(student.address.city, MAX_CITY_LENGTH);
    cout << "Enter City Postcode: ";
    cin >> student.address.postcode;
    cin.ignore();
    cout << "Enter Street Name: ";
    cin.getline(student.address.street, MAX_STREET_LENGTH);
    cout << "Enter Street Number: ";
    cin >> student.address.numStreet;
    cout << "Enter Street Letter: ";
    cin >> student.address.streetLetter;
    cout << "Enter Entrance Number: ";
    cin >> student.address.entrance;
    cout << "Enter Floor Number: ";
    cin >> student.address.floor;
    cout << "Enter Appartment Number: ";
    cin >> student.address.numApp;

    //Sets Student faculty number
    cin.ignore();
    cout << "Enter Student Facutly Number: ";
    cin.getline(student.facultyNum, FACULTY_NUMBER_SYMBOLS);

    //Sets Student Email
    cout << "Enter Student Email: ";
    cin.getline(student.email, MAX_STUDENT_LETTERS);


    //Sets student StudyField
    cout << "\nChoose student Study Field: \n";
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

    //Sets Student Major
    cout << "\nChoose Student Major\n";
    cout << "1. Cyber Security\n";
    cout << "2. Software Development\n";
    cout << "3. Artificial Intelligence\n";
    cout << "4. Data Science\n";
    while (true) {

        cin >> major;
        if (major >= 1 && major <= 4) {
            break;
        }
        cout << "Invalid Option! Try again: ";
    }
    if (major == 1) {
        student.major = Major::Cybersecurity;
    }
    else if (studyYear == 2) {
        student.major = Major::SoftwareDevelopment;
    }
    else if (studyYear == 3) {
        student.major = Major::ArtificialIntelligence;
    }
    else {
        student.major = Major::DataScience;
    }

    //Sets Student Study Year
    cout << "\nChoose Student Year of study\n";
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
        student.year = StudyYear::First;
    }
    else if(studyYear == 2) {
        student.year = StudyYear::Second;
    }
    else if (studyYear == 3) {
        student.year = StudyYear::Third;
    }
    else {
        student.year = StudyYear::Fourth;
    }


    //Set Student Group
    cout << "Enter Student Group: ";
    while (true) {
        cin >> student.group;
        if (student.group > 0) {
            break;
        }
        cout << "Group should be a positive value! Try again: ";
    }
    
    //Sets Student number of passed exams
    cout << "Enter Student number of passed exams: ";
    cin >> student.passedExams;

    //Sets Student grades
    student.grades = new float[student.passedExams];

    cout << "\nEnter Student grades for passed exams\n";
    for (size_t i = 0; i < student.passedExams; ++i) {
        cout << "Enter grade for Exam " << i + 1 << ": ";
        cin >> student.grades[i];
    }

    students.push_back(student);

    return student;
}

void PrintStudent(const Student& student) {
    cout << "Student Info\n";
    cout << "---------------\n";
    cout << "Name: " << student.name << "\n";
    cout << "Middle name: " << student.middleName << "\n";
    cout << "Surname: " << student.surname << "\n";
    cout << "Address: '" << student.address.city << "', " << student.address.postcode << ", '" << student.address.street << "', " <<
        student.address.numStreet << student.address.streetLetter << ", en. " << student.address.entrance << ", fl. " << student.address.floor << ", ap." << student.address.numApp << ". \n";
    cout << "Faculty Number: " << student.facultyNum << "\n";
    cout << "Email: " << student.email << "\n";
    cout << "Study Field: " << StudyFieldToString(student.studyField) << "\n";
    cout << "Major: " << MajorToString(student.major) << "\n";
    cout << "Year of study: " << StudyYearToString(student.year) << "\n";
    cout << "Group: " << student.group << "\n";
    cout << "Passed Exams: " << student.passedExams << "\n";
    cout << "\nGrades: \n";
    cout << "------------\n";
    cout << fixed << setprecision(2);
    for (size_t i = 0; i < student.passedExams; ++i) {
        cout << "Grade number " << i + 1 << ": " << student.grades[i] << "\n";
    }

}

