#include <stdio.h>
#include <stdlib.h>
struct stack {
    int top;
    char a[100];
};
typedef struct stack* stack;

int stack_empty(stack s){
    if(s->top==-1) return -1;
    return 1;
}
int stack_full(stack s,int n){
    if(s->top==n-1)return -1;
    return 1;
}
void push(stack s,char k,int n){
    if(stack_full(s,n)==-1)
    printf("-1\n");
    else{
    s->top++;
    s->a[s->top]=k;
    }  
}
void pop(stack s){
    if(stack_empty(s)==-1)printf("-1\n");
    else{    
    printf("%c\n",s->a[s->top]);
    s->top--;}
}
void peek(stack s){
    if(stack_empty(s)==-1)printf("-1\n");
    else{
    printf("%c\n",s->a[s->top]);
}}
int main(){
    stack s=malloc(sizeof(struct stack));
    s->top=-1;
    int n;
    scanf("%d",&n);
    char choice;
    char in;
    while(choice!='t'){
        scanf(" %c",&choice);
        switch(choice){
            case 'i':
             scanf(" %c",&in);
             push(s,in,n);
             break;
            case 'd':
             pop(s);
             break;
            case 'p':
             peek(s);
             break;
            case 't':
             break;
        }
    }
    return 1;

}