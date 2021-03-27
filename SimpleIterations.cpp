#include <iostream>
#include <cmath>
#include <vector>
#include "CppConsoleTable.hpp"
#include "SimpleIterations.h"

SimpleIterationsMethod::SimpleIterationsMethod(int command)
{
	this->command = command;
}

double SimpleIterationsMethod::EquationForIteration(double xPrev)
{
	double res;
	switch (command)
	{
	case 1:
		res = std::pow(xPrev + 1, 0.2);
		break;
	case 5:
		res = std::sqrt(0.5 * std::pow(xPrev, 2) + 0.6 * 0.5);
		break;
	case 6:
		res = std::sqrt(0.5 * std::pow(xPrev, 2) + 0.7 * 0.5);
		break;
	case 7:
		res = std::sqrt(0.5 * std::pow(xPrev, 2) + 0.8 * 0.5);
		break;
	}
	return res;
}

void DrawSimpleIterTableHeader(samilton::ConsoleTable& table)
{
	std::vector <std::string> headers = { "n", "xPrev", "xNext" };
	table.addRow(headers);
}

void AddRowInSimpleIterTable(double n, double xPrev, double xNext, samilton::ConsoleTable& table)
{
	std::vector <double> nums;
	nums.push_back(n);
	nums.push_back(xPrev);
	nums.push_back(xNext);
	table.addRow(nums);
}

void SimpleIterationsMethod::SimpleIterations()
{
	double n = 0;
	samilton::ConsoleTable table(1, 1, samilton::Alignment::centre);
	double xPrev = 0;
	double xNext = EquationForIteration(xPrev);
	double deltaX = fabs(xNext - xPrev);
	std::cout << "Simple iterations table: " << "\n";
	DrawSimpleIterTableHeader(table);
	AddRowInSimpleIterTable(n, xPrev, xNext, table);
	while (deltaX > e)
	{
		xPrev = xNext;
		xNext = EquationForIteration(xPrev);
		deltaX = fabs(xNext - xPrev);
		n++;
		AddRowInSimpleIterTable(n, xPrev, xNext, table);
	}
	std::cout << table;
}
