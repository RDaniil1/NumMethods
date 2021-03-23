#include <iostream>
#include "Bisection.h"
#include "SimpleIterations.h"
#include "NewtonsMethod.h"
#include "Secant.h"

int main()
{
	int numTask;
	std::cout << "Type number of task in practics: ";
	std::cin >> numTask;
	switch (numTask)
	{
	case 1:
	{
		BisectionMethod bisection(1, 0, 2);
		bisection.Bisection();
		SimpleIterationsMethod simpleIterations(1);
		simpleIterations.SimpleIterations();
		break;
	}
	case 2:
	{
		BisectionMethod bisection(2, 0, 2);
		bisection.Bisection();
		SecantMethod secant(2, 0, 1);
		secant.Secant();
		break;
	}
	case 3:
	{
		BisectionMethod bisection(3, 0, 2);
		bisection.Bisection();
		NewtonsMethod newton(3, 0, 1);
		newton.Newton();
		break;
	}
	case 4:
	{
		BisectionMethod bisection(4, 0, 2);
		bisection.Bisection();
		SecantMethod secant(4, 0, 2);
		secant.Secant();
		break;
	}
	case 5:
	{
		SimpleIterationsMethod simpleIterations(5);
		simpleIterations.SimpleIterations();
		NewtonsMethod newton(5, 0, 1);
		newton.Newton();
		break;
	}
	case 6:
	{
		SimpleIterationsMethod simpleIterations(6);
		simpleIterations.SimpleIterations();
		SecantMethod secant(6, 0.2, 1);
		secant.Secant();
		break;
	}
	case 7:
	{
		SimpleIterationsMethod simpleIterations(7);
		simpleIterations.SimpleIterations();
		SecantMethod secant(7, 0.2, 1);
		secant.Secant();
		break;
	}
	case 8:
	{
		SecantMethod secant(8, 0, 2);
		secant.Secant();
		NewtonsMethod newton(8, 0, 2);
		newton.Newton();
		break;
	}
	case 9:
	{
		NewtonsMethod newton(9, 0, 1.5);
		newton.Newton();
		SecantMethod secant(9, 0, 1.5);
		secant.Secant();
		break;
	}
	case 10:
	{
		SecantMethod secant(10, 0.5, 1.5);
		secant.Secant();
		SecantMethod secant2(10, 0.5, 1.5);
		secant2.Secant();
		break;
	}
	default:
		std::cout << "Incorrect number of task" << "\n";
		break;
	}
	return 0;
}

