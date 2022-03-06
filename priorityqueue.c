#include<stdio.h>
#include<stdlib.h>
struct queue 
{
    int *a;
    int f,r,count;
    int size;
};
typedef struct queue Queue;
void insert(Queue *q,int val)
{
    if(q->r==q->size-1)
    {
        printf("full");

    }
    else 
    {
        q->count++;
        int j=q->r;
        q->r++;
        q->a=(int *)realloc(q->a,sizeof(int)*(q->count));
        while(j>=0 && (*(q->a+j)>val))
        {
            *(q->a+j+1)=*(q->a+j)  ;
            j--;          
        }
        *(q->a+j+1)=val;
        if(q->f==-1)
        {
            q->f=0;
        }
    }
}
void delete (Queue *q)
{
    if(q->r==-1)
    {
        printf("empty ");

    }
    else 
    {
        q->count--;
        if(q->f==q->r)
        {
            q->f=q->r=-1;
        }
        else 
        {
            q->f++;

        }
        q->a=(int*)realloc(q->a,sizeof(int)*(q->count));
    }
}
void display(Queue *q)
{
    if(q->f==-1)
    {
        printf("empty");

    }
    else 
    {
        int i;
        for(i=q->f;i<=q->r;i++)
        {
            printf("Q[%d]= %d ",i+1,*(q->a+i));
        }
    }
}
void insertr(Queue *q ,int val)
{
    if(q->r==q->size-1)
    {
        printf("overflow");

    }
    else
    {
        q->count++;
        q->r++;
        q->a=(int*)realloc(q->a,sizeof(int )*(q->count));
        *(q->a+q->r)=val;
        if(q->f==-1)
        {
            q->f=0;
        }
    }
}
void delete_ino(Queue *q )
{
    if(q->f==-1)
    {
        printf("empty ");
    }
    else 
    {
        q->count--;
        int small;
        small=*(q->a+q->f);
        int j;
        for(int i=q->f+1;i<=q->r;i++)
        {
            if(small>(*(q->a+i)))
            {
                small = *(q->a+i);
                j=i;
            }
        }
        printf("%d  %d",small,j);
        for(int i =j;i>q->f;i--)
        {
            *(q->a+i)=*(q->a+i-1);
        }
        q->f++;
        q->a=(int*)realloc(q->a,sizeof(int )*(q->count));
    }
}
void main()
{
    int opr ,val;
    Queue q;
    q.f=-1;
    q.r=-1;
    q.a=(int*)malloc(0);
    printf("enetr the size ");
    scanf("%d",&(q.size));
    q.count=0;
    do 
    {
        printf("\n1 to insert \n2 to display\n3 dele rand\n4 ins rand\n 5 dele in asc\n6 exit ");
        scanf("%d",&opr);
        switch(opr)
        {
            case 1:
                    printf("enter the val;");
                    scanf("%d",&val);
                    insert(&q,val);
                    break;
            case 2 :
                    display(&q);
                    break; 
            case 3 :
                    delete(&q);
                    break;
            case 4 :
                    printf("enter the val");
                    scanf("%d",&val);
                    insertr(&q,val);
                    break;
            case 5 :
                    delete_ino(&q);
                    break;
            case 6 :
                   exit(0);                
                                    
        }
    }while(opr!=6);
}
