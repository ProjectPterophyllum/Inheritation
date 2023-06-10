#pragma once
#include "stdafx.h"

#define TEACHER_PARAMETERS_TAKE	const std::string& speciality, int experience
#define TEACHER_PARAMETERS_GIVE	speciality, experience

class Teacher :public Human
{
	//static const class members
	static const int SPECIALITY_WIDTH = 24;
	static const int EXPERIENCE_WIDTH = 3;
	//class members:
	std::string speciality;
	int experience;
public:
	//Get-Set
	const std::string& get_speciality()const;
	int get_experience()const;
	void set_speciality(const std::string& speciality);
	void set_experience(int experience);
	Teacher(HUMAN_PARAMETERS_TAKE, TEACHER_PARAMETERS_TAKE);
	~Teacher();
	void print()const;
	std::ostream& print(std::ostream& out) const;
	std::ofstream& print(std::ofstream& out) const;
	std::ifstream& scan(std::ifstream& in);
};