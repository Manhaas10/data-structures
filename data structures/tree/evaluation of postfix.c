#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack{
    int top;
    int size;
    int* a;
};
typedef struct stack* stack;
stack create_stack(int n){
    if(n==0) return NULL;
    stack stack=malloc(sizeof(struct stack));
    stack->size=n;
    stack->a=(int*)malloc(n*sizeof(int));
    stack->top=-1;
    return stack;
}
int isempty(stack stack){
    return stack->top==-1;
}
int isfull(stack stack){
    return stack->top==stack->size-1;
}
int peek(stack stack){
    if(isempty(stack))return -1;
    return stack->a[stack->top];
}
void push(stack stack,int o){
    if(isfull(stack)){return;}
    stack->a[++stack->top]=o;
}
int pop(stack stack){
    if(isempty(stack))return-1;
    return stack->a[stack->top--];
}
int check_n(char ch){
    return (ch>='0' && ch<='9');
}
int isop(char val)
{
  return (val == '+' || val == '-' || val == '*' || val == '/' );
}

int convert(char s[]){
    int n=atoi(s);
    return n;
}
int operation(stack stack,char ch){
    int d1,d2,d3;
    switch(ch){
        case '+':
          d1=pop(stack);
          d2=pop(stack);
          d3=d2+d1;
          push(stack,d3);
          break;
        case '-':
          d1=pop(stack);
          d2=pop(stack);
          d3=d2-d1;
          push(stack,d3);
          break;
        case '*':
          d1=pop(stack);
          d2=pop(stack);
          d3=d2*d1;
          push(stack,d3);
          break;
        case '/':
          d1=pop(stack);
          d2=pop(stack);
          d3=d2/d1;
          push(stack,d3);
          break;
    }
}
int main(){
    char s[100];
    fgets(s,sizeof(s),stdin);
    int i=0;int j=0;
    char us[100]={'\0'};
    stack stack=create_stack(100);
    while(s[i]!='\0'){
        if(check_n(s[i])){
            us[j++]=s[i];
            if(s[i+1]==' '){us[j]='\0';push(stack,convert(us));us[0]='\0';j=0;}
            
        }
        else if(isop(s[i])){
            if(isempty(stack) || stack->top==0){
            printf("-1");
            while(!isempty(stack)){
                pop(stack);
            }
            break;}else{
            operation(stack,s[i]);
            }
        }
    i++;}
    if(!isempty(stack))
    printf("%d",peek(stack));
}
