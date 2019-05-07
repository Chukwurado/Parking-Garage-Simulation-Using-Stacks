//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include <iostream>
#include <string>
#include "ArrayStack.h"
#include "Garage.h"
#include <fstream>

using namespace std;



int main()
{
	Garage garage;
	char mode;
	string plate;
	ifstream inFile;
	inFile.open("cars.txt");
	inFile >> mode >> plate;
	
	
	
	while (inFile) {
		if (mode == 'A') {
			garage.arrive(plate);
		}
		else if (mode == 'D') {
			garage.depart(plate);
		}
		inFile >> mode >> plate;
	}
	cout << endl << endl;
	

	cout << "\n\nEnd of the Array-Based Stack:" << endl;

	system("pause");
   return 0;
}  // end main

