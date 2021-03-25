#include <iostream>
#include <cmath>
#include "Bisection.h"
#include <iomanip>

BisectionMethod::BisectionMethod(int command, double an, double bn)
{
	this->command = command;
	this->an = an;
	this->bn = bn;
}

void BisectionMethod::EquationForBisection(double &fn, double x)
{
	switch (command)
	{
	case 1:
		fn = std::pow(x, 5) - x - 1;
		break;
	case 2:
		fn = std::pow(x, 3) - 4 * std::pow(x, 2) + 2;
		break;
	case 3:
		fn = std::pow(x, 3) + 3 * std::pow(x, 2) - 1;
		break;
	case 4:
		fn = std::pow(x, 3) + 3 * std::pow(x, 2) - 1;
		break;
	}
}

void BisectionMethod::Bisection()
{
	double xn = (bn + an) / 2;
	EquationForBisection(fan, an);
	EquationForBisection(fbn, bn);
	if (fan * fbn > 0)
	{
		return;
	}
	double fxn = 0; 
	EquationForBisection(fxn, xn);
	while (fabs(fxn) > e) 
	{
		if (fan * fxn > 0)
		{
			an = xn;
		}
		else bn = xn;
		xn = (bn + an) / 2;
		EquationForBisection(fan, an);
		EquationForBisection(fxn, xn);
	}
	
	std::cout << "Result for bisection is: "  << xn << std::endl;
}