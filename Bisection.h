#pragma once
class BisectionMethod 
{
private:
	int command;
	double e = std::pow(10, -5);
	double fan = 0;
	double fbn = 0;
	double an = 0;
	double bn = 0;
	void EquationForBisection(double& fn, double x);
public:
	BisectionMethod(int command, double an, double bn);
	void Bisection();
};
