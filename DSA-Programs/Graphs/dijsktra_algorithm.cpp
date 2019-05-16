// Dijkstra's Algorithm 
#include<iostream>
using namespace std;
#include<conio.h>
#define infinity 999
 
void dijkstra(int n,int v,int dest,int weight[10][10],int dist[],int path[10])
{
    int u,count,flag[10],min;
    for(int i=1;i<=n;i++)
     {
        flag[i]=0;
        dist[i]=weight[v][i];
        if(weight[v][i]==0)
           path[i]=1;
        else
           path[i]=v;
     }
    count=2;
    while(count<=n)
     {
        min=99;
        for(int w=1;w<=n;w++)
             if(dist[w]<min && !flag[w])
               {
                   min=dist[w];
                   u=w;
               }
             flag[u]=1;
        for(int w=1;w<=n;w++)
             if((dist[u]+weight[u][w]<dist[w]) && !flag[w])
                  {
					   dist[w]=dist[u]+weight[u][w];
					   path[w]=u;
				  }
        count++;
     }
} 
int main()
{
     int n,v,weight[10][10],dist[10],path[10];
     cout<<"\nEnter the number of nodes: ";
     cin>>n;
     cout<<"\nEnter the adjacency matrix: \n";
     for(int i=1;i<=n;i++)
       for(int j=1;j<=n;j++)
        {
           cin>>weight[i][j];
             if(weight[i][j]==0)
             {
               weight[i][j]=infinity;
               }
        }
     cout<<"\nEnter the source vertex:";
     cin>>v;
     int dest;
     cout<<"\nEnter the destination: ";
     cin>>dest;
     dijkstra(n,v,dest,weight,dist,path);
     cout<<"\nShortest path:\n";
     int j=1,c=1,tmp,temp[10],f=0;
     while(dest!=v)
        {
             tmp=path[dest];
             temp[j]=tmp;
             dest=tmp;
             j++;
             c++;
        }
     for(j=c;j>0;j--)
      { 
             cout<<temp[j]<<"-->";
             if(temp[j]==dest)
             f=1;
      }
     if(f!=1)
       cout<<dest;
        //printf("v%d",z); 
             cout<<endl;

     getch();
     return 0;
}
