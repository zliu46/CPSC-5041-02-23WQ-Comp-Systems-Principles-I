/**
 * Zhou Liu
 * hw4.cpp
 * This program allows the user to enter name-score pairs, sort the scores in ascending order
 * and calculates the average score.
 * 2/27/23
 * @version 1.0
 */
#include <iostream>
#include<iomanip>
using namespace std;
/**
 * This method will calculate the average score.
 * IN: students' score, the number of students.
 * OUT: average score.
 */
float calculate(const float *, int);
/**
 * This method sorts the scores in ascending order.
 * IN: string array students' name, int array students' scores, number of student.
 */
void sortScore(string*&, float*&, int);
/**
 * This method will print out the result of students' score.
 */
void printStats(string*, float*, int, float);

int main() {
    int size;//To hold the number of students.
    float average;//To hold the average score.
    int n = 0;//To trace the index of array.
    string blank;//To hold the blank spaces.
    string name;//To hold the student's name.
    float number;//To hold the student's score.
    cout << "How many test scores will you enter? ";//Ask user to enter the number of students.
    cin >> size;//Store the number to size.
    getline(cin, blank);//Store the blank spaces.
    float * score = new float[size];//Create an array to hold students' score.
    string * user = new string[size];//Create an array to hold students' name.
    for (int i = 0; i < size; i++) {//Ask the user for each student by using a for loop.
        cout << "Enter student " << i + 1 << "'s last name: ";
        cin >> name;//Store the student's name.
        cout << "Enter that student's test score: ";
        cin >> number;//Store the score.
        //Check if the score is valid.
        try {
            //If score is valid, store information to the array.
            if (number >= 0 && number <= 100) {
                user[n] = name;
                score[n] = number;
                n++;//Index increment.
            }
            else
                throw number;//Throw an exception.
        }
        catch (float num) {
            cout << "invalid number";
            return 0;
        }
    }
    average = calculate(score, n);//Call a method to get the average score.
    sortScore(user, reinterpret_cast<float *&>(score), n);//Call a function to sort the score.
    printStats(user, score, n, average);//Print out the result.
    delete [] user;//Delete the pointer.
    delete [] score;//Delete the pointer.
}
void printStats(string * user, float * score, int n, float average) {
    //Prints out the result of students' name and score.
    cout << "\nThe test scores in ascending order, and their average, are:\n";
    cout << "\nName" << setw(10) << "Score" << endl;
    //Prints out the result by using a for loop.
    for (int i = 0; i < n; i++) {
        cout << setw(10) << left << user[i] << score[i] << endl;
    }
    //Prints out the average score.
    cout << "\nAverage score: " << setprecision(2) << fixed << average << endl;
}

float calculate(const float * score, int n) {
    float total = 0;//Initialize the sum of scores.
    //Create a for loop to calculate the sum.
    for (int i = 0; i < n; i++) {
        total+= score[i];
    }
    //Return the average score.
    return total / n;
}

void sortScore(string *& user, float *& score, int n) {
    float tempScore;//To hold the score.
    string tempName;//To hold the name.
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (score[i] > score[j]) {//Check if the score is larger.
                tempScore = score[i];//Store the value to temp.
                tempName = user[i];//Store the value to temp.
                score[i] = score[j];//Swap the value in the array.
                user[i] = user[j];//Swap the value in the array.
                score[j] = tempScore;//Swap the value in the array.
                user[j] = tempName;//Swap the value in the array.
            }
        }
    }
}