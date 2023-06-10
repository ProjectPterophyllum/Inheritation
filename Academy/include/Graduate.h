#pragma once
#include "stdafx.h"

class Graduate :public Student
{
	std::string subject;
public:
	const std::string& get_subject()const;
	void set_subject(const std::string& subject);
	Graduate(HUMAN_PARAMETERS_TAKE, STUDENT_PARAMETERS_TAKE, const std::string& subject);
	~Graduate();
	void print()const;
	std::ostream& print(std::ostream& out)const;
	std::ofstream& print(std::ofstream& out)const;
	std::ifstream& scan(std::ifstream& in);
};