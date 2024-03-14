#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
    int key;
    struct node *next;
};
struct linkedlist{
    struct node *head;
};
typedef struct node* node;
typedef struct linkedlist* linkedlist;

node create_node(int k){
    node temp;
    temp=(node)malloc(sizeof(struct node));
    temp->key=k;
    temp->next=NULL;
    return temp;
    }
void list_insert_front(linkedlist L,node x){
    x->next=L->head;
    L->head=x;  
}
void list_insert_tail(linkedlist L,node x){
    node p;
    if(L->head==NULL){L->head=x;}
    else{
        p=L->head;
        while(p->next!=NULL)
        p=p->next;
        p->next=x;
    }
}
node list_search(linkedlist L,int k){
    node temp=L->head;
    if(temp!=NULL){
    while(temp!=NULL){
        if(temp->key==k){return temp;}
        temp=temp->next;
    }}
return NULL;
}
void list_insert_after(linkedlist L,node x,node y){
   node temp=L->head;

    if(y!=NULL){
    x->next=y->next;
    y->next=x;
}}

void list_insert_before(linkedlist L,node x,node y){
    node temp=L->head;
    node prev=NULL;

    if(L->head==y){
        list_insert_front(L,x);
    }
    else{
        while(temp!=y && temp!=NULL ){
            prev=temp;
            temp=temp->next;
        }
        if(temp==y){
        prev->next=x;
        x->next=y;
    }

}}
int list_delete(linkedlist L,node x){

    node new=L->head;
    int k;
    if(new==x){
        k=x->key;
        L->head=x->next;
        free(x);
        return k;
        
    }
    else{
    while(new->next!=NULL && new->next!=x){

        new=new->next;
    }
    if(new->next!=NULL){
        k=x->key;
        new->next=x->next;
        free(x);
        return k;
    }}}
int list_delete_front(linkedlist L){
    int key;
    node new_head=L->head;
    if(new_head!=NULL){
    L->head=new_head->next;
     key=new_head->key;
    free(new_head);
    return key;
}else{return -1;}}
int list_delete_last(linkedlist L){
    int key=-1;
    node current=L->head;

    node prev;
    while(current->next!=NULL){
     prev=current;
     current=current->next; }
     if(prev){prev->next=NULL;}
     else{L->head=NULL;}
     key=current->key;
     free(current);
 return key;
}


void list_display(linkedlist L) {
    node current=L->head;
    while(current!=NULL){
  printf("%d ",current->key);
  current=current->next;
}
printf("\n");
}
void list_reverse(linkedlist L){
    node prev=NULL;
    node current=L->head;
    node next=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;/-
    }
    L->head=prev;
    list_display(L);

}
void list_reverse_even(linkedlist L){
    node current=L->head;
    linkedlist even=(linkedlist)malloc(sizeof(struct linkedlist));
    even->head=NULL;
    node e=even->head;
    while(current!=NULL && current->next){
            node temp=current->next;
            current->next=temp->next;
            temp->next=e;
            e=temp;
        
        current=current->next;
    }
    current=L->head;
    while(e!=NULL){
        node temp=e->next;
        e->next=current->next;
        current->next=e;
        e=temp;
        current=current->next->next;
    }
    list_display(L);
    
}

int main(){
    linkedlist L = (linkedlist)malloc(sizeof(struct linkedlist));
    L->head=NULL;
    
    int k;
    node x;node y;
    char option[5];
    char s[]={"re"};
    char st[]={"ds"};
    while(option[0]!='e'){
        scanf("%s",option);
        if(strcmp(option,s)==0){list_reverse_even(L);}
        else if(strcmp(option,st)==0){list_display(L);}
        else{
        switch(option[0]){
            case 'f':
                scanf("%d",&k);
                x=create_node(k);
                list_insert_front(L,x);
                break;
            case 't':
                scanf("%d",&k);
                x=create_node(k);
                list_insert_tail(L,x);
                break;
            case 'a':
                 scanf("%d",&k);
                 x=create_node(k);
                 scanf("%d",&k);
                 y=list_search(L,k);
                 if(y!=NULL){list_insert_after(L,x,y);}
                 else{free(x);}
                 break;
            case 'b':
                 scanf("%d",&k);
                 x=create_node(k);
                 scanf("%d",&k);
                 y=list_search(L,k);
                 if(y!=NULL){list_insert_before(L,x,y);}
                 else{free(x);}
                 break;
            case 'd':
                 scanf("%d",&k);
                 x=list_search(L,k);
                 if(x!=NULL){
                    k=list_delete(L,x);
                    printf("%d\n",k);
                 }
                 else{printf("-1");}
                 break;

            case 'i':
                k=list_delete_front(L);
                printf("%d\n",k);
                break;

            case 'l':
               k=list_delete_last(L);
               printf("%d\n",k);
               break;
            case 's':
            scanf("%d",&k);
            x=list_search(L,k);
            if(x!=NULL){
                printf("1\n");
            }
            else{printf("-1\n");}
            break;
            case 'r':
             list_reverse(L);
             break;
            case 'e':
            break;
            default:
             break;
        }
    }}
    return 1;
}
