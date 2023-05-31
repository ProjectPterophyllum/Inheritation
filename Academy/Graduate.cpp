#include "Graduate.h"

const std::string& Graduate::get_subject()const
{
	return subject;
}
void Graduate::set_subject(const std::string& subject)
{
	this->subject = subject;
}
Graduate::Graduate(HUMAN_PARAMETERS_TAKE, STUDENT_PARAMETERS_TAKE, const std::string& subject) :Student(HUMAN_PARAMETERS_GIVE, STUDENT_PARAMETERS_GIVE)
{
	this->subject = subject;
#ifdef GDEBUG
	cout << "GraduateCtr:\t" << this << endl;
#endif // GDEBUG

}
Graduate::~Graduate()
{
#ifdef GDEBUG
	cout << "GraduateDstr:\t" << this << endl;
#endif // GDEBUG

}
void Graduate::print()const
{
	Student::print();
	cout << subject << endl;
}