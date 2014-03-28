#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <fstream>
int provFile(char);
int Find (int b[100], int, int, int );
void quick(int b[100] , int , int );
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
			 if(a!=' ')
			 { b[j]=provFile(a);j++;}
			 
			 else
				 {	quick(b,0,j-1);
					for(int i=0;i<j;i++)
		        	glas+=Find(b,i,j,0);
			        for(int i=0;i<j;i++)
			        soglas+=Find(b,i,j,1);
					j=0;
			     }
            
			 out<<a;
			 
	    }
	// sort(b, b + j);
	 cout<<"Гласные: "<<glas<<" Согласные: "<<soglas<<endl;
	 in.close();
     out.close();
	 cin.get();
	 cin.get();
	 return 0;
}
int provFile(char a)
{ int count;
	if (a=='A'||a=='a') count=0;
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
int Find(int b[100], int k, int l, int x)
{   int c=0;
    int first = k;
    int last = l;
   /* if (l == 0) 
	   {
		cout<<"Слово слишком коротко ";
       }
	else if (b[0] > x) 
	   {
       cout<<"Не найдено";
       } 
	*/
 
    while (first < last)
	    {
       
          int mid = first + (last - first) / 2;
          if (x <= b[mid])
            last = mid;
          else
            first = mid + 1;
        }
 
    
    if (b[last] == x) 
        c++;
    
	return c;
}
void quick(int a[100] , int l, int r)
	     {
		   int x = a[l + (r - l) / 2];
		   //запись эквивалентна (l+r)/2,
		   //но не вызввает переполнения на больших данных
		   int i = l;
		   int j = r;
		   //код в while обычно выносят в процедуру particle
		   while(i <= j)
		      { 
				  
		          while(a[i] < x) {i++;}
		          while(a[j] > x) {j--;}

		          if(i <= j)
		             {  
						 swap(a[i], a[j]);
		                 if(a[i]<a[j])
		                 i++;
		                 j--;
		               }
		       }
		   if (i<r)
			   quick(a,i, r);

		   if (l<j)
			   quick(a,l,j);

		  
	   }