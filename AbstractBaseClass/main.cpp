#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Vehicle
{
	int speed;
	const int MAX_SPEED;
public:
	Vehicle(int speed = 0, int max_speed = 250) :speed(speed), MAX_SPEED(max_speed){}
	virtual void move() = 0; //Pure virtual func;
};
class GroundVehicle : public Vehicle{};
class Car :public GroundVehicle
{
public:
	void move()
	{
		cout << "Машина ездит на колесах:" << endl;
	}
};
class Buldozer : public GroundVehicle
{
public:
	void move()
	{
		cout << "Бульдозер ездит на гусеницах:" << endl;
	}
};
void main()
{
	setlocale(LC_ALL, "");
	//Vehicle A; //Cannot instantiate Abstract Class;
	Car A;
	A.move();
	Buldozer amd;
	amd.move();
}