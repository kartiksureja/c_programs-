//Circular doubly linked list using header node
#include <stdio.h>
#include <stdlib.h>
typedef struct node* NODE;
struct node{
    int data;
    NODE rlink;
    NODE llink;
};
NODE create(){
    NODE newNode;
    newNode=(NODE)malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("\nMemory allocation error!....");
        exit(0);
    }
    newNode->rlink=newNode;
    newNode->llink=newNode; 
    return newNode;
}
void display(NODE header){
    NODE temp=header->rlink;
    if(header->rlink==header){
        printf("\nEmpty list!......");
        return ;
    }
    while(temp!=header){
        printf("%d\t",temp->data);
        temp=temp->rlink;
    }
}
void insAtBeg(NODE header,int val){
    NODE temp;
    temp=create();
    temp->data=val;
    temp->rlink=header->rlink;
    header->rlink->llink=temp;
    header->rlink=temp;
    temp->llink=header;
    header->data++;
}
NODE insAtEnd(NODE header,int val){
    NODE temp=create();
    temp->data=val;
    header->llink->rlink=temp;
    temp->llink=header->llink;
    temp->rlink=header;
    header->llink=temp;
    header->data++;
}
NODE insAtPos(NODE header,int val,int pos){
    NODE temp=header->rlink,newNode=create();
    newNode->data=val;
    int i=1;
    if(pos<1 || pos>header->data+1){
        printf("\nInvalid postion!......");
        return header;
    }
    while(i<pos){
        temp=temp->rlink;
        i++;
    }
    newNode->llink=temp->llink;
    temp->llink->rlink=newNode;
    newNode->rlink=temp;
    temp->llink=newNode;
    header->data++;
}
void delAtBeg(NODE header){
    NODE temp=header->rlink;
    if(header->rlink==header){
        printf("\nEmpty list!.......");
        return ;
    }    
    header->rlink=temp->rlink;
    temp->rlink->llink=header;
    free(temp);
    header->data--;
}
NODE delByPos(NODE header,int pos){
    NODE temp=header->rlink;
    int i=1;
    if(pos<1 || pos>header->data+1){
        printf("\nInvalid postion!......");
        return header;
    }
    while(i<pos){
        temp=temp->rlink;
        i++;
    }
    temp->rlink->llink=temp->llink;
    temp->llink->rlink=temp->rlink;
    free(temp);
    header->data--;
}
void delByVal(NODE header,int val){
    NODE temp=header->rlink;
    if(header->rlink==header){
        printf("\nEmpty list!....");
        return ;
    }
    while(temp->data!=val && temp!=header){
        temp=temp->rlink;
    }
    if(temp==header){
        printf("\nKey not found!.....");
        return ;
    }
    temp->rlink->llink=temp->llink;
    temp->llink->rlink=temp->rlink;
    free(temp);
    header->data--;
}
void delAtEnd(NODE header){
    NODE temp=header->llink;
    if(header->rlink=header){
        printf("\nEmpty list!.....");
        return ;
    }
    temp->llink->rlink=header;
    header->llink=temp->llink;
    free(temp);
    header->data--;
}
void search(NODE header,int val){
    NODE temp=header->rlink;
    int i=1;
    if(header->rlink==header){
        printf("\nEmpty list!.....");
        return ;
    }
    while(temp!=header){
        if(temp->data==val){
            printf("\nThe key found at position %d",i);
            return;
        }
        temp=temp->rlink;
        i++;
    }
    printf("\nKey not found!.....");
}
NODE reverse(NODE head)
{   
    int i;
    NODE temp=head->rlink,new,cur=head;
    
    for(i=0;i<head->data;i++)
    { 
        new=temp;
      temp=temp->rlink;  
      new->rlink=cur;
      new->llink=temp;
      cur=new;
    
    }
    head->rlink=cur;
    return head;
}
 NODE orderlis(NODE head1,int val)
 { NODE new=create();
 new->data=val;
     if(head1->data==0)
     { 
         head1->data++;
       new->rlink=head1;
       head1->rlink=new;
       new->llink=head1;
       head1->llink=new;
       return head1;
     }
     head1->data++;
     NODE temp=head1->rlink,prv;
     if(val<temp->data)
     {
         temp->llink=new;
         head1->rlink=new;
         new->rlink=temp;
         new->llink=head1;
         return head1;
     }
     while(val>temp->data&&temp!=head1)
     {
         prv=temp;
         temp=temp->rlink;
     }
     prv->rlink=new;
     new->llink=prv;
     new->rlink=temp;
     temp->llink=new;
     return head1;
 }
 /*NODE copy(NODE header,NODE head1)
 {
     NODE new,temp=header->rlink,cur=header;
     if(temp==header)
     {
         printf("empty");
         return header;
     }
     for(int i=0;i<header->data+1;i++)
     {     
           head1->data++;
           NODE new=create();
           new->data=temp->data;
           if(i=0)
           {
               new->llink=head1;
               head1->rlink=new;
              
           }
           else
           {
             new->llink=cur;
             cur->rlink=new;
           }
           cur=new;
     }
     cur->rlink=head1;
     head1->llink=cur;
  
   return head1;

 }*/
 NODE copy(NODE header,NODE head1)
{
    if(header->rlink==header)
    {
        printf("empty list ");
        return head1;
    }
    NODE temp=create(),prv,cur=header ;
    temp->data=cur->data;
    cur=cur->rlink;
    prv=temp;
    head1=temp;
   for(int i=0;i<header->data;i++)
   {
      NODE temp=create();
      temp->data=cur->data;
      temp->llink=prv;
      prv->rlink=temp;
      prv=temp;
      cur=cur->rlink;
   }

    head1->llink=prv;
    prv->rlink=head1;
    return head1;
}

