// Program to convert infix to postfix.

#include<iostream.h>
#include<conio.h>

const int size=50;
 
int top = -1;
char stack[size];
void push(char item);
char pop();
int check_operator(char symbol);
int precedence(char symbol);

int main()
{
int i=0, j=0;
char infix_exp[size], postfix_exp[size];
char item, x;
cout<<"\nEnter the arithmetic expression in Infix notation (enclosed in parentheses): \n";
gets(infix_exp);
item = infix_exp[i++];

while(item != '\0')
{

if(item == '(')
{
push(item);
}

else if((item >= 'A' && item <= 'Z') || (item >= 'a' && item <= 'z'))
{
postfix_exp[j++]=item;
}

else if(check_operator(item) == 1)
{
x = pop();
while(check_operator(x) == 1 && precedence(x) >= precedence(item))
{
postfix_exp[j++] = x;
x = pop();
}
push(x);
push(item);
}

else if(item == ')')
{
x = pop();
while(x != '(')
{
postfix_exp[j++] = x;
x = pop();
}
}

else
{
cout<<"\nInvalid Arithmetic Expression.\n";
getch();
}
item = infix_exp[i++];
}
postfix_exp[j++] = '\0';
cout<<"\nArithmetic expression in Postfix notation: ";
puts(postfix_exp);
getch();
}



void push(char item)
{
if(top == size-1)
       cout<<"\nOVERFLOW!!!\n";
else
{
             top = top+1;
          stack[top] = item;
}
}


char pop()
{
char item = '\0';
if(top == -1)
{
         cout<<"\nUNDERFLOW!!!\n";
}
else
{
      item = stack[top];
        top = top-1;
}
return item;
}


int check_operator(char symbol)
{
if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-')
   return 1;
else
   return 0;
}


int precedence(char symbol)
{
if(symbol == '^')
   return 3;
else if(symbol == '*' || symbol == '/')
    return 2;
else if(symbol == '+' || symbol == '-')
   return 1;
else
    return 0;
}
