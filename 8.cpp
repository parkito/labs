#include <iostream>
#include <windows.h>
#include <algorithm>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <fstream>
using namespace std;
char name[40], SecondName[40],mobile[40],Data;
int Hash(char);
int main()
{   
	setlocale(LC_ALL, "Rus");
    fstream read,read1,read2,read3,read4;
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
			 if(razdel<3)
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
				 //save<<endl;
			 }
	}
read.close();
	save.close();
	
	cout<<"Введите имя --> ";
	cin.getline(name,40);
	in<<name<<';';
	cout<<"Введите фамилию --> ";
	cin.getline(SecondName,40);
	in<<SecondName<<';';
	cout<<"Введите телефон --> ";
	cin.getline(mobile,40);
	in<<mobile<<';';
	in.close();
	in1.open("In.txt");
	razdel=0;
	while(1)
	{       
		     if (in1.eof()) break;
		     in1.get(Data);			 
			 if(razdel<3)
			 {
			    if(Data==';')
			    {   
				   razdel++;
				   hashin<<';';
			    }

			    else hashin<<Hash(Data);
			 	   

			 }

			 else
			 {
				 razdel=0;
				// hashin<<endl;
			 }
	}
	in1.close();
	hashin.close();
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	read2.open("HashDatabase.txt");
	read1.open("HashIn.txt");
	int i=0,j=0,coutS=0,coutP=0,simbolsD=0,simbolsI=0,provSimbols=0;
	char provD, provI,arrD[120],arrI[120];
	while(1)
	{       
		 if(read1.eof())break;
	     read1.get(provI);
		 if(provI!=';'&&provI!=9)
		  {
		    arrI[i]=provI;
		    i++;
			simbolsI++;
		  }


	}
	while(1)
	{   if(read2.eof())break;    
		while(coutS<3)
		 {
		     read2.get(provD);
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
		coutS=0;
		 
		  if(simbolsI==simbolsD)
		    {
			    for(int k=0;k<simbolsI;k++)
					if(arrI[k]==arrD[k])
						provSimbols++;
				if(provSimbols==simbolsI)
				{coutP++;}
		    }
		  coutS=0,simbolsD=0,provSimbols=0;
	}
	read2.close();
	read1.close();	
	cout<<"Совпадений по хешу "<<coutP<<endl;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	read3.open("Database.txt");
	read4.open("In.txt");
	 i=0,j=0,coutS=0,coutP=0,simbolsD=0,simbolsI=0,provSimbols=0;
	
	while(1)
	{       
		 if(read4.eof())break;
	     read4.get(provI);
		 if(provI!=';')
		  {
		    arrI[i]=provI;
		    i++;
			simbolsI++;
		  }


	}
	while(1)
	{   if(read3.eof())break;    
		while(coutS<3)
		 {
		     read3.get(provD);
		     if(provD==';')
			    coutS++;
			 	 else if  (provD==10) {;}
		     else
		       {
	             arrD[j]=provD;
			     simbolsD++;
		         j++;
		       }
		  }
		j=0;
		coutS=0;
		 
		  if(simbolsI==simbolsD)
		    {
			    for(int k=0;k<simbolsI;k++)
					if(arrI[k]==arrD[k])
						provSimbols++;
				if(provSimbols==simbolsI)
				{coutP++;}
		    }
		  coutS=0,simbolsD=0,provSimbols=0;
	}
	read3.close();
	read4.close();	
	cout<<"Точечных совпадений "<<coutP<<endl;

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