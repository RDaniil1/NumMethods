#pragma once
double NewtonEquation(double xn);
double FirstDeriv(double xn);
double SecondDeriv(double xn);
double FindNextXn(double xn);
void NewtonAlgorithm(double ab, double e, double &xn);
void NewtonsMethod();