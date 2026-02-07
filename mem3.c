#include <stdio.h>
#include <stdlib.h>

int main() {
int n = 10;

	int *arr = malloc(n * sizeof(int));
	if (arr == NULL) return 1;

	for (int i = 0; i < n; ++i)
	arr[i] = i + 1;

	int size = 2;
	int size1 = 0;

	int *arr1 = malloc(size * sizeof(int));
	if (arr1 == NULL) {
		free(arr);
		return 1;
	}

	for (int i = 0; i < n; ++i) {

	if (arr[i] % 2 == 0) {

	if (size1 == size) {
	size *= 2;
	int *temp = realloc(arr1, size * sizeof(int));
	if (temp == NULL) {
		free(arr);
		free(arr1);
		return 1;
	}
	arr1 = temp;
	}

	arr1[size1++] = arr[i];
	}
	}

	for (int i = 0; i < size1; ++i) printf("%d ", arr1[i]);

free(arr);
free(arr1);
}

