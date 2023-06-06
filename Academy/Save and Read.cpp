#include "stdafx.h"

void printGroup(Human** group, const int n)
{
	delimiter;
	for (int i = 0; i < n; i++)
		cout << *group[i] << endl << endl;
	delimiter;
}

Human* HumanFactory(const std::string& type)
{
	if (type.find("Student") != std::string::npos) return new Student("", "", 0, "", "", 0, 0);
	if (type.find("Graduate") != std::string::npos)return new Graduate("", "", 0, "", "", 0, 0, "");
	if (type.find("Teacher") != std::string::npos) return new Teacher("", "", 0, "", 0);
}

void save(Human** group, const int n, const char* filename)
{
	std::ofstream fout(filename);
	for (int i = 0; i < n; i++)
	{
		fout << typeid(*group[i]).name() << ":\t";
		fout << *group[i] << endl;
	}
	fout.close();
	char cmmd[FILENAME_MAX] = "start notepad ";
	strcat_s(cmmd, filename);
	system(cmmd);
}
Human** read(const std::string& filename, int& count)
{
	std::ifstream fin(filename);
	if (fin.is_open())
	{
		//Calculating members of group
		std::string tmp;
		for (count = 0; !fin.eof(); count++)
		{
			std::getline(fin, tmp);
			if (tmp.empty()) count--;
		}
		//Memory allocation
		Human** group = new Human * [count] {};
		//Return to begin of file
		fin.clear();
		fin.seekg(0);
		//Add the group members to allocated memory
		for (int i = 0; i < count; i++)
		{
			std::getline(fin, tmp, ':');
			group[i] = HumanFactory(tmp);
			fin.ignore();
			fin >> *group[i];
		}
		fin.close();
		return group;
	}
	else
	{
		cout << "Error: file not found" << endl;
		return nullptr;
	}
}