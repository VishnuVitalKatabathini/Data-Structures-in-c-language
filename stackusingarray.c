#include<stdio.h>
//#include<stdlib.h>
#define SIZE 5
int stack[SIZE];
int top=-1;
void push(int val)
{
   
    if(top==SIZE-1)
    {
        printf("stack overflow....\n");

    }
    else
    {
        top++;
        stack[top]=val;

    }
}
void pop()
{
    if (top==-1 )
    {
        printf("stack underflow\n");
    }
    else
    {
        printf("poped element is %d",stack[top]);
        top--;
    }
    
}
void display()
{
    if(top==-1)
    {
        printf("stack is empty\n");
    }
    else{
        for(int i=top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}
void  main()
{
    push(10);
    push(20);
    push(30);
    display();
    pop();
    pop();
    display();
    pop();
    display();
    pop();

}