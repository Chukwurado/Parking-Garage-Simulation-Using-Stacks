#pragma once

#include <string>

using namespace std;
class Car {
public:
	Car();
	void setPlate(string lsc);
	void incMove();
	int getMoves();
	string getPlate();
	bool operator==(Car car);
private:
	string plate;
	int moves;
};

Car::Car() {
	moves = 0;
}
void Car::setPlate(string lsc) {
	plate = lsc;
}
void Car::incMove() {
	moves++;
}

bool Car::operator==(Car car) {
	if (plate == car.plate) {
		return true;
	}
	return false;
}

int Car::getMoves() {
	return moves;
}

string Car::getPlate() {
	return plate;
}
//add operator overload function