#include<stdio.h>
#include<stdlib.h>
void main()
{
    int a[5],size,i;
    printf("enter size for array:");
    scanf("%d",&size);
    if(size>(sizeof(a)/4))//checking array bound if true program terminates 
    {
        printf("size should be less than or equal to size of already declared array\n ");

        exit(0);
    }
    printf("enter elements into array");
    for(i=0;i<size;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("printing array elements\n");
    for (i=0 ; i <size; i++)
    {
       printf("%d\t",a[i]); /* code */
    }
    
}