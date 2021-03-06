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

// Sample Output is appended at the end of the file

#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

// This function introduces the user to what the program does.
// It also gives an example scenario on how the program works.
void intro();
// This function obtains the student's current grades on homework,
// tests, participation, and any extra credit.
// Pre-condition: Takes in % of coursework remaining and % of coursework
//                  finished.
// Post-condition: Returns weighed average in decimal value. 
//                   If 50% of coursework is finished at 100%,
//                    it would return (0.50)
double obtainGrades(double &gradeRemain,double &gradeFinished);
// This displays the results of analysis from the obtainGrades function.
// Pre-condition: Takes in the weighted average, % of coursework remaining,
//                  and % of coursework finished to calculate grades.
void dispResult(double avg, double gradeRemain, double gradeFinished);

int main () {
  double gradeRemain = 100;
  double gradeFinished = 0;
// Just prints introduction of program to user.
  intro();
// Obtains the weighted average from user input of current grades. 
  double weightedAverage = obtainGrades(gradeRemain,gradeFinished);
// Display the analysis on grades the user inputs.
  dispResult(weightedAverage,gradeRemain,gradeFinished);
}

/* Sample input to copy and paste for each section of the grade.
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
"Push the <enter> key"
* Tests
50
4
2
120
150
105
150
"Push the <enter> key"
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
"Push the <enter> key"
Extra Credit
y
1
n
"Push the <enter> key"

Confirmation:
55% of coursework completed
Grade: 81.6364
Letter Grade: B
Still have 45% of coursework to go.
* */

// This function introduces the user to what the program does.
// It also gives an example scenario on how the program works.
void intro() {
  cout << "Hello! This is a grade calculator based on your coursework "
       << "thus far! \n\n";
  cout << "First I will ask how your grade is distributed based on "
       << "homework, tests, participation, and extra credit. \n\n";
  cout << "I will then ask you how many homeworks or tests or "
       << "participation and extra credit you have. \n\n";

  cout << "Example Scenario: \n";
  cout << "  Example with 25% of final grade, 5 homeworks, 3 submitted, \n"
       << "\t12 points for hw #1, 15 possible points for hw #1, \n"
       << "\t80 points for hw #2, 100 possible points for hw #2, ... etc \n\n";

  cout << "Shortcut: \t%weight, \t#hwtotal, \t#submit \n";
  cout << "\t\tPoints obtained for #1, \tPoints possible for #1, \n\n";

  cout << "Shortcut Example: Weight Total homesworks Submitted\':  '25 5 3'" << endl; 
  cout << "\t\t\'Pts1 \tHw1 \tPts2 \tHw2\': " << endl;
  cout << "\t\t'12 \t15 \t80 \t100' ... <pts> <possible> ... \n\n";
}

// This function obtains the student's current grades on homework,
// tests, participation, and any extra credit.
// Pre-condition: Takes in % of coursework remaining and % of coursework
//                  finished.
// Post-condition: Returns weighed average in decimal value. 
//                   If 50% of coursework is finished at 100%,
//                    it would return (0.50)
double obtainGrades(double &gradeRemain,double &gradeFinished) {
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
  // Queries user about the grade of each homework
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
  // Outputs total homework score and its % of final grade
  cout << "Your total hw score is " << hwSum << " out of a possible "
       << hwPoss << " with a weight of " << hwWeight
       << "% of your final grade. \n\n";

// Queries user for information about test grades
  cout << "How much percentage of your total grade is test?: ";
  cin >> testWeight;

  cout << "How many tests do you have?: ";
  cin >> testTot;
  cout << "How many have you taken so far?: ";
  cin >> testCompl;
  // Queries user about the grade of each test
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
  // Outputs total test score and its % of final grade
  cout << "Your total test score is " << testSum << " out of a possible "
       << testPoss << " with a weight of " << testWeight 
       << "% of your final grade. \n\n";

// Queries user for information about participation grades
  cout << "How much percentage of your total grade is participation?: ";
  cin >> partWeight;

  cout << "How many participations do you have?: ";
  cin >> partTot;
  cout << "How many have been given so far?: ";
  cin >> partCompl;
  // Queries user about the grade of each participation
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
  // Outputs total participation score and its % of final grade
  cout << "Your total participation score is " << partSum 
       << " out of a possible "
       << partPoss << " with a weight of " << partWeight 
       << "% of your final grade. \n\n";

// Extra Credit Portion of the Grade
  cout << "Do you have any extra credit to add? (y/n) : ";
  cin >> additionalEC;
  // Queries user about the grade of each extra credit
  while (additionalEC == 'y')
  {
	  cout << "How much extra credit do you want to add? : ";
      cin >> extraCred;
	  cout << "Do you have any other extra to add? : ";
	  cin >> additionalEC;
  }
  // Outputs total extra credit score and its % of final grade
  cout << "You have a total of " << extraCred 
       << " extra credit to add to your final score. \n\n";

// Computes how much of the total homework assignments have been finished.
// Also computes the current grade on homeworks.
  double hwRatio = (double) hwCompl/hwTot;
// Current grade on tests
  double testRatio = (double) testCompl/testTot;
// Current grade on participation
  double partRatio = (double) partCompl/partTot;

// Subtracts homeworks from remaining final grade to be achieved.
  gradeRemain = gradeRemain - hwWeight * hwRatio;
// Subtracts tests from remaining final grade to be achieved.
  gradeRemain = gradeRemain - testWeight * testRatio;
// Subtracts participation from remaining final grade to be achieved.
  gradeRemain = gradeRemain - partWeight * partRatio;

// gradeFinished indicates how much of final grade has been attempted.
  gradeFinished = 100 - gradeRemain;

// Calculates individual portions of homework, test, and partcipation
//   that it averages to.
  double homeworkPart = hwWeight * (hwCompl/hwTot) * (hwSum/hwPoss);
  double testPart = testWeight * (testCompl/testTot) * (testSum/testPoss);
  double partPart = partWeight * (partCompl/partTot) * (partSum/partPoss);
  
// The average grade is returned using formula below.
  return homeworkPart + testPart + partPart + extraCred;
}

