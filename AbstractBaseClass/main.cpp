#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Vehicle
{
	int speed;
	const int MAX_SPEED;
public:
	virtual void move() = 0; //Pure virtual func;
};
class GroundVehicle : public Vehicle{};
void main()
{
	setlocale(LC_ALL, "");
	//Vehicle A; //Cannot instantiate Abstract Class;
	GroundVehicle gv;
}