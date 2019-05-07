//#pragma once

#ifndef GARAGE_
#define GARAGE_

#include <iostream>
#include "ArrayStack.h";
#include "Car.h";
#include <string>

using namespace std;
class Garage {
private:
	ArrayStack<Car> lane1;
	ArrayStack<Car> lane2;
	ArrayStack<Car> street;
	void move(ArrayStack<Car> *from, ArrayStack<Car> *to);

public:
	bool arrive(string plate);
	bool depart(string plate);
};

bool Garage::arrive(string plate) {
	Car car;
	car.setPlate(plate);
	
	if (lane1.isFull()) {
		if (lane2.isFull()) {
			cout << "Car with license plate " <<  plate << " can not be parked. The garage is full" << endl;
			return false;
		}
		else {
			lane2.push(car);
			cout << "Parking car with license plate " << plate << " in lane 2" << endl;
			return true;
		}
	}
	else {
		lane1.push(car); 
		cout << "Parking car with license plate " << plate << " in lane 1" << endl;
		return true;
	}
}

bool Garage::depart(string plate) {
	Car car;
	car.setPlate(plate);
	if (!lane1.search(car)) {
		if (!lane2.search(car)) {
			cout << "Car not found" << endl;
			return false;
		}
		else {
			bool isCar = lane2.peek() == car;
			while (!isCar) {
				if (!lane1.isFull()) {
					move(&lane2, &lane1);
				}
				else {
					move(&lane2, &street);
				}
				isCar = lane2.peek() == car;
			}
			cout << "Removing car with license plate " << lane2.peek().getPlate() << " from lane 2. Car was moved " << lane2.peek().getMoves() << " times(s)." << endl;
			lane2.pop();
			
			if (!street.isEmpty()) {
				while (!street.isEmpty()) {
					move(&street, &lane2);
				}
			}
		}
	}
	else {
		
		bool isCar = lane1.peek() == car;
		while (!isCar) {
			if (!lane2.isFull()) {
				move(&lane1, &lane2);
			}
			else {
				move(&lane1, &street);
			}
			isCar = lane1.peek() == car;
		}
		cout << "Removing car with license plate " << lane1.peek().getPlate() << " from lane 1. Car was moved " << lane1.peek().getMoves() << " times(s)." << endl;
		lane1.pop();
		
		if (!street.isEmpty()) {
			while (!street.isEmpty()) {
				move(&street, &lane1);
			}
		}
	}
	return true;
}

void Garage::move(ArrayStack<Car> *from, ArrayStack<Car> *to) {
	Car car = from->peek();
	from->pop();
	car.incMove();
	to->push(car);
}
#endif