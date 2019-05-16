//warshall

#include<iostream>
using namespace std;
#include<conio.h>

int main()
{
    int a[4][4],p[4][4];
    
    cout<<"\nEnter the matrix: ";
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
              p[i][j]=p[i][j]|(p[i][k]&p[k][j]);
              }
              }
              }
              cout<<"\nPath matrix is: \n";
              for(int i=0;i<4;i++)
              {
      for(int j=0;j<4;j++)
      {    //if(p[i][j]>0)
              //p[i][j]=1;
         cout<<p[i][j]<<"   ";
      }
      cout<<"\n";
      }
         getch();
         return 0;
         }
    
    
