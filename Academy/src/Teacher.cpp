#include "stdafx.h"

//Get-Set
const std::string& Teacher::get_speciality()const
{
	return speciality;
}
int Teacher::get_experience()const
{
	return experience;
}
void Teacher::set_speciality(const std::string& speciality)
{
	this->speciality = speciality;
}
void Teacher::set_experience(int experience)
{
	this->experience = experience;
}
//Constructor:
Teacher::Teacher(HUMAN_PARAMETERS_TAKE, TEACHER_PARAMETERS_TAKE) :Human(HUMAN_PARAMETERS_GIVE)
{
	set_speciality(speciality);
	set_experience(experience);
#ifdef TDEBUG
	cout << "TeacherCtr:\t" << this << endl;
#endif // TDEBUG

}
Teacher::~Teacher()
{
#ifdef TDEBUG
	cout << "TDestructor:\t" << this << endl;
#endif // TDEBUG

}
void Teacher::print()const
{
	Human::print();
	cout << speciality << " " << experience << endl;
}
std::ostream& Teacher::print(std::ostream& out) const
{
	return Human::print(out) << " " << speciality << " " << experience;
}
std::ofstream& Teacher::print(std::ofstream& out) const
{
	Human::print(out);
	out.width(SPECIALITY_WIDTH);
	out << speciality;
	out.width(EXPERIENCE_WIDTH);
	out << experience;
	return out;
}
std::ifstream& Teacher::scan(std::ifstream& in)
{
	Human::scan(in);
	char buffer[SPECIALITY_WIDTH + 1] = {};
	in.read(buffer, SPECIALITY_WIDTH);
	speciality = buffer;
	in >> experience;
	return in;
}