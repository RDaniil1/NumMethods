#pragma once
#include <cmath>
class SecantMethod
{
private:
	int command;
	const double e = std::pow(10, -5);
	double x1, x2;
	double SecantEquation(double xn);
	double FirstDerivSec(double xn);
	double SecoDerivSec(double xn);
	double DeltaB(double a, double bn);
	bool ConditionIsExecuted(double a, double b);
	void SecantAlgorithm(double a, double bn);
public:
	SecantMethod(int command, double x1, double x2);
	void Secant();
};
