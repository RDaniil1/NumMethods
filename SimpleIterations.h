#pragma once
#include <cmath>
#include "CppConsoleTable.hpp"

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

void DrawSimpleIterTableHeader(samilton::ConsoleTable& table);

void AddRowInSimpleIterTable(double n, double xPrev, double xNext, samilton::ConsoleTable& table);