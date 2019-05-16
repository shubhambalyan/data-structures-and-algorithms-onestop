//Warshall Floyd algorithm

#include<iostream>
using namespace std;
#include<conio.h>

int min(int a, int b)
{
    if(a<b)
       return a;
    else
       return b;
}
       

int main()
{
    int a[4][4],p[4][4];
    cout<<"\nIf the highest weight in your graph is<99, take infinity as 99, otherwise as 999";
    cout<<"\nEnter the matrix(enter 99 or 999 for infinity): ";
    for(int i=0;i<4;i++)
      for(int j=0;j<4;j++)
         cin>>a[i][j];
    
    cout<<"\nBuilding path matrix: ";
    for(int i=0;i<4;i++)
      for(int j=0;j<4;j++)
         p[i][j]=a[i][j];
    for(int k=0;k<4;k++)
    {      
     for(int i=0;i<4;i++)
     {
      for(int j=0;j<4;j++)
      {
              p[i][j]=min(p[i][j],(p[i][k]+p[k][j]));
      }
     }
    }
	cout<<"\nPath matrix is: \n";
	for(int i=0;i<4;i++)
	{
      for(int j=0;j<4;j++)
      {
         cout<<p[i][j]<<"   ";
      }
    cout<<"\n";
    }
    getch();
    return 0;
}
    
    
