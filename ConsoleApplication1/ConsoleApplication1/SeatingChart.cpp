#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void sellTickets(double prices[15], char seats[15][30]);
void singleTicket(double prices[15], char seats[15][30]);
void multiTicket(double prices[15], char seats[15][30]);
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

void savePriceofSeats(double price[15]){
	ofstream saveFile;
	string fileName;
	cout << "What would you like to name the save file?" << endl << "Please do not include a '.txt'" << endl;
	cin >> fileName;
	fileName.append(".txt");
	saveFile.open(fileName);
	for (int i = 0; i < 15; i++){
		saveFile << price[i] << endl;
	}
	saveFile.close();
	cout << "The file was saved as " << fileName << endl << endl;
}

int main(){
	char seats[15][30];
	double prices[15];

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
		
		//**********TEST FOR SELL FUCTION< PLEASE UPDATE
		for (int i = 0; i < 15; i++){
			prices[i] = 15 - i;
		}
		//********TEST FOR SELL FUCTION< PLEASE UPDATE


	}

	int selection = 0;
	while (selection != -1){
		cout << "-Main Menu-" << endl
			<< "What would you like to do?" << endl 
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
			sellTickets(prices, seats);
		}
		else if (selection == 4){
			savePriceofSeats(prices);
		}
		else {
			cout << "INVALID SELECTION" << endl << endl;
		}
	}

	printSeats(seats);

	//PRINT STATISTICS DOWN HERE AS WELL.
	return 0;
}

void sellTickets(double prices[], char seats[15][30]){
	
	int selection;
	cout << "Would you like to purchase a single, or multiple tickets?" << endl
		<< "1. Single" << endl
		<< "2. Multiple" << endl;
	cin >> selection;
	//User Input of row and seat number
	if (selection == 1){
		singleTicket(prices, seats);
		}

	else if (selection == 2){
		multiTicket(prices, seats);
	}
	else{
		cout << "Incorrect choice, returing to main menu."<<endl;
	}
		
}

void singleTicket(double prices[], char seats[15][30]){
	int x1;
	int y;
	int confirm;
	
	// User input for row and seat
	cout << "please enter a row number(1-15): " << endl;
	cin >> y;
	y = y - 1;
	while (y > 15 || y < 0) {
		cout << "invalid row, please try again with a vailid number (1-15):" << endl;
		cin >> y;
	}
	cout << "Please enter a seat number: " << endl;
	cin >> x1;
	x1 = x1 - 1;
	while (x1 > 30 || x1 < 0 ) {
		cout << "invalid seat, please try again with a vaild number (1-30):" << endl;
		cin >> x1;
	}

	// Confirm and Validate Purchase
	cout << " You have selected row " << (y + 1) << " seat " << (x1 + 1) << "." << endl;

	if (seats[y][x1] == '#')
	{      //checks seat availibility, # indicates an open seat
		cout << "The price for this seat is " << prices[y] << endl << "please enter 1 to confirm purchase";
		cin >> confirm;
		if (confirm == 1)
		{
			seats[y][x1] = '*';
			cout << "Seats have been successfully purchased." << endl;
		}
		else
		{
			cout << "Not Purchasing tickets, returning to Main Menu." << endl;
		}
	}
	else if (seats[y][x1] == '*')
	{
		cout << endl << "This seat is already taken, please refer to seating chart in main menu." << endl << endl;
	}

}

void multiTicket(double prices[], char seats[15][30]){
	int x1;
	int x2;
	int totalSeats;
	int temp;
	int confirm;
	int y;
	bool occupied = false;
	
	// User input for row and seat numbers
	cout << "Please select a row and the first and last seat of the section you wish to purchase."
		 << endl <<endl<< "please enter a row number for your tickets: " << endl;
	cin >> y;
	y = y - 1;
	while (y > 15 || y < 0)
	{
		cout << "invalid row, please try again with a vailid number (1-15):" << endl;
		cin >> y;
	}
	
	cout << "Please enter the first seat number: " << endl;
	cin >> x1;
	x1 = x1 - 1;
	while (x1 > 30 || x1 < 0)
	{
		cout << "invalid seat, please try again with a vaild number (1-30):" << endl;
		cin >> x1;
	}

	cout << "Please enter the last seat number: " << endl;
	cin >> x2;
	x2 = x2 - 1;
	while (x2 > 30 || x2 < 0  || x2 == x1)
	{
		cout << "invalid seat, please try again with a vaild number (1-30):" << endl;
		cin >> x2;
	}
	
	// calculates ticket range
	if (x2 > x1){
		temp = x1;
		x1 = x2; 
		x2 = temp;
	}
	totalSeats = x1 - x2 + 1;

	for (int i = x2; i <= x1; i++)
	{
		if (seats[y][i] == '*') occupied = true;
	}
	if (occupied == true){
		cout << " these seats are already occupied. Returning to Menu"<<endl;
	}
	else {
		cout << "The seats in row " << (y + 1) << " from "
			<< (x2 + 1) << " to " << (x1 + 1) << " are availible at $" << prices[y] << " each." << endl;
		cout << "Your total will be $" << (prices[y] * totalSeats) << '.' << endl << "Enter 1 to confirm purchase." << endl;
		cin >> confirm;
		if (confirm == 1)
		{
			for (int i = x2; i <= x1; i++)
			{
				seats[y][i] = '*';
			}
			cout << "Seats have been successfully purchased." << endl << endl;
		}
		else
		{
			cout << "Returning to Main Menu" << endl << endl;
		}
	}
	return;
}