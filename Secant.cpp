#include <iostream>
#include <cmath>
#include <vector>
#include "CppConsoleTable.hpp"
#include "Secant.h"
SecantMethod::SecantMethod(int command, double x1, double x2)
{
	this->command = command;
	this->x1 = x1;
	this->x2 = x2;
}

double SecantMethod::SecantEquation(double xn)
{
	double res;
	switch (command)
	{
	case 2:
		res = std::pow(xn, 3) - 4 * std::pow(xn, 2) + 2;
		break;
	case 6:
		res = xn - 0.5 * xn - (0.5 * 0.7 / xn);
		break;
	case 8:
		res = std::pow(xn, 3) + 3 * std::pow(xn, 2) - 3;
		break;
	case 10:
		res = std::pow(xn, 3) - std::pow(xn, 2) - 4 * xn + 4;
		break;
	}
	return res;
}

double SecantMethod::FirstDerivSec(double xn)
{
	double res;
	switch (command)
	{
	case 2:
		res = 3 * std::pow(xn, 2) - 8 * xn;
		break;
	case 6:
		res = xn;
		break;
	case 8:
		res = 3 * std::pow(xn, 2) + 6 * xn;
		break;
	case 10:
		res = 3 * std::pow(xn, 2) - 2 * xn - 4;
		break;
	}
	return res;
}

double SecantMethod::SecoDerivSec(double xn)
{
	double res;
	switch (command)
	{
	case 2:
		res = 6 * xn - 8;
		break;
	case 6:
		res = 1;
		break;
	case 8:
		res = 6 * xn + 6;
		break;
	case 10:
		res = 6 * xn - 2;
		break;
	}
	return res;
}

double SecantMethod::DeltaB(double a, double bn)
{
	double fa = SecantEquation(a);
	double fbn = SecantEquation(bn);
	return ((bn - a) / (fbn - fa)) * fbn;
}

bool SecantMethod::ConditionIsExecuted(double a, double b)
{
	double fa = SecantEquation(a);
	double fb = SecantEquation(b);
	if (fa * fb < 0)
	{
		return true;
	}
	else return false;
}

void SecantMethod::SecantAlgorithm(double a, double bn, samilton::ConsoleTable &table)
{
	double n = 0;
	double deltaB = DeltaB(a, bn);
	double fa = SecantEquation(a);
	double fbn = SecantEquation(bn);
	AddRowInSecantTable(n, a, bn, fa, fbn, table);
	while (fabs(deltaB) > e)
	{
		deltaB = DeltaB(a, bn);
		bn -= deltaB;
		n++;
		fa = SecantEquation(a);
		fbn = SecantEquation(bn);
		AddRowInSecantTable(n, a, bn, fa, fbn, table);
	}
}

void DrawSecantTableHeader(samilton::ConsoleTable& table)
{
	std::vector <std::string> headers = { "n", "an", "bn", "fan", "fbn"};
	table.addRow(headers);
}

void AddRowInSecantTable(double  n, double an, double bn, double fan, double fbn, samilton::ConsoleTable& table)
{
	std::vector <double> nums;
	nums.push_back(n);
	nums.push_back(an);
	nums.push_back(bn);
	nums.push_back(fan);
	nums.push_back(fbn);
	table.addRow(nums);
}

void SecantMethod::Secant()
{
	samilton::ConsoleTable table(1, 1, samilton::Alignment::centre);
	double a, bn;
	double x1FuncSign = SecantEquation(x1) * SecoDerivSec(x1);
	double x2FuncSign = SecantEquation(x2) * SecoDerivSec(x2);
	std::cout << "Secant method table: " << "\n";
	DrawSecantTableHeader(table);
	if (ConditionIsExecuted(x1, x2))
	{
		if (x1FuncSign > 0
			and x2FuncSign < 0)
		{
			a = x1;
			bn = x2;
			SecantAlgorithm(a, bn, table);
		}
		else
			if (x1FuncSign < 0
				and x2FuncSign > 0)
			{
				a = x2;
				bn = x1;
				SecantAlgorithm(a, bn, table);
			}
	}
	std::cout << table;
}