#include<stdio.h>
#include<stdlib.h>
struct student
{
int roll,m1,m2,m3;
double avrg;
char name[20];

};
typedef struct student STD;

double avarage(int a,int b,int c)
 {  int i; 
    int arr[3]={a,b,c}, temp;
    for(i=0;i<3;i++)
    {
        if(arr[i]<arr[i+1])
        {
            temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;

        }
        
    }
   return (arr[0]+arr[1])/2.0;

}
void input(STD *s)
{
    
        printf("enter the roll number ");
        scanf("%d",(s->roll));
        printf("enter the name  ");
        scanf("%s",&(s->name));
        printf("enter the marks of test 1 ");
        scanf("%d",&(s->m1));
        printf("enter the marks of test 2 ");
        scanf("%d",&(s->m2));
        printf("enter the marks of test 3 ");
        scanf("%d",&(s->m3));
        (s->avrg)=avarage((s->m1),(s->m2),(s->m3));
    
    
}
void display(STD *s,int n)
{   int i;
    printf("   roll no     ");
    printf("   name        ");
    printf("   marks 1     ");
    printf("   marks 2     ");
    printf("   marks 3     ");
    printf("   avarage     ");
    for(i=0;i<n;i++)
    {
    printf("\n   %d          ",(s+i)->roll);
    printf("   %s          ",((s+i)->name));
    printf("   %d          ",(s+i)->m1);
    printf("   %d          ",(s+i)->m2);
    printf("   %d          ",(s+i)->m3);
    printf("   %lf          ",(s+i)->avrg);
    }
}
void main()
{    
    int x,opr,size;
    STD *s;
    printf("enter 1 to continue or any number to exit ");
    scanf("%d",&x);
    while(x==1)
    {
        printf("\n1-input \n2-ouput\n3-exit\nyour choice= ");
        scanf("%d",&opr);
        switch (opr)
        {
            case 1:
                    printf("enter the number of entries");
                    scanf("%d",&size);
                    s=(STD *)calloc(size,sizeof(STD ));
                    if(s==NULL)
                    {
                        printf("memory error ");
                    }
                    for(int i=0;i<size;i++)
                    {
                    input(s+i);
                    }
                    break;
            case 2:
                    display(s,size);
                    break;
            case 3:
                    x=0;
                    break;
            default:
                    printf("wrong choice ");
                    break;        
        }
    }        
}


