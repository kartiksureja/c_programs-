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
    char exp[20],*c,x,pre[20];
    c=exp;
    int k=0;
    stack s;
    s.top=-1;
    printf("enetr the epression");
    scanf("%s",exp);
    for(int i=strlen(exp)-1;*(c+i)!='\0';i--)
    {
        if(isalnum(*(c+i)))
        {
            pre[k++]=*(c+i);
        }
        else 
        {
            if(*(c+i)==')')
            {
                push(&s,*(c+i));
            }
            else if(*(c+i)=='(')
            {
                while((x=pop(&s))!=')')
                {
                    pre[k++]=x;
                }
            }
            else if(priority(*(c+i))>=priority(s.s[s.top]))
            {
                push(&s,*(c+i));
            }
            else 
            {
                while(priority(*(c+i))<priority(s.s[s.top]))
                {
                    x=pop(&s);
                   pre[k++]=x;

                }
                push(&s,*(c+i));
            }
        }
    }
    while(s.top!=-1)
    {
        pre[k++]=pop(&s);
    }
    for(int i=strlen(exp)-1;i>=0;i--)
    {
        printf("%c",pre[i]);
    }
}
