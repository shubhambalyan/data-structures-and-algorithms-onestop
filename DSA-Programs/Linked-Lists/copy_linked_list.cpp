 // Program to copy a singly linked list
 
 #include<iostream>
 #include<conio.h>
 #include<malloc.h>
 using namespace std;
 struct node
 {
        int data;
        struct node*link;
 };
 
 struct node*head, *newnode, *ptr, *curr, *ptr1, *newhead;
 
 node*create(int x)
 {
        ptr=(struct node*)malloc(sizeof(struct node));
        ptr->data=x;
     ptr->link=NULL;
     return ptr;
 } 
 
 void insert(node*np)
 {
      if(head==NULL)
          head=np;
      else
        { 
           curr=head;
           head=np;
           np->link=curr;
           }
}

void display(node*np)
{
      while(np!=NULL)
      {
              cout<<np->data<<"...";
              np=np->link;
              }
}
              
  
 int main()
 {
     head=NULL;
     int item;
     char ch;
     do
     {
         cout<<"\nEnter the element to be inserted in the list: ";
         cin>>item;
         newnode=create(item);
         insert(newnode);
         cout<<"\nThe linked list now is...";
          display(head);
         cout<<"\nDo you want to add more elements: ";
         cin>>ch;
     }while((ch=='y')||(ch=='Y'));
     
     cout<<"\nCopying a singly linked list...\n";
     ptr=head;
     newhead=(struct node*)malloc(sizeof(struct node));
     ptr1=newhead;
     newhead->data=ptr->data;
     while(ptr->link!=NULL)
      {
               ptr=ptr->link;
               newnode=(struct node*)malloc(sizeof(struct node));
               newnode->data=ptr->data;
               ptr1->link=newnode;
               newnode->link=NULL;
               ptr1=newnode;
       }
       cout<<"\nThe copied linked list is: ";
       display(newhead);
               
     getch();
     return 0;
}
