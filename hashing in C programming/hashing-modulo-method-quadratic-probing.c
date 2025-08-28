#include<stdio.h>
int hash_function(int,int);
void quadratic_probing(int,int);
int a[10];
int count=0;
void main(){
    int key,id;
    for(int i=0;i<10;i++)
    {
        printf("'enter key value into hash table\n");
        scanf("%d",&key);
        quadratic_probing(key,0);
         
    }
    
    
}

int hash_function(int key,int i)
{
    int id;
    id=(key%10+i)%10;
    return id;
}
void quadratic_probing(int key,int ind)
{
    
    int id=hash_function(key,ind);
    if(a[id]==0)
    {
        // printf("%d collisions\n",count);
        a[id]=key;
        printf("a[%d]=%d\n",id,a[id]);
        count=0;
    } 
    else
    {
        count++;
         printf("%d collisions\n",count);
        if (count==10){
            exit(0);
        }
        else{
            quadratic_probing(key,count*count);
        }
    }
    
}
