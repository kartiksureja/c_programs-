#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int info;
    struct node *rlink,*llink;
};
int count=0;
typedef struct node * NODE;
NODE create()
{
    NODE new;
    new=(NODE)malloc(sizeof(struct node));
    new->rlink=new;
    new->llink=new;
    return new;
}
NODE insert(NODE head,int val,int pos)
{
    if(pos<0||pos>head->info+1)
    {
        printf("invalid poositipn ");
        return head ;
    }
    else 
    {
        head->info++;
        NODE new=create(),temp;
        new->info=val;
        int i=1;
        temp=head->rlink;
        for(i=1;i<pos;i++)
        {
        temp=temp->rlink;
        }
        new->llink=temp->llink;
        new->rlink=temp;
        temp->llink->rlink=new;
        temp->llink=new;
        return head;
    }
}
NODE delete(NODE head,int pos )
{
    if(pos<1||pos>head->info)
    {
        printf(" wrong ");
        return head;
    }
    else 
    {
        NODE temp=head->rlink;
        int i=1;
        while(i<pos)
        {
            temp=temp->rlink;
            i++;
        }
        temp->rlink->llink=temp->llink;
        temp->llink->rlink=temp->rlink;
        free(temp);
        head->info--;
        return head;
    }
}
void display(NODE head )
{
    if(head->info==0)
    {
        printf("empty");
    }    
    else 
    {
        NODE temp=head->rlink;
        do
        {
            printf(" ->%d ",temp->info);
            temp=temp->rlink;
        } while (temp!=head);
        
    }

}
NODE reverse(NODE head )
{
    if(head->info==0)
    {
        printf(" npo element ");
        return head;
    }
    else if(head->info==1)
    {
        printf("only 1 element ");
        return head;
    }
    else 
    {
        NODE temp=head->rlink,new,cur=NULL;
        while(temp!=head)
        {
            new=temp;
            temp=temp->rlink;
            new->rlink=cur;
            new->llink=temp;
            cur=new;
        }
        cur->llink=head;
        head->rlink=cur;
        temp=cur;
        while(temp->rlink!=NULL)
        {
            temp=temp->rlink;
        }
       // head->llink=temp;
        temp->rlink=head;
        return head;
    }
}
NODE deleteval(NODE head,int val)
{
    if(head->info==0)
    {
        printf(" no element ");
        return head;
    }
    else 
    {
        int flag=1;
        NODE temp=head->rlink;
        for(int i=0;i<head->info;i++)
        {
            if(temp->info==val)
            {
                temp->llink->rlink=temp->rlink;
                temp->rlink->llink=temp->llink;
                head->info--;
                flag=0;
                break;


            }
            temp=temp->rlink;
        }
        if(flag==1)
        {
            printf("key not found");

        }
        return head;
    }
}
void main()
{
    int val,pos,key,opr;
    NODE head=create();
    head->info=0;
    do 
    {
        printf("\n enter \n 1 to insert \n 2 to display \n 3 to delete by  pos\n 4 to reverse \n 5 to delete bty valv\n ");
        scanf("%d",&opr);
        switch(opr)
        {
            case 1:
                    printf("enter the position and val ");
                    scanf("%d%d",&pos,&val);
                    head=insert(head,val,pos);
                    break;
            case 2:
                    display(head);
                    break;
            case 3:
                    printf("enter the position");
                    scanf("%d",&pos);
                    head=delete(head,pos);
                    break;

            case 4:
                    head=reverse(head);
                    display(head);
                    break;
            case 5 :
                    printf("enter the val");
                    scanf("%d",&val);
                    head=deleteval(head,val);
                    break;
            default:
                    printf(" wrong option ");
                    break;

        }
    }while(opr!=101);

}
