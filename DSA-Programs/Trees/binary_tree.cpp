#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
int count;

struct tree 
{
       int data;
       struct tree *left;
       struct tree *right;
}*root=0;

tree* insert(tree *root,int *a,int index,int n)
{
      if(index>n-1)
      return 0; 
      root=new tree;
      root->data=a[index];
      root->left=insert(root->left,a,2*index+1,n);
      root->right=insert(root->right,a,2*index+2,n);
      return root;
}

void preorder(tree *root)
{
     if(root!=NULL)
     {
     	if(root->left==NULL&&root->right==NULL)
     	count++;
        cout<<root->data<<"->";
        preorder(root->left);
        preorder(root->right);
     }
}

void preorder(tree *root,int search)
{
	int flag=0;
     if(root!=NULL)
     {
     	if(root->data==search)
     	{
     		cout<<"Element found\n";
     	flag=1;
       	}
        //cout<<root->data<<"->";
        preorder(root->left);
        preorder(root->right);
     }
     //if(flag==0)
     //cout<<"Search element not found\n";     
}

int find(tree *root)
{
	if(root==NULL)
	return 0;
	else
	return (1+max(find(root->left),find(root->right)));
}
int find1(tree* root)
{
	if(root==NULL)
	return 0;
	else
	return(1+find1(root->left)+find1(root->right));
}
      
int main()
{
	int n;
    cout<<"Total values to be entered\n";
    cin>>n;
    int a[10];
    for(int i=0;i<n;i++)
            cin>>a[i];
    root=insert(root,a,0,n);
    preorder(root);
    int height1=find(root);
    int height2=find(root->left);
    int height3=find(root->right);
    cout<<"Height of tree:"<<height1<<endl;
    cout<<"Height of left subtree:"<<height2<<endl;
    cout<<"Height of right subtree:"<<height3<<endl;
    cout<<"\nTotal no. of leaf nodes:"<<count;
    int node=find1(root);
    cout<<"\nTotal no . of nodes:"<<node<<endl;
    if(node==(pow(2,height1)-1))
    cout<<"Its a complete binary tree\n";
    cout<<"Enter an element to be searched\n";
    int search;
    cin>>search;
    preorder(root,search);
    system("pause");
    return 0;
}
       
