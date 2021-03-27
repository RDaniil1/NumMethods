#include <vector>
#include <iostream>
#include <cmath>
#include <iomanip>
#include "Bisection.h"
#include "CppConsoleTable.hpp"

BisectionMethod::BisectionMethod(int command, double an, double bn)
{
	this->command = command;
	this->an = an;
	this->bn = bn;
}

void BisectionMethod::EquationForBisection(double &fn, double x)
{
	switch (command)
	{
	case 1:
		fn = std::pow(x, 5) - x - 1;
		break;
	case 2:
		fn = std::pow(x, 3) - 4 * std::pow(x, 2) + 2;
		break;
	case 3:
		fn = std::pow(x, 3) + 3 * std::pow(x, 2) - 1;
		break;
	case 4:
		fn = std::pow(x, 3) + 3 * std::pow(x, 2) - 1;
		break;
	}
}

void DrawBisectionTableHeader(samilton::ConsoleTable &table)
{
	std::vector <std::string> headers = { "n", "an", "bn", "xn", "fan", "fbn", "fxn", "bn - an" };
	table.addRow(headers);
}

void AddRowInBisectionTable(double  n, double an, double bn, double xn, double fan, double fbn, double fxn, samilton::ConsoleTable &table)
{
	std::vector <double> nums;
	nums.push_back(n);
	nums.push_back(an);
	nums.push_back(bn);
	nums.push_back(xn);
	nums.push_back(fan);
	nums.push_back(fbn);
	nums.push_back(fxn);
	nums.push_back(bn - an);
	table.addRow(nums);
}

void BisectionMethod::Bisection()
{
	samilton::ConsoleTable table(1, 1, samilton::Alignment::centre);
	double n = 0;
	double xn = (bn + an) / 2;
	EquationForBisection(fan, an);
	EquationForBisection(fbn, bn);
	if (fan * fbn > 0)
	{
		return;
	}
	double fxn = 0; 
	EquationForBisection(fxn, xn);
	std::cout << "Bisection table: " << "\n";
	DrawBisectionTableHeader(table);
	AddRowInBisectionTable(n, an, bn, xn, fan, fbn, fxn, table);
	while (fabs(fxn) > e) 
	{
		if (fan * fxn > 0)
		{
			an = xn;
		}
		else bn = xn;
		xn = (bn + an) / 2;
		EquationForBisection(fan, an);
		EquationForBisection(fxn, xn);
		n++;
		AddRowInBisectionTable(n, an, bn, xn, fan, fbn, fxn, table);
	}
	std::cout << table;
}