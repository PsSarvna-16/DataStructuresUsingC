#include<stdio.h>
#include "charStack.h"

void operations();

int main(){
	
	int size;
	printf("\nEnter the Size of Stack : ");
	scanf("%d",&size);
	
	Stack* stack = createStack(size);
	
	char ch;
	int choice,repeat=1;
	do{	
		operations();
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				printf("\nEnter Character to Push : ");
				scanf("\n%c",&ch);
				if(!isFull(stack)){
					push(stack,ch);
					printf("\n%c is Pushed into the Stack",ch);
				}else{
					printf("\nStack OverFlow !!");
				}	
				break;
			case 2:
				ch = pop(stack);
				if( ch != '\0'){
					printf("\n%c is Popped from the Stack",ch);
				}
				break;
			case 3:
				ch = peep(stack);
				printf("\n%c is the Top-Most Element.",ch);
				break;
			case 4:
				if(isEmpty(stack)){
					printf("\nStack is Empty");
				}else{
					printf("\nStack is Not Empty");
				}
				break;
			case 5:
				if(isFull(stack)){
					printf("\nStack is Full");
				}else{
					printf("\nStack is Not Full");
				}
				break;
			case 6:
				display(stack);
				break;
			case 7:
				repeat = 0;
				break;
			default:
				printf("Enter Valid Choice.");
				break;	
		}		
	}while(repeat);
	return 0;
}

void operations(){
	
		printf("\n\n************************");
		printf("\nStack Operations : ");
		printf("\n\t1. Push");
		printf("\n\t2. Pop");	
		printf("\n\t3. Peep");	
		printf("\n\t4. isEmpty");
		printf("\n\t5. isFull");
		printf("\n\t6. Display Stack");
		printf("\n\t7. EXIT");		
		printf("\n************************");
		
		printf("\n\nEnter Your Choice : ");
}
