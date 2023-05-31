#include "Teacher.h"

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