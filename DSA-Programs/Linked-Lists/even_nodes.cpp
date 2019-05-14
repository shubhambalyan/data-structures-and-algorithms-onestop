#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
            int data;
            node *next;      
           }*head,*root;
           
void addNodes(int value);
void buildReverse(struct node*);
void display();
void onlyEvenNodes();

      
void onlyEvenNodes()
     {
     if(head->next==NULL)
            {
            printf("No Even Nodes\n");
            head =NULL;
            }
     else
         {                     
         head = head ->next;
         struct node *temp=head; 
         while(temp->next!=NULL)
                {
                if(temp->next->next!=NULL){
                         temp->next = temp->next->next;
                         temp = temp->next;                          
                         } 
                else
                    temp->next = NULL;         
                }
         }                      
     } 

void display()
      {
      struct node *temp = head;
      if(head==NULL)
         printf("Nothing to display");        
      else
          {
          while(temp!=NULL)
             {
             printf("%d ",temp->data);
             temp = temp->next;
             }               
          }
      }



//Adding new nodes to the Linked List           
void addNodes(int value)
     {
     struct node *temp = (struct node*)malloc(sizeof(struct node));
     temp->data = value;
     temp->next = NULL;
     if(head==NULL)
           head = root=temp;
     else
         {
         root->next = temp;
         root = temp;
         root->next = NULL;}       
     }            
          
           
main()
      {
      printf("ctr+z and enter to stop adding nodes\n");
      int n;
      while((scanf("%d",&n))!=EOF)
            addNodes(n);
      onlyEvenNodes();      
      display();
      getch();          
      } 
