#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Qnode{
    int key;
    struct Qnode* next;
};
struct queue{
    struct Qnode *front,*rear;
};
typedef struct queue* queue;
typedef struct Qnode* node;
node createnode(int k){
    node temp=(node)malloc(sizeof(struct Qnode));
    temp->key=k;
    temp->next=NULL;
    return temp;
}
queue create_q(){
    queue q=(queue)malloc(sizeof(struct queue));
    q->rear=q->front=NULL;
    return q;
}
void enqueue(queue q,int k){
    node temp=createnode(k);
    if(q->rear==NULL){
        q->front=q->rear=temp;
        return;
    }
    q->rear->next=temp;
    q->rear=temp;
}
void dequeue(queue q){
    if(q->front==NULL){
        return;
    }
    q->front=q->front->next;
    if(q->front==NULL)
    q->rear=NULL;
    //free(temp);
}
int main()
{
    queue q = create_q();
    enqueue(q, 10);
    enqueue(q, 20);
    dequeue(q);
    dequeue(q);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    dequeue(q);
    printf("Queue Front : %d \n", ((q->front != NULL) ? (q->front)->key : -1));
    printf("Queue Rear : %d", ((q->rear != NULL) ? (q->rear)->key : -1));
    return 0;
}