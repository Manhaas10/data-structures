#include<stdio.h>
#include<stdlib.h>
struct LinkedList{
 int data;
 struct LinkedList *next;
 struct LinkedList *prev;

};

typedef struct LinkedList *node;

node createNode() {
 node temp; // declare a node
 temp = (node ) malloc (sizeof(struct LinkedList));
 // allocate memory using malloc()
 if(temp == NULL)
    {
        printf("Error creating a new node.\n");
        exit(0);
    }
 temp->next = NULL; temp->prev=NULL; // make next point to NULL
 return temp; //return the new node
}


node insert_at_begin(int data, node first)
{
    node new_head;
    node new_node =createNode();
    new_node->data = data;
    new_node->next = first;
    new_node->prev=first->prev;    
    new_head = new_node;
    return new_head;
}
node insert_at_end(int data, node first)
{
    node temp,p;
    temp = createNode();
    temp->data = data;
    temp->next=NULL;temp->prev=NULL;
    if(first == NULL) { first = temp; }
    else
    {
      p = first;
      while(p->next != NULL)
        p = p->next;
      p->next = temp;
      temp->prev=p;
    }
    return first;
}

void printlist(node head)
{
  if(head==NULL)
    printf("List is empty\n");
  else
  {
    while(head!=NULL)
    {
      printf("%d-->",head->data);
      head=head->next;
    }printf("\b\b\b");
  }
}

void printlistreverse(node head)
{
  node previous=NULL,first=head;
  if(head==NULL)
    printf("List is empty\n");
  else
  {
    while(head!=NULL)
    {
      printf("%d-->",head->data);
      previous=head;
      head=head->next;
    }printf("\b\b\b");
    printf("\n REVERSE\n");
    while(previous!=first)
    {
      printf("%d-->",previous->data);
      previous=previous->prev;
    }printf("%d",previous->data);

  }
}
node delete_value(int value, node head)
{

  node temp=NULL,first=head,prev=NULL;
  if(head==NULL)
    printf("Deletion not possible: List is empty\n");
  else
  {
    if(first->data==value)
    {
      head=head->next;
      head->prev=NULL;
      free(first);
    }
    else
    {

        while(first->data!=value)
        {
          prev=first;
          first=first->next;
        }
        if(first->data==value)
        {
          prev->next=first->next;
          if(first->next!=NULL)
          {
            first->next->prev=prev;
          }
          free(first);
        }
        else
        {
          printf("Deletion unsuccessful: Value not found");
        }
    }
  }
  return head;
}


int main()
{
  node head=NULL,temp=NULL;
  int n,val;
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    scanf("%d",&val);
    head = insert_at_end(val, head);
  }
  printlist(head);
  scanf("%d",&val);
  printf("\n");
  head=delete_value(val,head);
  printlistreverse(head);
  
}