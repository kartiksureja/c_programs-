#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
struct stack
{
    char s[50];
    int top;
};
typedef struct stack stack;
void push(stack *s,char c)
{
    s->top++;
    s->s[s->top]=c;
}
char pop(stack *s)
{
    return s->s[(s->top--)];
}
void main()
{
    char exp[50],*c,o1,o2,o3;
    stack s;
    int opr;
    s.top=-1;
    c=exp;
    do{
      printf("\nenter 1 for post\n2 for pre \n3 to exit");
      scanf("%d",&opr);
      switch(opr){
       case 1: 
          printf("enter the express");
          scanf("%s",exp);
          c=exp;
          while((*c)!='\0')
         {
            if(isalnum(*c))
                {
                    push(&s,(*c)-48);
                }
          else 
          {
            o2=pop(&s);
            o1=pop(&s);
            if(*c=='+')
            {
                o3=o1+o2;
            }
            else if(*c=='-')
            {
                o3=o1-o2;
            }
            else if(*c=='*')
            {
                o3=o1*o2;
            }
            else if(*c=='/')
            {
                o3=o1/o2;
            }

            else if(*c=='^')
            {
                o3=pow(o1,o2);
            }
            push(&s,o3);

         }
         c++;
        }
         printf("the solution is  %d",pop(&s));
         break;
        case 2 :
           printf("enter the express");
           scanf("%s",exp);
           c=exp;
           for(int i=strlen(exp)-1;i>=0;i--)
         {
          if(isalnum(*(c+i)))
          {
            push(&s,(*(c+i)-48));
          }
          else 
          {
            o2=pop(&s);
            o1=pop(&s);
            if(*(c+i)=='+')
            {
                o3=o1+o2;
            }
            else if(*(c+i)=='-')
            {
                o3=o1-o2;
            }
            else if(*(c+i)=='*')
            {
                o3=o1*o2;
            }
            else if(*(c+i)=='/')
            {
                o3=o1/o2;
            }

            else if(*(c+i)=='^')
            {
                o3=pow(o1,o2);
            }
            push(&s,o3);

           }
        }
         printf("the solution %d",pop(&s));
         break;
        case 3:
        exit(0);
        }
    }while(opr!=3);   

        
}
