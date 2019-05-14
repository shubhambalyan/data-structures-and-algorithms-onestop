#include<stdio.h>
#include<conio.h>
void TOH(int n,char x,char y,char z);
main()
{
 int n;
 printf("nEnter number of plates:");
 scanf("%d",&n);
 TOH(n-1,'A','B','C');
 getch();
}
void TOH(int n,char x,char y,char z)
{
 if(n>0)
 {
  TOH(n-1,x,z,y);
  printf("n%c -> %c",x,y);
  TOH(n-1,z,y,x);
 }
}
