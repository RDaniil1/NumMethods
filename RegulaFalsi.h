#pragma once
#include <cmath>
class RegulaFalsiMethod
{
private:
	int command;
	const double e = std::pow(10, -5);
	double a, b;
	double fan, fbn, fxn , xn;
	double FalsiEquation(double xn);
	double FindXn(double an, double bn);
public:
	RegulaFalsiMethod(int command, double a, double b);
	void RegulaFalsi();
}; 
