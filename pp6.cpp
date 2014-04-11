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
  cout << "Hello! This is a grade calculator based on your coursework\n"
       << "    thus far! \n";
  cout << "First I will ask how your grade is distributed based on\n" 
       << "    homework, tests, participation, and extra credit. \n";
  cout << "I will then ask you how many homeworks or tests or\n"
       << "    participation and extra credit you have. \n";
}

double obtainGrades() {
  char confirm;
  double avg;

  int hwTot, hwCompl;
  double hwWeight, hwSingle, hwSinglePoss, hwSum = 0, hwPoss = 0;
/*
  double testSum;

  double partSum;
*/
  cout << "Shortcut: #hwtotal, #submit, %weight " << endl;
  cout << "Points obtained for #1, Points possible for #1" << endl;
  cout << "Example with 6 homeworks, 4 submitted, 15% of final grade, \n"
       << "    95 points for hw #1, 100 possible points for hw #1, \n "
       << "    35 points for hw #2, 50 possible points for hw #2, ... etc \n";
  cout << "6, 4, 15, 95, 100, y, 35, 50, y, ... pts, possible, y ... " << endl;

  cout << "How many homeworks do you have?: ";
  cin >> hwTot;
  cout << "How many have submitted so far?: ";
  cin >> hwCompl;
  
  cout << "How much percentage of your total grade is homework?: ";
  cin >> hwWeight;

  for (int i = 1; i <= hwCompl; i++)
  {
    cout << "What is your grade for homework #" << i << ": ";
    cin >> hwSingle;
    cout << "What is the total points for homework #" << i << ": ";
    cin >> hwSinglePoss;
    cout << "For homework #" << i << " : You entered " << hwSingle << endl
         << "                out of " << hwSinglePoss << " points." << endl
         << "Is this correct? (y/n): ";
    cin >> confirm;
    if (confirm == 'y') {
      hwSum = hwSum + hwSingle;
      hwPoss = hwPoss + hwSinglePoss;
    }
    else
      i--;
  }
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
  
  return hwWeight * (hwSum/hwPoss);

}

void dispResult(double avg)
{
  cout << "Your current grade is " << avg << endl;
}

int main () {
  
  intro();
  double average = obtainGrades();
  dispResult(average);
}




