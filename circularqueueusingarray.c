#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX];
int f=-1,r=-1;
void enqueue()
{
    int val;
    
    if(f==-1&&r==-1)
    {
        printf("enter value:\n");
        scanf("%d",&val);
        f=r=0;
        queue[r]=val;
        printf("r=f=%d,%d",r,f);
    }
    if((r+1)%MAX==f)
      printf("queue overflow\n");
    else
    {
        r=(r+1)%MAX;
        printf("enter value :\n");
        scanf("%d",&val);
        queue[r]=val;
        printf("r=%d\n",r);
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
        printf("r=f=%d \n",r);
    }
    else
    {
        printf("deleted element is %d\n",queue[f]);
        f=(f+1)%MAX;
        printf("f=%d\n",f);
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
        int i;
        for( i=f;i!=r;)
        {
            
            printf("%d\t",queue[i]);
            i=(i+1)%MAX;
            
        }
        printf("%d",queue[r]);
        printf("i=%d\n",i);
    }
}
void main()
{
    int ch;
    while(1)
    {
        printf("choose an operatio  below\n");
        printf("1.enqueue()\n");
        printf("2.dequeue\n");
        printf("3.display\n");
        printf("4.exit\n");
        printf("enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                enqueue();
                break;
            case 2:
                 dequeue();
                 break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default :
            printf("enter a valid input\n");
        }   
    }
}
