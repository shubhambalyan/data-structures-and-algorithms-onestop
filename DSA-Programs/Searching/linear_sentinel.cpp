// Linear search in reverse order with sentinel.

 
 #include<iostream.h>
 #include<conio.h>
 
 int sentinel_search(int arr[],int num,int item)
 {
     arr[0]=item;
     while(arr[num]!=item)
     {
           num--;
     }
     if(num==0)
       return -1;
     else
       return num;
 }
 
 int main()
 {
     int arr[30];
     int num,item;
     cout<<"\nEnter the no. of elements in the array: ";
     cin>>num;
     cout<<"\nEnter the elements: \n";
     for(int i=1;i<=num;i++)
     {
             cin>>arr[i];
     }
     cout<<"\nEnter the element to be searched: ";
     cin>>item;
     int accept=sentinel_search(arr,num,item);
     if(accept==-1)
        cout<<"\nItem not found...";
     else
        cout<<"Item found at position: "<<accept;
     getch();
     return 0;
 }
     
