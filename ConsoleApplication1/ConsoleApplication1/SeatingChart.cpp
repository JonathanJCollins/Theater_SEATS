#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void printSeats(char seats[15][30]){
	cout << "\t123456789012345678901234567890" << endl;
	cout << endl;
	for (int i = 0; i < 15; ++i){
		cout << "Row " << i+1 << "\t";
		for (int j = 0; j < 30; ++j){
			cout << seats[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int main(){
	char seats[15][30];
	for (int i = 0; i < 15; ++i){
		for (int j = 0; j < 30; ++j){
			seats[i][j] = '#';
		}
	}
	int yesNo = 0;
	cout << "Would you like to import seat prices? 1 for yes, anything else for no.";
	cin >> yesNo;

	if (yesNo == 1) {
		// IMPORT FUNCTION HERE!
	}
	else {
		// MANUAL SET PRICE FUNCTION
	}

	int selection = 0;
	while (selection != -1){
		cout << "What would you like to do?" << endl 
			<< "1 : List Seating Chart" << endl 
			<< "2 : Show sales info" << endl 
			<< "3 : Purchase Seats" << endl 
			<< "4 : Save Current Seat Prices to File" << endl 
			<< "-1: QUIT" << endl;

		cin >> selection;
		
		if (selection == 1) {
			cout << "Current Available Seats: " << endl << endl;
			printSeats(seats);
		}
		else if (selection == 2) {
			// STATISTICS CHART
		}
		else if (selection == 3) {
			// SEAT SELLING 
		}
		else if (selection == 4){
			// SAVE PRICES TO TEXT FILE
		}
		else {
			cout << "INVALID SELECTION" << endl << endl;
		}
	}

	printSeats(seats);

	//PRINT STATISTICS DOWN HERE AS WELL.
	return 0;
}