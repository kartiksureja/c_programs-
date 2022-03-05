#include<stdlib.h>
#include<stdio.h>
struct time {
    int min,hr,sec;
};
typedef struct time time;

void input(time *t)
{
    printf("enter the hour ");
    scanf("%d",&(t->hr));
    printf("enter the min(<60)");
    scanf("%d",&(t->min));
    printf("enter the sec(60)");
    scanf("%d",&(t->sec));
    
}
void display(time *t)
{
 printf("%0.2d : %d : %d",t->hr,t->min,t->sec);
}
void update(time *t)
{
    (t->sec)++;
    if(t->sec==60)
    {
        t->sec=0;
        t->min++;
        if(t->min==60)
       {
        t->min=0;
        t->hr++;
        
       }  
    }
}
time add(time *t1,time *t2)
{
    time t3;
    t3.min=0;
    t3.hr=0;
   // printf("enter hour,min,sec for t1");
    //scanf("%d %d %d",&(t1->hr),&(t1->min),&(t1->sec));
    //printf("enter hour,min,sec for t2");
    //scanf("%d %d %d",&(t2->hr),&(t2->min),&(t2->sec));
    input(t1);
    input(t2);
    t3.sec=(t1->sec)+(t2->sec);
    if(t3.sec>=60)
    {
        t3.sec=t3.sec-60;
        t3.min++;
        if(t3.min==60)
       {
        t3.min=0;
        t3.hr++;
        
       }  
    }
    t3.min=t3.min+(t1->min)+(t2->min);
    if(t3.min>=60)
    {
        t3.min=t3.min-60;
        t3.hr++;
    }
    t3.hr=t3.hr+(t1->hr)+(t2->hr);
    printf("\nthe sum is =");
    display(&t3);

}
void main()
{    
    int x,opr,size;
    time *t,t1,t2;
    printf("enter 1 to continue or any number to exit ");
    scanf("%d",&x);
    while(x==1)
    {
        printf("\n1-input \n2-ouput\n3-update\n4-add\n5-exit\nyour choice= ");
        scanf("%d",&opr);
        switch (opr)
        {
            case 1:
                    t=(time *)malloc(sizeof(time ));
                    if(t==NULL)
                    {
                        printf("memory error ");
                    }
                    input(t);
                    break;
            case 2:
                    display(t);
                    break;
            case 3:
                   update(t);
                   display(t);
                   break;       
            case 4:
                    add(&t1,&t2);
                    break;
            case 5:
                   x=0;
                   break;        
            default:
                    printf("wrong choice ");
                    break;        
        }
    }        
}
