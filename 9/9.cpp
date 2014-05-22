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
	typedef double (*function)(double, double);
	HINSTANCE my_dll = LoadLibraryA("my_dll.dll");
	if(my_dll==NULL)
	{
		cout<<"Ошибка открытия DLL";
		cin.get();
	    cin.get();
		exit(0);
	}

	function mycosec = (function)GetProcAddress(my_dll, "my_func");
	//////////////////////////////////////////////////////////////
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
	if((1/XStart)!=NULL&&XStart!=0)
	{
       cosec=pow(1/sin(XStart),2);
       delta=sqrt(abs( pow(mycosec(XStart,eps),2)-pow(cosec,2) ) );
       printf("|%15.7f|%20.10f|%20.10f|%20.10f|\n",XStart,mycosec(XStart,eps),cosec,delta);
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
printf("|     Epsilon   |       My_ctg(x)    |        ctg(x)      |        Sigma       |\n");
printf("|---------------|--------------------|--------------------|--------------------|\n");
 for( ;eps>0.0000001;eps=eps/10)
{
	 if((1/XIdeal)!=NULL&&XIdeal!=0)
      {
            
           cosec=pow((1/sin(XIdeal)),2);
           delta=sqrt(abs( pow(mycosec(XIdeal,eps),2)-pow(cosec,2) ) );
           printf("|%15.7f|%20.10f|%20.10f|%20.10f|\n",eps,mycosec(XIdeal,eps),cosec,delta);


       }
else
    printf("|   %10.7f  |       ошибка       |       ошибка       |       ошибка       |\n",eps);
 }
    printf("|---------------|--------------------|-----------------------------------------|\n");




	
	
	  	
	cin.get();
	cin.get();
	return 0;
	}