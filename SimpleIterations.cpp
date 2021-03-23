#include "SimpleIterations.h"
#include <cmath>
#include <iostream>

SimpleIterationsMethod::SimpleIterationsMethod(int command)
{
	this->command = command;
}

double SimpleIterationsMethod::EquationForIteration(double xPrev)
{
	double res;
	switch (command)
	{
	case 1:
		res = std::pow(xPrev + 1, 0.2);
		break;
	case 5:
		res = std::sqrt(0.5 * std::pow(xPrev, 2) + 0.6 * 0.5);
		break;
	case 6:
		res = std::sqrt(0.5 * std::pow(xPrev, 2) + 0.7 * 0.5);
		break;
	case 7:
		res = std::sqrt(0.5 * std::pow(xPrev, 2) + 0.8 * 0.5);
		break;
	}
	return res;
}

void SimpleIterationsMethod::SimpleIterations()
{
	double xPrev = 0;
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
