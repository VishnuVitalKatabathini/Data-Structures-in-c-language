#include<stdio.h>
#include<stdlib.h>
#define MAX 30
int a[MAX],size,i;
void insertintoarray();
void display();
void insert();
void insertatend();
void insertatend()
{
   int val;
   printf("enter value");
   scanf("%d",&val);
   a[size]=val;
   size=size+1;
   display();
}
void insert()//for unsorted array and it's time complexity is reduced to O(1)
{//also for insert at beg
     int pos,val,temp;
    printf("enter position to insert");
    scanf("%d",&pos);
    if(pos<0||pos>size)
    {
        printf("position should not be less than 0 nor grater than size of array\n");
        exit(0);
    }  
    printf("enter value to insert:\n");
    scanf("%d",&val);
    temp=a[pos-1];
    a[pos-1]=val;
    a[size]=temp;
    size++;
    display();
}
void insertintoarray()//this code works for both sorted and unsorted array
{//this works for insert at beg also
    int pos,val;
    printf("enter position to insert");
    scanf("%d",&pos);
    if(pos<0||pos>size)
    {
        printf("position should not be less than 0 nor grater than size if array\n");
        exit(0);
    }
    for(i=size;i>=pos-1;i--)
    {
        a[i+1]=a[i];
    }
    printf("enter val to insert:\n");
    scanf("%d",&val);
    a[pos-1]=val;
    size++;
    display();
}
void display()
{
   printf("array elements are:\n");
    for ( i = 0; i <size; i++)
    {
         printf("%d\t",a[i]);
    }
}
void main()
{
    
    printf("enter size of array\n");
    scanf("%d",&size);
    if(size>(sizeof(a)/4))
    {
        printf("size should be less than actual size of array");
        exit(0);
    }
    printf("enter array elements\n");
    for ( i = 0; i < size; i++)
    {
        scanf("%d",&a[i]);
    }
    display();
    insertintoarray();
    insert();
    insertatend();
    
    
}
