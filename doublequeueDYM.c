#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int *a ;
    int size;
    int f,r;
    int count;
};
typedef struct queue Queue;

void insert_front(Queue *q,int val)
{
    if(q->f==0)
    {
        printf(" cant add");
    }
    else 
    {
        q->count++;
        q->a=(int * )realloc(q->a,sizeof(int)*(q->count));
        if(q->f==-1)
        {
            q->f=0;
            q->r=0;
            *(q->a+q->r)=val;
        }
        else 
        {
            q->f--;
            *(q->a+q->f)=val;
        }

    }
}
void insert_rear(Queue *q,int val)
{
    if(q->r==q->size-1)
    {
        printf("cant add ");

    }
    else 
    {
        q->count++;
        q->a=(int *)realloc(q->a,sizeof(int)*(q->count));
        q->r++;
        *(q->a+q->r)=val;
    }
}
void deletefront(Queue *q)
{
    if(q->f==-1)
    {
        printf("empty");
    }
    else 
    {
        q->count--;
        if(q->f==q->r)
        {
            q->f=-1;
            q->r=-1;
        }
        else 
        {
            q->f++;
        }
        q->a=(int *)realloc(q->a,sizeof(int )*(q->count));
    }
}
void delete_rear(Queue *q)
{
    if(q->f==-1)
    {
        printf("empty");
    }
    else 
    {
        q->count--;
        if(q->f==q->r)
        {
            q->f=-1;
            q->r=-1;
        }
        else
        {
            q->r--;
        }
        q->a=(int *)realloc(q->a,sizeof(int)*(q->count));
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
        int i=0;
        for(i=q->f;i<=q->r;i++)
        {
            printf("Q[%d] = %d",i+1,*(q->a+i));
        }
    }
}
void main()
{
    int opr,val;
    Queue q;
    q.f=-1;
    q.r=-1;
    q.count=0;
    printf("enter the size of the queue ");
    scanf("%d",&(q.size));
    q.a=(int*)malloc(0);
    do 
    {
        printf("\n1 ins fr\n2 ins rer\n3 del fr\n4 del rer\n5 exit ");
        scanf("%d",&opr);
        switch(opr)
        {
            case 1 :
                    printf("enetr the val ");
                    scanf("%d",&val);
                    insert_front(&q,val);
                    break;
            case 2 :
                    printf("enetr the val ");
                    scanf("%d",&val);
                    insert_rear(&q,val);
                    break; 
            case 3:
                    deletefront(&q);
                    break;
            case 4 :
                    delete_rear(&q);
                    break;
            case 5 :
                    exit(0);
            case 6:
                   display(&q);
                   break ;               

        }

    }while(opr!=5);
}
