#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
};
void count_node(struct node *head){
    int c=0;
    if(head==NULL)
    printf("empty");
    struct node *ptr=NULL;
    ptr=head;
    while(ptr!=NULL){
        c++;
        ptr=ptr->link;
    }
    printf("%d",c);
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
count_node(head);
    //printf("%d",head->link);



}