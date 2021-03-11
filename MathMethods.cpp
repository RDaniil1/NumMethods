#include <iostream>
#include "Bisection.h"
#include "SimpleIterations.h"
#include "NewtonsMethod.h"

int main()
{
	//x^5 - x - 1
	std::cout << "For equation x^5 - x - 1: " << std::endl << std::endl;
	Bisection(); 
	SimpleIterations();
	//x^3 - 3 * x^2 - 1
	std::cout << std::endl << "For equation x^3 - 3 * x^2 - 1: " << std::endl << std::endl;
	NewtonsMethod();
	return 0;
}

