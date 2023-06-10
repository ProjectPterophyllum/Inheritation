#pragma once
#include "stdafx.h"

#define HUMAN_PARAMETERS_TAKE const std::string& last_name, const std::string& first_name, int age
#define HUMAN_PARAMETERS_GIVE last_name, first_name, age
//Класс человек, параметры - Фамилия, Имя, Возраст.
class Human
{
	//static constant members:
	static const int LAST_NAME_WIDTH = 18;
	static const int FIRST_NAME_WIDTH = 15;
	static const int AGE_WIDTH = 4;
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
	virtual std::ostream& print(std::ostream& out) const;
	virtual std::ofstream& print(std::ofstream& out) const;
	virtual std::ifstream& scan(std::ifstream& in);
};

//Operators declaration:
std::ostream& operator <<(std::ostream& out, const Human& name);
std::ofstream& operator <<(std::ofstream& out, const Human& name);
std::ifstream& operator >>(std::ifstream& in, Human& name);
