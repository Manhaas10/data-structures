#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
};
void add_at_end(struct node *head,int d){
    struct node *temp,*ptr;
    ptr=head;
    ptr=(struct node*)malloc(sizeof(struct node));
    temp->data=d;
    temp->link=NULL;
    while(ptr->link!=NULL){    
     ptr=ptr->link;
    }
    ptr->link=temp;
    printf("%d",(ptr->link->data));
    
}
void print_node(struct node *head){
    int c=0;
    if(head==NULL)
    printf("empty");
    struct node *ptr=NULL;
    ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
}
int main(){
    struct node *head =malloc(sizeof(struct node));

    head->data=45;
    head->link=NULL;
    struct node *current=malloc(sizeof(struct node));
    current->data=98;
    current->link=NULL;
    head->link=current;
    struct node *current2=malloc(sizeof(struct node));
    current2->data=8;
    current2->link=NULL;
    //current->link=current2; it same as below one
    head->link->link=current2;
add_at_end(head,90);
//print_node(head);
    //printf("%d",head->link);



}