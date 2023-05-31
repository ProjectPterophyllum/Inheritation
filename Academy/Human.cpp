#include "Human.h"

//Get-Set:
const std::string& Human::get_last_name() const
{
	return last_name;
}
const std::string& Human::get_first_name() const
{
	return first_name;
}
int Human::get_age() const
{
	return age;
}
void Human::set_last_name(const std::string& last_name)
{
	this->last_name = last_name;
}
void Human::set_first_name(const std::string& first_name)
{
	this->first_name = first_name;
}
void Human::set_age(int age)
{
	this->age = age;
}
//Constructors:
Human::Human(HUMAN_PARAMETERS_TAKE)
{
	set_last_name(last_name);
	set_first_name(first_name);
	set_age(age);
#ifdef HDEBUG
	cout << "HumanCtr:\t" << this << endl;
#endif // HDEBUG
}
Human::~Human()
{
#ifdef HDEBUG
	cout << "HumanDctr:\t" << this << endl;
#endif // HDEBUG
}
void Human::print() const
{
	std::string S_ages(" Лет ");
	if (age == 1 || age > 20 && age % 10 == 1) S_ages = " Год ";
	else if (age == 2 && age <= 4 || age > 20 && (age % 10 == 2 && age % 10 <= 4)) S_ages = " Года ";
	cout << last_name << " " << first_name << " " << age << S_ages << endl;
}