
#include <stdio.h>
#include <stdlib.h>

struct queue{
    int a[1000];
    int size;
    int capacity;
};
typedef struct queue* q;

q createpriorityqueue(int maxCapacity) {
    q pq = malloc(sizeof(struct queue));
    pq->size = 0;
    pq->capacity = maxCapacity;
    return pq;
}
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void heapifyUp(q pq, int index) {
    while (index > 1 && pq->a[index] < pq->a[index / 2]) {
        swap(&pq->a[index], &pq->a[index / 2]);
        index = index / 2;
    }
}

// Function to insert an element into the priority queue
void insert(q pq, int value) {
    if (pq->size < pq->capacity) {
        pq->size++;
        pq->a[pq->size] = value;
        heapifyUp(pq, pq->size);
    } else return;
    
}

void heapifyDown(q pq, int index) {
    int smallest = index;
    int left = 2 * index;
    int right = 2 * index + 1;

    if (left <= pq->size && pq->a[left] < pq->a[smallest]) {
        smallest = left;
    }

    if (right <= pq->size && pq->a[right] < pq->a[smallest]) {
        smallest = right;
    }

    if (smallest != index) {
        swap(&pq->a[index], &pq->a[smallest]);
        heapifyDown(pq, smallest);
    }
}

// Function to remove and return the element with the highest priority
int extractMin(q pq) {
    if (pq->size == 0) {
        printf("Priority queue is empty.\n");
        return -1; // You can choose an appropriate error value
    }

    int min = pq->a[1];
    pq->a[1] = pq->a[pq->size];
    pq->size--;
    heapifyDown(pq, 1);
    return min;
}

int isEmpty(q pq) {
    return pq->size == 0;
}

int main() {
   q pq = createPriorityQueue(100);

    insert(pq, 5);
    insert(pq, 2);
    insert(pq, 9);
    insert(pq, 1);

    while (!isEmpty(pq)) {
        printf("%d ", extractMin(pq));
    }
    return 0;
}
