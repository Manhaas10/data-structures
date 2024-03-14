#include <stdio.h>
#include <stdlib.h>
#define max 4
int stack[max];
int top=-1;
void push(int data){
    if(top==max-1){printf("STack overflow");return;}
    top++;
    stack[top]=data;
}
int pop(){
    int value;
    if(top==-1){printf("stack underflow");
    exit(1);//abnormal termination //termination with failure
    }
    value=stack[top];
    top=top-1;
    return value;
}
void print(){
    if(top==-1){printf("stack underflow");return;}
    for(int i=top;i>=0;i--){
        printf("%d",stack[i]);
        printf("\n");
    }
}
int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    int data=pop();
    print();
    printf("%d",pop());
}

