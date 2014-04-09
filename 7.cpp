#include <iostream>
#include <windows.h>
#include <algorithm>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <fstream>
HANDLE hStdout;
int provFile(char);
int Find (int *b, int, int );

char a;
using namespace std;
int main()
{    
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout, BACKGROUND_INTENSITY);

	fstream in;
    ofstream out;
	
	
	int glas=0,soglas=0;
	setlocale(LC_ALL,"Rus");
	in.open("input.txt");

      	  if (in.fail())
	     {
            SetConsoleTextAttribute(hStdout, 15);
			cout<<"Не удалось открыть файл!";
			cin.get();
	        cin.get();
            return 0;
         }

		  
		  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		   SetConsoleTextAttribute(hStdout, 15);cout<<"Последовательный поиск "<<endl<<endl;
		  
     while(1) 
	    {    
             in.get(a);
			 if (in.eof()) break;
			 if(provFile(a)==1) 
				 {
					 SetConsoleTextAttribute(hStdout, 9);
			         cout<<a;
					 soglas++;
			 }
			 else if(provFile(a)==0) 
				{ 
					SetConsoleTextAttribute(hStdout, 12);
			        cout<<a;
					glas++;
			 }
			 else 
				 {
					 SetConsoleTextAttribute(hStdout, 15);cout<<a;
			     }
		
            
			 
	    }

	// sort(b, b + j);
	 SetConsoleTextAttribute(hStdout, 12);
	 cout<<endl<<endl<<endl<<"Vowel: "<<glas;
	 SetConsoleTextAttribute(hStdout, 9);
	cout<<" Consonant: "<<soglas<<endl;
	int size_arr=soglas+glas;
	int *b=new int[size_arr];
	 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	 in.close();
	 SetConsoleTextAttribute(hStdout, 15);cout<<endl<<endl<<"Бинарный поиск "<<endl<<endl;
	 in.open("input.txt");
	 if (in.fail())
	     {
            SetConsoleTextAttribute(hStdout, 15);
		    cout<<"Не удалось открыть файл!";
			cin.get();
	        cin.get();
            return 0;
         }
	 int i=0;
	 while(1) 
	    { 
			in.get(a);
			if (in.eof()) break;
			if(provFile(a)==1) 
				 {   SetConsoleTextAttribute(hStdout, 9);
			          b[i]=1;
					  cout<<b[i];i++;
			     }
			 else if(provFile(a)==0) 
				{ 
					SetConsoleTextAttribute(hStdout, 12);
			          b[i]=0;
					  cout<<b[i];i++;
			    }
			 else{}
			
	    }
	 
	 sort(b, b + i);
	 SetConsoleTextAttribute(hStdout, 15);
	 cout<<endl<<endl<<"Сортируем "<<endl<<endl;
	 for(int k=0;k<i;k++)
	 {
		 if(b[k]==1) 
				 {   SetConsoleTextAttribute(hStdout, 9);
			          cout<<b[k];
			     }
			 else if(b[k]==0) 
				{ 
					SetConsoleTextAttribute(hStdout, 12);
			         cout<<b[k];
			    }
	 }
	 int z=Find(b, i, 1);
	 SetConsoleTextAttribute(hStdout, 12);
	 cout<<endl<<endl<<endl<<"Vowel: "<<z;
	 SetConsoleTextAttribute(hStdout, 9);
	 cout<<" Consonant: "<<i-z<<endl;


   in.close();
	
     cin.get();
	 cin.get();
	 return 0;
}
int provFile(char a)
{ int count;
	if (a=='A'||a=='a') return 0;
	else if (a=='B'||a=='b') return 1;
	else if (a=='C'||a=='c') return 1;
	else if (a=='D'||a=='d') return 1;
	else if (a=='E'||a=='e') return 0;
	else if (a=='F'||a=='f') return 1;
	else if (a=='G'||a=='g') return 1;
	else if (a=='H'||a=='h') return 1;
	else if (a=='I'||a=='i') return 0;
	else if (a=='J'||a=='j') return 1;
	else if (a=='K'||a=='k') return 1;
	else if (a=='L'||a=='l') return 1;
	else if (a=='M'||a=='m') return 1;
	else if (a=='N'||a=='n') return 1;
	else if (a=='O'||a=='o') return 0;
	else if (a=='P'||a=='p') return 1;
	else if (a=='Q'||a=='q') return 1;
	else if (a=='R'||a=='r') return 1;
	else if (a=='S'||a=='s') return 1;
	else if (a=='T'||a=='t') return 1;
	else if (a=='V'||a=='v') return 1;
	else if (a=='W'||a=='w') return 1;
	else if (a=='U'||a=='u') return 0;
	else if (a=='X'||a=='x') return 1;
	else if (a=='Y'||a=='y') return 1;
	else if (a=='Z'||a=='z') return 1;
	
	
	
}
int Find(int *a, int r, int x)
{int l=0;
while(r - l >1)
    //пока результат не станет однозначным
    {
        int mid = l+(r - l) / 2;
        //делим отрезок [l,r] пополам
        if(a[mid]<x)
        //првоеряем где находимся
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    
    
    for(int i = l; i <= r; i++)
        if(a[i]==x)
            return i;
    return 0;// не нашли такого элемента

}


