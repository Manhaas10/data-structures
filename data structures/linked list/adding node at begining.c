#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node* add_node(struct node *ptr,int d){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=d;
    temp->link=NULL;

    ptr->link=temp;
    return temp;
    
}
struct node* add_at_begining(struct node *head,int d){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=d;
    temp->link=NULL;
    temp->link=head;
    head=temp;
    return head;
}
int main(){
    struct node *head =malloc(sizeof(struct node));

    head->data=45;
    head->link=NULL;
   struct node *ptr=head;
   ptr=add_node(ptr,90);
   ptr=add_node(ptr,63);
   ptr=add_node(ptr,40);
   ptr=add_node(ptr,14);
   head=add_at_begining(head,10);

ptr=head;
while(ptr!=NULL){   
    printf("%d ",ptr->data); 
     ptr=ptr->link;
    }

}