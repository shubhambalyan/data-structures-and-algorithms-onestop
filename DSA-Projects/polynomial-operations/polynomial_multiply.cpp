/*  POLYNOMALS USING LINKED LISTS   */

/* 1.Representing polynomials.
   2.Performing Multiplication of two polynomials.*/
   
#include<iostream>
#include<conio.h>
using namespace std;

struct poly
{
    float coeff;
    int pow;
    struct poly*next;
};

class multiply_poly
{
   poly *poly1, *poly2, *poly3;
   public:
   multiply_poly()
   {
        poly1=poly2=poly3=NULL;
   }
   void mul_poly();
   void display();
};

void multiply_poly::mul_poly()
{
      int p;
      poly *newl=NULL,*end=NULL;
      cout<<"Enter highest power for x\n";
      cin>>p;
      
      cout<<"\n\nFirst Polynomial\n";
      for(int i=p;i>=0;i--)
      {
       newl=new poly;
       newl->pow=i;
       cout<<"Enter Co-efficient for degree"<<i<<"::  ";
       cin>>newl->coeff;
       newl->next=NULL;
       if(poly1==NULL)
         poly1=newl;
       else
         end->next=newl;
       end=newl;
      }

      cout<<"\n\nSecond Polynomial\n";
      end=NULL;
      for(int i=p;i>=0;i--)
      {
       newl=new poly;
       newl->pow=i;
       cout<<"Enter Co-efficient for degree"<<i<<"::  ";
       cin>>newl->coeff;
       newl->next=NULL;
       if(poly2==NULL)
         poly2=newl;
       else
         end->next=newl;
       end=newl;
      }

      cout<<"\nMultiplying the polynomials: \n";
      poly *p1=poly1,*p2=poly2;
      end=NULL;
      while(p1 !=NULL)
      {
           p2=poly2;
              while(p2!=NULL)
                {
                   newl=new poly;
                   newl->pow=p1->pow + p2->pow;
                   newl->coeff=p1->coeff * p2->coeff;
                   newl->next=NULL;
                      if(poly3==NULL)
                         poly3=newl;
                      else
                         end->next=newl;
                   end=newl;
                   p2=p2->next;
                }
        p1=p1->next;
     }
}

void multiply_poly::display()
{
   poly *t=poly3;
   cout<<"\n\nAnswer after multiplication is: ";
   while(t!=NULL)
   {
      cout.setf(ios::showpos);
      cout<<t->coeff;
      cout.unsetf(ios::showpos);
      cout<<"x^"<<t->pow;
      t=t->next;
   }
}


int main()
{
    multiply_poly obj;
    obj.mul_poly();
    obj.display();
    getch();
    return 0;
}
