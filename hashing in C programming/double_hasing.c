#include<stdio.h>
#define SIZE 10
int hashtable[SIZE];
int double_hashing(int );
void main()
{
    int t;
    int a[]={53,90,44,52,61,20,30};
    for(int i=0;i<7;i++)
    {
        t=double_hashing(a[i]);
    }
    for(int i=0;i<SIZE;i++)
    {
        printf("%d\t",hashtable[i]);
    }
}

int double_hashing(int key)
{
    int id;
    for(int i=0;i<SIZE;i++)
    {
       id=(key%SIZE+i*(1+key%(SIZE-2)));
       if(hashtable[id]==0)
       {
            hashtable[id]=key;
            return 1;
       } 
    }
}                                     