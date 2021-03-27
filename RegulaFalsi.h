#pragma once
#include <cmath>
#include "CppConsoleTable.hpp"

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

void DrawFalsiTableHeader(samilton::ConsoleTable& table);

void AddRowInFalsiTable(double  n, double an, double bn, double xn, double fan, double fbn, double fxn, samilton::ConsoleTable& table);