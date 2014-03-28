#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <fstream>
int provFile(char);
using namespace std;
int main()
{   fstream in;
    ofstream out;
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
     while(1) 
	    { 
             in>>a;
			 
cin.get(a);

             if (in.eof()) break;
             if(provFile(a)==0)glas++;
			 else if(provFile(a)==1)soglas++;
			 out<<a;
        }
	 cout<<"Гласные: "<<glas<<" Согласные: "<<soglas<<endl;
	 //cout<<
	 in.close();
     out.close();
	 cin.get();
	 cin.get();
	 return 0;
}
int provFile(char a)
{ int count;
	if (a=='A'||a=='a') count=1;
	else if (a=='B'||a=='b') count=0;
	else if (a=='C'||a=='c') count=1;
	else if (a=='D'||a=='d') count=1;
	else if (a=='E'||a=='e') count=0;
	else if (a=='F'||a=='f') count=1;
	else if (a=='G'||a=='g') count=1;
	else if (a=='H'||a=='H') count=1;
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
	else if (a=='U'||a=='u') count=1;
	else if (a=='X'||a=='x') count=1;
	else if (a=='Y'||a=='y') count=1;
	else if (a=='Z'||a=='z') count=1;
	else count=3;
	return count;
	
}