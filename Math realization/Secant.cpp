#include <iostream>
#include <cmath>
#include "Secant.h"

constexpr double e = 10E-5;
double SecantEquation(double xn)
{
	return std::pow(xn, 3) - 4 * std::pow(xn, 2) + 2;
}

double FirstDerivSec(double xn)
{
	return 3 * std::pow(xn, 2) - 8 * xn;
}

double SecoDerivSec(double xn)
{
	return 6 * xn - 8;
}

double DeltaB(double a, double bn)
{
	double fa = SecantEquation(a);
	double fbn = SecantEquation(bn);
	return ((bn - a) / (fbn - fa)) * fbn;
}

bool ConditionIsExecuted(double a, double b)
{
	double fa = SecantEquation(a);
	double fb = SecantEquation(b);
	if (fa * fb < 0)
	{
		return true;
	}
	else return false;
}

void SecantAlgorithm(double a, double bn)
{
	double deltaB = DeltaB(a, bn);
	while (fabs(deltaB) > e)
	{
		deltaB = DeltaB(a, bn);
		bn -= deltaB;
	}
	std::cout << "Secant result is: " << bn << std::endl;
}

void Secant()
{
	double a, bn;
	double x1 = -1, x2 = 0;
	double x1FuncSign = SecantEquation(x1) * SecoDerivSec(x1);
	double x2FuncSign = SecantEquation(x2) * SecoDerivSec(x2);
	if (ConditionIsExecuted(x1, x2))
	{
		if (x1FuncSign > 0
			and x2FuncSign < 0)
		{
			a = x1;
			bn = x2;
			SecantAlgorithm(a, bn);
		}
		else
			if (x1FuncSign < 0
				and x2FuncSign > 0)
			{
				a = x2;
				bn = x1;
				SecantAlgorithm(a, bn);
			}
	}
}