#pragma once
#include "stdafx.h"

#define HUMAN_PARAMETERS_TAKE const std::string& last_name, const std::string& first_name, int age
#define HUMAN_PARAMETERS_GIVE last_name, first_name, age

class Human
{
	//class members:
	std::string last_name;
	std::string first_name;
	int age;
public:
	//Get-Set:
	const std::string& get_last_name() const;
	const std::string& get_first_name() const;
	int get_age() const;
	void set_last_name(const std::string& last_name);
	void set_first_name(const std::string& first_name);
	void set_age(int age);
	//Constructor:
	Human(HUMAN_PARAMETERS_TAKE);
	//Desctructor:
	virtual ~Human();
	virtual void print()const;
};