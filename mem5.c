#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
char name[50];
int age;
float grade;
} student;

int main() {

	int count = 2;

	student *arr = malloc(count * sizeof(student));
	if (arr == NULL) return 1;

	strcpy(arr[0].name, "Anna");
	arr[0].age = 20;
	arr[0].grade = 88.5;
	strcpy(arr[1].name, "Aram");
	arr[1].age = 21;
	arr[1].grade = 91.2;

	count = 3;

	student *temp = realloc(arr, count * sizeof(student));
	if (temp != NULL) {
		arr = temp;

		strcpy(arr[2].name, "Vahe");
		arr[2].age = 17;
		arr[2].grade = 99.0;
	}

	for (int i = 0; i < count; i++) {
		printf("%s %d %.2f\n",
		arr[i].name,
		arr[i].age,
		arr[i].grade);
	}

free(arr);
}

