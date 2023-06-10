#pragma once
void printGroup(Human** group, const int n);
Human* HumanFactory(const std::string& type);
void save(Human** group, const int n, const char* filename);
Human** read(const std::string& filename, int& count);