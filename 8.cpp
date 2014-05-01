#include <iostream>
#include <windows.h>
#include <algorithm>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <fstream>
using namespace std;
char name[15], SecondName[15],mobile[10],Data;
int Hash(char);
int main()
{   
	setlocale(LC_ALL, "Rus");
    fstream read,read1;
    ofstream save;
	ofstream in;
	fstream in1;
	ofstream hashin;
	read.open("Database.txt");
	save.open("HashDatabase.txt");
	in.open("In.txt");
	hashin.open("HashIn.txt");
	if (read.fail()||save.fail())
	     {
            
			cout<<"Не удалось открыть файл!";
			cin.get();
	        cin.get();
            return 0;
         }
	
	int razdel=0;
	while(1)
	{       
		     if (read.eof()) break;
		     read.get(Data);			 
			 if(razdel<=3)
			 {
			    if(Data==';')
			    {   
				   razdel++;
				   save<<';';
			    }

			    else save<<Hash(Data);
			 	   

			 }

			 else
			 {
				 razdel=0;
				 save<<endl;
			 }
	}

	read.close();
	save.close();
	
	cout<<"Введите имя --> ";
	cin.getline(name,15);
	in<<name<<';';
	cout<<"Введите фамилию --> ";
	cin.getline(SecondName,15);
	in<<SecondName<<';';
	cout<<"Введите телефон --> ";
	cin.getline(mobile,10);
	in<<mobile<<';';
	razdel=0;
	in.close();
	in1.open("In.txt");
	while(1)
	{        if (in1.eof()) break;
		     in1.get(Data);
			 if(razdel<4)
			 {
			    
			    hashin<<Hash(Data);
			 
			   if(Data==';')
			    {   
				   razdel++;
				   hashin<<';';
			    }

			 }

			 if(razdel==4)
			 {
				 razdel=0;
				 hashin<<endl;
			 }
	}
	in1.close();
	hashin.close();

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    read.open("HashDatabase.txt");
	read1.open("HashIn.txt");
	int i=0,j=0,coutS=0,coutP=0,simbolsD=0,simbolsI=0,provSimbols=0;
	char provD, provI,arrD[50],arrI[50];
	while(1)
	{       
		 if(read1.eof())break;
	     read1.get(provI);
		 if(provI!=';')
		  {
		    arrI[i]=provI;
		    i++;
			simbolsI++;
		  }


	}
	while(1)
	{   if(read.eof())break;    
		while(coutS<4)
		 {
		     read.get(provD);
		     if(provD==';')
			    coutS++;
		     else
		       {
	             arrD[j]=provD;
			     simbolsD++;
		         j++;
		       }
		  }
		j=0;
		 
		  if(simbolsI==simbolsD)
		    {
			    for(int k=0;k<simbolsI;k++)
					if(arrI[k]==arrD[k])
						provSimbols++;
				if(provSimbols==simbolsI)
				{coutP++;cout<<coutP;}
		    }
		  coutS=0,simbolsD=0,provSimbols=0;
	}
	read.close();
	read1.close();
	//cout<<coutP;
	
	cin.get();
	cin.get();
	return 0;
}
int Hash(char a)
{
	if (a%2==0)
		return 0;
	else
		return 1;
	
}