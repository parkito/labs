#include<iostream>
#include<math.h>
#include<conio.h>
#include<windows.h>
double eps,
	   XStart,
	   XEnd,
	   DX,
	   XIdeal,
	   mycosec, 
	   cosec,
	   delta;
const double PI=3.14;
using namespace std;
int main()
{    
    setlocale(LC_ALL, "Rus");
	typedef double (*my_function)(double, double, double);
	typedef double (*math_function)(double, double);
	typedef char * (*name)();
	HINSTANCE my_dll = LoadLibraryA("my_dll.dll");
	if(my_dll==NULL)
	{
		cout<<"Ошибка открытия DLL";
		cin.get();
	    cin.get();
		exit(0);
	}
		
	math_function cosec = (math_function)GetProcAddress(my_dll, "myf_math");
	my_function mycosec = (my_function)GetProcAddress(my_dll, "myf_2");
	name Name = (name)GetProcAddress(my_dll, "Name");
	//////////////////////////////////////////////////////////////
	cout<<"Работаю с функцией "<<Name()<<endl<<endl;
	cout<<"Ввеедите Epsilon --> ";
    cin>>eps;
    if(eps<=0)
	{
		
		cout<<"Ошибка";
		cin.get();
	    cin.get();
		exit(0);
	}

cout<<"Введите X начальное --> ";
cin>>XStart;
cout<<"Введите X конечное --> ";
cin>>XEnd;
cout<<"Ввеедите DX --> ";
cin>>DX;
double temp;
if(DX==0)
	{
		XEnd=XStart+1;
        DX=2;
    }
else if(XStart<XEnd&&DX<=0)
	{
		
		cout<<"Ошибка";
		cin.get();
	    cin.get();
		exit(0);
	}
else if(XStart>XEnd&&DX>0)
    {
        temp=XStart;XStart=XEnd;XEnd=temp;
    }
else if(XStart>XEnd&&DX<0)
    {
		DX=-DX;
        temp=XStart;XStart=XEnd;XEnd=temp;
    }


    printf("|---------------|--------------------|--------------------|--------------------|\n");
    printf("|        X      |       My_Fun(x)    |        Fun(x)      |        Sigma       |\n");
    printf("|---------------|--------------------|--------------------|--------------------|\n");

///////////////////////////////////////////////////////////


for( ;XStart<=XEnd;XStart=XStart+DX)
{
	if(sin(XStart)!=0)
	{
       
       delta=sqrt(abs( pow(mycosec(XStart,0,eps),2)-pow(cosec(0,XStart),2) ) );
       printf("|%15.7f|%20.10f|%20.10f|%20.10f|\n",XStart,mycosec(XStart,0,eps),cosec(0,XStart),delta);
	}
	else 
   {
       printf("|   %10.7f  |       ошибка       |       ошибка       |       ошибка       |\n",XStart);
 
   }


}
printf("|---------------|--------------------|-----------------------------------------|\n");


cout<<"Введите X проверочный --> ";
cin>>XIdeal;
 eps=0.1;
printf("|---------------|--------------------|--------------------|--------------------|\n");
printf("|     Epsilon   |       My_Fun(x)    |        Fun(x)      |        Sigma       |\n");
printf("|---------------|--------------------|--------------------|--------------------|\n");
 for( ;eps>0.0000001;eps=eps/10)
{
	 if(sin(XIdeal)!=0)
      {
            
           
           delta=sqrt(abs( pow(mycosec(XIdeal,0,eps),2)-pow(cosec(0,XIdeal),2) ) );
           printf("|%15.7f|%20.10f|%20.10f|%20.10f|\n",eps,mycosec(XIdeal,0,eps),cosec(0,XIdeal),delta);


       }
else
    printf("|   %10.7f  |       ошибка       |       ошибка       |       ошибка       |\n",eps);
 }
    printf("|---------------|--------------------|-----------------------------------------|\n");




	
	
	  	
	cin.get();
	cin.get();
	return 0;
	}