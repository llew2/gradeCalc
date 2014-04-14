/*
  Lawrence Lew
  pp6.cpp

  Function Homework
  Calculates current grade in class, % of coursework completed,
  * % coursework remaining, and % needed in remaining coursework to
  * obtain an A, B, C, or D, letter grade.
  CS 110A Practice Problem 6
  4/9/2014
*/

#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

// To do:
// Each function should have a comment next to its prototype and body,
// explaining what it does

// This function introduces the user to what the program does.
// It also gives an example scenario on how the program works.
void intro() {
  cout << "Hello! This is a grade calculator based on your coursework "
       << "thus far! \n";
  cout << "First I will ask how your grade is distributed based on "
       << "homework, tests, participation, and extra credit. \n\n";
  cout << "I will then ask you how many homeworks or tests or "
       << "participation and extra credit you have. \n\n";

  cout << "Example Scenario: \n";
  cout << "  Example with 15% of final grade, 6 homeworks, 4 submitted, \n"
       << "  95 points for hw #1, 100 possible points for hw #1, \n"
       << "  35 points for hw #2, 50 possible points for hw #2, ... etc \n\n";

  cout << "Shortcut: %weight, #hwtotal, #submit \n\n";
  cout << "  Points obtained for #1, Points possible for #1, \n";

  cout << "\'Weight Totalhws Submitted\':  '15 6 4'" << endl; 
  cout << "\'Pts1 Hw1 Pts2 Hw2\': '95 100 35 50' ... <pts> <possible> ... \n\n";
}

// This function obtains the student's current grades on homework,
// tests, participation, and any extra credit.
// Postcondition: Returns weighed average in decimal value. 
//                If 50% of coursework is finished at 100%,
//                    it would return (0.50)
double obtainGrades(double &gradeRemain,double &gradeFinished) {
  char confirm;
  double avg;

// Homework Variables
  double hwTot, hwCompl;
  double hwWeight, hwSingle, hwSinglePoss, hwSum = 0, hwPoss = 0;
// Test Variables
  double testTot, testCompl;
  double testWeight, testSingle, testSinglePoss, testSum = 0, testPoss = 0;
// Participation Variables
  double partTot, partCompl;
  double partWeight, partSingle, partSinglePoss, partSum = 0, partPoss = 0;
// Extra Credit
  char additionalEC = 'y';
  double extraCred = 0, addEC = 0;

// Queries user for information about homework grades
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
// Queries user for information about test grades
  cout << "How much percentage of your total grade is test?: ";
  cin >> testWeight;

  cout << "How many test do you have?: ";
  cin >> testTot;
  cout << "How many have submitted so far?: ";
  cin >> testCompl;
  
  for (int i = 1; i <= testCompl; i++)
  {
    cout << "What is your grade for test #" << i << ": ";
    cin >> testSingle;
    cout << "What is the total points for test #" << i << ": ";
    cin >> testSinglePoss;
    cout << "\nFor test #" << i << " : You entered " << testSingle
         << " out of " << testSinglePoss << " points.\n" << endl;
    testSum = testSum + testSingle;
    testPoss = testPoss + testSinglePoss;
  }

  cout << "Your total test score is " << testSum << " out of a possible "
       << testPoss << " with a weight of " << testWeight << "% of your final grade. \n";
// Queries user for information about participation grades
  cout << "How much percentage of your total grade is participation?: ";
  cin >> partWeight;

  cout << "How many participation do you have?: ";
  cin >> partTot;
  cout << "How many have submitted so far?: ";
  cin >> partCompl;
  
  for (int i = 1; i <= partCompl; i++)
  {
    cout << "What is your grade for participation #" << i << ": ";
    cin >> partSingle;
    cout << "What is the total points for participation #" << i << ": ";
    cin >> partSinglePoss;
    cout << "\nFor participation #" << i << " : You entered " << partSingle
         << " out of " << partSinglePoss << " points.\n" << endl;
    partSum = partSum + partSingle;
    partPoss = partPoss + partSinglePoss;
  }

  cout << "Your total participation score is " << partSum << " out of a possible "
       << partPoss << " with a weight of " << partWeight << "% of your final grade. \n";

  cout << "Do you have any extra credit to add? (y/n) :";
  cin >> additionalEC;

  while (additionalEC == 'y')
  {
	  cout << "How much extra credit do you want to add? :";
      cin >> extraCred;
	  cout << "Do you have any other extra to add? :";
	  cin >> additionalEC;
  }
  cout << "You have a total of " << extraCred 
       << " extra credit to add to your final score. \n";

// Computes how much of the total homework assignments have been finished.
// Also computes the current grade on homeworks.
  double hwRatio = (double) hwCompl/hwTot;
// Current grade on tests
  double testRatio = (double) testCompl/testTot;
// Current grade on tests
  double partRatio = (double) partCompl/partTot;

// Subtracts homeworks from remaining final grade to be achieved.
  gradeRemain = gradeRemain - hwWeight * hwRatio;
// Subtracts tests from remaining final grade to be achieved.
  gradeRemain = gradeRemain - testWeight * testRatio;
// Subtracts participation from remaining final grade to be achieved.
  gradeRemain = gradeRemain - partWeight * partRatio;

// gradeFinished indicates how much of final grade has been attempted.
  gradeFinished = 100 - gradeRemain;

  double homeworkPart = hwWeight * (hwCompl/hwTot) * (hwSum/hwPoss);
  double testPart = testWeight * (testCompl/testTot) * (testSum/testPoss);
  double partPart = partWeight * (partCompl/partTot) * (partSum/partPoss);
  
// The average grade is returned below
  return homeworkPart + testPart + partPart + extraCred;
}
/* 
 * Homeworks
25
5
3
12
15
80
100
90
85
* 
* Tests
50
4
2
120
150
105
150
Participation
25
10
6
5
10
8
10
9
10
8
10
7
10
9
10
* */

void dispResult(double avg, double gradeRemain, double gradeFinished) {
  cout << "*******************************************\n";
  cout << "You have completed " << gradeFinished << "% of your coursework. YAY!\n";
  cout << "\nYour current grade is " << avg/gradeFinished * 100 << "."  << endl;
  cout << "Based on that, your uncurved grade is ";
  if (avg/gradeFinished * 100 >= 90) { cout << "an A!" << endl; }
  else if (avg/gradeFinished * 100 >= 80) { cout << "a B!" << endl; }
  else if (avg/gradeFinished * 100 >= 70) { cout << "a C." << endl; }
  else if (avg/gradeFinished * 100 >= 60) { cout << "a D." << endl; }
  else { cout << "an F." << endl; }

  cout << "\nYou still have " << gradeRemain << "% of your final grade left to go!"
       << "\n\nYou'll need: \n";

  cout << 90 - avg << "% for an A or an average of "
       << (90 - avg)/gradeRemain * 100
       << "% in the remainder of your coursework.\n";    
  cout << 80 - avg << "% for a B or an average of "
       << (80 - avg)/gradeRemain * 100
       << "% in the remainder of your coursework.\n";    
  cout << 70 - avg << "% for a C or an average of "
       << (70 - avg)/gradeRemain * 100
       << "% in the remainder of your coursework.\n";          
  cout << 60 - avg << "% for a D or an average of "
       << (60 - avg)/gradeRemain * 100
       << "% in the remainder of your coursework.\n";           
}

int main () {
  double gradeRemain = 100;
  double gradeFinished = 0;
  intro();
  double average = obtainGrades(gradeRemain,gradeFinished);
  dispResult(average,gradeRemain,gradeFinished);
}
