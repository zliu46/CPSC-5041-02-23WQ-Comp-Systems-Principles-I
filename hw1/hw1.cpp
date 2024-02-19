//Zhou Liu
//hw1.cpp
//Purpose: This is the program that runs the power function and the myLog function.
//1/16/21
//@version: 1.0

#include <iostream>
using namespace std;

int power(int, int);
//This is the power function compute the base and the exponent. And the function will return the result.
//IN: the value of the base, the value of the exponent.
//OUT: the answer of computation.

int myLog(int, int);
//This is the myLog function that takes a base and a number. Then it will return a result.
//IN: the value of the base, the value of the number.
//OUT: the answer of computation.

int main() {
    //This is the main function that prompt the user for one power call and one myLog call.
    //This method asks the user for the value of number and call the function to compute the numbers.

    int base, num; //Create variables to hold the value of the base and the number.

    cout << "Enter a base: ";//Asks the user for a base.
    cin >> base;//Stores the value of the base to base.
    cout << "Enter an exponent: ";//Asks the user for an exponent.
    cin >> num;//Stores the value of the exponent to num.
    //Prints out the result.
    cout << base << " to the " << num << " is " << power(base, num) << endl;
    cout << endl;

    cout << "Enter a base: ";//Gets the value of base from the user.
    cin >> base;//Stores value to base.
    cout << "Enter a number: ";//Gets the value of number from the user.
    cin >> num;//Stores the value of number to num.
    //Prints out the result.
    cout << "Log of " << num << " in base " << base << " is " << myLog (base,num);
    //Return an integer.
    return 0;
}

int power (int num, int exp) {
    //Create a variable to hold the result of computation.
    //Initialize the value of result.
    int power = 1;

    //Check if the value exponent is negative.
    //Return zero when the exponent is negative.
    if (exp < 0) {
        return 0;
    }
    //Check if exponent is equal to zero.
    //Return the value of power which is one.
    else if (exp == 0) {
        return power;
    }
    else {
        //Using a for loop to compute the value.
        for (int i = 0; i < exp; i++) {
            power = power * num;
        }
        //Return the value of power.
        return power;
    }
}

int myLog (int base, int num) {
    //Check if the number is negative.
    if (num < 0) {
        //Throw an exception if the number is negative.
        throw invalid_argument("the number cannot be negative!");
    }
    else {
        //Create a variable to hold the value of exponent. Initialize the exp to 0.
        int exp = 0;
        //Create a variable to hold the result of computation. Initialize the result to 1.
        int result = 1;

        //Create a loop to compute the result until the result is larger than the input value of number.
        while (result < num) {
            //the increment of exponent.
            exp++;
            //Call the power function to get the result.
            result = power(base, exp);
        }
        //Return the value of exponent.
        return exp - 1;
    }
}