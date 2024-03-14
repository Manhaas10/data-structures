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
// function searchIteratively(root, key):
//     while root is not null:
//         // If the key is equal to the current node's key, return the node
//         if key is equal to root.key:
//             return root
        
//         // If the key is smaller than the current node's key, search in the left subtree
//         else if key < root.key:
//             root = root.left
        
//         // If the key is larger than the current node's key, search in the right subtree
//         else:
//             root = root.right
    
//     // Key not found
//     return null
node in(node root,int k){
    node temp=create_node(k);
    if(root==NULL){
        return create_node(k);
    }
    if(k>root->key) {root->left=in(root->left,k);root->left->parent=root;}
    else {root->right=in(root->right,k);root->right->parent=root;}
    return root;
}
// function insertIteratively(root, key):
//     newNode = createNode(key)

//     if root is null:
//         return newNode

//     current = root
//     while true:
//         if key < current.key:
//             if current.left is null:
//                 current.left = newNode
//                 return root
//             else:
//                 current = current.left
//         else if key > current.key:
//             if current.right is null:
//                 current.right = newNode
//                 return root
//             else:
//                 current = current.right
//         else:
//             // Duplicate key, update value or counter
//             current.value = newValue  // Update the value associated with the node
//             return root
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
// function deleteNodeIteratively(root, key):
//     parent = null
//     current = root

//     // Search for the node to delete
//     while current is not null and current.key is not equal to key:
//         parent = current

//         if key < current.key:
//             current = current.left
//         else:
//             current = current.right

//     // If the key is not found
//     if current is null:
//         return root

//     // Node with only one child or no child
//     if current.left is null:
//         if parent is null:
//             return current.right
//         else if parent.left is current:
//             parent.left = current.right
//         else:
//             parent.right = current.right
//     else if current.right is null:
//         if parent is null:
//             return current.left
//         else if parent.left is current:
//             parent.left = current.left
//         else:
//             parent.right = current.left
//     else:
//         // Node with two children: Find in-order predecessor
//         predecessorParent = current
//         predecessor = current.left

//         while predecessor.right is not null:
//             predecessorParent = predecessor
//             predecessor = predecessor.right

//         // Replace the key with the in-order predecessor's key
//         current.key = predecessor.key

//         // Delete the in-order predecessor
//         if predecessorParent.left is predecessor:
//             predecessorParent.left = predecessor.left
//         else:
//             predecessorParent.right = predecessor.left

//     return root

// function deleteNode(root, key):
    // Base case: If the tree is empty
    // if root is null:
    //     return null
    
    // // Search for the node to delete
    // if key < root.key:
    //     root.left = deleteNode(root.left, key)
    // else if key > root.key:
    //     root.right = deleteNode(root.right, key)
    // else:
    //     // Node with only one child or no child
    //     if root.left is null:
    //         return root.right
    //     else if root.right is null:
    //         return root.left

    //     // Node with two children: Find the in-order predecessor
    //     root.key = findMaxValue(root.left)  // In-order predecessor//predecessor
    //     root.left = deleteNode(root.left, root.key)

    // return root

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