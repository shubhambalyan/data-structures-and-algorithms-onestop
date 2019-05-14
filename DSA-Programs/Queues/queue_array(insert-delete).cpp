// Program to insert and delete elements from a queue using array.

 #include<iostream.h>
 #include<conio.h>
 const int size=50;
 int queue[size],front=-1,rear=-1;
 
 void insert(int queue[], int item)
 {
      if(rear==size-1)
        cout<<"\nOVERFLOW!!!";
      else if(rear==-1)
       {  front=rear=0;
          queue[rear]=item;  }
      else
         {   rear++;
             queue[rear]=item;
             }
}

 int remove(int queue[])
  {
       int temp;
       if(front==-1)
          cout<<"\nUNDERFLOW!!!";
       else
         {
              temp=queue[front];
              if(front==rear)
                 front=rear=-1;
              else
                 front++;
         }
       return temp;
}

  void display(int queue[], int front, int rear)
  {
       for(int i=front;i<=rear;i++)
         cout<<queue[i]<<endl;
}

 int main()
 {
      int item,p;
      char ch;
      do
      {
           cout<<"\nEnter the element to be inserted into the queue: ";
           cin>>item;
           insert(queue,item);
           cout<<"\nThe queue contains: \n";
           display(queue,front,rear);
           cout<<"\nDo you want to enter more elements: ";
           cin>>ch;
      }while((ch=='y')||(ch=='Y'));
      
      ch='y';
      cout<<"\nNow the deletion begins: ";
      
      do
      {
           cout<<"\nThe deleted element is: ";
           p=remove(queue);
           cout<<p;
           cout<<"\nThe queue contains: \n";
           display(queue,front,rear);
           cout<<"\nDo you want to delete more elements: ";
           cin>>ch;
      }while((ch=='y')||(ch=='Y'));
      
      getch();
      return 0;
}
       
 
