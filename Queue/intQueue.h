#include <stdbool.h>
#include <malloc.h>
#define MAX_SIZE 100

struct Queue{
	
	int que[MAX_SIZE];
	int front;
	int rear;
	int size;
};

typedef struct Queue Queue;

Queue* createQueue(int size){
	
	Queue* queue = (Queue *)malloc(sizeof(Queue));
	
	queue->size = size;
	queue->front = -1;
	queue->rear = -1;
}

bool isEmptyQueue(Queue* queue){
	
	if( queue->front > queue->rear || queue->front == -1){
		return true;
	}
	return false;
}

bool isFullQueue(Queue* queue){
	
	if( queue->rear == queue->size-1 ){
		return true;
	}
	return false;
}

bool enQueue(Queue* queue, int val ){
	
	if( ! isFullQueue(queue)){
		
		if(queue->front == -1){
			queue->front = 0;
		} 
		queue->rear++;
		queue->que[queue->rear] = val;
		return true;
	}
	return false;	
}

int deQueue(Queue* queue){
	
	if( ! isEmptyQueue(queue)){
		return queue->que[queue->front++];
	}
	return 0;	
}

void displayQueue(Queue* queue){
	if(isEmptyQueue(queue)){
		printf("\nQueue is empty !!");
		return;
	}
	int ind = queue->front;
	printf("\nQueue : ");
	while(ind <= queue->rear){
		printf("%d ",queue->que[ind]);
		ind++;
	}
	return;
}
