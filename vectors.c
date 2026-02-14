#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TYPE int
#define DEFAULT_SIZE 8

typedef struct Vector{
    TYPE*ptr;
    size_t size;
    size_t capacity;
}Vector;

bool constructor(Vector *vector);
bool reserve(Vector *vector, size_t size);
void resize(Vector *vector);
void clear(Vector *vector);

void push_back(Vector *vector, TYPE value);
void push_front(Vector *vector, TYPE value);
void pop_back(Vector *vector);
void pop_front(Vector *vector);

void insert(Vector *vector, int index, TYPE value);
void finde(Vector *vector,TYPE value);



int main(){

	Vector array;
		constructor(&array);
		printf("%zu\n" , array.capacity);
		printf("%zu\n" , array.size);
//reserve (&array , 32);
//printf("%zu\n" , array.capacity);
//printf("%zu\n" , array.size);
		resize(&array);
		printf("%zu\n" , array.capacity);
		printf("%zu\n" , array.size);
	for (int i = 0; i < 12; ++i){
		push_back(&array , i);
		printf("%d\n", array.ptr[i]);
	}

	printf("%zu\n" , array.capacity);
	printf("%zu\n" , array.size);
	insert(&array,2,99);	
	insert(&array,8,99);
	finde(&array,99);
	finde(&array,101);


}


bool constructor(Vector * vector){

	vector->ptr = malloc (DEFAULT_SIZE * sizeof(TYPE));
	if(!vector->ptr){
		perror("Malloc error: ");
		return false;
	}
	vector->capacity = DEFAULT_SIZE;
	vector->size = 0;
	return true;
}

bool reserve(Vector *vector, size_t size){

	vector->ptr = realloc (vector->ptr,size * sizeof(TYPE));
 	if (!vector->ptr) {
		perror("Realloc error: ");
		return false;
	}
	vector->capacity = size;
	return true;
}


void resize(Vector *vector){
	
	if (!(vector->capacity == vector->size)) return;
	vector->ptr = realloc (vector->ptr,vector->capacity * 2 * sizeof(TYPE));
        if (!vector->ptr) {
                perror("Realloc error: ");
                return;
        }
        vector->capacity *= 2;
}


void clear(Vector *vector){
	free(vector->ptr);
	vector->size = 0;
	vector->capacity = 0;
}



void push_back(Vector *vector, TYPE value){
	
	resize(vector);
	vector->ptr[vector->size] = value;
	++vector->size;
}

void push_front(Vector *vector, TYPE value){

	resize(vector);
	for(int i = vector->size; i > 0;--i) vector->ptr[i] = vector->ptr[i - 1];
	vector->ptr[0] = value;
	++vector->size;		


}

void pop_back(Vector *vector){
	--vector->size;
}

void pop_front(Vector *vector){

	for(int i = 0; i < (vector->size - 1);++i) vector->ptr[i] = vector->ptr[i + 1];
	--vector->size;		


}



void insert(Vector *vector, int index, TYPE value){

	resize(vector);
	for(int i = vector->size; i > index;--i) vector->ptr[i] = vector->ptr[i - 1];
	vector->ptr[index + 1] = value;
	++vector->size;		
}



void finde(Vector *vector,TYPE value){
	
	char b = 0;
	for(int i = 0; i < vector->size; ++i){
		if (vector->ptr[i] == value) {
			printf("%d in index %d\n" ,vector->ptr[i], i );	
			b = 1;
		}
	}		 
	if(b==0)printf("I don't finde %d\n" , value);
}













