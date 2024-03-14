#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
    int top;
    int size;
    char* a;
};
typedef struct stack* stack;
stack create_stack(int n){
    if(n==0) return NULL;
    stack stack=malloc(sizeof(struct stack));
    stack->size=n;
    stack->a=(char*)malloc(n*sizeof(char));
    stack->top=-1;
    return stack;
}
int isempty(stack stack){
    return stack->top==-1;
}
int isfull(stack stack){
    return stack->top==stack->size-1;
}
char peek(stack stack){
    if(isempty(stack))return -1;
    return stack->a[stack->top];
}
void push(stack stack,char o){
    if(isfull(stack)){return;}
    stack->a[++stack->top]=o;
}
char pop(stack stack){
    if(isempty(stack))return-1;
    return stack->a[stack->top--];
}
int check_letter(char ch){
    return (ch>='A' && ch<='Z');
}
int pre(char ch){
    if(ch=='+' || ch== '-'){
        return 1;
    }
    else if(ch== '*' || ch== '/')return 2;
    else if(ch=='^')return 3;
    else
    return -1;
}
int isop(char val)
{
  if (val == '+' || val == '-' || val == '*' || val == '/' || val == '^')
  {
    return 1;
  } else {
    return 0;
  }
}

int main(){
    int n;
    scanf("%d",&n);
    stack stack=create_stack(n);
    char ch;
    int j=0;
    char a[n];
    int i;
    for( i=0;i<n;i++){
        scanf(" %c",&ch);
        if(check_letter(ch)){
        a[j++]=ch;}
        else if(ch=='('){
        push(stack,ch);}

        else if(ch==')'){
            while(!isempty(stack) && peek(stack)!='('){
            a[j++]=pop(stack);
            }
            if(!isempty(stack) && peek(stack)=='(')
            pop(stack);
        }
        else if(isop(ch)){
            while(!isempty(stack) && peek(stack)!='(' && pre(ch)<=pre(peek(stack)) ){
                a[j++]=pop(stack);
            }
            push(stack,ch);
        }
    }

    for(int i=0;i<j;i++){
        printf("%c",a[i]);}
    
    while(!isempty(stack)){
        printf("%c",pop(stack));
    }

















}