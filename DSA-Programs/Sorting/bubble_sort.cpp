#include<stdio.h>
#include<conio.h>
int main()
{
int i,j,m,size,temp;
int a[30];
printf("enter the size");
scanf("%d",&size);
printf("Enter the array elements");
for(i=0;i<size;i++)
{
scanf("%d",&a[i]);
}
for(i=0;i<size-1;i++)

{
for(j=0;j<size-i-1;j++)
if(a[j]>a[j+1])
 {
             temp=a[j];
             a[j]=a[j+1];
             a[j+1]=temp;
             }
             }              
printf("the sorting array \n");
for(i=0;i<size;i++)
{
                   printf("%d\n",a[i]);
                   
                   }
                   getch();
                   }                                   
