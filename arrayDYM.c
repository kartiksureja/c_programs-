#include<stdio.h>
#include<stdlib.h>
void insert(int *p,int n)
{
    int i;
    for(i=0;i<n;i++)
    {  
        scanf("%d",(p+i));
    }
}
void display(int *p,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf(" %d ",*(p+i));
    }
}
void search(int *p,int n,int key)
{
    int i,flag=0;
    for(i=0;i<n;i++)
    {
        if(key==*(p+i))
        {
            printf(" %d found at %d ",key,i+1);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf(" element not found ");
    }
}
void insert_ele(int *p,int *n,int value,int pos)
{   
    
    int i;
    if(pos<*n)
    {   p=(int *)realloc(p,*(n+1));
        (*n)++;
        for(i=*n-2;i>=pos-1;i--)
        {
            *(p+i+1)=*(p+i);
        }
        
     *(p+pos-1)=value;
     display(p,*n);
     
    }
    else if(pos==*n)
    {
        p=(int *)realloc(p,*(n+1));
        (*n)++;
       *(p+pos-1)=value; 
       display(p,*n);
    }
    else 
    printf("inserting position wrong");
    
}
void delete(int *p,int *n,int pos)
{    int i;
    if(pos>0&&pos-1<*n)
    {
         for(i=pos-1;i<*n;i++)
        {
            *(p+i)=*(p+i+1);
        }
        p=(int *)realloc(p,*(n-1));
         (*n)--;
         display(p,*n);
    }
    else 
    {
        printf("position not available");
    }
}
void delete_vl(int *p,int *n,int value)
{
    int i,flag=0;
    for(i=0;i<*n;i++)
    {
     if(*(p+i)==value)
     { 
       flag =1;  
      for(int j=i;j<*n-1;j++)
      {
          *(p+j)=*(p+j+1);
      }
       (*n)--;
     }
    }
    if(flag==0)
    {
        printf("value not found");
    }
    else 
    {
        p=(int *)realloc(p,sizeof(int)*(*n));
    }
}

void main()
{   
int x,size,opr,key,pos,value,*p;
printf("enter 1 to continue or any number to exit ");
scanf("%d",&x);
while(x==1)
{
    printf(" \n1-input \n2-ouput\n3-search\n4-insert \n5-delete\n6-delete using value\n101-exit\nyour choice=  ");
    scanf("%d",&opr);
    switch (opr)
    {
    case 1:
        printf("enter the size of the array");
        scanf("%d",&size);
        printf("enter the elements\n");
        p=(int *)calloc(size,sizeof(int));
        if(p==NULL)
        {
            printf("memory error");
        }
        insert(p,size);
        break;
    case 2:
        printf("the elements are \n");
        display(p,size);
        break;
    case 3:
        printf("enter the key to searched ");
        scanf("%d",&key);
        search(p,size,key);
        break;
    case 4:
        printf("enter the postion and value of the new key");
        scanf("%d %d",&pos,&value) ;
        insert_ele(p,&size,value,pos);
        break; 
    case 5:
        printf("enter the postion to be deleted")            ;
        scanf("%d",&pos); 
        delete(p,&size,pos);  
        break;
    case 6:
        printf("enter the value to be deleted")            ;
        scanf("%d",&value); 
        delete_vl(p,&size,value);
        break;
    case 101:
        x=0;
        break;    
    default:
        printf("entered value is wrong");
        break;
    }
}

}
