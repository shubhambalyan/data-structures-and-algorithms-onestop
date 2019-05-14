 //Program to insert a node to a linked list at the beginning.
 
 #include<iostream.h>
 #include<conio.h>
 
 struct node
 {
        int data;
        struct node*link;
 };
 
 struct node*front, *newptr, *ptr, *rear;
 
 node*create(int n)
 {
     ptr=(struct node*)malloc(sizeof(struct node));
     ptr->data=n;
     ptr->link=NULL;
     return ptr;
 } 
 
 void insert(node*np)
 {
      if(front==NULL)
        front=rear=np;
      else
        {
             rear->link=np;
             rear=np;
        }
 }
 
 void remove()
 {
      if(front==NULL)
         cout<<"\nUNDERFLOW!!!";
      else
        {
                  ptr=front;
                  front=front->link;
                  free(ptr);
        }
 }
 
 void display(node*np)
 {
      while(np!=NULL)
       {
             cout<<np->data;
             np=np->link;
             }
}      
 
 int main()
 {
     int item;
     char ch;
     front=rear=NULL;
     do
     {
         cout<<"\nEnter the element to be inserted in the queue: ";
         cin>>item;
         newptr=create(item);
         insert(newptr);
         cout<<"\nDo you want to add more elements: ";
         cin>>ch;
     }while((ch=='y')||(ch=='Y'));
     
    
     ch='y';
     
     do
     {
          cout<<"\nThe linked queue now is...";
          display(front);
          cout<<"\nDo you want to delete element: ";
         cin>>ch;
         if((ch=='y')||(ch=='Y'))
          remove();
     }while((ch=='y')||(ch=='Y'));
     
     getch();
     return 0;
}
