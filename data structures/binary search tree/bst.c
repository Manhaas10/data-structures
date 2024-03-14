#include <stdio.h>
#include <stdlib.h>

struct treenode{
    int key;
    struct treenode* left;
    struct treenode* right;
    struct treenode* parent;
};
typedef struct treenode* node;
node create_node(int key){
    node node=malloc(sizeof(struct treenode));
    node ->key=key;
    node->left=NULL;
    node->right=NULL;
    node->parent=NULL;
    return node;
}
node in(node root,int k){
    node temp=create_node(k);
    if(root==NULL){
        return create_node(k);
    }
    if(k>root->key) {root->left=in(root->left,k);root->left->parent=root;}
    else {root->right=in(root->right,k);root->right->parent=root;}
    return root;
}
void sea(node root,int k,int* c){
    if(!root){return;}
    if(root->key==k) {(*c)=0;printf("F\n");return;}
    else if(k>root->key) {sea(root->left,k,c);}
    else  {sea(root->right,k,c);}
    if(*c!=0){
    return;}(*c)++;
}
int min(node root){
    if(!root) return -1;
    while(root->right){root=root->right;}
    return root->key;
}
int max(node root){
    
    if(!root) return -1;
    while(root->left){root=root->left;}
    return root->key;
}
void inorder(node root){
    if (root) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
    else return;

}
void postorder(node root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);  
    }
    else return;
    
}
void preorder(node root){
    int c=0;
    if(root){
        printf("%d ",root->key);
        preorder(root->left);
        preorder(root->right);
        c++;
    }
    else return;
}
int main(){
    node root=NULL;
    int i,d;
    char ch;int c=0;
    while(ch!='e'){
        scanf("%c",&ch);
        switch(ch){
            case 'a':
              scanf("%d",&i);
              root=in(root,i);
              break;
              
            case 's':
              scanf("%d",&i);
              
              sea(root,i,&c);
              if(c!=0){printf("N\n");}

              break;
            case 'x':

             d=max(root);
             if(d!=-1)
             printf("%d\n",d);
            break;
            case 'n':
             d=min(root);
             if(d!=-1)
             printf("%d\n",d);
            break;
            case 'i':
            if(root){
             inorder(root);
             printf("\n");}
             
             break;
            case 'p':
            if(root){
             preorder(root);
             printf("\n");}
             
             break;
            case 't':
            if(root){
             postorder(root);
             printf("\n");}
             break;

        }
    }
}