#include <cmath>
#include <iostream>
#include "NewtonsMethod.h"

NewtonsMethod::NewtonsMethod(int command, double a, double b)
{
	this->command = command;
	this->a = a;
	this->b = b;
}
double NewtonsMethod::NewtonEquation(double xn)
{
	double res;
	switch (command)
	{
	case 3:
		res = std::pow(xn, 3) + 3 * std::pow(xn, 2) - 1;
		break;
	case 5:
		res = xn - 0.5 * xn - (0.5 * 0.6 / xn);
		break;
	case 8:
		res = std::pow(xn, 3) + 3 * std::pow(xn, 2) - 3;
		break;
	case 9:
		res = std::pow(xn, 3) + std::pow(xn, 2) - 10 * xn + 8;
		break;
	}
	return res;
}

double NewtonsMethod::FirstDeriv(double xn)
{
	double res;
	switch (command)
	{
	case 3:
		res = 3 * std::pow(xn, 2) + 6 * xn;
		break;
	case 5:
		res = 2 * xn;
		break;
	case 8:
		res = 3 * std::pow(xn, 2) + 6 * xn;
		break;
	case 9:
		res = 3 * std::pow(xn, 2) + 2 * xn - 10;
		break;
	}
	return res;
}

double NewtonsMethod::SecondDeriv(double xn)
{
	double res;
	switch (command)
	{
	case 3:
		res = 6 * xn + 6;
		break;
	case 5:
		res = 2;
		break;
	case 8:
		res = 3 * xn + 6;
		break;
	case 9:
		res = 3 * xn + 2;
		break;
	}
	return res;
}

double NewtonsMethod::FindNextXn(double xn)
{
	return xn - (NewtonEquation(xn)/FirstDeriv(xn));
}

void NewtonsMethod::NewtonAlgorithm(double ab, double e, double &xn)
{
	xn = ab;
	double fxn = NewtonEquation(xn);
	while (fabs(fxn) > e)
	{
		xn = FindNextXn(xn);
		fxn = NewtonEquation(xn);
	}
}

void NewtonsMethod::Newton()
{
	double xn;
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
	std::cout << "Newton's method result is: " << std::fixed << xn << std::endl;
}