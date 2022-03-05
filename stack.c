#include<stdlib.h>
#include<stdio.h>

struct stack{
    int info;
    struct stack *link;
};
typedef struct stack* STACK;
STACK push(STACK top,int val)
{
    STACK new;
    new=(STACK)malloc(sizeof(struct stack));
    new->info=val;
    new->link=top;
    return new;
}
STACK pop(STACK top)
{
    if(top==NULL)
    {printf("empty stack");
    return top;
    }
    STACK temp=top;
    top=top->link;
    printf("%d deleted",temp->info);
    free(temp);
    return top;
    }
void display(STACK top)
{
    if(top==NULL)
    {
        printf("empty stack ");
    }
    STACK temp=top;
    while(temp!=NULL)
    {
        printf("%d \n",temp->info);
        temp=temp->link;
    }
}
void main()
{   int val,x;
    STACK top=NULL;
    do {
        printf("enter \n1 to push \n2 to peek \n3 to pop \n4 to sidplay\n5 to exit ");
        scanf("%d",&x);
        switch(x)
        {
            case 1:
                   printf("enetr the val to entered ");
                   scanf("%d",&val);
                   top=push(top,val);
                   break;
            case 2:
                   printf("%d",top->info);
                   break;
            case 3:
                    top=pop(top);  
                    break;
                    
            case 4: 
                   display(top);    
                   break;
            case 5:
                   break;
            default:
                   printf("wrong");
                   break;                
        }
    }while(x!=5);
}
