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
	
	index=0;
	while(!isEmpty(stack)){
		if(str[index++] != pop(stack)){
			printf("\n  %s is not a Palindrome",str);
			return 0;
		}
	}
	printf("\n  %s is a Palindrome",str);
	return 0;
}
