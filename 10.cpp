#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
#include "iostream"
#include "windows.h"
#include <string>
#include <ctype.h>
using namespace std;
string EnterText, AddText;
int SizeText, TimeLifeOfWhile=0, choose;

int main()
{   
    setlocale(LC_ALL, "Rus");
	cout<<"������� ���� ����� --> ";
	getline(cin,EnterText);
	cout<<EnterText;
	
	while(TimeLifeOfWhile==0)
		{
		cout<<endl<<"�������� "<<endl<<"1> - ���������� ������"<<endl<<"2> - ������ �������� ���� �� ���������"<<endl<<"3> - ���������� �� �����"<<endl<<"4> - ����� �� ���������"<<endl<<"-->";
    SizeText=EnterText.length();	
	cin>>choose;
	if(choose<1||choose>4)
	{
		cout<<"������ !!! ";
	    cin.get();
	    cin.get();
		exit(0);
	}
	else if (choose==1)
	{
	cout<<"������� ����� ��� ���������� --> ";
	cin.ignore();
    getline(cin,AddText);
	EnterText=EnterText+AddText;
	cout<<endl<<"���������"<<endl<<EnterText;

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
		
	
		cout<<endl<<"���������"<<endl<<EnterText;
	}
	else if (choose==3)
	{}
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