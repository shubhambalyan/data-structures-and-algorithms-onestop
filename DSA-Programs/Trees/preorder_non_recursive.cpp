// Preorder non-recursive traversal
#include<stdio.h>
#include<conio.h>
#include<malloc.h>

typedef struct tree
{
        int info;
        struct tree *left;
        struct tree *right;
}*Tree;

typedef struct stack
{
        struct tree *ptr;
        struct stack *next;
}*Stack;

Tree root = NULL;
int x;
void BuildTree(Tree, int);
void TravPreorder(Tree);
Stack Push(Stack, Tree);

main()
{    int i;
     printf("\n Enter the Values\n");
     scanf("%d", &x);
     root = (Tree)malloc(sizeof(struct tree));
     root -> info = x;
     root ->left = NULL;
     root ->right = NULL; 
/* for (i=1; i<6; i++)
    { scanf("%d", &x);
      BuildTree(root,x);}*/
     printf("\nEnter ^z after pressing an enter to terminate\n"); // Ctrl Z for EOF
while (scanf("%d", &x) !=EOF)
           BuildTree(root, x);
     printf("\n");
     printf("\n Preorders \n");
     TravPreorder(root);
     getch();
}

void BuildTree(Tree node, int number)
{ 
     Tree newnode;
     if (number > node->info)
     {
                if (node ->right ==NULL)
                {
                   newnode = (Tree)malloc(sizeof(struct tree));
                   newnode ->info = number;
                   newnode ->left = NULL;
                   newnode ->right = NULL;
                   node -> right = newnode;
                }
                else
                BuildTree(node->right, number);
     }
     else
       {
     if(number < node ->info)
     {
                if(node ->left == NULL)
               {
                   newnode = (Tree)malloc(sizeof(struct tree));
                   newnode ->info = number;
                   newnode ->left = NULL;
                   newnode ->right = NULL;
                   node -> left = newnode;    
               }
               else
               BuildTree(node->left, number);
     }
     else
               printf("\n Duplicate Number = %d\n",number);
               }
}

Stack Push(Stack top, Tree node)
{
      Stack curr;
      curr = (Stack)malloc(sizeof(struct stack));
      curr ->ptr = node;
      curr ->next = NULL;
      if (top == NULL)
         top = curr;
      else
      {
          curr->next =top;
          top = curr;
      }
      return top;
}
void TravPreorder(Tree node)
{
     Stack top = NULL;     
     Stack curr, temp;
     do
     {     while(node != NULL)
           {
                      printf("%d ", node->info);
                      if(node ->right != NULL)
                              top = Push(top, node->right);
                      node = node ->left;                      
           }
           if(top != NULL)
           {
                  node = top->ptr;
                  temp = top;
                  top = top->next;
                  free(temp);
           }
     }while(top!=NULL || node != NULL);
}
