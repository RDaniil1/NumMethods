#include <iostream>
#include <cmath>
#include "Bisection.h"
#include <iomanip>

double EquationForBisection(double x)
{
	return std::pow(x, 5) - x - 1; //Equation for solving 
}

void Bisection()
{
	double e = std::pow(10, -5);
	double an = 0;
	double bn = 2;
	double xn = (bn + an) / 2;
	double fan = EquationForBisection(an);
	double fbn = EquationForBisection(bn);
	if (fan * fbn > 0)
	{
		return;
	}
	double fxn = EquationForBisection(xn);
	while (fabs(fxn) > e) 
	{
		if (fan * fxn > 0)
		{
			an = xn;
		}
		else bn = xn;
		xn = (bn + an) / 2;
		fan = EquationForBisection(an);
		fxn = EquationForBisection(xn);
	}
	
	std::cout << "Result for bisection is: " << std::fixed << xn << std::endl;
}