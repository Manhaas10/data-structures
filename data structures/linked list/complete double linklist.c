#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
    int key;
    struct node *next;
    struct node *prev;
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
    temp->prev=NULL;
    return temp;
}
void list_insert_front(linkedlist L,node x){
    if(!(L->head)){L->head=x;}
    else{
    x->next=L->head;
    x->prev=NULL;
    L->head->prev=x;
    L->head=x;
}}
void list_insert_tail(linkedlist L,node x){
    node p;
    if(L->head==NULL){L->head=x;}
    else{
        p=L->head;
        while(p->next){  p=p->next; }
        p->next=x;
        x->prev=p;
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
    if(y!=NULL && y->next){
    x->prev=y;
    x->next=y->next;
    y->next->prev=x;
    y->next=x;
}}
void list_insert_before(linkedlist L,node x,node y){
    node temp=L->head;
    if(L->head==y){
        list_insert_front(L,x);
    }
    else{
        x->prev=y->prev;
        x->next=y;
        if(y->prev!=NULL){
            y->prev->next=x;
        }
        y->prev=x;
    }}
int list_delete(linkedlist L, node x) {
    if (!x || !L->head) {return -1;}
    int k = x->key;
    if (x->prev) {
        x->prev->next = x->next;
    } else {
        L->head = x->next;
        if (L->head) {
            L->head->prev = NULL;
        }
    }
    if (x->next) {
        x->next->prev = x->prev;
    }

    free(x);
    return k;
}

int list_delete_initial(linkedlist L){
    if (L->head==NULL) {
        return -1; }
    node temp=L->head;
    int k=temp->key;
    L->head=temp->next;
    if(L->head){L->head->prev=NULL;}
    free(temp);
    return k;
}


int list_delete_last(linkedlist L){
    int k=-1;
    if (L->head==NULL) {
        return -1; }
    node temp=L->head;
    while(temp->next){
        temp=temp->next;
    }
    k=temp->key;
    if(temp->prev){
        temp->prev->next=NULL;
    }
    else{L->head=NULL;}
    free(temp);
    return k; 
}
void list_display(linkedlist L){
     node current=L->head;
    while(current!=NULL){
  printf("%d ",current->key);
  current=current->next;
}
printf("\n");
}
void list_reverse_negative(linkedlist L) {
    int a[100]={0};
    int i=0;
    node temp=L->head;
    while(temp!=NULL){
        if(temp->key<0){
            a[i++]=temp->key;
            //i++;
        }
        temp=temp->next;
    }
    temp=L->head;
    i--;
    while(temp!=NULL){
        if(temp->key<0){
            temp->key=a[i--];
        }
        temp=temp->next;
    }
    list_display(L);
}

int main(){
     linkedlist L = (linkedlist)malloc(sizeof(struct linkedlist));
    L->head=NULL;
    
    int k;
    node x;node y;
    char option[5];
    char s[]={"rn"};
    char st[]={"ds"};
    while(option[0]!='e'){
        scanf("%s",option);
        if(strcmp(option,s)==0){list_reverse_negative(L);}
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
                k=list_delete_initial(L);
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
            case 'e':
            break;
            default:
             break;
        }
    }}
    return 1;
}

