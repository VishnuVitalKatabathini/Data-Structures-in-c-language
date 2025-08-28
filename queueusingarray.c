#include<stdio.h>
//#include<stdlib.h>
#define SIZE 5
int queue[SIZE];
int f=-1,r=-1;
void enqueue( int val)
{
    if(r==SIZE-1)
      printf("queue overflow\n");
    else if(f==-1&&r==-1)
    {
        f=r=0;
        queue[r]=val;
    }
    else
    {
        r++;
        queue[r]=val;
    }
}
void dequeue()
{
    if(f==-1&&r==-1)
    {
        printf("queue underflow");
    }
    else if(f==r)
    {
        printf("deleted element is %d\n",queue[f]);
        f=r=-1;
    }
    else
    {
        printf("deleted element is %d\n",queue[f]);
        f++;
    }
}
void display()
{
    if(f==-1&&r==-1)
    {
        printf("queue is empty\n");

    }
    else
    {
        for(int i=f;i<=r;i++)
        {
            printf("%d\t",queue[i]);
        }
        printf("\n");
    }
}
void main()
{
   enqueue(10);
   enqueue(20);
   enqueue(30);
   enqueue(40);
   enqueue(50);
   enqueue(60);
   display();
   dequeue();
   display();
   
}
