#include<stdio.h>
#include<stdlib.h>
struct LinkedList{
 int data;
 struct LinkedList *next;
};

typedef struct LinkedList *node;

node createNode() {
node temp;                                                     // declare a node
temp = (node ) malloc (sizeof(struct LinkedList));             // allocate memory using malloc()
if(temp == NULL){
    printf("Error creating a new node.\n");
    exit(0);
}
temp->next = NULL;                                             // make next point to NULL
return temp;                                                   //return the new node
}

void printlist(node head){
  if(head==NULL)
    printf("List is empty\n");
  else
  {
    while(head!=NULL)
    {
      printf("%d-->",head->data);
      head=head->next;
    }
    printf("\b\b\b");
    printf("\n");
  }
}




node insert_at_begin(int data, node first){
    node new_head;
    node new_node =createNode();
    new_node->data = data;
    new_node->next = first;
    new_head = new_node;
    return new_head;
}

node insert_at_end(int data, node first){
    node temp,p;
    temp = createNode();
    temp->data = data;
    temp->next=NULL;
    if(first == NULL) { first = temp; }
    else
    {
      p = first;
      while(p->next != NULL)
        p = p->next;
      p->next = temp;
    }
    return first;
}

int main(){
//LIST ON TWO NODES
// int n;
// scanf("%d",&n);
// node new_node1 =createNode();
// node new_node2 =createNode();
// new_node1->data=10;
// new_node2->data=20;
// new_node1->next=new_node2;
// new_node2->next=NULL;
// printlist(new_node1);
////  CREATING A LIST ON USER INPUT VALUES
node head1=NULL,head2=NULL,temp=NULL;
  int n1,n2,val;
  scanf("%d",&n1);
  for(int i=0;i<n1;i++)
  {
    scanf("%d",&val);
    head1 = insert_at_end(val, head1);
  }
  printf("LIST1\n");
  printlist(head1);
  scanf("%d",&n2);
  for(int i=0;i<n2;i++)
  {
    scanf("%d",&val);
    head2 = insert_at_end(val, head2);
  }
  printf("LIST2\n");
  printlist(head2);

  if(head1!=NULL)
  {
    for(temp=head1;temp->next!=NULL;temp=temp->next);
    temp->next=head2;
  }
  else
  head1=head2;
  printf("COMBINED LIST\n");
  printlist(head1);

// node head=NULL;
// int n,val;
// scanf("%d",&n);
// for(int i=0;i<n;i++){
//     scanf("%d",&val);
//     head = insert_at_end(val, head);
// }
// printlist(head);
}