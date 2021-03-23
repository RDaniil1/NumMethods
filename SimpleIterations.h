#pragma once
#include <cmath>
class SimpleIterationsMethod
{
private:
	int command;
	const double e = std::pow(10, -5);
	double EquationForIteration(double xPrev);
public:
	SimpleIterationsMethod(int command);
	void SimpleIterations();
};