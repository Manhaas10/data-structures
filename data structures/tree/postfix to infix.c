#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
    int top;
    int size;
    char** a;
};
typedef struct stack* stack;
stack create_stack(int capacity){
    stack stack=malloc(sizeof(struct stack));
    stack->top=-1;
    stack->size=capacity;
    stack->a=(char**)malloc(capacity*sizeof(char*));
    for (int i = 0; i < capacity; i++) {
        stack->a[i] = (char*)malloc(100 * sizeof(char));
        stack->a[i][0] = '\0';
    }
    return stack;
}
int isempty(stack stack){
    return stack->top==-1;
}
int isfull(stack stack){
    return stack->top==stack->size-1;
}
char* peek(stack stack){
    if(isempty(stack))return NULL;
    return stack->a[stack->top];
}
void push(stack stack, char* o) {
    if (isfull(stack)) {return; }
    char* temp = (char*)malloc((strlen(o) + 1) * sizeof(char));
    strcpy(temp, o);
    stack->a[++stack->top] = temp;
}
char* pop(stack stack){
    if(isempty(stack))return NULL;
    return stack->a[stack->top--];
}
int check_l(char ch){
    return (ch>='A' && ch<='Z') || (ch>='a' && ch<= 'z');
}
int check_n(char ch){
    return (ch>='0' && ch<='9');
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
    int i=0;
    char s[100];
    scanf("%s",s);
    stack stack=create_stack(100);
    int j=0;
    while(s[i]!='\0'){
        if(check_l(s[i]) || check_n(s[i])){
            char aa[2]={s[i],'\0'};
            push(stack,aa);

        }
        else if(isop(s[i])){
            j=0;
            if(s[i+1]!='\0'){
                j=0;
                char temp[100]={"\0"};
                temp[j++] = '(';
                char* x1=pop(stack);
                char* x2=pop(stack);
                if(strlen(x1)==1 && strlen(x2)==1){
                    temp[j++]=x2[0];
                    temp[j++]=s[i];
                    temp[j++]=x1[0];
                    temp[j++]=')';
                    temp[j]='\0';
                }
                else {
                    strcat(temp,x2);
                    temp[strlen(temp)] = s[i];
                    strcat(temp,x1);
                    char ss[]={")"};
                    strcat(temp,ss);
                    temp[strlen(temp)]='\0';
                }
                    push(stack,temp);


                    }
            else {
                 j=0;
                 char temp[100];
                 temp[0]='\0';
                 char* x1=pop(stack);
                char* x2=pop(stack);

                if(strlen(x1)==1 && strlen(x2)==1){
                    temp[j++]=x2[0];
                    temp[j++]=s[i];
                    temp[j++]=x1[0];
                    temp[j]='\0';

                }
                else {
                    j=0;
                    strcat(temp,x2);
                    
                    temp[strlen(temp)]='\0';
                    j=strlen(temp);
                    temp[j] = s[i];
                    temp[j+1]='\0';
                    strcat(temp,x1);
                    j=strlen(temp);
                    temp[j]='\0';
                }
                    push(stack,temp);
                     
}

        }
        i++;
        j=0;
    }
    printf("%s", stack->a[stack->top]);
     }