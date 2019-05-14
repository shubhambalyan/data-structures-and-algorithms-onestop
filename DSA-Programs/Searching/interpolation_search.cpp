// Interpolaation Search

#include<iostream.h>
#include<conio.h>

 int interpolation_search(int arr[],int num,int item)
 {
     int low=0,high=num-1,mid;
     while(arr[low]<item&&arr[high]>=item)
     {
           mid=low+(high-low)*(item-arr[low])/(arr[high]-arr[low]);
           if(arr[mid]<item)
              low=mid+1;
           else if(arr[mid]>item)
              high=mid-1;
           else
              return mid;
     }
     if(arr[low]=item)
        return low;
     else
        return -1;
 } 

 int main()
 {
     int arr[30];
     int num,item;
     cout<<"\nEnter the no. of elements in the array: ";
     cin>>num;
     cout<<"\nEnter the elements in sorted way: \n";
     for(int i=0;i<num;i++)
     {
             cin>>arr[i];
     }
     cout<<"\nEnter the element to be searched: ";
     cin>>item;
     int accept=interpolation_search(arr,num,item);
     if(accept==-1)
        cout<<"\nItem not found";
     else
        cout<<"Item found at position: "<<accept+1;
     getch();
     return 0;
 }
