#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *data;
	int top;
	int capacity;
} Stack;

static int isEmpty(Stack *s){
	return s->top == -1;
}

static void push(Stack *s, char ch){
	if(s->top == s->capacity - 1) return; // ignore overflow for minimal API
	s->top++;
	s->data[s->top] = ch;
}

static char pop(Stack *s){
	char ch = s->data[s->top];
	s->top--;
	return ch;
}

int isBalanced(const char *expr){
	int n = (int)strlen(expr);
	Stack *s = (Stack*)malloc(sizeof(Stack));
	if(s == NULL) return 0;
	s->data = (char*)malloc(sizeof(char) * n);
	if(s->data == NULL){
		free(s);
		return 0;
	}
	s->top = -1;
	s->capacity = n;

	int i;
	for(i = 0; i < n; i++){
		char c = expr[i];
		if(c == '(' || c == '{' || c == '['){
			push(s, c);
		}else if(c == ')' || c == '}' || c == ']'){
			if(isEmpty(s)){
				free(s->data);
				free(s);
				return 0;
			} //edge case 1 if starting is ) } ] 
			char top = pop(s);
			int matches =
				(top == '(' && c == ')') ||
				(top == '{' && c == '}') ||
				(top == '[' && c == ']');
			if(matches == 0){
				free(s->data);
				free(s);
				return 0;
			}
		}
	}
	int balanced = isEmpty(s);
	free(s->data);
	free(s);
	return balanced;
}

int main(){
	char buffer[512];
	if(fgets(buffer, sizeof(buffer), stdin) == NULL) return 0;
	buffer[strcspn(buffer, "\n")] = '\0';
	if(isBalanced(buffer)){
		printf("Balanced\n");
	}else{
		printf("Not Balanced\n");
	}
	return 0;
}


