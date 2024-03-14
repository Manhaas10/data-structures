#include<stdio.h>
#include<stdlib.h>
struct LinkedList{
 int data;
 struct LinkedList *next;
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
 temp->next = NULL; // make next point to NULL
 return temp; //return the new node
}


node insert_at_begin(int data, node first)
{
    node new_head;
    node new_node =createNode();
    new_node->data = data;
    new_node->next = first;
    new_head = new_node;
    return new_head;
}
node insert_at_end(int data, node first)
{
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

node delete_from_end(node first)
{
  node temp=NULL,head=first,prev=NULL;
  if(first!=NULL)
  {
    if(first->next!=NULL)
    {
      prev=NULL;
      while(first->next!=NULL)
      {
        prev=first;
        first=first->next;
      }
      temp=prev->next;
      //printf("%d\n",temp->data);
      prev->next=NULL;
    }
    else
    {
      temp=first;
      head=NULL;
    }  
    printlist(head);
    free(temp);
  }
  else
    printf("DELETE unsucessful: List is empty");
  return head;
}


void Dispose(node head)
{
    node cursor=NULL, tmp=NULL;
    if(head != NULL)
    {
        cursor = head;
        while(cursor != NULL)
        {
            tmp = cursor->next;
            free(cursor);
            cursor = tmp;
        }
    }
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

  printf("\n Deleting the first element\n");
  if(head!=NULL)
  {
    temp=head;
    head=head->next;
    printlist(head);
    free(temp);
  }
  else
    {
      printf("DELETE unsucessful: List is empty");
    }
  printf("\n Deleting the last element\n");
  head=delete_from_end(head);
  Dispose(head);
//  printlist(head);
}