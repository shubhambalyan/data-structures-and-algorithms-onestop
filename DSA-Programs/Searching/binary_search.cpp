#include<stdio.h>
#include<conio.h>
int main()
{
int i,j,size,temp,n,low,high,mid,flag=0;
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
for(j=i+1;j<size;j++)
{
                    if(a[i]>a[j])
                    {
                                temp=a[i];
                                a[i]=a[j];
                                a[j]=temp;
                                }
                                }
                                }
printf("the sorting array \n");
for(i=0;i<size;i++)
{
                   printf("%d\n",a[i]);
                   
                   }
 printf("Enter the element to be searched");
 scanf("%d",&n);
 low=0,high=size-1;
 while(high!=low)
 {
                 mid=(high+low)/2;
if(a[mid]>n)

high=mid-1;

else  if(a[mid]<n)

low=mid+1;
     
else if(a[mid]==n)

{
printf("element is searched %d found in %d position",n,mid+1);
flag=1;        
break;
}
}
if(flag==0)
{
          printf("Element %d is not found",n);
          }
  
          getch();
          }
                
                                                    
