#include "Student.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int arraySize = 10;


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
    do {
        cin >> student.address.postcode;
        if (student.address.postcode < 1000 || student.address.postcode > 9999) {
            cout << "Invalid value! Postcode must be between 1000 and 9999! Try again: ";
        }

    } while (student.address.postcode < 1000 || student.address.postcode > 9999);
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
    do {
        cin >> student.group;
        if(student.group <= 0 || student.group > 50)
        cout << "Group should be a positive value! Try again: ";
    } while (student.group <= 0 || student.group > 50);
    
    //Sets Student number of passed exams
    cout << "Enter Student number of passed exams: ";
    do {
        cin >> student.passedExams;
        if(student.passedExams <= 0 || student.passedExams > 10)
            cout << "Value must be between 1 and 10! Try again: ";
    } while (student.passedExams <= 0 || student.passedExams > 10);

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
    cout << "\nStudent Info\n";
    cout << "---------------\n";
    cout << "Name: " << student.name << "\n";
    cout << "Middle name: " << student.middleName << "\n";
    cout << "Surname: " << student.surname << "\n";
    cout << "Address: " << student.address.city << ", " << student.address.postcode << ", '" << student.address.street << "' " <<
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

Student RandomStudent() {
    Student student;

    //Sets up a random name for the student
    string randomNames[arraySize] = { "Ivelin", "Martin", "Todor", "Ivan", "Petyr", "Georgi", "Dimityr", "Boqn", "Simeon", "Panayot" };
    int randomNameIndex = rand() % 10;
    strcpy_s(student.name, randomNames[randomNameIndex].c_str());

    //Sets up a random middle name for the student
    string randomMiddleNames[arraySize] = { "Ivelinov", "Martinov", "Todorov", "Ivanov", "Petrov", "Georgiev", "Dimitrov", "Boqnov", "Simeonov", "Panayotov" };
    int randomMiddleNameIndex = rand() % 10;
    strcpy_s(student.middleName, randomMiddleNames[randomMiddleNameIndex].c_str());

    //Sets up a random surname for the student
    string randomSurnames[arraySize] = { "Ivelinov", "Martinov", "Todorov", "Ivanov", "Petrov", "Georgiev", "Dimitrov", "Boqnov", "Simeonov", "Panayotov" };
    int randomSurnameIndex = rand() % 10;
    strcpy_s(student.surname, randomSurnames[randomSurnameIndex].c_str());

    //Sets up a random city
    string randomCities[arraySize] = { "Sofia", "Varna", "Ruse", "Burgas", "Plovdiv", "Dobrich", "Targovishte", "Stara Zagora", "Blagoevgrad", "Montana" };
    int randomCityIndex = rand() % 10;
    strcpy_s(student.address.city, randomCities[randomCityIndex].c_str());

    //Sets a random postcode
    student.address.postcode = 1000 + (rand() % 9000);

    //Sets a random street
    string randomStreets[arraySize] = { "Hristo Botev", "Vasil Levski", "Ivan Vazov", "Stefan Stambolov", "Georgi Rakovski", "Shipka", "Opalchenska", "Tsar Osvoboditel",
        "Tsar Boris", "Tsar Simeon" };
    int randomStreetIndex = rand() % 10;
    strcpy_s(student.address.street, randomStreets[randomStreetIndex].c_str());

    //Sets a random street number
    student.address.numStreet = (rand() % 300) + 1;
    
    //Sets a random street letter
    student.address.streetLetter = 'A' + rand() % 26;

    //Sets a random entrance
    student.address.entrance = (rand() % 5) + 1;

    //Sets a random floor
    student.address.floor = (rand() % 14) + 1;

    //Sets a random appartment number
    student.address.numApp = (rand() % 70) + 1;

    //Sets a random faculty number
    for (int i = 0; i < FACULTY_NUMBER_SYMBOLS; ++i) {
        student.facultyNum[i] = (rand() % 10) + '0';
    }
    student.facultyNum[FACULTY_NUMBER_SYMBOLS] = '\0';


    //Sets a random email
    string randomEmails[arraySize] = { "myemail@abv.bg", "myemail@gmail.com", "student@outlook.com", "warrior1@gmail.com", "uni@mail.bg", "school@FMI.bg", "myStudies@SU.com",
    "lectures@FMI.bg", "important@abv.bg", "general@mail.bg" };
    int randomEmailIndex = rand() % 10;
    strcpy_s(student.email, randomEmails[randomEmailIndex].c_str());

    //Sets random Field of Study
    int setFieldOfStudy = (rand() % 4) + 1;
    if (setFieldOfStudy == 1)
        student.studyField = StudyField::Informatics;
    else if (setFieldOfStudy == 2)
        student.studyField = StudyField::ComputerScience;
    else if (setFieldOfStudy == 3)
        student.studyField = StudyField::Math;
    else
        student.studyField = StudyField::Engineering;

    //Sets random Major
    int setMajor = (rand() % 4) + 1;
    if (setMajor == 1)
        student.major = Major::Cybersecurity;
    else if (setMajor == 2)
        student.major = Major::SoftwareDevelopment;
    else if (setMajor == 3)
        student.major = Major::ArtificialIntelligence;
    else
        student.major = Major::DataScience;

    //Sets random Study Year
    int setYearOfStudy = (rand() % 4) + 1;
    if (setYearOfStudy == 1)
        student.year = StudyYear::First;
    else if (setYearOfStudy == 2)
        student.year = StudyYear::Second;
    else if (setYearOfStudy == 3)
        student.year = StudyYear::Third;
    else
        student.year = StudyYear::Fourth;
  
    //Sets random Group
    student.group = (rand() % 50) + 1;

    //Sets random passed exams
    student.passedExams = (rand() % 10) + 1;

    //Sets random grades
    student.grades = new float[student.passedExams];

    for (int i = 0; i < student.passedExams; ++i) {
        student.grades[i] = 1.0f + static_cast<float>(rand()) / (RAND_MAX / 3.0f);
    }

    return student;
}

//Calculates student average score
float CalculateAverageGrade(const Student& student) {
    float totalScore = 0.0;

    for (int i = 0; i < student.passedExams; ++i) {
        totalScore += student.grades[i];
    }

    return totalScore / student.passedExams;
}

//Shows the students with a grade above a certain threshold
vector<Student> TopStudents(const vector<Student>& students, float threshold) {
    vector<Student> tîpStudents;
    float averageGrade = 0.0;
    int number = 1;

    cout << "\nTop students\n";
    cout << "----------------\n";
    for (const Student& student : students) {
       averageGrade = CalculateAverageGrade(student);
       if (averageGrade >= threshold) {
           tîpStudents.push_back(student);
        }
    }

    return tîpStudents;
}

