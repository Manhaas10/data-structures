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
node mini(node root){
    if(!root) return NULL;
    while(root->right){root=root->right;}
    return root;
}
node maxi(node root){
    
    if(!root) return NULL;
    while(root->left){root=root->left;}
    return root;
}
node sea(node root,int k){
    if(!root){return NULL;}
    if(root->key==k) {return root;}
    else if(k>root->key) {sea(root->left,k);}
    else  {sea(root->right,k);}

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
node del(node root,int k){
    if(!root)return NULL;
    if(root->key>k){
        root->right=del(root->right,k);
    }
    else if(root->key<k) root->left=del(root->left,k);
    else{
        if(!root->left){
            node temp=root->right;
            free(root);
            return temp;
        }
         if(!root->right){
            node temp=root->left;
            free(root);
            return temp;
        }
        node temp=mini(root->left);
        root->key=temp->key;
        root->left=del(root->left,root->key);
    }
    return root;
}
void preorder(node root){

    if(root){
        printf("%d ",root->key);
        preorder(root->left);
        preorder(root->right);
    }
    else {return;}
}
node suck(node groot,int k){
    node root=sea(groot,k);
    if(!root)return NULL;
    if (root->right) return mini(root->right);
    node y;
    y=root->parent;
    while(y && root==y->right){
        root=y;
        y=y->parent;
    }
    return y;
}
node pred(node groot,int k) {
    node root=sea(groot,k);
    if(!root)return NULL;
    if(root==groot){return NULL;}
    if (root->left) {
        return maxi(root->left);
    }
    
    node y = root->parent;
    while (y && root == y->left) {
        root = y;
        y = y->parent;
    }
    return y;
}
void inorder(node root){
    if (root) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
    else return;
}
int main(){
    node root = NULL;  
    int k;
    node n,g;
    char ch;
    while(ch!='e'){
        scanf("%c",&ch);
      switch(ch){
        case 'a':
         scanf("%d",&k);
         root=in(root,k);
         break;
        case 'd':
         scanf("%d",&k);
         if(sea(root,k)){
         root=del(root,k);printf("%d\n",k);
         }
         else printf("-1\n");
         break;

        case 'c':
         scanf("%d",&k);

         if(sea(root,k)){
            n=suck(root,k);
            if(n)
         printf("%d\n",n->key);
         else printf("-1\n");
         }
         else printf("-1\n");
         break;

         
        case 'r':
        scanf("%d",&k);
         if(sea(root,k) ){
            n=pred(root,k);
            if(n)
         printf("%d\n",n->key);
         else printf("-1\n");
         }
         else printf("-1\n");
         break;

        case 'p':
         if(root){
         preorder(root);
         printf("\n");}
         else printf("-1\n");
         break;

      }
    }
}