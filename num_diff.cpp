// num_diff.cpp : This file contains the 'main' function. DESIGN AND WRITE FIRST. Program execution begins and ends there.
// code compile and run successful in vs 2019. It's a basic finite difference project

#include<iostream>// standard input-output stream. The methods declared in these files are used for manipulating streams. contains definitions of setw, setprecision, etc.
#include<cmath>
#include"pch.h"//precompiled header file added to project

using namespace std;
/*ALGORITHM: math function is rep by the blue curve
DEFINE POLYNOMIALNOMIAL DEGREE
DEF CONSTANTS
CONSTRUCT POLYNOMIAL USING ABOVE 2 STEPS
DEFINE THE POINT TO DO DIFF
DO THE DIFFRENTIATION USING EQUATION
COUT << RESULT
y = A+Bx+Cx^2+....EX^4+… (10 DEGREE POLYNOMIAL = 11 COEFFS, 4+3+2+1+1=11 )
y=coef[0]+coef[1]*X^1+....
1.write the main function 
2.void displayPOLYNOMIAL
3.float POLYNOMIAL
4.LINE 68 ONWARDS math diffrentiation
*/

void displayPOLYNOMIAL(float coeff[11], int degree) {  //sub-function so that main is not heavy
	for (int i = 0; i <= degree; i++) {
		if (i == 0) {  //no need of co-eff here since i =0
			cout << coeff[i] << " + ";
		}
		else if (i == degree) {			//if i = last one i.e. 3 in this case
			cout << coeff[i] << "X ^" << i << endl;
		}
		else {							// else print whole equation
			cout << coeff[i] << "X ^" << i << " + ";
		}
	}
}

float POLYNOMIAL(float coeff[11], float degree, float X ){// creating a sub-fn makes most sense so that we can use it for the top point
	float Y = 0.0;
	for (int i = 0; i <= degree; i++)
	{
		Y += coeff[i] * pow(X, i);		//as per eqn y = A+Bx+..., anything to pow 1 = 0
	}
	cout << "Y =" << Y << endl;			//
	return Y;
	}


int main()
{
	int degree;
	cout << "degree of POLYNOMIAL:";
	cin >> degree;

	float coeff[11];		//BECAUSE 10 DEGREE POLYNOMIAL so 11 inside the ARRAY
	cout << "Input POLYNOMIAL constants:" << endl;		//user input for how many constants 
	for (int i = 0; i <= degree; i++) {     //rest further co-effs would be zero 
		cout << "coeff" << i << ":";	//each one should print out coeff#
		cin >> coeff[i];		//need to tell program which co-eff like A = coeff 0, B = coeff 1, C = 2...
	}
	
	displayPOLYNOMIAL(coeff, degree); // to display POLYNOMIAL
	 
	float X;		//contruct the POLYNOMIAL
	cout << "input value for X for diff: ";
	cin >> X;

	float y = POLYNOMIAL(coeff, degree, X);//
	float h = 0.0001; // need to choose the approriate tiny h  value as lt.X->0, CAN EXPERIMENT WITH THIS VALUE, CURRENT VALUE IS MOST OPTIMAL
	float X1 = X + h; //X+h = distance on Y -> axis
	float y1 = POLYNOMIAL(coeff, degree, X1); //distance on X -> axis

	float slope = (y1 - y) / h; //optimization for consistent slope (meaning differentiation) for Convergence of FD , see line 70
	cout << "slope = " << slope << endl;	
}
