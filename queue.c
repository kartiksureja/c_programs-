#include<stdio.h>
#include<stdlib.h>
struct queue 
{
    int *a;
    int front,rear;
    int size;
    int count;
};
typedef struct queue * Queue;
void insert(Queue q,int val)
{
    if((q->front==0&&q->rear==q->size-1)||(q->front==q->rear+1))
    {
        printf("queue full overfollow ");
    }
    else 
    {
        q->count++;
        q->a=(int*)realloc(q->a,sizeof(int)*(q->count));
        if(q->front==-1)
        {
       
            q->front=0;
            q->rear=0;
            *((q->a+q->rear))=val;
        }
        else if(q->rear==q->size-1) 
        {
            
            q->rear=0;
            *((q->a)+q->rear)=val;
        }
        else 
        {
            (q->rear)++;
            *(q->a+q->rear)=val;
        }
    }
}
void dequeue(Queue q)
{
    if(q->front==-1)
    {
        printf("empty");

    }
    else
     {
         q->count--;
         if(q->front==q->rear) 
         {
            q->front=-1;
           q->rear=-1;
         }
         else if(q->front==q->size-1)
         {
             q->front=0;
         }
         else 
         {
             (q->front)++;
         }
         q->a=(int*)realloc(q->a,sizeof(int)*(q->count));
    } 
}
void display(Queue q )
{
    if(q->count==0)
    {
        printf("epmpty");
    }
    else if(q->front<=q->rear) 
    {
        
      for(int i=q->front;i<=q->rear;i++)
      {
          printf(" %d ",*(q->a+i));
      }
    }
    else 
    {
        
        for(int i=q->front;i<q->size;i++)
        {
            printf(" Q[%d] = %d ",i,*((q->a)+i));
        } 
        for(int i=0;i<=q->rear;i++)
        {
            printf(" Q[%d] = %d ",i,*((q->a)+i));
        }
    }
}
void main()
{
    struct queue q;
    Queue Q;
    Q=&q;
    q.front=-1;
    q.rear=-1;
    int opr,val;
    q.count=0;
    q.size=5;
    q.a=(int *)malloc(0);
    do 
    {
        printf("\nenter \n1 to insert \n2 to display\n3 to delete\n4 to exit ");
        scanf("%d",&opr);
        switch(opr)
        {
            case 1:
                printf("enetr the val");
                scanf("%d",&val);
                insert(Q,val);
                break;
            case 2:
                display(Q);
                break;
            case 3:
                dequeue(Q);
                break;
            case 4:
                break;
            default:
                printf("wrong option");               
        }
    }while(opr!=4);
}
