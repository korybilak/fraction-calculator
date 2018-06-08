/*
* Created by Kory Bilak
* Started on 11/05/2015 finished on 11/12/2015
* update 6/8/2018 fixed negative addition and subtraction
*/
#include <iostream>
#include "fraction.h"
#include <string>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <cstdlib>
using namespace std;


int main(int argc, char *argv[])
{
	int userchoice = 0;
	string temporary = " ";
	Fraction f1, f2, f3;
   cout << "Mixed Number calculator!\n";
   cout << "Type in 1 to put in your first number, 2 to put in your second number, 3 to add, 4 to subtract, 5 to multiply, 6 to divide, 7 to do relational operators,\n and 8 to quit.\n";
   
   do
   {
    cout << "What do you want to do next :";
    cin.sync();
    getline(cin, temporary);
	if(temporary.find_first_not_of("1234567890") != -1 || temporary.size() == 0) // checks if user types in spaces (an entire line), and sets it to the default case if they do
	{
     userchoice = 9;
    }
    else
    {
    userchoice = atoi(temporary.c_str());
    }
	cin.sync();
	switch(userchoice)
   {
   	case 1: //allows the user to type in their second fraction
   		cout << "You can type in a whole number, a mixed number, or a fraction, with or without negatives.\n";
   		cout << "Type in your first number:";
   		reset(f1); //resets the value before they type something in, originally only for f3, but necessary if user wants to make multiple inputs.
   		cin >> f1;
   		break;
   	case 2: // allows the user to type in their second fraction
        cout << "You can type in a whole number, a mixed number, or a fraction, with or without negatives.\n";
   		cout <<"Type in your second number:";
   		reset(f2);
   		cin >> f2;
   		userchoice = 0;
   		break;
   	case 3: // converts, adds, and reduces the fractions
   		convert(f1); 
   		convert(f2);
   		reset(f3);
   		f3 = f1+f2;
   		reduce(f3);
   		reduce(f1);
   		reduce(f2);
		cout << f3;
		cout << "\n";
   		userchoice = 0;
   		break;
   	case 4: //converts, subtracts, and reduces the fractions
   		convert(f1);
   		convert(f2);
   		reset(f3);
   		f3 = f1-f2;
   		reduce(f3);
   		reduce(f1);
   		reduce(f2);
   		cout << f3;
   	    cout << "\n";
   		userchoice = 0;
   		break;
   	case 5: // converts, multiplies, and reduces the fractions
   		convert(f1);
   		convert(f2);
   		reset(f3);
   		f3 = f1*f2;
   		reduce(f1);
   		reduce(f2);
   		reduce(f3);
   		cout << f3;
   		cout << "\n";
   		userchoice = 0;
   		break;
   	case 6: // converts, divides, and reduces the fractions
   		convert(f1);
   		convert(f2);
   		reset(f3);
   		f3 = f1/f2;
   		reduce(f3);
   		reduce(f2);
   		reduce(f1);
   		cout << f3;
   		cout << "\n";
   		userchoice = 0;
	 	break;
   	case 7: //converts reduces and then performs the relational comparisons.
        reduce(f1);
        cout << f1;
        cout << " is "; 
   		convert(f1);
   		convert(f2);
   		if (f1>f2)
   		{
   		reduce(f1);
   		reduce(f2);
   		cout << " > ";
		}
		convert(f1);
		convert(f2);
		if (f1<f2)
   		{
   		reduce(f1);
   		reduce(f2);
   		cout << " < ";
		}
		convert(f1);
		convert(f2);
		if (f1>=f2)
   		{
   		reduce(f1);
   		reduce(f2);
   		cout << " >= ";
		}
		convert(f1);
		convert(f2);
		if (f1<=f2)
   		{
   		reduce(f1);
   		reduce(f2);
   		cout << " <= ";
		}
		convert(f1);
		convert(f2);
		if (f1==f2)
   		{
   		reduce(f1);
   		reduce(f2);
   		cout << " == ";
		}
		convert(f1);
		convert(f2);
		if (f1!=f2)
   		{
   		reduce(f1);
   		reduce(f2);
   		cout << " != ";
		}
		cout << " to ";
		reduce(f2);
		cout << f2;
		cout << "\n";
		userchoice = 0;
	 break;
	case 8: //quits the program
	break;
	default: // checks for invalid choice.
	cout << "Invalid choice try again \n";
	cout << "Type in 1 to put in your first number, 2 to put in your second number, 3 to add, 4 to subtract, 5 to multiply, 6 to divide, 7 to do relational operators,\n and 8 to quit.\n";
	userchoice = 0;
	break;
}
} while (userchoice != 8);
  //exits the program
    system("PAUSE");
    return EXIT_SUCCESS;
}

    
