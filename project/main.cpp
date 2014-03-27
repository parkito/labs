#include<iostream>
#include <ctime>
#include <iomanip>
#include <stdlib.h>
using namespace std;
int A,B;
void upd(int **obs, int  **Arr);
void razbit(int *temp,int **Arr,int **obs);
void display(int **Arr);
void puz(int *temp);
void otbor(int *temp);
void vstav(int *temp);
void Shell(int *temp);
void quick(int *temp, int i, int j);
void table();
int m, k;
int SravPuz=0, NazPuz=0;
int SravOtbor=0, NazOtbor=0;
int SravVstav=0, NazVstav=0;
int SravShell=0, NazShell=0;
int SravQuick=0, NazQuick=0;
int main()
{ 
	  srand(time(NULL));
	  setlocale(LC_ALL,"Rus");
	  char pr;
	  do
	  {
	  cout<<"������� A --> ";
	  cin>>A;
	  cout<<"������� B --> ";
	  cin>>B;
	  if(A<0||B<0||A%1!=0||B%1!=0)
	  {cout<<"������!"<<endl;
	  cin.get();
	  cin.get();
	  exit(0);
	  }
	  int *temp=new int[B]; //������ ��� ���������� ������� ������
	  int **Arr = new int* [A]; //���������� ������
	  for (int i = 0; i < A; i++)
	  Arr[i] = new int [B];
	  int **obs = new int* [A]; //����������� ������
	  for (int i = 0; i < A; i++)
	  obs[i] = new int [B];

	  //�������������� ������
	  int min=-100,max=100;

	  for(int i=0;i<A;i++)
		 for(int j=0;j<B;j++)
			obs[i][j]=min + rand() % (max - min); 
	  upd(obs, Arr);
	  cout<<endl<<"����������������� ������� "<<endl<<endl;
	  //������� ��� ��������� ������� �� �������
	  razbit(temp,Arr,obs);
	  table();
	for (int i = 0; i < A; i++)
	delete [] obs[i];
delete [] obs;
for (int i = 0; i < A; i++)
	delete [] Arr[i];
delete [] Arr;
 SravPuz=0, NazPuz=0;
 SravOtbor=0, NazOtbor=0;
 SravVstav=0, NazVstav=0;
 SravShell=0, NazShell=0;
 SravQuick=0, NazQuick=0;
cout<<"��� ��� ? (y/n) ";
cin>>pr;
	  }while(pr=='Y'||pr=='y');
	  cin.get();
	  cin.get();
	  return 0;
}

void upd(int **obs, int  **Arr)
{     for(int i=0;i<A;i++)
		 for(int j=0;j<B;j++)
			 Arr[i][j]=obs[i][j];
}

void razbit(int *temp,int **Arr,int **obs)
{    
	   for(int count = 0;count<=5;count++)
	{  
	   //������� ��� ���������� �������
	   display(Arr);cout<<endl<<endl<<endl;
	   upd(obs, Arr);
			   if (count == 0) cout<<"���������� ��������� "<<endl<<endl;
			   else if (count == 1) cout<<"���������� ��������� "<<endl<<endl;
			   else if (count == 2) cout<<"���������� ������� "<<endl<<endl;
			   else if (count == 3) cout<<"���������� ����� "<<endl<<endl;
			   else if (count == 4) cout<<"���������� ������� "<<endl<<endl;
	   for(int j=0;j<B;j++)
		 {
			for(int i=0;i<A;i++)
			  {
				 temp[i]=Arr[i][j];

			  }
			   if (count == 0)puz(temp);
			   else if (count == 1) otbor(temp); 
			   else if (count == 2) vstav(temp); 
			   else if (count == 3) Shell(temp);
			   else if (count == 4) quick(temp,0,A-1);
			for(int i=0;i<A;i++)
			  {
				 Arr[i][j]=temp[i];

			  }
			
		  }
	   }
}


