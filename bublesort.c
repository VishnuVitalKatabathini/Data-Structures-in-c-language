#include<stdio.h>

void sort(int arr[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void main()
{
    int arr[]={12,3,4,78,23,1};
    int n=sizeof(arr)/sizeof(int);
    printf("%d",n);
    printf("\narray before sorted:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("after sorted:\n");
    sort(arr,n);
      for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}