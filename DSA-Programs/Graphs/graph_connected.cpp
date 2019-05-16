#include<iostream>
using namespace std;
#include<conio.h>

int a[20][20],q[20],visited[20],n,f=0,r=-1;
int reach[20];
void dfs(int v)
{
 reach[v]=1;
 for(int i=1;i<=n;i++)
  if(a[v][i] && !reach[i])
  {
   printf("\n %d->%d",v,i);
   dfs(i);
  }
}

void bfs(int v)
{
 for(int i=1;i<=n;i++)
  if(a[v][i] && !visited[i])
   q[++r]=i;
 if(f<=r)
 {
  visited[q[f]]=1;
  bfs(q[f++]);
 }
}

int main()
{
 int count=0;
 cout<<"\n Enter number of vertices:";
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  reach[i]=0;
  for(int j=1;j<=n;j++)
   a[i][j]=0;
 }
 cout<<"\n Enter the adjacency matrix:\n";
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
   cin>>a[i][j];
 dfs(1);
 for(int i=1;i<=n;i++)
 {
  if(reach[i])
   count++;
 }
 if(count==n)
  cout<<"\n Graph is connected";
 else
  cout<<"\n Graph is not connected";
 cout<<"\n\n\nBFS: ";
 
 int v;
 for(int i=1;i<=n;i++)
 {
  q[i]=0;
  visited[i]=0;
 }
 bfs(1);
 cout<<"\n The node which are reachable are:\n";
 for(int i=1;i<=n;i++)
  if(visited[i])
   cout<<i<<"\t";
  else
   cout<<"\n Bfs is not possible";
 getch();
 return 0;
}
