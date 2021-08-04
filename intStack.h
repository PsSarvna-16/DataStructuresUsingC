//                	INT STACK (HEADER FILE)
#include <stdbool.h>
#define MAX_SIZE 100

struct Stack{
	int stk[MAX_SIZE];
	int size;
	int top;
};
typedef struct Stack Stack;

// Create Stack
Stack* createStack(int size){
	Stack* stack = (Stack *)malloc(sizeof(Stack));
	stack->size = size;
	stack->top = -1;
	return stack;
}

//    FULL
bool isFull(Stack* stack){
	if(stack->top == (stack->size-1)){
		return true;
	}
	return false;
}

//    EMPTY
bool isEmpty(Stack* stack){
	if(stack->top < 0){
		return true;
	}
	return false;
}

//	DISPLAY
void display(Stack* stack){

	if(isEmpty(stack)){
		printf("\nStack is Empty !!");
	}else{
		printf("\nStack Elements (top to bottom) : ");
		for(int index=stack->top ; index >=0 ; index-- ){
				printf("%c ",stack->stk[index]);
		}	
	}
}

//     PUSH
void push(Stack* stack,int val){

	if(! isFull(stack)){
		stack->top += 1;
		stack->stk[stack->top] = val;
		return;
	}
}

//     POP
int pop(Stack* stack){
	int val;
	if(isEmpty(stack)){
		return '\0';
	}
	else{
		val = stack->stk[stack->top] ;
		stack->top -= 1;
		return val;
	}
}

//     PEEP
int peep(Stack* stack){
	
	if(! isEmpty(stack)){
		return stack->stk[stack->top];
	}	
}
