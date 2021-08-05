#include <stdio.h>
#include "charStack.h"

int main(){
	
	int size;
	printf("\nEnter the Size of Stack : ");
	scanf("%d",&size);
	
	Stack* stack = createStack(size);

	printf("Enter the String : ");
	char str[size];
	scanf("%s",str);
	
	int index=0;		
	while(str[index] != '\0'){
		push(stack,str[index++]);
	}
	
	printf("Reversed String : ");
	while(!isEmpty(stack)){
		printf("%c",pop(stack));
	}
}


