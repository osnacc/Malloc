#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
char *name;
int *arr;
int count;
} Student;

int main() {

	Student *st = malloc(sizeof(Student));
	if (st == NULL) return 1;

	st->name = malloc(50 * sizeof(char));
	if (st->name == NULL) return 1;

		strcpy(st->name, "Vahe");

		st->count = 3;

	st->arr = malloc(st->count * sizeof(int));
	if (st->arr == NULL) return 1;

		st->arr[0] = 80;
		st->arr[1] = 90;
		st->arr[2] = 85;

	int newCount = 5;

	int *temp = realloc(st->arr, newCount * sizeof(int));
	if (temp != NULL) {
		st->arr = temp;

		st->arr[3] = 88;
		st->arr[4] = 92;

		st->count = newCount;
	}

	printf("%s\n", st->name);
	for (int i = 0; i < st->count; ++i) printf("%d ", st->arr[i]);

free(st->name);
free(st->arr);
free(st);
}

