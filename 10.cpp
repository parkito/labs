#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
#include "iostream"
#include "windows.h"
#include <string>
#include <ctype.h>
#include <fstream>
using namespace std;
string EnterText, AddText, AddTextFromFile;
int SizeText, TimeLifeOfWhile=0, choose;

int main()
{   
    setlocale(LC_ALL, "Rus");
	cout<<"Введите свой текст --> ";
	getline(cin,EnterText);
	cout<<EnterText;
	
	while(TimeLifeOfWhile==0)
		{
		cout<<endl<<"Операции "<<endl<<"1> - Добавление текста"<<endl<<"2> - Замена строчных букв на прописные"<<endl<<"3> - Добавление из файла"<<endl<<"4> - Выход из программы"<<endl<<"-->";
    SizeText=EnterText.length();	
	cin>>choose;
	if(choose<1||choose>4)
	{
		cout<<"Ошибка !!! ";
	    cin.get();
	    cin.get();
		exit(0);
	}
	else if (choose==1)
	{
	cout<<"Введите текст для добавления --> ";
	cin.ignore();
    getline(cin,AddText);
	EnterText=EnterText+AddText;
	cout<<endl<<"Результат"<<endl<<EnterText;

	}
	else if (choose==2)
	{   
		int j=0;
		while(j+1<SizeText)
		{
		if(isspace(EnterText[j])==8&&(EnterText[j+1]>=65&&EnterText[j+1]<=90)&&isalpha(EnterText[j+1]))
		{ EnterText[j+1] = EnterText[j+1] + 32; cout<<isspace(EnterText[j]);}
		if((EnterText[0]>=65&&EnterText[0]<=90))
			EnterText[0] = EnterText[0] + 32; 
		    
			j++;
		}
		
	
		cout<<endl<<"Результат"<<endl<<EnterText;
	}
	else if (choose==3)
	{
		ifstream in;
		in.open("Text.txt");
		if (in.fail())
	     {            
			cout<<"Ошибка. Файл не найден! ";
			cin.get();
	        cin.get();
            exit(0);
         }
		in>>AddTextFromFile;
		EnterText=EnterText+AddTextFromFile;
		cout<<endl<<"Результат"<<endl<<EnterText;
		in.close();
	}
	else if (choose==4)
	{
	  cin.get();
	  cin.get();
	  exit(0);
	}
	}
	cin.get();
	cin.get();
	return 0;
	}