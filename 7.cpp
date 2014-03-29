#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <fstream>
int provFile(char);
int Find (int b[100], int, int );
int Find1 (int b[100], int, int );
using namespace std;
int main()
{  
	fstream in;
    ofstream out;
	int b[100];
	char a;
	int glas=0,soglas=0;
	setlocale(LC_ALL,"Rus");
	in.open("input.txt");
    out.open("output.txt");

      	  if (in.fail())
	     {
            cout<<"Не удалось открыть файл!";
			cin.get();
	        cin.get();
            return 0;
         }
		  int j=0;
     while(1) 
	    {    
             in.get(a);
			 if (in.eof()) break;
			 if(a!=32||in.eof())
			 {b[j]=provFile(a);j++;}
			 else 
			 { sort(b, b + j);
			 if(Find(b, j, 0)==1)
			 out<<"(V:YES)";
			 if(Find1(b, j, 1)==1)
			 out<<"(S:YES)";
			 j=0;}
			 if(provFile(a)==0)glas++;
 			 else if(provFile(a)==1)soglas++;
 			 out<<a;
            
			 
	    }

	// sort(b, b + j);
	 out<<endl<<endl<<endl<<"Vowel: "<<glas<<" Consonant: "<<soglas<<endl;
	 in.close();
     out.close();
	 cin.get();
	 cin.get();
	 return 0;
}
int provFile(char a)
{ int count;
	if (a=='A'||a=='a') count=0;
	else if (a=='B'||a=='b') count=1;
	else if (a=='C'||a=='c') count=1;
	else if (a=='D'||a=='d') count=1;
	else if (a=='E'||a=='e') count=0;
	else if (a=='F'||a=='f') count=1;
	else if (a=='G'||a=='g') count=1;
	else if (a=='H'||a=='h') count=1;
	else if (a=='I'||a=='i') count=0;
	else if (a=='J'||a=='j') count=1;
	else if (a=='K'||a=='k') count=1;
	else if (a=='L'||a=='l') count=1;
	else if (a=='M'||a=='m') count=1;
	else if (a=='N'||a=='n') count=1;
	else if (a=='O'||a=='o') count=0;
	else if (a=='P'||a=='p') count=1;
	else if (a=='Q'||a=='q') count=1;
	else if (a=='R'||a=='r') count=1;
	else if (a=='S'||a=='s') count=1;
	else if (a=='T'||a=='t') count=1;
	else if (a=='V'||a=='v') count=1;
	else if (a=='W'||a=='w') count=1;
	else if (a=='U'||a=='u') count=0;
	else if (a=='X'||a=='x') count=1;
	else if (a=='Y'||a=='y') count=1;
	else if (a=='Z'||a=='z') count=1;
	else count=3;
	return count;
	
}
int Find(int a[100], int r, int x)
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
    
    //[l,r]
    for(int i = l; i <= r; i++)
        if(a[i]==x)
            return 1;
    return 0;// не нашли такого элемента

}
int Find1 (int b[100], int j, int x )
{  for(int i=0;i<j;i++)
	if(b[i]==x) return 1;
return 0;
}

	


