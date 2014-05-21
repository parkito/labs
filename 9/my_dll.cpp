#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <windows.h>
using namespace std;

extern "C" __declspec(dllexport) double my_func (double X, double epsilon);
double Karnov_func (double, double);
double fact(double);
double cosec(double , double);

extern "C" __declspec(dllexport) double my_func (double X, double epsilon)
{
return pow(cosec (X, epsilon ),2);
}



double Karnov_funk(double x, double EPS) {
    double result = x;
    double delta = x;
    for (int n=1; fabs(delta)>EPS; n++) {
        delta *= x/(2*n)*x/(2*n+1);
        delta *= -1;
        result+=delta;
    }
    return result;
}
double cosec(double x, double EPS) {
    return 1.0f/Karnov_funk(x, EPS);
}

double fact(double x)
{
    if (x<=1) return 1;
    else return x*fact(x-1);
}
