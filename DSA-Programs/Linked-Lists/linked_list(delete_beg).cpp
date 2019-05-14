// Program to delete from the beginning.

 #include<iostream.h>
 #include<conio.h>
 
 struct node
 {
        int data;
        struct node*link;
 };
 
 struct node*header, *newnode, *ptr, *currentnode, *last;
 
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
          header=last=np;
      else
        { 
           last->link=np;
           last=np;
           }
}

void remove()
 {
      if(header==NULL)
         cout<<"\nUNDERFLOW!!!";
      else
        {
                  ptr=header;
                  header=header->link;
                  free(ptr);
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
     
     ch='y';
     
     do
     {
            cout<<"\nDo you want to delete element: ";
         cin>>ch;
         if((ch=='y')||(ch=='Y'))
          remove();
          cout<<"\nThe linked list now is...";
          display(header);
     }while((ch=='y')||(ch=='Y'));
     
     getch();
     return 0;
}
