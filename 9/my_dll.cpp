#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <windows.h>
using namespace std;

extern "C" __declspec(dllexport) double my_func (double X, double epsilon);
double Karnov_func (double, double);
double fact(double);
double f(double, double);

extern "C" __declspec(dllexport) double my_func (double X, double epsilon)
{
return Karnov_func (X, epsilon );
}

double Karnov_func(double X, double epsilon)
{double n=0,sum=0;

 while(abs(f(n,sum)-f(n+1,sum))<epsilon)
  {
	 sum=f(n,sum);
	 n++;
	 
  }

	return (1/X)+f(n,sum);
}

double fact(double x)
{
    if (x<=1) return 1;
    else return x*fact(x-1);
}

double f(double n, double sum)
{      
   	        sum += ( 2*(pow(2,2*n+1)-1) ) /( fact(2*n+2));
			return sum;

		
 }