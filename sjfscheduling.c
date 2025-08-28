#include<stdio.h>
void sort(int bt[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(bt[j]>bt[j+1])
            {
                temp=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp;
            }
        }
    }
  
}
void completiontime(int at[],int bt[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(bt[j]<bt[j+1]||at[j+1]<at[j])
            {

            }
        }
    }
}
void main()
{
   int at[]={1,3,0,2,4};
   int bt[]={5,2,3,1,6};
   int n=sizeof(at)/sizeof(int);
   printf("arrival time :");
   for(int i=0;i<n;i++)
    {
        printf("%d\n",at[i]);
       
    }
    printf("\nburst time :\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\n",bt[i]);
       
    }
    printf("\nburst time in sorted order:\n");
   /*sort(bt,n);
    
    for(int i=0;i<n;i++)
    {
        printf("%d\n",bt[i]);
       
    }*/
    printf("sjfscheduling.........");
    completiontime(at,bt,n);    
}