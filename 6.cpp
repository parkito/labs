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
void quick(int *temp, int , int );
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
	  
	  cout<<"Введите A --> ";
	  cin>>A;
	  cout<<"Введите B --> ";
	  cin>>B;
	  if(A<0||B<0||A%1!=0||B%1!=0)
	     {
		    cout<<"Ошибка!"<<endl;
	        cin.get();
	        cin.get();
	        exit(0);
	     }
	  int *temp=new int[A]; //массив для сортировки каждого столба
	  int **Arr = new int* [A]; //изменяемый массив
	  for (int i = 0; i < A; i++)
	     Arr[i] = new int [B];
	  int **obs = new int* [A]; //константный массив
	  for (int i = 0; i < A; i++)
	     obs[i] = new int [B];
	  //Инициализируем массив
	  int min=-100,max=100;
	  for(int i=0;i<A;i++)
		 for(int j=0;j<B;j++)
	  obs[i][j]=1;//min + rand() % (max - min); 
	  upd(obs, Arr);
	  cout<<endl<<"Неотсортированная матрица "<<endl<<endl;
	  //Функция для разбиения массива на столбцы
	  razbit(temp,Arr,obs);
	  table();
	  for (int i = 0; i < A; i++)
	     delete [] obs[i];
      delete [] obs;
      for (int i = 0; i < A; i++)
	     delete [] Arr[i];
      delete [] Arr;
      cin.get();
	  cin.get();
	  return 0;
}

      void upd(int **obs, int  **Arr)
         {     
		    for(int i=0;i<A;i++)
		       for(int j=0;j<B;j++)
			      Arr[i][j]=obs[i][j];
    
         }

      void razbit(int *temp,int **Arr,int **obs)
         {    
	        for(int count = 0;count<5;count++)
	           {  
	               //Функция для обновления массива
	              display(Arr);
				  cout<<endl<<endl<<endl;
	              upd(obs, Arr);
			      if (count == 0) cout<<"Сортировка пузырьком "<<endl<<endl;
			      else if (count == 1) cout<<"Сортировка вставками "<<endl<<endl;
			      else if (count == 2) cout<<"Сортировка выбором "<<endl<<endl;
			      else if (count == 3) cout<<"Сортировка Шелла "<<endl<<endl;
			      else if (count == 4) cout<<"Сортировка быстрая "<<endl<<endl;
	              for(int j=0;j<B;j++)
		             {
			            for(int i=0;i<A;i++)
			               {
				              temp[i]=Arr[i][j];

			               }
			     if (count == 0) puz(temp);
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
             for(i = 0; i < A - 1 ; ++i) // i - номер прохода
	            {
		           for(j = 0; j < A - 1 - i ; ++j) // внутренний цикл прохода
		              { 
					     if(j+1>j)SravPuz++;
			             if (temp[j + 1] < temp[j])
		                	{
								NazPuz++;
				                tmp = temp[j + 1];
				                temp[j + 1] = temp[j];
				                temp[j] = tmp;
			                }
		                }
	              }
}

       void otbor(int* temp) //выбор наименьшего
          {
	         int tmp, i, j, pos;
	         for(i = 0; i < A; ++i) // i - номер текущего шага
	            { 
		           pos = i; 
		           tmp = temp[i];
		           for(j = i + 1; j < A; ++j) // цикл выбора наименьшего элемента
		           { 
					   SravOtbor++;
			           if (temp[j] < tmp) 
			              {
			                 pos = j; 
			                 tmp = temp[j]; 
			               }
		            }
		      if(temp[pos]!=temp[i])
		      NazOtbor++;
		      temp[pos] = temp[i]; 
		      temp[i] = tmp; // меняем местами наименьший с a[i]
	             }
              }

	   void vstav(int* temp)// выбирается кей и сравнивается с предыдущими с каждым предыдущим
	   {
		   int temp1,key;
	       for (int i=0; i<A-1; i++)
	          {
		         key=i+1;
		         temp1=temp[key];
		         for (int j=i+1; j>0; j--)
		           {
					  SravVstav++;
		              if (temp1<temp[j-1])
		                { 
			               NazVstav++;
		                   temp[j]=temp[j-1];
		                    key=j-1;
		                 }
		           }
		           temp[key]=temp1;
	            }
	   }
	   void Shell(int *temp)
	     { 
			int step = A / 2;//инициализируем шаг.
	        while (step > 0)//пока шаг не 0
	          {
		         for (int i = 0; i < (A - step); i++)
		            {
			           int j = i;
			           //будем идти начиная с i-го элемента
			           SravShell++; 
			           while (j >= 0 && temp[j] > temp[j + step])
				       //пока не пришли к началу массива
				       //и пока рассматриваемый элемент больше
				       //чем элемент находящийся на расстоянии шага
			              {
							  if(j!=i)SravShell++;
			                  //меняем их местами
			                   NazShell++;
			                   int tem = temp[j];
			                    temp[j] = temp[j + step];
			                     temp[j + step] = tem;
			                     j--; 
			               }
		             }
		                step = step / 2;//уменьшаем шаг
	           } 
	   }
	   void quick(int *a , int l, int r)
	     {
		   int x = a[l + (r - l) / 2];
		   //запись эквивалентна (l+r)/2,
		   //но не вызввает переполнения на больших данных
		   int i = l;
		   int j = r;
		   //код в while обычно выносят в процедуру particle
		   while(i <= j)
		      { 
				  SravQuick++;
		          while(a[i] < x) {SravQuick++;i++;}
		          while(a[j] > x) {SravQuick++;j--;}

		          if(i <= j)
		             {  
						 swap(a[i], a[j]);
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
		   printf("|Сортировка| Сравнивания| Присвоения|\n");
		   printf("|----------|------------|-----------|\n");
		   printf("|  Пузырек | %10i | %10i|\n",SravPuz,NazPuz);
		   printf("|  Вставка | %10i | %10i|\n",SravVstav,NazVstav);
		   printf("|   Выбор  | %10i | %10i|\n",SravOtbor,NazOtbor);
		   printf("|   Шелл   | %10i | %10i|\n",SravShell,NazShell);
		   printf("|  Быстрая | %10i | %10i|\n",SravQuick,NazQuick);
		   printf("|----------|------------|-----------|\n");
	   }
