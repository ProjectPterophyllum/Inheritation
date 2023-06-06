#pragma once
Human* HumanFactory(const std::string& type);
void save(Human** group, const int n, const char* filename);
Human** read(const std::string& filename, int n);