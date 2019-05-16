// Program to implement Binary Search Trees array implementation

 #include<iostream.h>
 #include<conio.h>
 #define true 1;
 #define false 0;
 const int treenodes=100;
 
 struct tree
 {
        int info;
        int used;
 };
 
 struct tree nodes[treenodes];

  void setleft(int pos, int x)
 {
      int a=2*pos+1;
      nodes[a].info=x;
      nodes[a].used=true;
 }
 
  void setright(int pos, int x)
 {
      int a=2*pos+2;
      nodes[a].info=x;
      nodes[a].used=true;
 }
 
 void buildtree(int x)
 {
        int i;
        nodes[0].info=x;
        nodes[0].used=true;
        for(i=1;i<treenodes;i++)
        {
           nodes[i].used=false;
        }
 }
 
 void insert(int x)
 {
        int p=0,q=0;
        while(q<treenodes && nodes[q].used && x!=nodes[p].info)
        {
             p=q;
             if(x<nodes[p].info)
             {
                                q=2*p+1;
             }
             
             else
             {
                                q=2*p+2;
             }
        }
       if (x == nodes[p].info)
          cout<<"\nDuplicate number: "<<x;
      else
          if (x<nodes[p].info)
             setleft(p,x);
          else
             setright(p,x);

 } 
  
 int main()
 {
     cout<<"\nBuilding the Binary Search tree.........";
     buildtree(50);
     insert(44);
     insert(30);
     insert(19);
     insert(60);
     cout<<"\nThe tree is as follows: ";
     for(int i=0;i<treenodes;i++)
     {
             cout<<nodes[i].info<<"-->";
     }
     getch();
     return 0;
 }
