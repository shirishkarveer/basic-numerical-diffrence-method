// num_diff.cpp : This file contains the 'main' function. Program execution begins and ends there.
// code compile and run successful in vs 2019

#include<iostream>
#include<cmath>
#include"pch.h"

using namespace std;
/*ALGO:
DEF POLY DEGREE
DEF CONST
CONSTRUCT POLY USING ABOVE 2 STEPS
DEFINE THE POINT TO DO DIFF
DO THE DIFF USING EQUATION
COUT << RESULT
y = A+Bx+Cx^2+....EX^4+… (10 DEGREE POLY = 11 COEFFS)
*/

void dispoly(float coeff[11], int degree) {
	for (int i = 0; i <= degree; i++) {
		if (i == 0) {
			cout << coeff[i] << " + ";
		}
		else if (i == degree) {
			cout << coeff[i] << "X ^" << i << endl;
		}
		else {
			cout << coeff[i] << "X ^" << i << " + ";
		}

	}
}

float poly(float coeff[11], float degree, float X ){
	float Y = 0.0;
	for (int i = 0; i <= degree; i++)
	{
		Y += coeff[i] * pow(X, i);
	}
	cout << "Y =" << Y << endl;
	return Y;
	}
int main()
{
	int degree;
	cout << "degree of poly:";
	cin >> degree;

	float coeff[11];
	cout << "Input poly consts:" << endl; 
	for (int i = 0; i <= degree; i++) {
		cout << "coeff" << i << ":";
		cin >> coeff[i];
	}
	
	dispoly(coeff, degree); // to disp polynomial
	 
	float X;
	cout << "input value for X for diff: ";
	cin >> X;

	float y = poly(coeff, degree, X);
	float h = 0.0001; // need to choose the correct h or finite diff methods
	float X1 = X + h; 
	float y1 = poly(coeff, degree, X1); 

	float slope = (y1 - y) / h; //optimization for consistent slope for convergence
	cout << "slope = " << slope << endl;

	
}


