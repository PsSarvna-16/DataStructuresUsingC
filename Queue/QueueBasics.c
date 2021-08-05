#include<stdio.h>
#include "intQueue.h"

void operations();

int main(){

	int size;
	printf("\nEnter the Size of Queue : ");
	scanf("%d",&size);

	Queue* queue = createQueue(size);

	int val,choice,repeat=1;
	do{	
		operations();
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("\nEnter Integer to Enqueue : ");
				scanf("%d",&val);
				if(enQueue(queue,val)){
					printf("%d is added to Queue",val);
				}else{
					printf("Queue is full");
				}
				break;
			case 2:
				if(!isEmptyQueue(queue)){
					printf("\n Dequeue : %d",deQueue(queue));
				}else{
					printf("\nQueue UnderFlow !!!");	
				}
				break;
			case 3:
				displayQueue(queue);
				break;
			case 4:
				if(isEmptyQueue(queue)){
					printf("\nQueue is Empty !!!");
				}else{
					printf("\nQueue is Not Empty.");
				}
				break;
			case 5:
				if(isFullQueue(queue)){
					printf("\nQueue is Full !!!");
				}else{
					printf("\nQueue is Not Full.");
				}
				break;
			case 6:
				repeat = 0;
				break;
			default:
				printf("Enter Valid Choice.");			
		}		
	}while(repeat);
	return 0;
}

void operations(){
	
	printf("\n\n************************");
	printf("\nQueue Operations : ");
	printf("\n\t1. Enqueue");
	printf("\n\t2. Dequeue");
	printf("\n\t3. Display Queue");	
	printf("\n\t4. isEmpty");
	printf("\n\t5. isFull");
	printf("\n\t6. EXIT");	
	
	printf("\n\nEnter Your Choice : ");
}
