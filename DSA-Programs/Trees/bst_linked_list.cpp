#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct tree
{
    int info;
    struct tree *left;
    struct tree *right;
};
typedef struct tree *bstnode;
bstnode Insert(bstnode, int);
bstnode FindMin(bstnode);
bstnode Delete(bstnode, int);
void InorderTraversal(bstnode);
main()
{
      bstnode t;
      int x;
      char ch = '1';
      t = NULL;
      while( ch != '4')
      {
             printf("\n 1 - INSERT");
             printf("\n 2 - DELETE");
             printf("\n 3 - INORDER TRAVERSAL");
             printf("\n 4 - QUIT");
             printf("\n Enter Your Choice");
             fflush(stdin);
             ch = getchar();
             switch(ch)
             {
                       case '1':
                            printf("\n Enter the Element to be Inserted");
                            scanf("%d", &x);
                            t = Insert (t, x);
                            break;
                       case '2':
                            printf("\n Enter the Element to be Deleted");
                            scanf("%d", &x);
                            t = Delete (t, x);
                            break;
                       case '3':
                            InorderTraversal(t);
                            break;
                       case '4':
                            break;
                       case '5':
                            printf("\n Wrong Choice! Try Again");
             }
      }
}

bstnode FindMin(bstnode t)
{
        if(t == NULL ) return NULL;
        else
            if (t -> left == NULL)
               return t;
            else
                return  (FindMin (t -> left));
}

bstnode Insert(bstnode t, int x)
{
        if (t == NULL)
        {
              t = (bstnode)malloc(sizeof(struct tree));
              if ( t == NULL)
                 printf("\n Out of Memory");
              else
                  {
                    t -> info = x;
                    t -> left = t ->right  = NULL;
                  }
        }
        else 
        if (x < t->info)
           t->left = Insert(t->left, x);
        else if (x > t->info)
           t->right = Insert(t->right, x);
        //printf("\n%u", t);
       // printf("\n%u", t->left);
           
        return t;
}

bstnode Delete(bstnode t, int x)
{
        bstnode temp;
        if (t == NULL)
           printf("\n The Element Is Not Found");
        else
           if(x < t->info)
               t -> left = Delete(t->left,x);
           else
           if (x > t->info)
               t ->right = Delete(t->right, x);
           else
           if (t -> left && t->right)
           {
                 temp = FindMin(t->right);
                 t->info = temp ->info;
                 t->right = Delete(t->right, t->info);
           }
           else
           {
               temp = t;
               if (t->left == NULL)
                  t = t->right;
               else if (t ->right == NULL)
                  t = t ->left;
               free(temp);
           }
           return t;
}

void InorderTraversal(bstnode t)
{
     if (t != NULL)
     {
           InorderTraversal(t->left);
           printf("%d-->", t->info);
           InorderTraversal(t->right);
     }
}            
