#include<stdio.h>
#include<stdlib.h>
int count =0;
struct node
{
 int coeff,pow;
 struct node *link;
 };
 typedef struct node * NODE ;
NODE create(){
    NODE newNode;
    newNode=(NODE)malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("\nMemory allocation error!....");
        exit(0);
    }
    newNode->link=NULL; 
    return newNode;
}
NODE insert(NODE first,int pow,int coeff)
{
    count++;
    NODE new=create();
    new->coeff=coeff;
    new->pow=pow;
    if (first==NULL)
    {
        return new ;
    }
    else
    {
        new->link=first;
        return new ;
    }
    
}
NODE merge(NODE first1,NODE first2,NODE first3)
{
    NODE temp1=first1,temp2=first2;
   while(temp1!=NULL && temp2!=NULL)
   {
       
     if (temp1->pow>temp2->pow)
       {
           first3=insert(first3,temp1->pow,temp1->coeff);
           temp1=temp1->link;
       }
       else if(temp2->pow>temp1->pow) 
       {
           first3=insert(first3,temp2->pow,temp2->coeff);
           temp2=temp2->link;
       }
      else
       {
           first3=insert(first3,temp1->pow,temp1->coeff+temp2->coeff);
           temp1=temp1->link;
           temp2=temp2->link;
       }
       
   }
  if(temp1!=NULL)
   {
       first3=insert(first3,temp1->pow,temp1->coeff);
       temp1=temp1->link;
   }
   if(temp2!=NULL)
   {
       first3=insert(first3,temp2->pow,temp2->coeff);
       temp2=temp2->link;
   }
   return first3;
}
NODE display(NODE first )
{
    if(first==NULL)
    {
        printf("empty link list ");
        return first;
    }
    else 
    {
        NODE temp=first;
        while(temp!=NULL)
        {
            if(temp->coeff>0)
           
           { printf(" + %d X^%d ",temp->coeff,temp->pow);
            temp=temp->link;
           }
            else if(temp->coeff<0)
           
           { printf(" - %d X^%d ",temp->coeff,temp->pow);
            temp=temp->link;
           }
        }
        return first;
    }
}
void main()
{
    int opr,pow,coeff;
    NODE first1=NULL,first2=NULL,first3=NULL;
    do
    {
        printf("\n enter \n1 to insert \n2 to input in list 2 \n3 to merge \n4 to display \n5 to exit  ");
        scanf("%d",&opr);
        switch(opr)
        {
            case 1: 
                printf(" (enter in order with smallest first )enter the pow and coeff");
                scanf("%d %d",&pow,&coeff);
                first1=insert(first1,pow,coeff);
                break;
            case 2:
                printf("(enter in order with smallest first )enter the pow and coeff");
                scanf("%d %d",&pow,&coeff);
                first2=insert(first2,pow,coeff);
                break;
            case 4:
                printf("enter which one to display");
                scanf("%d",&pow);
                if(pow==1)
                first1=display(first1);
                if(pow==2)
                first2=display(first2);
                if(pow==3)
                first3=display(first3);
                else 
                printf("you idiot ");

                break;

            case 3:
                first3=merge(first1,first2,first3);
                break;
            case 5:
                break;    
            default:
                printf("idiot "); 
                break;   
        }
    } while (opr!=5);
    
}
