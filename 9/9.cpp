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
//////////////////////////////////////////////////////////////
	cout<<"¬веедите Epsilon --> ";
    cin>>eps;
    if(eps<=0)
	{
		
		cout<<"ќшибка";
		cin.get();
	    cin.get();
		exit(0);
	}

cout<<"¬ведите X начальное --> ";
cin>>XStart;
cout<<"¬ведите X конечное --> ";
cin>>XEnd;
cout<<"¬веедите DX --> ";
cin>>DX;
double temp;
if(DX==0)
	{
		XEnd=XStart+1;
        DX=2;
    }
else if(XStart<XEnd&&DX<=0)
	{
		
		cout<<"ќшибка";
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
	if((1/XStart)!=NULL)
	{
       cosec=(1/sin(XStart))*(1/sin(XStart));
       delta=sqrt(abs(mycosec*mycosec-cosec*cosec));
       printf("|%15.7f|%20.10f|%20.10f|%20.10f|\n",XStart,mycosec(XStart)*mycosec(XStart),cosec,delta);
	}
	else 
   {
       printf("|   %10.7f  |       ошибка       |       ошибка       |       ошибка       |\n",XStart);
 
   }


}
printf("|---------------|--------------------|-----------------------------------------|\n");


cout<<"¬ведите X проверочный --> ";
cin>>XIdeal;
 eps=0.1;
printf("|---------------|--------------------|--------------------|--------------------|\n");
printf("|        X      |       My_ctg(x)    |        ctg(x)      |        Sigma       |\n");
printf("|---------------|--------------------|--------------------|--------------------|\n");
 for( ;eps>0.0000001;eps=eps/10)
{
	 if((1/XIdeal)!=NULL)
      {
            
           cosec=(1/sin(XIdeal))*(1/sin(XIdeal));
           delta=sqrt(abs(mycosec*mycosec-cosec*cosec));
           printf("|%15.7f|%20.10f|%20.10f|%20.10f|\n",XIdeal,mycosec(XIdeal)*mycosec(XIdeal),cosec,delta);


       }
else
    printf("|%10.7f |       ошибка       |       ошибка       |       ошибка       |\n",eps);
 }
    printf("|---------------|--------------------|-----------------------------------------|\n");




	HINSTANCE my_dll = LoadLibraryA("my_dll.dll");
	if(my_dll==NULL)
	{
		cout<<"ќшибка открыти€ DLL";
		cin.get();
	    cin.get();
		exit(0);
	}

	
	  	
	cin.get();
	cin.get();
	return 0;
	}