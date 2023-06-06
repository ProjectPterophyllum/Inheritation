#pragma once
#include "stdafx.h"
#define STUDENT_PARAMETERS_TAKE const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_PARAMETERS_GIVE speciality, group, rating, attendance

class Student : public Human
{
	//static constant members:
	static const int SPECIALITY_WIDTH = 26;
	static const int GROUP_WIDTH = 18;
	static const int RATING_WIDTH = 8;
	static const int ATTENDANCE_WIDTH = 8;
	//class members:
	std::string speciality;
	std::string group;
	double rating;
	double attendance;
public:
	//Get-Set:
	const std::string& get_speciality()const;
	const std::string& get_group()const;
	double get_rating()const;
	double get_attendance()const;
	void set_speciality(const std::string& speciality);
	void set_group(const std::string& group);
	void set_rating(double rating);
	void set_attendance(double attendance);
	//Constructors:
	Student(HUMAN_PARAMETERS_TAKE, STUDENT_PARAMETERS_TAKE);
	~Student();
	void print()const;
	std::ostream& print(std::ostream& out) const;
	std::ofstream& print(std::ofstream& out) const;
	std::ifstream& scan(std::ifstream& in);
};