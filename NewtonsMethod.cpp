#include <cmath>
#include <vector>
#include <iostream>
#include "CppConsoleTable.hpp"
#include "NewtonsMethod.h"

NewtonsMethod::NewtonsMethod(int command, double a, double b)
{
	this->command = command;
	this->a = a;
	this->b = b;
}

double NewtonsMethod::NewtonEquation(double xn)
{
	double res;
	switch (command)
	{
	case 3:
		res = std::pow(xn, 3) + 3 * std::pow(xn, 2) - 1;
		break;
	case 5:
		res = xn - 0.5 * xn - (0.5 * 0.6 / xn);
		break;
	case 8:
		res = std::pow(xn, 3) + 3 * std::pow(xn, 2) - 3;
		break;
	case 9:
		res = std::pow(xn, 3) + std::pow(xn, 2) - 10 * xn + 8;
		break;
	}
	return res;
}

double NewtonsMethod::FirstDeriv(double xn)
{
	double res;
	switch (command)
	{
	case 3:
		res = 3 * std::pow(xn, 2) + 6 * xn;
		break;
	case 5:
		res = 2 * xn;
		break;
	case 8:
		res = 3 * std::pow(xn, 2) + 6 * xn;
		break;
	case 9:
		res = 3 * std::pow(xn, 2) + 2 * xn - 10;
		break;
	}
	return res;
}

double NewtonsMethod::SecondDeriv(double xn)
{
	double res;
	switch (command)
	{
	case 3:
		res = 6 * xn + 6;
		break;
	case 5:
		res = 2;
		break;
	case 8:
		res = 3 * xn + 6;
		break;
	case 9:
		res = 3 * xn + 2;
		break;
	}
	return res;
}

double NewtonsMethod::FindNextXn(double xn)
{
	return xn - (NewtonEquation(xn)/FirstDeriv(xn));
}

void NewtonsMethod::NewtonAlgorithm(double ab, double &xn, samilton::ConsoleTable &table)
{
	double n = 0;
	xn = ab;
	double fxn = NewtonEquation(xn);
	double f1ab = FirstDeriv(ab);
	AddRowInNewtonsTable(n, xn, f1ab, fxn, table);
	while (fabs(fxn) > e)
	{
		xn = FindNextXn(xn);
		fxn = NewtonEquation(xn);
		n++;
		AddRowInNewtonsTable(n, xn, f1ab, fxn, table);
	}
}

void DrawNewtonsTableHeader(samilton::ConsoleTable& table)
{
	std::vector <std::string> headers = { "n", "xn", "f'xn", "fxn"};
	table.addRow(headers);
}

void AddRowInNewtonsTable(double  n, double xn, double f1xn, double fxn, samilton::ConsoleTable& table)
{
	std::vector <double> nums;
	nums.push_back(n);
	nums.push_back(xn);
	nums.push_back(f1xn);
	nums.push_back(fxn);
	table.addRow(nums);
}

void NewtonsMethod::Newton()
{
	double n = 0;
	samilton::ConsoleTable table(1, 1, samilton::Alignment::centre);
	double xn;
	double conditionPrev = NewtonEquation(a) * SecondDeriv(a);
	double conditionNext = NewtonEquation(b) * SecondDeriv(b);
	std::cout << "Newton's method table: " << "\n";
	DrawNewtonsTableHeader(table);
	if (conditionPrev > 0)
	{
		NewtonAlgorithm(a, xn, table);
	}
	else if (conditionNext > 0)
	{
		NewtonAlgorithm(b, xn, table);
	}
	else return;
	std::cout << table;
}