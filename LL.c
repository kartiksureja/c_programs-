#include<stdio.h>
#include<stdlib.h>
int counter=0;
typedef struct node * NODE;
struct node 
{
 int info;
 NODE link;
};
NODE create()
{
 NODE s;
   s=(NODE )malloc(sizeof(struct node ));
   s->link=NULL;
   counter=counter+1;
  return s;
}
void display(NODE p )
{
    NODE temp;
    temp=p;
    if(temp==NULL)
    {
      printf("no link");
    }
    while(temp!=NULL)
    {
        printf("->%d",temp->info);
        temp=temp->link;
    }
    
    
}

NODE addfront(NODE p)
{ NODE s;
  s=create();
  if(p==NULL)
  {
    printf("enter the info");
    scanf("%d",&(s->info));
    s->link=NULL;
    return s;
  }
  else
  { printf("enter the info");
   scanf("%d",&(s->info));
   s->link=p;
   return s;
  }
}
NODE insert(NODE p,int pos,int val)
{ int i=1;
  if(pos<1||pos>counter+1)
  {
    printf("wrong position");
    return p;
  }
  
  NODE temp=p;
  NODE new=create();
  new->info=val;
  if(pos==1)
  {
    new->link=temp;
    return new;
  }
  while(i<pos-1)
  {
   temp=temp->link;
   i++;
  }
  new->link=temp->link;
  temp->link=new;
  return p;

}
NODE delete_pos(NODE p,int pos)
{ 
  if(p==NULL)
  {
    printf(" no link list present ");
    return p;
  }
  if(pos<1||pos>counter)
  {
    printf("wrong position");
    return p;
  }
  int i=1;
  NODE temp,cur,prev;
  temp =p;
  cur =p;
  if(pos==1)
  {
    cur=cur->link;
    free(temp);
    counter--;
    return cur;
  }
  else 
  {
    while(i<pos)
    {
     prev=cur;
     cur=cur->link;
     i++;
    }
    prev->link=cur->link;
    printf("%d deleted",cur->info);
    free(cur);
    counter--;
    return p;
  }
}
NODE reverse(NODE p)
{
  if(p==NULL)
  {
    printf(" no link list present ");
    return p;
  }
  else if(counter==1)
  {
    printf("only one elment");
    return p;
  }
  else 
  {
    NODE temp,cur=NULL;
    while (p!=NULL)
    {
     temp=p;
     p=p->link;
     temp->link=cur;
     cur=temp;
    }
    return cur;

  }
}
NODE delete_val(NODE p,int value)
{
  NODE prv,cur;
  int flag=0;
  cur=p;
  
  if(p->info==value)
  { printf("2");
    printf("deleted 1st element ");
    free(cur);
    flag=1;
    counter--;
    return p->link;
  }
  while(cur->link!=NULL)
   {
     prv=cur;
     cur=cur->link;
     if(cur->info==value)
     {
       printf("deleted in between ");
       prv->link=cur->link;
       free(cur);
       flag=1;
       counter--;
       return p;
     }
  }
  if(flag==0)
  {
    printf("not present ");
    return p;
  }
}
NODE search(NODE p,int value)
{
  if(p==NULL)
  {
    printf("link list not present ");
    return p;
  }
  if(p->info==value)
  {
    printf("key found at position 1");
    return p;

  }
  NODE temp=p->link;
  int i=2;
  while(temp->link!=NULL)
  {
    if(temp->info==value)
    {
      printf("found at %d",i);
      return p;
    }
    temp=temp->link;
    i++;
  }
  return p;
}                                                                                                                                 

NODE update(NODE p,int key,int value)
{  int i;
  NODE temp=p;
  if(temp==NULL)
  {
    printf("empty");
    return p;
  }
  while(temp->info!=key && temp->link!=NULL)
  {
    temp=temp->link;
  }
  if(temp->info==key)
  {
    temp->info=value;
    return p;
  }
   else
 {
    printf("element not found ");
    return p;
  }
}
void main()
{
 
   
int x,size,opr,key,pos,value,*p;
NODE first=NULL;
printf("enter 1 to continue or any number to exit ");
scanf("%d",&x);
while(x==1)
{
    printf(" \nenter \n1-input new front  \n2-ouput\n3-insert in b/w\n4-reverse \n5-delete\n6-delete using value\nsearch\n8-update\n9-ordered\n101-exit\nyour choice=  ");
    scanf("%d",&opr);
    switch (opr)
    {
    case 1:
         first=addfront(first);
        break;
    case 2:
        display(first);
        break;
    case 3:
        printf("enter the key to added and its postion");
        scanf("%d %d",&value,&pos);
        first=insert(first,pos,value);
        break;
    case 4:
        first=reverse(first);
        break; 
    case 5:
        printf("enter the postion to be deleted");
        scanf("%d",&pos); 
        first=delete_pos(first,pos);
        break;
    case 6:
        printf("enter the value to be deleted");
        scanf("%d",&value); 
        first=delete_val(first,value);
        break;
    case 7:
        first=search(first,20);
        break; 
    case 8:
        printf("enter the key to changed and its new value ");
        scanf("%d%d",&key,&value);
        first=update(first,key,value);
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

  
