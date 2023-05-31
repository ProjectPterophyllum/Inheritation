#pragma once
#include "stdafx.h"
#include "Human.h"

#define TEACHER_PARAMETERS_TAKE	const std::string& speciality, int experience
#define TEACHER_PARAMETERS_GIVE	speciality, experience

class Teacher :public Human
{
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
};