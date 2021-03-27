#pragma once
#include <cmath>
#include "CppConsoleTable.hpp"

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
	void SecantAlgorithm(double a, double bn, samilton::ConsoleTable& table);
public:
	SecantMethod(int command, double x1, double x2);
	void Secant();
};

void DrawSecantTableHeader(samilton::ConsoleTable& table);

void AddRowInSecantTable(double  n, double an, double bn, double fan, double fbn, samilton::ConsoleTable& table);