void main(){
    NODE header=create(),head1=create(),cur,temp;
    header->data=0;
    head1->data=0;
    int ch,i,val,pos;
    for(;;){
        printf("\n1.Read\n2.Display\n3.Insert at beginning\n4.Insert at position\n5.Insert at end\n6.Delete the beginning\n7.Delete by pos\n8.Delete by value\n9.Delete the end\n10.Search by value\n11.Reverse the list\n12.Copy the list\n13.Exit\nEnter your choice>>");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:cur=NULL;printf("\nEnter the number of terms>>");scanf("%d",&(header->data));
                for(i=0;i<header->data;i++){
                    temp = create();
                    printf("Enter the data>>");
                    scanf("%d",&(temp->data));
                    if(header->rlink==header){
                        header->rlink=temp;
                        temp->llink=header;
                        temp->rlink=header;
                        header->llink=temp;
                        cur=temp;
                    }
                    else{
                        cur->rlink=temp;
                        temp->llink=cur;
                        temp->rlink=header;
                        header->llink=temp;
                        cur=temp;
                    }
                }
            break; 
        case 2:display(header);break;
        case 3:printf("\nEnter the value to be inserted>>");scanf("%d",&val);insAtBeg(header,val);break;
        case 4:printf("\nEnter the postion where value to be inserted>>");
            scanf("%d",&pos);
            printf("Enter the value to be inserted>>");
            scanf("%d",&val);
            insAtPos(header,val,pos);
            break;
        case 5:printf("\nEnter the value to be inserted>>");scanf("%d",&val);insAtEnd(header,val);break;
        case 6:delAtBeg(header);break;
        case 7:printf("\nEnter the position where value to be deleted>>");
            scanf("%d",&pos);delByPos(header,pos);break;
        case 8:printf("\nEnter the value to be deleted>>");scanf("%d",&val);delByVal(header,val);break;
        case 9:delAtEnd(header);break;
        case 10:printf("\nEnter the value to search>>");scanf("%d",&val);search(header,val);break;
        case 11:header=reverse(header);break;
        case 12: printf("enter the info");
        scanf("%d",&val);
        head1=orderlis(head1,val);
        display(head1);
        break;
        case 13:
        head1=copy(header,head1);
        display(head1);

        break;
        default:exit(0);
        }
    }
}
