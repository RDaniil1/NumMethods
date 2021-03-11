#include "SimpleIterations.h"
#include <cmath>
#include <iostream>

double EquationForIteration(double xPrev)
{
	return std::pow(xPrev + 1, 0.2);//Equation for solving 
}

void SimpleIterations()
{
	double xPrev = 1;
	double xNext = EquationForIteration(xPrev);
	double e = std::pow(10, -5);
	double deltaX = fabs(xNext - xPrev);
	while (deltaX > e)
	{
		xPrev = xNext;
		xNext = EquationForIteration(xPrev);
		deltaX = fabs(xNext - xPrev);
	}
	std::cout << "Simple iterations result is: " << xNext << std::endl;
}