// This displays the results of analysis from the obtainGrades function.
// Pre-condition: Takes in the weighted average, % of coursework remaining,
//                  and % of coursework finished to calculate grades.
void dispResult(double avg, double gradeRemain, double gradeFinished) {
  cout << "*******************************************\n";
// Displays the % of coursework finished and the current grade of the student.
  cout << "You have completed " << gradeFinished << "% of your coursework. YAY!\n";
  cout << "\nYour current grade is " << avg/gradeFinished * 100 << "."  << endl;
// Outputs the current grade in the form of a letter: A,B,C,D,F
  cout << "Based on that, your uncurved grade is ";
  if (avg/gradeFinished * 100 >= 90) { cout << "an A!" << endl; }
  else if (avg/gradeFinished * 100 >= 80) { cout << "a B!" << endl; }
  else if (avg/gradeFinished * 100 >= 70) { cout << "a C." << endl; }
  else if (avg/gradeFinished * 100 >= 60) { cout << "a D." << endl; }
  else { cout << "an F." << endl; }

// Displays % of remaining coursework to go and the averaged needed
//   to reach certain letter grades.
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


/* Sample Output
// Homework scores were entered individually while test and participation
//   scores were entered via copy and paste.
// The above comments were not part of the original code output.
//   Everything else is.

Hello! This is a grade calculator based on your coursework thus far! 

First I will ask how your grade is distributed based on homework, tests, participation, and extra credit. 

I will then ask you how many homeworks or tests or participation and extra credit you have. 

Example Scenario: 
  Example with 25% of final grade, 5 homeworks, 3 submitted, 
	12 points for hw #1, 15 possible points for hw #1, 
	80 points for hw #2, 100 possible points for hw #2, ... etc 

Shortcut: 	%weight, 	#hwtotal, 	#submit 
		Points obtained for #1, 	Points possible for #1, 

Shortcut Example: Weight Total homesworks Submitted':  '25 5 3'
		'Pts1 	Hw1 	Pts2 	Hw2': 
		'12 	15 	80 	100' ... <pts> <possible> ... 

How much percentage of your total grade is homework?: 25
How many homeworks do you have?: 5
How many have submitted so far?: 3
What is your grade for homework #1: 12
What is the total points for homework #1: 15

For homework #1 : You entered 12 out of 15 points.

What is your grade for homework #2: 80
What is the total points for homework #2: 100

For homework #2 : You entered 80 out of 100 points.

What is your grade for homework #3: 90
What is the total points for homework #3: 85

For homework #3 : You entered 90 out of 85 points.

Your total hw score is 182 out of a possible 200 with a weight of 25% of your final grade. 

How much percentage of your total grade is test?: 50
4
2
120
150
105
150How many tests do you have?: How many have you taken so far?: What is your grade for test #1: What is the total points for test #1: 
For test #1 : You entered 120 out of 150 points.

What is your grade for test #2: What is the total points for test #2: 

For test #2 : You entered 105 out of 150 points.

Your total test score is 225 out of a possible 300 with a weight of 50% of your final grade. 

How much percentage of your total grade is participation?: 25
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
10How many participations do you have?: How many have been given so far?: What is your grade for participation #1: What is the total points for participation #1: 
For participation #1 : You entered 5 out of 10 points.

What is your grade for participation #2: What is the total points for participation #2: 
For participation #2 : You entered 8 out of 10 points.

What is your grade for participation #3: What is the total points for participation #3: 
For participation #3 : You entered 9 out of 10 points.

What is your grade for participation #4: What is the total points for participation #4: 
For participation #4 : You entered 8 out of 10 points.

What is your grade for participation #5: What is the total points for participation #5: 
For participation #5 : You entered 7 out of 10 points.

What is your grade for participation #6: What is the total points for participation #6: 

For participation #6 : You entered 9 out of 10 points.

Your total participation score is 46 out of a possible 60 with a weight of 25% of your final grade. 

Do you have any extra credit to add? (y/n) : y
How much extra credit do you want to add? : 1
Do you have any other extra to add? : n
You have a total of 1 extra credit to add to your final score. 

*******************************************
You have completed 55% of your coursework. YAY!

Your current grade is 81.6364.
Based on that, your uncurved grade is a B!

You still have 45% of your final grade left to go!

You'll need: 
45.1% for an A or an average of 100.222% in the remainder of your coursework.
35.1% for a B or an average of 78% in the remainder of your coursework.
25.1% for a C or an average of 55.7778% in the remainder of your coursework.
15.1% for a D or an average of 33.5556% in the remainder of your coursework.
*/
