#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
struct stack
{
    char s[20];
    int top;
};
typedef struct stack stack ;
void push(stack *s,char c)
{
    s->top++;
    s->s[s->top]=c;
}
char pop(stack *s)
{
    return s->s[s->top--];
}
int priority(char c)
{
    if(c=='('||c==')')
    return 0;
    if(c=='+'||c=='-')
    return 1;
    if(c=='*'||c=='/')
    return 2;
    if(c=='^'||c=='$')
    return 3;
    else 
    return 0;
}
void main()
{
    char exp[20],*c,x;
    c=exp;
    stack s;
    s.top=-1;
    printf("enetr the epression");
    scanf("%s",exp);
    while((*c)!='\0')
    {
        if(isalnum(*c))
        {
            printf("%c",*c);
        }
        else 
        {
            if(*c=='(')
            {
                push(&s,*c);
            }
            else if(*c==')')
            {
                while((x=pop(&s))!='(')
                {
                    printf("%c",x);
                }
            }
            else if(priority(*c)>priority(s.s[s.top]))
            {
                push(&s,*c);
            }
            else 
            {
                while(priority(*c)<=priority(s.s[s.top]))
                {
                    x=pop(&s);
                    printf("%c",x);

                }
                push(&s,*c);
            }
        }
        c++;
    }
    while(s.top!=-1)
    {
        printf("%c",pop(&s));
    }
}
