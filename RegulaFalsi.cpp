#include <iostream>
#include <cmath>
#include <vector>
#include "CppConsoleTable.hpp"
#include "RegulaFalsi.h"

RegulaFalsiMethod::RegulaFalsiMethod(int command, double a, double b)
{
	this->command = command;
	this->a = a;
	this->b = b;
}

double RegulaFalsiMethod::FalsiEquation(double xn)
{
	double res;
	switch (command)
	{
	case 4:
		res = std::pow(xn, 3) + 3 * std::pow(xn, 2) - 1;
		break;
	case 7:
		res = xn - 0.5 * xn - (0.5 * 0.8 / xn);
		break;
	case 9:
		res = std::pow(xn, 3) + std::pow(xn, 2) - 10 * xn + 8;
		break;
	case 10:
		res = std::pow(xn, 3) - std::pow(xn, 2) - 4 * xn + 4;
		break;
	}
	return res;
}

double RegulaFalsiMethod::FindXn(double an, double bn)
{
	fan = FalsiEquation(an);
	fbn = FalsiEquation(bn);
	return (an * fbn - bn * fan)/(fbn - fan);
}

void DrawFalsiTableHeader(samilton::ConsoleTable& table)
{
	std::vector <std::string> headers = { "n", "an", "bn", "xn", "fan", "fbn", "fxn", "bn - an" };
	table.addRow(headers);
}

void AddRowInFalsiTable(double  n, double an, double bn, double xn, double fan, double fbn, double fxn, samilton::ConsoleTable& table)
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

void RegulaFalsiMethod::RegulaFalsi()
{
	double n = 0;
	samilton::ConsoleTable table(1, 1, samilton::Alignment::centre);
	fan = FalsiEquation(a);
	fbn = FalsiEquation(b);
	if (fan * fbn > 0)
	{
		return;
	}
	xn = FindXn(a, b);
	fxn = FalsiEquation(xn);
	std::cout << "Regula falsi method table: " << "\n";
	DrawFalsiTableHeader(table);
	AddRowInFalsiTable(n, a, b, xn, fan, fbn, fxn, table);
	while (fabs(fxn) > e)
	{
		if (fan * fxn < 0)
		{
			b = xn;
		}
		else if (fbn * fxn < 0)
		{
			a = xn;
		}
		xn = FindXn(a, b);
		fxn = FalsiEquation(xn);
		n++;
		AddRowInFalsiTable(n, a, b, xn, fan, fbn, fxn, table);
	}
	std::cout << table;
}