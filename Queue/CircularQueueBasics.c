#include<stdio.h>
#include "intCircularQueue.h"

void operations();

int main(){

	int size;
	printf("\nEnter the Size of Circular Queue : ");
	scanf("%d",&size);

	Queue* queue = createCircularQueue(size);

	int val,choice,repeat=1;
	do{	
		operations();
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("\nEnter Integer to Enqueue : ");
				scanf("%d",&val);
				if(enQueue(queue,val)){
					printf("%d is added to Circular Queue",val);
				}else{
					printf("Circular Queue is full");
				}
				break;
			case 2:
				if(!isEmptyQueue(queue)){
					printf("\n Dequeue : %d",deQueue(queue));
				}else{
					printf("\nCircular Queue UnderFlow !!!");	
				}
				break;
			case 3:
				displayQueue(queue);
				break;
			case 4:
				if(isEmptyQueue(queue)){
					printf("\nCircular Queue is Empty !!!");
				}else{
					printf("\nCircular Queue is Not Empty.");
				}
				break;
			case 5:
				if(isFullQueue(queue)){
					printf("\nCircular Queue is Full !!!");
				}else{
					printf("\nCircular Queue is Not Full.");
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
	printf("\nCircular Queue Operations : ");
	printf("\n\t1. Enqueue");
	printf("\n\t2. Dequeue");
	printf("\n\t3. Display Queue");	
	printf("\n\t4. isEmpty");
	printf("\n\t5. isFull");
	printf("\n\t6. EXIT");	
	
	printf("\n\nEnter Your Choice : ");
}
