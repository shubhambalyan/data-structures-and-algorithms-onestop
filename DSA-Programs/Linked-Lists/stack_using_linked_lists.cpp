 // Program to push and pop in a linked stack.
 
 #include<iostream.h>
 #include<conio.h>
 #include<process.h>
 
 struct node
 {
        int data;
        struct node*link;
 };
 
 struct node*top, *newnode, *ptr, *newptr, *save;
 
 node* create(int x)
 {
       ptr=(struct node*)malloc(sizeof(struct node));
       ptr->data=x;
       ptr->link=NULL;
       return ptr;
 }
 
 void push(node*np)
 {
      if(top==NULL)
         top=np;
      else
         {
                save=top;
                top=np;
                np->link=save;
         }
 }
 
 void pop()
 {
      if(top==NULL)
         cout<<"\nOVERFLOW!!!";
      else
       {
             ptr=top;
             top=top->link;
             delete ptr;
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
     do
     {
         cout<<"\nEnter the element to be inserted in the stack: ";
         cin>>item;
         newptr=create(item);
         push(newptr);
         cout<<"\nThe linked stack contains: ";
         display(top);
         cout<<"\nDo you want to add more elements: ";
         cin>>ch;
     }while((ch=='y')||(ch=='Y'));
     
     ch='y';
     
     cout<<"\nNow the deletion begins...";
     do
     {
          pop();
          display(top);
          cout<<"\nDo you want to delete more elements: ";
         cin>>ch;
     }while((ch=='y')||(ch=='Y'));
          
     getch();
     return 0;
         
 }
 
