// Program to perform quick sort

 #include<iostream>
 using namespace std;
 #include<conio.h>
 
 int partition(int a[], int p, int r);
 
 void swap(int&a,int&b)
 {
      int temp;
      temp=a;
      a=b;
      b=temp;
}
 
 void quicksort(int a[], int p, int r)
 {
      int q;
      if(p<r)
        {
             q=partition(a,p,r);
             quicksort(a,p,q-1);
             quicksort(a,q+1,r);
         }
}

int partition(int a[], int p, int r)
{
    int x,i,j;
    x=a[p];
    i=p-1;
    j=r+1;
    while(true)
    {
               do
                 j=j-1;
               while((a[j]<=x)&&(j>=p));
               do
                 i=i+1;
               while((a[i]>x)&&(i<=r));
       if(i<j)
        swap(a[i],a[j]);
       else
         return j;
}
swap(a[j],a[i]);

}

int main()
{
    int a[25],num,p=0,r;
    cout<<"\nEnter the number of elements in the list: ";
    cin>>num;
    cout<<"\nEnter the elements: ";
    cout<<endl;
    for(int i=0;i<num;i++)
       cin>>a[i];
    r=num-1;
    quicksort(a,p,r);
    cout<<"\nThe sorted elements are: \n";
    for(int i=0;i<num;i++)
      cout<<a[i]<<"...";
    getch();
    return 0;
}
    

