#include<stdio.h>
#include<conio.h>
#include<malloc.h>
typedef struct nodelist
{
        int info;
        struct nodelist *next;
        struct edgelist *adj;
} Node;

typedef struct edgelist
{
      int adj_node;
      struct edgelist *link;  
} Edge;

void InsertEdges();
void BuildNodeList();
void Display();
Node *start;
int n;

void BuildNodeList()
{
     Node *curr, *prev;
     int i;
     printf("\nEnter the number of nodes in Graph:- ");
     scanf("%d", &n);
     prev = NULL;
     for ( i=1; i<=n; i++)
     {
         curr=(Node*) malloc(sizeof(Node));
         if (curr == NULL)
         {
            printf("\n Out of Memory Space");
            exit(0);
         }
         curr->next = NULL;
         curr->adj = NULL;
         curr->info = i;
         if(prev == NULL)
           start = curr;
         else
           prev->next = curr;
         prev = curr;
     }
}

void InsertEdges()
{
     Edge *curr, *prev;
     Node *temp, *ptr;
     int i,j,m,k,p;
     temp = start;
     for (i=1; i<=n; i++)
     {
         b:
         printf("\n Enter the number of Adjacent Nodes of %d:- ",i);
         scanf("%d", &m);
         if(m<0 || m>n)
                {
                    printf("\nInvalid data....");
                    goto b;
                }
         prev=NULL;
         for (j=1; j<=m; j++)
         {
             a:
             printf("\nEnter the %d adjacent node of %d:- ", j,i);
             scanf("%d", &k);
             if(k<0 || k>n)
                {
                    printf("\nInvalid data....");
                    goto a;
                }
             curr = (Edge *)malloc(sizeof(Edge));
             if (curr == NULL)
             {
                   printf("\n Out of Memory Space");
                   exit(0);   
                   }
             ptr=start;
             curr ->adj_node=k;
             curr ->link = NULL;
             if(prev == NULL)
                temp->adj = curr;
             else
                prev->link = curr;
             prev = curr;
         }
         temp = temp ->next;
    }
}
void Display()
{
     Node *node;
     Edge *ptr;
     node = start;
     printf("\n Node\tAdjacency List\n");
     printf("--\t-------\n");
     while(node != NULL)
     {
                printf("%d", node ->info);
                ptr = node ->adj;
                printf("\t");
                while(ptr != NULL)
                {
                          printf("%d     ", ptr->adj_node);
                          ptr=ptr->link;
                }
                printf("\n");
                node=node->next;
     }
}
main()
{ 
     BuildNodeList();
     InsertEdges();
     Display();
     getch();
}
