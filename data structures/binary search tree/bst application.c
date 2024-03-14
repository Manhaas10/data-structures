#include <stdio.h>
#include <stdlib.h>

struct treenode{
    int key;
    struct treenode* left;
    struct treenode* right;
};

typedef struct treenode* node;
node create_node(int key){
    node node=malloc(sizeof(struct treenode));
    node ->key=key;
    node->left=NULL;
    node->right=NULL;
    return node;
}
int check_n(char ch){
    return (ch>='0' && ch<='9');
}

node build_tree(char* s,int* i){
    node root;
    if(!s[*i]) return NULL;
        if(s[*i]=='('){(*i)++;
        if(s[*i]==' '){(*i)++;}
        if(s[*i]==')'){(*i)++;return NULL;}

            int num = 0;
            while (check_n(s[*i])) {
                num = num * 10 + (s[*i] - '0');
                (*i)++;
            }
 
            root=create_node(num);
            if(s[*i]==' '){(*i)++;}
            
            root->left=build_tree(s,i);
            if(s[*i]==' '){(*i)++;}

            root->right=build_tree(s,i);
            if(s[*i]==' '){(*i)++;}
            if(s[*i]==')'){(*i)++;}

            return root;
        }
        return NULL;
}
void print(node root){
    if (root) {
        print(root->left);
        printf("%d ", root->key);
        print(root->right);
    }
    else return;

}
int main(){
    int i=0;
    char s[103];
    scanf(" %[^\n]",s);
    node root=build_tree(s,&i);
    print(root);
}