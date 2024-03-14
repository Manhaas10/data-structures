#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct stack_char{
    int top;
    char a[100];
};
struct stack_int{
    int top;
    float aa[100];
};
struct treenode {
    char data;
    struct treenode* left;
    struct treenode* right;
};
struct Stack {
    int top;
    struct treenode** arr;
};


typedef struct stack_char* stackc;
typedef struct stack_int* stacki;
typedef struct Stack* stack;
typedef struct treenode* node;
stack is(int size) {
     stack stack =malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->arr = (struct treenode**)malloc(size * sizeof(struct treenode*));
    return stack;
}
void push(stack stack, node node) {
    stack->arr[++stack->top] = node;
}
node pop(stack stack) {
    if (stack->top == -1) {
        return NULL; // Empty stack
    }
    return stack->arr[stack->top--];
}
node create_node(char data){
    node newnode = malloc(sizeof(struct treenode));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

stackc create_stackc(){
    stackc stackc=malloc(sizeof(struct stack_char));
    stackc->top=-1;
    return stackc;
}
stacki create_stacki(){
    stacki stacki=malloc(sizeof(struct stack_int));
    stacki->top=-1;
    return stacki;
}
int isemptyi(stacki stack){
    return stack->top==-1;
}
int isemptyc(stackc stack){
    return stack->top==-1;
}

char peek_char(stackc stack){
    if(isemptyc(stack))return -1;
    return stack->a[stack->top];
}
float peek_int(stacki stack){
    if(isemptyi(stack))return -1;
    return stack->aa[stack->top];
}
void push_char(stackc stack,char o){
    stack->a[++stack->top]=o;
}
void push_int(stacki stack,float o){
    stack->aa[++stack->top]=o;
}
char pop_char(stackc stack){
    return stack->a[stack->top--];
}
float pop_int(stacki stack){
    return stack->aa[stack->top--];
}
int check_n(char ch){
    return (ch>='0' && ch<='9');
}
float convert(char s[]){
    float n=atof(s);
    return n;
}
int isop(char val)
{
  return (val == '+' || val == '-' || val == '*' || val == '/' );
}
float evaluate(char* s){
    stacki stack=create_stacki();
    int i=0; int c=0;   char us[100]={'\0'};int j=0;
    while(s[i]!='\0'){
        if(check_n(s[i]) || s[i]=='.'){//imp
            us[j++]=s[i];
            if(s[i+1]==' '){us[j]='\0';push_int(stack,convert(us));us[0]='\0';j=0;} 
        }
        else if(isop(s[i])) {
            float op1=pop_int(stack);
            float op2=pop_int(stack);
            switch(s[i]){
                case '+':
                push_int(stack,op2+op1);
                break;
                case '-':
                push_int(stack,op2-op1);
                break;
                case '*':
                push_int(stack,op2 * op1);
                break;
                case '/':
                 if(op1==0){
                    return -1.11;
                 }
                 push_int(stack,op2/op1);
                 break;
            }
        }i++;}
return peek_int(stack);
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
void itop(char* s,char** o){
    stackc stack=create_stackc();
    int j=0;
    char a[100];
    int i;int k=0;int n=100;
    *o=(char*)malloc(n*sizeof(char));
    *o[0]='\0';
        for( i=0;s[i]!='\0';i++){
        if(check_n(s[i])){
        a[j++]=s[i];
        if(s[i+1]==' '){a[j++]=' ';a[j]='\0';}
        //if(s[i+1]=='\0'){a[j++]=' ';a[j]='\0';}
        }
        else if(s[i]=='('){
        push_char(stack,s[i]);}

        else if(s[i]==')'){
            while(!isemptyc(stack) && peek_char(stack)!='('){
            a[j++]=pop_char(stack);
            a[j++]=' ';
            }
            if(!isemptyc(stack) && peek_char(stack)=='(')
            pop_char(stack);
        }
                else if(isop(s[i])){
            while(!isemptyc(stack) && peek_char(stack)!='(' && pre(s[i])<=pre(peek_char(stack)) ){
                a[j++]=pop_char(stack);
                a[j++]=' ';
            }
            push_char(stack,s[i]);
        }
        else if(s[i]==' '){continue;}
    }
    a[j]='\0';
    for(i=0;i<j;i++){
        (*o)[k++]=a[i];
    }
    (*o)[k++]=' ';
    while(!isemptyc(stack)){
        (*o)[k++]=pop_char(stack);
        (*o)[k++]=' ';
    }
    (*o)[k]='\0';

}
int fH(node root) {
    if (root == NULL) {
        return -1;
    }
    if (root->left == NULL && root->right == NULL) {
        return 0;
    }
    int lH = fH(root->left);

    int rH = fH(root->right);

    return (lH > rH) ? (lH + 1) : (rH + 1);
}



node build_tree(char* s) {
    stack stack = is(strlen(s));

    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];

        if (check_n(ch)) {

            int num = 0;
            while (check_n(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            i--;  
            node numNode = create_node('0' + num);
            push(stack, numNode);
        } else if (isop(ch)) {
            node opNode = create_node(ch);
            opNode->right = pop(stack);
            opNode->left = pop(stack);
            push(stack, opNode);
        }
    }

    return pop(stack);
}
int min(node root){
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 0;
    }
    int lH = fH(root->left);

    int rH = fH(root->right);

    return (lH<rH)?(lH+1):(rH+1);
    
}

int main() {
    char s[100];
    fgets(s, sizeof(s), stdin);
    char* o = NULL;node head=NULL;
    itop(s, &o);
    int i=0;
    printf("%s\n", o);

    float d = evaluate(o);
    if (fabs(d - (-1.11)) < 0.00001) {
        printf("N\n");
    } else {
        printf("%.2f\n", d);
    }
    node root=build_tree(o);
    
    int height = fH(root);
    printf("%d\n",height);
    height=min(root);
    printf("%d",height);
  
}