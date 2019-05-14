// Program to insert a node at the beginning of a linked list.

 #include<iostream.h>
 #include<conio.h>
 
 struct node
 {
        int data;
        struct node*link;
 };
 
 struct node*header, *newnode, *ptr, *currentnode;
 
 node*create(int x)
 {
        ptr=(struct node*)malloc(sizeof(struct node));
        ptr->data=x;
     ptr->link=NULL;
     return ptr;
 } 
 
 void insert(node*np)
 {
      if(header==NULL)
          header=np;
      else
        { 
           currentnode=header;
           header=np;
           np->link=currentnode;
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
     header=NULL;
     int item;
     char ch;
     do
     {
         cout<<"\nEnter the element to be inserted in the list: ";
         cin>>item;
         newnode=create(item);
         insert(newnode);
         cout<<"\nThe linked list now is...";
          display(header);
         cout<<"\nDo you want to add more elements: ";
         cin>>ch;
     }while((ch=='y')||(ch=='Y'));
     
     getch();
     return 0;
}
