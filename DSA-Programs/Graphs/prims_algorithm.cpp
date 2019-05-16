//Prim's Algorithm
#include<iostream>
using namespace std;
#include<conio.h>
int a,b,u,v,n,ne=1;
int visited[10]={0},mincost=0,cost[10][10];
int main()
{
 int minimum=999;
 cout<<"\n Enter the number of nodes:";
 cin>>n;
 cout<<"\n Enter the adjacency matrix:\n";
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
  {
    cin>>cost[i][j];
   if(cost[i][j]==0)
    cost[i][j]=999;
  }
 visited[1]=1;

 while(ne<n)
 {
  for(int i=1;i<=n;i++)
   for(int j=1;j<=n;j++)
    if(cost[i][j]<minimum)
     if(visited[i]!=0)
     {
      minimum=cost[i][j];
      a=u=i;
      b=v=j;
     }
  if(visited[u]==0 || visited[v]==0)
  {
   cout<<"\n Edge "<<ne++<<":("<<a<<" "<<b<<") cost: "<<minimum;
   mincost+=minimum;
   visited[b]=1;
  }
  cost[a][b]=cost[b][a]=999;
 }
 cout<<"\n Minimun cost= "<<mincost;
 getch();
 return 0; 
}
