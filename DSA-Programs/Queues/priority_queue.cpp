 // Program to implement a priority queue using arrays.
 
 #include<iostream.h>
 #include<conio.h>
 
 const int size=5;  
 int priority_queue[size],f=-1,r=-1;  

 void PQ_insert(int item)
{
    int i;       
    if(r==size-1) 
      cout<<"\nOVERFLOW!!!";
    else
    {
        f=0;
        i=r;
        ++r;
        while(priority_queue[i]<=item && i>=0)
        {
            priority_queue[i+1]=priority_queue[i];
            i--;
        }
        priority_queue[i+1]=item;
    }
}

 int PQ_delete()
{                     
    int temp;
    if(f==-1)
     cout<<"\nUNDERFLOW!!!";
    else
    {
        temp=priority_queue[f];
        f++;
        cout<<"\nDeleted Element is: "<<temp;
    }    
}

void display()
{                
        for(int i=f;i<=r;i++)
            cout<<priority_queue[i]<<"...";
}

int main()
{                        
    int item,choice;
    char ch='y';
    do
    {
        cout<<"\nPriority Queue Menu: ";
        cout<<"\n1.Insertion \n 2.Deletion \n 3.Display \n 4.Exit\n";
        cout<<"\nYour choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1: cout<<"\nEnter the element to be inserted: ";
                cin>>item;
                PQ_insert(item); 
                break;
                
        case 2: PQ_delete();
                break;
                
        case 3: cout<<"\nNow the queue contains: ";
                display(); 
                break;
                
        case 4: exit(0); 
                break;
                
        default: cout<<"\nNo such option!!!";
                 break;
        }
        cout<<"\nDo you wish to continue: ";
        cin>>ch;
    }while((ch=='y')||(ch=='Y'));
    getch();
    return 0;
}
