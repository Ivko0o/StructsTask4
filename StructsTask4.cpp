/*
Задача 4.
Да се реализира структура, която представя адрес. Той се състои от град (символен низ с не повече от 32 символа); пощенски код (цяло число без знак); улица (символен низ с не повече от 64 символа);
номер (цяло число без знак); една буква (към номера); вход, етаж, апартамент (малки цели числа без знак). Примерен адрес би бил: "София", 1234, "ул. Цар Симеон", 10 а, вх. 2, ет. 7, ап. 30.
Да се напишат методи, позволяващи въвеждане и извеждане на адрес от стандартния вход / изход.

Да се реализира структура, която представлява студент. Той се състои от:
Име, презиме, фамилия - всеки от тях символен низ с не повече от 32 символа; Адрес - от горния тип; Специалност - едно от предварително зададени опции (изброен тип); 
Факултетен номер - символен низ с 10 символа; e-mail - символен низ с не по-вече от 32 символа;
курс, поток, група, брой успешно положени изпити, оценки от тези изпити - за тях подберете подходящи типове.

За студентите реализирайте функционалности за:
- прочитане на данни за студент то стандартния вход
- извеждане на данни за студент на стандартния вход
- генериране на случайни, но валидни данни за студент
- пресмятане на средния успех от положените изпити
Напишете функции, работещи с масив от записи за студенти, които:
- намира и връща като резултат всички студенти, които имат успех по-голям от даден праг (например отличници).
- намира определен брой студенти за дадена специалност с максимален успех, които имат поне даден брой успешно положени изпит.
- Извежда информация за студентите, намерени сред всички по едно или няколко от полетата: име, презиме, фамилия, факултетен номер.
Позволете подаването на критерия да бъде като масив от низове и подходящи други параметри, определящи какви полета точно ще бъдат използвани при търсенето.

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
#include "Student.h"

using namespace std;

int main()
{
	srand(time(0));
	vector<Student> students;
	float threshold = 2.0;

	//Creates 10 random students
	for (int i = 0; i < 10; ++i) {
		Student student;
		student = RandomStudent();
		students.push_back(student);
	}

	//Shows the top achievers
	vector<Student> topStudents = TopStudents(students, threshold);
	for (const Student& topStudent : topStudents) {
		PrintStudent(topStudent);
		cout << "\nAverage Score: " << CalculateAverageGrade(topStudent) << "\n";
	}


	//Releases the memory used for the grades
	for (const Student& student : students) {
		delete[] student.grades;
	}

	return 0;

}


