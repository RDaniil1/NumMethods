#pragma once
#include "CppConsoleTable.hpp"
class NewtonsMethod
{
private:
	int command;
	double a = 0;
	double b = 1;
	double e = std::pow(10, -5);
	double NewtonEquation(double xn);
	double FirstDeriv(double xn);
	double SecondDeriv(double xn);
	double FindNextXn(double xn);
	void NewtonAlgorithm(double ab, double& xn, samilton::ConsoleTable& table);
public:
	NewtonsMethod(int command, double a, double b);
	void Newton();
};

void AddRowInNewtonsTable(double  n, double xn, double f1xn, double fxn, samilton::ConsoleTable& table);

void DrawNewtonsTableHeader(samilton::ConsoleTable& table);