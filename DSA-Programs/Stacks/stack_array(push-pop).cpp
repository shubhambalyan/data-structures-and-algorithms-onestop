// Program to push and pop in a stack array.

 #include<iostream.h>
 #include<conio.h>
 const int size=50;
 
 void push(int stack[], int&top, int item)
 {
      if(top==size-1)
        cout<<"\nOVERFLOW!!!";
      else
      stack[++top]=item;
 }
 
 void pop(int stack[], int&top)
 {
      if(top==-1)
         cout<<"\nUNDERFLOW!!!";
      else
          top--;
 }
 
 void display(int stack[], int&top)
 {
      int i;
      for(i=top;i>=0;i--)
         cout<<stack[i]<<endl;
 } 
 
 int main()
 {
     int stack[size],item,top=-1;
     char ch;
     do
     {
       cout<<"\nEnter the element for insertion into the stack: ";
       cin>>item;
       push(stack,top,item);
       cout<<"\nThe stack contains: \n";
       display(stack,top);
       cout<<"\nDo you want to add more elements: ";
       cin>>ch;
       }while((ch=='y')||(ch=='Y'));
     
     ch='y';
     
     do
     {
     cout<<"\nNow the deletion begins: ";
     pop(stack,top);
     cout<<"\nThe stack now contains: \n";
     display(stack,top);
     cout<<"\nDo you want to delete more elements: ";
       cin>>ch;
       }while((ch=='y')||(ch=='Y'));
       
      getch();
      return 0;
  }  
       
     
     
