#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *data;
	int top;
	int capacity;
} Stack;

static Stack* createStack(int capacity){
	Stack *s = (Stack*)malloc(sizeof(Stack));
	if(s == NULL) return NULL;
	s->data = (char*)malloc(sizeof(char) * capacity);
	if(s->data == NULL){
		free(s);
		return NULL;
	}
	s->top = -1;
	s->capacity = capacity;
	return s;
}

static void destroyStack(Stack *s){
	if(s == NULL) return;
	free(s->data);
	free(s);
}

static void push(Stack *s, char ch){
	if(s->top == s->capacity - 1) return; // overflow ignored per minimal API
	s->top++;
	s->data[s->top] = ch;
}

static char pop(Stack *s){
	char ch = s->data[s->top];
	s->top--;
	return ch;
}

void reverseString(char *s){
	int len = (int)strlen(s);
	if(len <= 1) return;
	Stack *st = createStack(len);
	if(st == NULL) return;
	int i;
	for(i = 0; i < len; i++) push(st, s[i]);
	for(i = 0; i < len; i++) s[i] = pop(st);
	destroyStack(st);
}

int main(){
	char str[256] = "hello world";
	printf("Original: %s\n", str);
	reverseString(str);
	printf("Reversed: %s\n", str);
	return 0;
}

