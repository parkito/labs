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
    fstream read;
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
			 
			 if(razdel<4)
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
				 save<<endl<<endl;
			 }
	}
	
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
	{        
		     in1.get(Data);
			 if(razdel<4)
			 {
			    if (in1.eof()) break;
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