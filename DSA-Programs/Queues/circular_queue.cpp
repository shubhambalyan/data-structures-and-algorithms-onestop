// Program to perform insertion and deletion in a circular queue using arrays.

 #include<iostream.h>
 #include<conio.h>
 #include<process.h>
 
 const int size=20;
 int queue[size], rear=-1,front=-1;
 
 void insert(int queue[], int x)
 {
      if((front==0 && rear==size-1)||(front==rear+1))
         { cout<<"\nOVERFLOW!!!";  exit(0);  } 
      else if(rear==-1)
          front=rear=0;
      else if(rear==size-1)
          rear=0;
      else
          rear++;
          queue[rear]=x;
 }
 
 void remove(int queue[])
 {
      int temp;
      if(front==-1)
         cout<<"\nUNDERFLOW!!!";
      else
         {
              temp=queue[front];  
              if(front==rear)
                front=rear=-1;
              else if(front==size-1)
                front=0;
              else
                 front++;
                 }
      cout<<"\nThe element deleted is: "<<temp;
 }
 
 void display(int queue[], int front, int rear)
 {
      if(rear>=front)
       {
                     for(int i=front; i<=rear; i++)
                        cout<<queue[i]<<"...";
                        }
      else
       {
                        for(int i=front;i<size;i++)
                        cout<<queue[i]<<"...";
                     for(int i=0;i<=rear;i++)
                        cout<<queue[i]<<"...";
                        }
}
 
 int main()
 {
     int item,choice;
     char ch;
     do
     {
          cout<<"\nThe Menu is as follows: ";
          cout<<"\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\n";
          cout<<"Enter your choice: ";
          cin>>choice;
          switch(choice)
          {
                        case 1: cout<<"\nEnter the element to be inserted: ";
                                cin>>item;
                                insert(queue,item);
                                cout<<"\nNow the queue is: \n";
                                display(queue,front,rear);
                                break;
                        
                        case 2: remove(queue);
                                cout<<"\nNow the queue is: \n";
                                display(queue,front,rear);
                                break;
                        
                        case 3: display(queue,front,rear);
                                break;
                                
                        case 4: exit(0);
                                break;
                                
                        default: cout<<"\nNo such option!!!";
           }

          cout<<"\nDo you wish to continue: ";
          cin>>ch;
  }while((ch=='y')||(ch=='Y'));
  getch();
  return 0;
}                
                           
          
          
