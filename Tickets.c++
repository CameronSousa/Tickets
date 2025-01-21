#include <iostream>
#include<iomanip>
#include <math.h>
using namespace std;
int main() {
	// user input
	string input;
	//say from input
	string dayIn;
	//seat from input
	string seatIn;
	//space location
	int space = 0;
	//day
	int day = 0;
	//seat
	int seat = 0;
	//seat array
	bool seats[5][68];
	//accepted seats
	int sold = 0;
	//malformed selection
	int malf = 0;
	//rejected seats
	int rjct = 0;
	//temp for sold in day
	int dsold = 0;
	//best day for sales
	int bd = 0;
	//best day sales
	int bds = 0;
	//initialize array values to 0
	for(int i = 0; i < 5; i ++)
	{
		for(int j = 0; j < 68; j++)
		{
			seats[i][j] = 0;
		}
	}
	//for 40 values accept input and check
	while(1){
		
		//input
		cout << "Enter day between 1 and 5 and seat choice between 1 and 68: \n";
		getline(cin,input);
		//check if length is 0
		if(input.length() > 0){
			//find the space
			space = input.find(" ");
			dayIn = input.substr(0,space);
			seatIn = input.substr(space+1, input.length() - dayIn.length() - 1);
			day = stoi(dayIn);
			seat = stoi(seatIn);
			day--;
			seat--;
			//check for bogus
			if(((0<=day)&&(day<=4))&&((0<=seat)&&(seat<=67))){
				//check if seat is avalible
				if(!(seats[day][seat])){
					seats[day][seat] = 1;
					cout << ++day << ++seat << " Confirmed \n" << endl;
					sold++;
				}
				else{
					cout << ++day << ++seat << " Selection Rejected \n" << endl;
					rjct++;
				}
			}
			else{
				cout << ++day << ++seat << " Bogus Input \n" << endl;
				malf++;
			}
		}
		else break;
	}
	//for each day print how many seats were sold and the percentage
	for(int k = 0; k < 5; k++)
	{
		dsold = 0;
		for(int f = 0; f < 68; f++)
		{
			if(seats[k][f] == 1){
				dsold++;
			}
		}
		if(bds < dsold){
			bd = k + 1;
			bds = dsold;
		}
		cout << "Day" << setw(2) << k+1 << setw(4) << dsold << " seats sold" << setw(4) << round(dsold*100/68.0) << "%" << endl;  
	}
	//totals and best day
	cout << "Total seats sold:" << setw(3) << sold << " of possible 340 (" << round(sold*100.0/340.0) << "%)" << endl;
	cout << "Total malformed:" << setw(5) << malf << endl;
	cout << "Total rejects:" << setw(7) << rjct << endl;
	cout << "Best day for sales: " << bd << endl;	
	
	return 0;
}
