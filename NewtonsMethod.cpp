#include <cmath>
#include <iostream>
#include "NewtonsMethod.h"

double NewtonEquation(double xn)
{
	return std::pow(xn, 3) + 3 * std::pow(xn, 2) - 1;
}

double FirstDeriv(double xn)
{
	return 3 * std::pow(xn, 2) + 6 * xn;
}

double SecondDeriv(double xn)
{
	return 6 * xn + 6;
}

double FindNextXn(double xn)
{
	return xn - (NewtonEquation(xn)/FirstDeriv(xn));
}

void NewtonAlgorithm(double ab, double e, double &xn)
{
	xn = ab;
	double fxn = NewtonEquation(xn);
	while (fabs(fxn) > e)
	{
		xn = FindNextXn(xn);
		fxn = NewtonEquation(xn);
	}
}

void NewtonsMethod()
{
	double xn;
	double a = 0;
	double b = 1;
	double e = std::pow(10, -5);
	double conditionPrev = NewtonEquation(a) * SecondDeriv(a);
	double conditionNext = NewtonEquation(b) * SecondDeriv(b);
	if (conditionPrev > 0)
	{
		NewtonAlgorithm(a, e, xn);
	}
	else if (conditionNext > 0)
	{
		NewtonAlgorithm(b, e, xn);
	}
	else return;
	std::cout << "Newton's method result is: " << xn << std::endl;
}