void puz(int *temp)
{
	int tmp, i, j;
 
	for(i = 0; i < A - 1 ; ++i) // i - ����� �������
	{
		for(j = 0; j < A - 1 - i ; ++j) // ���������� ���� �������
		{ if(j+1>j)SravPuz++;
			if (temp[j + 1] < temp[j])
			{NazPuz++;
				tmp = temp[j + 1];
				temp[j + 1] = temp[j];
				temp[j] = tmp;
			}
		}
	}//if(NazPuz==0&&A>1)SravPuz--;
}

void otbor(int* temp) //����� �����������
{
	int tmp, i, j, pos;
	for(i = 0; i < A; ++i) // i - ����� �������� ����
	{ 
		pos = i; 
		tmp = temp[i];
		for(j = i + 1; j < A; ++j) // ���� ������ ����������� ��������
		{SravOtbor++;
			if (temp[j] < tmp) 
			{
			   pos = j; 
			   tmp = temp[j]; 
			}
		}
		if(temp[pos]!=temp[i])
		NazOtbor++;
		temp[pos] = temp[i]; 
		temp[i] = tmp; // ������ ������� ���������� � a[i]
	}
}

void vstav(int* temp)// ���������� ��� � ������������ � ����������� � ������ ����������
{int temp1,key;
for (int i=0; i<A-1; i++)
{
key=i+1;
temp1=temp[key];
for (int j=i+1; j>0; j--)
{SravVstav++;
if (temp1<temp[j-1])
{NazVstav++;
temp[j]=temp[j-1];
key=j-1;
}
}
temp[key]=temp1;
}
}
void Shell(int *temp)
{ int step = A / 2;//�������������� ���.
	while (step > 0)//���� ��� �� 0
	{
	  for (int i = 0; i < (A - step); i++)
				{
					int j = i;
					//����� ���� ������� � i-�� ��������
					SravShell++; 
					while (j >= 0 && temp[j] > temp[j + step])
					//���� �� ������ � ������ �������
					//� ���� ��������������� ������� ������
					//��� ������� ����������� �� ���������� ����
					{if(j!=i)SravShell++;
						//������ �� �������
						NazShell++;
						int tem = temp[j];
						temp[j] = temp[j + step];
						temp[j + step] = tem;
						j--; 
					}
				}
				step = step / 2;//��������� ���
			}  }
void quick(int *a , int l, int r)
{
	int x = a[l + (r - l) / 2];
	//������ ������������ (l+r)/2,
	//�� �� �������� ������������ �� ������� ������
	int i = l;
	int j = r;
	//��� � while ������ ������� � ��������� particle
	while(i <= j)
	{   //SravQuick++;
		while(a[i] < x) {SravQuick++;i++;}
		while(a[j] > x) {SravQuick++;j--;}

		if(i <= j)
		{   swap(a[i], a[j]);
			if(a[i]<a[j])NazQuick++;
			i++;
			j--;
		}
	}
	if (i<r)
				quick(a,i, r);

	if (l<j)
		quick(a,l,j);

	if(A<2)SravQuick=0;
}

void display(int **Arr)
{
  for(int i=0;i<A;i++)
	{
		for(int j=0;j<B;j++)
		  cout<<setw(5)<<Arr[i][j]<<"  ";
		cout<<endl;
	}
}
void table()
{
printf("|����������| �����������| ����������|\n");
printf("|----------|------------|-----------|\n");
printf("|  ������� | %10i | %10i|\n",SravPuz,NazPuz);
printf("|  ������� | %10i | %10i|\n",SravVstav,NazVstav);
printf("|   �����  | %10i | %10i|\n",SravOtbor,NazOtbor);
printf("|   ����   | %10i | %10i|\n",SravShell,NazShell);
printf("|  ������� | %10i | %10i|\n",SravQuick,NazQuick);
printf("|----------|------------|-----------|\n");
}