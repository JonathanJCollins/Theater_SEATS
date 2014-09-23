#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void printSeats(char seats[15][30]){
	
	for (int i = 0; i < 15; ++i){
		cout << "Row " << i+1 << "\t";
		for (int j = 0; j < 30; ++j){
			cout << seats[i][j];
		}
		cout << endl;
	}
}

int main(){
	char seats[15][30];
	for (int i = 0; i < 15; ++i){
		for (int j = 0; j < 30; ++j){
			seats[i][j] = '#';
		}
	}
	printSeats(seats);
	return 0;
}