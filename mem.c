#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, sum = 0;
    int *arr;

    printf("greq zangvaci chap@: ");
    scanf("%d", &n);

    arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Hishoxutyan sxal bashxum!\n");
        return 1;
    }

    printf("greq %d tiv:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    printf("gumar@ =  %d\n", sum);

    free(arr);
    return 0;
}

