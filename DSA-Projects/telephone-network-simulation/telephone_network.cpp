// Telephone Network using Dijkstra's Algorithm

/* Representation of Network Graph:
 * 1. Vertices represents Switching Station.
 * 2. Edges represents the Transmission lines.
 * 3. Weight of edges represents the BW. */  


#include<iostream>
using namespace std;
#include<conio.h>
#define INFINITY -999
#define MAX 10

// Dijkstra's Algorithm to find the path with highest Bandwidth(BW).

void telephone(int BW[MAX][MAX],int source,int call[MAX],int n)
{
    int p,node,flag[MAX];
    int not_visited=0;
    int visited=1;
    int max;
    
    for(int i=1;i<=n;i++)
     {
        flag[i]=not_visited;                         
        call[i]=BW[source][i];
     }
     
    node=2;
    
    while(node<=n)
     {
        max=0;
        
        // To find the Maximum of the BW, of nodes that have been visited from source vertex.
        for(int j=1;j<=n;j++)
             if(call[j]>max && flag[j]==not_visited)
               {
                   max=call[j];
                   p=j;
               }
               
        flag[p]=visited;     // Initialising the flag of node with highest BW from the source to Zero(0).
        
        for(int j=1;j<=n;j++)
             if((call[p]+BW[p][j]>call[j]) && flag[j]==not_visited)       // To check for other highest BW for the same node.
               {
                   call[j]=call[p]+BW[p][j];
               }
               
        node++;
        
     }
}

int main()
{
     int num,source,dest,BW[MAX][MAX],call[MAX];
     char ch,chg;
     
     cout<<"\n-------------------------------------------------------------------------------";
     cout<<"\n\t\t\t\tTelephone Network";
     cout<<"\n-------------------------------------------------------------------------------";
     
     cout<<"\n\nData Structure Used: Graph";
     cout<<"\n\nAlgorithm Used: Dijkstra's Algorithm";
     cout<<"\n\n\t\t.....This is only valid for Directed Graphs.....";
     
     cout<<"\n\n-------------------------------------------------------------------------------";
     
     do
     {
     cout<<"\nEnter the number of Switching Stations: ";
     cin>>num;
     // Accepting the Adjacency Matrix.
     cout<<"\nEnter the BW(Band width) Adjacency Matrix: \n";
     for(int i=1;i<=num;i++)
          for(int j=1;j<=num;j++)
              {
                  cout<<"\nEnter the BW for line["<<i<<"]["<<j<<"]: ";
                  cin>>BW[i][j];
                  if(BW[i][j]==0)
                      BW[i][j] =INFINITY;
              }
     
     cout<<"\n\n-------------------------------------------------------------------------------";
     
     cout<<"\nBW Adjacency Matrix is as follows: \n";
     for(int i=1;i<=num;i++)
     {
         for(int j=1;j<=num;j++)
         {
             cout<<BW[i][j]<<"\t";
         }
         cout<<"\n";
     }
     
     do
     {
         
     cout<<"\n\n-------------------------------------------------------------------------------";
    
     b:
     // Accepting the Terminals for the Phone Call.
     cout<<"\nEnter the Source Station:";
     cin>>source;
     cout<<"\nEnter the Destination Station: ";
     cin>>dest;
     
     // Check the Validity of the Terminals entered.
     if(source<1 || source>num || dest<1 || dest>num || source==dest)
     {
           cout<<"\nInvalid Stations !!!";
           goto b;
     }
     
     telephone(BW,source,call,num);
     
     cout<<"\n\n-------------------------------------------------------------------------------";
     
     // Displaying the Result(Highest BW from Source to Destination in order to route a Call).
     cout<<"\nRouting Call from "<<source<<" to "<<dest<<"..........\n";
       for(int i=1;i<=num;i++)
          if(i==dest)
             cout<<source<<"-->"<<i<<"\tTotal BW="<<call[i]<<endl;
     
     cout<<"\nDo you wish to continue for the same graph(y/n): ";
     cin>>ch;
     
     }while(ch=='y'||ch=='Y');
     
     cout<<"\nDo you want to go for another graph(y/n): ";
     cin>>chg;
     
     }while(chg=='y'||chg=='Y');
     
     getch();
     return 0;
}
