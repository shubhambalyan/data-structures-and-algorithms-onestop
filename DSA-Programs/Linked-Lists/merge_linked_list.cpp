#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//******************************************************************************
typedef struct LL  //Linked List
{
int data;
struct LL *next;
}LL;
//******************************************************************************
LL* create(LL **head)
{
int data,no_of_nodes,i;
LL *newnode,*first,*last;
 first = *head;
 printf("\nEnter how many nodes: ");
 scanf("%d",&no_of_nodes);
 for (i = 0;i < no_of_nodes;i++)
 {
  printf("\nEnter data%d: ",i+1);
  scanf("%d",&data);
  newnode = (LL*)malloc(sizeof(LL));
  newnode->data = data;
  newnode->next = NULL;
  if (first == NULL) first = last = newnode;
  else
  {
   last->next = newnode;
   last = last->next;
  }
 }
 return first;
}
//******************************************************************************
int exist(LL *head,int data)
{
LL *i;
 for (i = head;i != NULL;i = i->next)
 {
  if (i->data == data)
  return 1;
 }
 return 0;
}
//******************************************************************************
LL* merge(LL *head1,LL *head2)
{
LL *list1,*list2;
 list1 = head1;
 list2 = head2;
 while (list1->next != NULL) list1 = list1->next;
 while (list2 != NULL)
 {
  if (!exist(head1,list2->data))
  {
   list1->next = (LL*)malloc(sizeof(LL));
   list1 = list1->next;
   list1->data = list2->data;
   list1->next = NULL;
  }
  list2 = list2->next;
 }
 return head1;
}
//******************************************************************************
void display(LL *head)
{
LL *i;
 printf("\n");
 for (i = head;i != NULL;i = i->next) printf("%d=>",i->data);
 printf("\b\b");
}
//******************************************************************************
int main()
{
LL *list1,*list2,*list3;
 list1 = list2 = list3 = NULL;
 printf("\n\tLIST 1");
 list1 = create(&list1);
 printf("\n\tLIST 2");
 list2 = create(&list2);
 printf("\n\tLIST 1");
 display(list1);
 printf("\n\tLIST 2");
 display(list2);
 list3 = merge(list1,list2);
 printf("\nAfter merging");
 display(list3);
 getch();
 return 0;
}
