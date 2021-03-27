#pragma once
#include "CppConsoleTable.hpp"

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

void DrawBisectionTableHeader(samilton::ConsoleTable& table);

void AddRowInBisectionTable(double  n, double an, double bn, double xn, double fan, double fbn, double fxn, samilton::ConsoleTable& table);
