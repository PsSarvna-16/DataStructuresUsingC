#include <stdio.h>
#include "charStack.h"

bool balancingParanthesis(Stack* stack,char str[]);
int precedence(char ch);
void infix2Post(Stack* stack,char str[]);

int main(){
	
	Stack* stack = createStack(50);

	char str[50];
	printf("Infix Expression   : ");
	scanf("%[^\n]",str);
	infix2Post(stack,str);

	return 0;
}

void infix2Post(Stack* stack,char str[]){

	int ind=0;char ch;
	printf("Postfix Expression : ");
	if(! balancingParanthesis(stack,str)){
		return;
	}
	while(str[ind] != '\0'){
		if((str[ind] == '+')||(str[ind] == '-')||(str[ind] == '*')||(str[ind] == '/')){
			if(!isEmpty(stack)){
				while(precedence(peep(stack)) >= precedence(str[ind])){
					printf("%c",pop(stack));
					if(isEmpty(stack))
						break;
				}	
			}
			push(stack,str[ind]);
		}else if(str[ind] == '('){
			push(stack,str[ind]);
		}else if(str[ind] == ')'){
			ch = pop(stack);
			while(ch != '(' && !(isEmpty(stack))){
				printf("%c",ch);
				ch = pop(stack);
			}		
		}else if (str[ind]== ' '){}
		else{
			printf("%c",str[ind]);
		}
		ind++;
	}
	while(!isEmpty(stack)){
		printf("%c",pop(stack));
	}	
}

bool balancingParanthesis(Stack* stack,char str[]){
	int ind;
	for(ind = 0; str[ind]!= '\0';ind++){

		if(str[ind] == '('){
			push(stack,str[ind]);
		}
		
		else if(str[ind] == ')'){
			if(isEmpty(stack)){
				printf("\nOpening '(' Paranthesis is Missing !!!");
				return false;
			}
			if(pop(stack) != '('){
				printf("\nOpening '(' Paranthesis is Missing !!!");
				return false;
			}
		}
	}

	if(!(isEmpty(stack))){
		printf("\nClosing Paranthesis is Missing !!!");
		return false;
	}else{
		return true;
	}
		
}

int precedence(char ch){
	
	if(ch == '(') { return 0; }
	else if((ch == '+')||(ch == '-')) { return 1; }
	else if((ch == '*')||(ch == '/')) { return 2; }
}

