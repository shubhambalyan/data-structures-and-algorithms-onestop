/*  POLYNOMALS USING LINKED LISTS   */

/* 1.Representing polynomials.
   2.Performing Addition and Subtraction on polynomials.
   3.Performing Multiplication of two polynomials.
   4.Performing Differentiation of polynomial.  */
   
   #include<iostream>
   using namespace std;
   #include<conio.h>
   
   struct polynomial
   {
          int pow;
          float coeff;
          struct polynomial*next;
   };
   
   struct polynomial *poly1=NULL,*poly2=NULL,*poly=NULL,*ptr,*end;   
   
   void create(polynomial*ptr)
   {
        char ch;
        do
        {
        cout<<"\nEnter the coefficient and power of the term: ";
        cin>>ptr->coeff>>ptr->pow;
        ptr->next=new polynomial;
        ptr=ptr->next;
        ptr->next=NULL;
        cout<<"\nWant to enter another term: ";
        cin>>ch;
        }while(ch=='y');
   }
   
   void add(polynomial*poly1, polynomial*poly2, polynomial*poly)
   {
        while((poly1->next!=NULL)&&(poly2->next!=NULL))
        {
             if(poly1->pow > poly2->pow)
                {
                           poly->coeff=poly1->coeff;
                           poly->pow=poly1->pow;
                           poly1=poly1->next;
                }
                
             else if(poly1->pow < poly2->pow)
                {
                           poly->coeff=poly2->coeff;
                           poly->pow=poly2->pow;
                           poly2=poly2->next;
                }
                
             else
                {
                           poly->coeff=poly1->coeff + poly2->coeff;
                           poly->pow=poly2->pow;
                           poly1=poly1->next;
                           poly2=poly2->next;
                }
             
             poly->next=new polynomial;
             poly=poly->next;
             poly->next=NULL;
        }
        
        while((poly1->next)||(poly2->next))
        {
              if(poly1->next!=NULL)
                {
                          poly->coeff=poly1->coeff;
                          poly->pow=poly1->pow;
                          poly1=poly1->next;
                }

              if(poly2->next!=NULL)
                {
                          poly->coeff=poly2->coeff;
                          poly->pow=poly2->pow;
                          poly2=poly2->next;
                }
             poly->next=new polynomial;
             poly=poly->next;
             poly->next=NULL; 
        }
   }
   
   void subtract(polynomial*poly1, polynomial*poly2, polynomial*poly)
   {
        while((poly1->next!=NULL)&&(poly2->next!=NULL))
        {
             if(poly1->pow > poly2->pow)
                {
                           poly->coeff=poly1->coeff;
                           poly->pow=poly1->pow;
                           poly1=poly1->next;
                }
                
             else if(poly1->pow < poly2->pow)
                {
                           poly->coeff=(-1)*poly2->coeff;
                           poly->pow=poly2->pow;
                           poly2=poly2->next;
                }
                
             else
                {
                           poly->coeff=poly1->coeff - poly2->coeff;
                           poly->pow=poly2->pow;
                           poly1=poly1->next;
                           poly2=poly2->next;
                }
             
             poly->next=new polynomial;
             poly=poly->next;
             poly->next=NULL;
        }
        
        while((poly1->next)||(poly2->next))
        {
              if(poly1->next!=NULL)
                {
                          poly->coeff=poly1->coeff;
                          poly->pow=poly1->pow;
                          poly1=poly1->next;
                }

              if(poly2->next!=NULL)
                {
                          poly->coeff=(-1)*poly2->coeff;
                          poly->pow=poly2->pow;
                          poly2=poly2->next;
                }
             poly->next=new polynomial;
             poly=poly->next;
             poly->next=NULL; 
        }
   }   

   void multiply(polynomial*poly1, polynomial*poly2, polynomial*poly)
   {
      int i=0;
      polynomial*temp=poly2,*start;
      while(poly1!=NULL)
      {
           poly2=temp;
           while(poly2!=NULL)
           { 
                             poly->coeff=poly1->coeff * poly2->coeff;
                             poly->pow= poly1->pow  + poly2->pow ;
                             if(i==0)
                               start=poly;
                             poly->next=new polynomial;
                             poly=poly->next;
                             poly->next=NULL; 
                             i++;
                             poly2=poly2->next;      
           }
        poly1=poly1->next;
      }
   }     

   void differentiation(polynomial*poly1, polynomial*poly)
   {

       while(poly1->next!=NULL)
        {
             poly->coeff=poly1->coeff*poly1->pow;
             poly->pow=poly1->pow-1;
             poly->next=NULL;
             poly->next= new polynomial;
             poly=poly->next;
             poly1=poly1->next;
        }
    }
   
   void show(polynomial*p)
   {
        while(p->next!=NULL)
	     {              
              cout<<p->coeff<<"x^"<<p->pow;
        	  p=p->next;
              if(p->next!=NULL)
                 cout<<" + ";
         }
   }

   
   int main()
   {
       poly1=new polynomial;
       poly2=new polynomial;
       poly=new polynomial;
       
       int choice;
       char ch;
       
       cout<<"\n!!! Enter the terms from highest degree to lowest !!!\n";
       cout<<"\n.....Polynomial 1.....";
       create(poly1);
          
       cout<<"\nPolynomial 1 is as follows: \n";
       show(poly1);
       
       cout<<"\n\n.....Polynomial 2.....";
       create(poly2);
                  
       cout<<"\nPolynomial 2 is as follows: \n";
       show(poly2);
       
       do
       {
                   cout<<"\n....................MENU....................\n";
                   cout<<"\n1.Addition \n2.Subtraction \n3.Multiplication \n4.Differentiation \n5.Exit";
                   cout<<"\nChoice: ";
                   cin>>choice;
                   switch(choice)
                   {
                                 case 1: cout<<"\n\n----------Adding the Polynomials----------\n";
                                         add(poly1,poly2,poly);
                                         cout<<"\n\nThe Result of Addition is: ";
                                         show(poly); 
                                         break;
                                 
                                 case 2: cout<<"\n\n----------Subtracting the Polynomials----------\n";
                                         subtract(poly1,poly2,poly);
                                         cout<<"\n\nThe Result of Subtraction is: ";
                                         show(poly);
                                         break;  
                                         
                                 case 3: cout<<"\n\n----------Multiplying the Polynomials----------\n";
                                         multiply(poly1,poly2,poly);       
                                         cout<<"\n\nThe Result of Multiplication is: ";
                                         show(poly);
                                         break;
                                         
                                 case 4: cout<<"\n\n----------Differentiating the Polynomial 1----------\n";
                                         differentiation(poly1,poly);       
                                         cout<<"\n\nThe Result of Differentiation is: ";
                                         show(poly);
                                         break;
                                         
                                 case 5: exit(0);
                                         break;
                                         
                                default: cout<<"\nNo Such Option.....";
                                         break;
                    }
       cout<<"\n\nDo you wish to continue: ";
       cin>>ch;
       }while((ch=='y')||(ch=='Y'));      
      
       getch();
       return 0;
    }
