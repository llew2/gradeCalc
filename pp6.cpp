/*
  Lawrence Lew
  pp6.cpp

  Function Homework
  Calculates Current Grade in Class
  CS 110A Practice Problem 6
  4/9/2014
*/

#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

// I want to...
// Intro use, req current grades and %tage, display results

void intro() {
  cout << "Hello! This is a grade calculator based on your coursework "
       << "thus far! \n";
  cout << "First I will ask how your grade is distributed based on "
       << "homework, tests, participation, and extra credit. \n\n";
  cout << "I will then ask you how many homeworks or tests or "
       << "participation and extra credit you have. \n\n";
}

double obtainGrades(double &gradeRemain) {
  char confirm;
  double avg;

  int hwTot, hwCompl;
  double hwWeight, hwSingle, hwSinglePoss, hwSum = 0, hwPoss = 0;
/*
  double testSum;
  double partSum;
*/
  cout << "Example Scenario: \n";
  cout << "  Example with 15% of final grade, 6 homeworks, 4 submitted, \n"
       << "  95 points for hw #1, 100 possible points for hw #1, \n"
       << "  35 points for hw #2, 50 possible points for hw #2, ... etc \n\n";

  cout << "Shortcut: %weight, #hwtotal, #submit \n\n";
  cout << "  Points obtained for #1, Points possible for #1, \n";

  cout << "\'Weight Totalhws Submitted\':  '15 6 4'" << endl; 
  cout << "\'Pts1 Hw1 Pts2 Hw2\': '95 100 35 50' ... <pts> <possible> ... \n\n";

// cout << "15 5 3"
// cout << "12 15 80 100 90 85"

  cout << "How much percentage of your total grade is homework?: ";
  cin >> hwWeight;

  cout << "How many homeworks do you have?: ";
  cin >> hwTot;
  cout << "How many have submitted so far?: ";
  cin >> hwCompl;
  
  for (int i = 1; i <= hwCompl; i++)
  {
    cout << "What is your grade for homework #" << i << ": ";
    cin >> hwSingle;
    cout << "What is the total points for homework #" << i << ": ";
    cin >> hwSinglePoss;
    cout << "\nFor homework #" << i << " : You entered " << hwSingle
         << " out of " << hwSinglePoss << " points.\n" << endl;
    hwSum = hwSum + hwSingle;
    hwPoss = hwPoss + hwSinglePoss;
  }

  cout << "Your total hw score is " << hwSum << " out of a possible "
       << hwPoss << " with a weight of " << hwWeight << "% of your final grade. \n";

/*
  cout << "How many tests do you have? \n";
  cin >> testTot;
  cout << "How many have you taken so far? \n";
  cin >> testCompl;

  for (int i = 0; i < testCompl; i++)
  {
    cout << "What is your grade for test #" << i << endl;
    cin >> testSingle;
    testSum = testSum + testSingle;
  }

  cout << "How much participation do you have? \n";
  cin >> partTot;
  cout << "How many were given so far? \n";
  cin >> partCompl;

  for (int i = 0; i < partCompl; i++)
  {
    cout << "What is your grade for part #" << i << endl;
    cin >> partSingle;
    partSum = partSum + partSingle;
  }
*/
  double hwRatio = (double) hwCompl/hwTot;
  cout << "\n\n hwratio: " << hwRatio * hwWeight << endl << endl;
  cout << "Grade remain: " << gradeRemain << endl << endl;

  gradeRemain = gradeRemain - hwWeight * hwRatio;


  return hwWeight * (hwSum/hwPoss);
}

void dispResult(double avg, double gradeRemain) {
  cout << "*******************************************\n";
  cout << "You have completed " << 100 - gradeRemain << "% of your coursework. YAY!\n";
  cout << "\nYour current grade is " << avg << "."  << endl;
  cout << "Based on that, your uncurved grade is ";
  if (avg >= 90) { cout << "an A!" << endl; }
  else if (avg >= 80) { cout << "a B!" << endl; }
  else if (avg >= 70) { cout << "a C." << endl; }
  else if (avg >= 60) { cout << "a D." << endl; }
  else { cout << "an F." << endl; }

  cout << "\nYou still have " << gradeRemain << "% of your final grade left to go!"
       << "\n\nYou'll need: \n";

  cout << 90 - (1-gradeRemain)*avg << "% for an A or an average of "
       << (double) (90 - (1-gradeRemain)*avg)/gradeRemain 
       << "% in the remainder of your coursework.\n";

  cout << 80 - (1-gradeRemain)*avg << "% for a B or an average of "
       << (double) (80 - (1-gradeRemain)*avg)/gradeRemain 
       << "% in the remainder of your coursework.\n";

}

int main () {
  double gradeRemain = 100;
  intro();
  double average = obtainGrades(gradeRemain);
  dispResult(average,gradeRemain);
}




