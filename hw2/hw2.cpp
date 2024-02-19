/**
 * @author Zhou Liu
 * hw2.cpp
 * Purpose: This is program converts a number from Decimal to Binary.
 * My assumption is that there are two ways that I have learned from our class.
 * First method is to compare the number with 1, 2，4, 8, 16, etc. Then sub the number with the sequence.
 * Second method is to divide the number by 2. The binary number will be 1 when it has remainder.
 * The binary number will be 0 when it doesn't have a remainder.
 * I am using the second method for this program.
 * @version 1.0
 * 1/27/23
 */
#include <iostream>
using namespace std;
/**
 * this method prints out a welcome message.
 */
void printWelcomeMessage();

/**
 * This method prints out a message to prompt the user to enter a decimal number.
 */
void printGetNumMessage();

/**
 * This method converts a decimal number to a binary number.
 * The method prints out the result of binary number.
 */
void decToBinary(int);

/**
 * This method converts number to single binary digit.
 * @param int decimal digit.
 * @return  int binary digit.
 */
int getBinary(int);

/**
 * This method prints out a goodbye message.
 */
void printGoodbyeMessage();

int main() {
  string input, blank;//To hold input value from the user.
  char repeat;//To store a char for repeating the program.
  int number;//To hold the number that the user entered.
  printWelcomeMessage();//Call a method to print out a welcome message.
  do {
      printGetNumMessage();//Call a function to ask the user to enter decimal.
      cin >> number;//Store the number.
      getline(cin, blank);//Get the blank space.
      decToBinary(number);//Call a method to convert decimal to binary.
      cout << "\nWould you like to try another number? (y/n) ";//Ask the user if they want to repeat.
      getline(cin, input);//Get the answer.
      repeat = input[0];//Store the answer to a variable.
  }while (tolower(repeat) == 'y');//Repeat the program when the user enter 'y'.
  printGoodbyeMessage();//Prints out a goodbye message.
}

void printWelcomeMessage() {
    cout << "****************************************************************************" <<endl;
    cout << "Welcome to the Decimal to Binary converter!" << endl;
    cout << "This program can convert a decimal number that you enter to a binary number." << endl;

}
void printGetNumMessage() {
    cout << "****************************************************************************" << endl;
    cout << "Enter decimal number: ";
}

void decToBinary(int number)
{
    unsigned int temp;//To hold the positive number.
    int curr;//To hold either positive or negative number.
    int binaryNum[4];//Create an integer array to hold the binary number by using 64 bits.
    int twosBinary[4];//Create an array for binary number in two's complement.
    int i = 0;//Set the length of binary number.
    /**
     * For converting the negative number to binary number.
     * I chose to use two's complement method.
     * Gets the binary number of the positive number, then flip the binary number
     * Then binary number  + 1.
     */
    if (number > 0)  //To store the number if it is positive.
        temp = number;
    else
    {
        curr = number; //To store a negative number.
        temp = curr * -1;//To inverse the negative number.
    }
    while(temp > 0)//To get the binary number until the number becomes zero.
    {
        binaryNum[i] = getBinary(temp);//Get the binary number.

        temp = temp / 2;//Divide the number by 2.

        i++;//Increment the length of binary number.
    }
    /**
     * Using two's complement to convert a negative number to a binary number.
     */
    if (number < 0) { //Using twos complement if number is negative.
        for (int n = 0; n < i; n++) { //Flip the binary number. 0 is negative, 1 is positive.
            if (binaryNum[n] == 1)
                binaryNum[n] = 0;
            else {
               binaryNum[n] = 1;
            }
        }
        //Using a for loop to initialize the array of binary number.
        for (int n = i - 1; n >= 0; n--) {
          twosBinary[n] = binaryNum[n];
        }
        /**
         * Add 1 to the binary number.
         */
        for (int n = 0; n < i; n++) {//Traverse from the least significant bit.
            if (binaryNum[n] == 1)//Set binary to 0 if it is 1.
                twosBinary[n] = 0;
            else {
                twosBinary[n] = 1;
                break; //Stop the loop when it finds a 0.
            }
        }
        cout << "Binary number: ";
        //Prints out the binary number by using a for loop.
        for (int j = i - 1; j >= 0; j--) {
            cout << twosBinary[j];
        }
    }
    else {
        cout << "Binary number: ";
        //Prints out the binary number by using a for loop.
        for (int j = i - 1; j >= 0; j--) {
            cout << binaryNum[j];
        }
    }
}

int getBinary(int n) {
    if (n % 2 == 0) {//Check if the number is dividable by 2.
        return 0;//Return 0 if the number is dividable by 2.
    }
    else
        return 1;//Return 1 if the number is not dividable by 2.
}
void printGoodbyeMessage() {
    cout << "****************************************************************************";
    cout << "\nThanks for using this program!" << endl;
}
