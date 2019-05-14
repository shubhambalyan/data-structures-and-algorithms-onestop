// Program to evaluate a postfix expression.

 #include<iostream.h>
 #include<conio.h>
 #include<math.h>
 #define SIZE 50 
 #include <ctype.h>
int stack[SIZE];
int top=-1; 
void push(int item)
{ 
stack[++top]=item;
}
int pop()
{ 
return(stack[top--]);
}
int main()
{ 
char postfix[50],ch;
int i=0,op1,op2;
cout<<"\nEnter the Postfix Expression: ";
cin>>postfix;
while( (ch=postfix[i++]) != '\0')
{
if(isdigit(ch)) 
 push(ch-'0');
else
{ 
op2=pop();
op1=pop();
switch(ch)
{
case '+':push(op1+op2);break;
case '-':push(op1-op2);break;
case '*':push(op1*op2);break;
case '/':push(op1/op2);break;
case '^':push(pow(op1,op2)); break;
}
}
}
cout<<"\n Given Postfix Expn: "<<postfix;
cout<<"\n Result after Evaluation:\n"<<stack[top];
getch();
return 0;
}
 
 
 
 
 
 
