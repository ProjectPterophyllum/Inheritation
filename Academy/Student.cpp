#include "Student.h"

//Get-Set
const std::string& Student::get_speciality()const
{
	return speciality;
}
const std::string& Student::get_group()const
{
	return group;
}
double Student::get_rating()const
{
	return rating;
}
double Student::get_attendance()const
{
	return attendance;
}
void Student::set_speciality(const std::string& speciality)
{
	this->speciality = speciality;
}
void Student::set_group(const std::string& group)
{
	this->group = group;
}
void Student::set_rating(double rating)
{
	this->rating = rating;
}
void Student::set_attendance(double attendance)
{
	this->attendance = attendance;
}
//Constructors:
Student::Student(HUMAN_PARAMETERS_TAKE, STUDENT_PARAMETERS_TAKE) :Human(HUMAN_PARAMETERS_GIVE)
{
	set_speciality(speciality);
	set_group(group);
	set_rating(rating);
	set_attendance(attendance);
#ifdef SDEBUG
	cout << "StudentCtr:\t" << this << endl;
#endif // SDEBUG

}
Student::~Student()
{
#ifdef SDEBUG
	cout << "StudentDstr:\t" << this << endl;
#endif // SDEBUG

}

void Student::print()const
{
	Human::print();
	cout << speciality << ", " << group << " " << rating << " " << attendance << endl;
}