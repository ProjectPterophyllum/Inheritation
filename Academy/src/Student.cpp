#include "stdafx.h"

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
	cout << speciality << " " << group << " " << rating << " " << attendance << endl;
}
std::ostream& Student::print(std::ostream& out) const
{
	return Human::print(out) << speciality << " " << group << " " << rating << " " << attendance;
}
std::ofstream& Student::print(std::ofstream& out) const
{
	Human::print(out);
	out.width(SPECIALITY_WIDTH);
	out << speciality;
	out.width(GROUP_WIDTH);
	out << group;
	out.width(RATING_WIDTH);
	out << rating;
	out.width(ATTENDANCE_WIDTH);
	out << attendance;
	return out;
}
std::ifstream& Student::scan(std::ifstream& in)
{
	Human::scan(in);
	char* spec = new char[SPECIALITY_WIDTH + 1] {};
	in.read(spec, SPECIALITY_WIDTH);
	for (int i = strlen(spec) - 1; spec[i] == ' '; i--)	spec[i] = 0;
	while (spec[0] == ' ')for (int i = 0; spec[i]; i++)	spec[i] = spec[i + 1];
	speciality = spec;
	delete[] spec;
	char* grp = new char[GROUP_WIDTH + 1] {};
	in.read(grp, GROUP_WIDTH);
	for (int i = strlen(grp) - 1; grp[i] == ' '; i--)grp[i] = 0;
	while (grp[0] == ' ')for (int i = 0; grp[i]; i++)grp[i] = grp[i + 1];
	group = grp;
	delete[] grp;
	in >> rating >> attendance;
	return in;
}