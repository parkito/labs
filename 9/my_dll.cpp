#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <windows.h>
using namespace std;

extern "C" __declspec(dllexport) double myf_2(double, double, double);
extern "C" __declspec(dllexport) double myf_math (double, double);
extern "C" __declspec(dllexport) char* Name();
double Karnov_func (double, double);
double fact(double);
double cosec(double , double);

 double myf_2 (double X, double a, double epsilon)
{return pow(cosec (X, epsilon ),2);}

double Karnov_funk(double x, double EPS) 
{
    double result = x;
    double delta = x;
    for (int n=1; fabs(delta)>EPS; n++)
	{
        delta *= x/(2*n)*x/(2*n+1);
        delta *= -1;
        result+=delta;
    }
    return result;
}

double cosec(double x, double EPS)
{
    return 1.0f/Karnov_funk(x, EPS);
}

 double myf_math (double a, double X)
{
	return pow(1/sin(X),2);
}
 char* Name()
{return "cosec(x)";}
