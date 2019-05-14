// Linear Search.
 
 #include<iostream.h>
 #include<conio.h>
 
 int linearSearch(int arr[],int num,int item)
 {
     for(int i=0;i<num;i++)
     {
             if(arr[i]==item)
             {
                  cout<<"\nItem Found...";
                  return i;
             }
     }
     cout<<"\nItem not found...";
 }
 
 int main()
 {
     int arr[30];
     int num,item;
     cout<<"\nEnter the no. of elements in the array: ";
     cin>>num;
     cout<<"\nEnter the elements: \n";
     for(int i=0;i<num;i++)
     {
             cin>>arr[i];
     }
     cout<<"\nEnter the element to be searched: ";
     cin>>item;
     int accept=linearSearch(arr,num,item);
     cout<<"at position: "<<accept+1;
     getch();
     return 0;
 }
     
