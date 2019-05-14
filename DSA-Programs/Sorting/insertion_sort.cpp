#include<stdio.h>
#include<conio.h>
int main()
{
int i,j,m,size,temp;
int a[30];
printf("enter the size ");
scanf("%d",&size);
printf("Enter the array elements ");
for(i=0;i<size;i++)
{
    scanf("%d",&a[i]);
}
for(j=1;j<=size-1;j++)
 {
     if(a[j]<a[j-1])  
       {
               i=j-1;
               m=a[j];               
               while(i>=0 && m<a[i])
               {
                  a[i+1]=a[i];
                  i=i-1;
               }
               a[i+1]=m;
       }
 }
printf("the sorting array \n");
for(i=0;i<size;i++)
{
                   printf("%d\n",a[i]);
                   
}
   getch();
}                                   
