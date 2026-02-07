#include <stdio.h>
#include <stdlib.h>

int main() {

int size = 5;

	int * arr = malloc(size * sizeof(int));
	if (arr == NULL) {	
		printf("Sxal hishoxutyan bashxum\n");
		return 1;	
	}

	for (int i = 0; i < size; ++i) {
		arr[i] = i + 1;
	}

	int newsize = 10;
	int *temp = realloc(arr, newsize * sizeof(int));
	
	if (temp == NULL) {
	printf("realloc sxal\n");
	free(arr);
	return 1;
	}

arr = temp;

	for (int i = size; i < newsize; ++i) {
		arr[i] = i + 1;
	}

	for (int i = 0; i < newsize; ++i) {
		printf("%d ", arr[i]);
	}

free(arr);
return 0;
}

