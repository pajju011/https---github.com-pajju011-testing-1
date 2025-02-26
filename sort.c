#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int *a, n;
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void selectionsort(int a[], int n)
{
    int i, j, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            min = j;
        if (a[j] < a[min])
            min = j;
        swap(&a[i], &a[min]);
    }
}

void display()
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
        printf("\n");
    }
}
int main()
{
    float start, end, complexity;
    printf("Enter the size of array\n");
    scanf("%d", &n);
    a = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 20;
    }
    printf("content of array\n");
    display();
    start = clock();
    selectionsort(a, n);
    end = clock();
    printf("Array after sort\n");
    display();
    complexity = (end - start) / CLOCKS_PER_SEC;
    printf("complexity is %f", complexity);
    free(a);
    return 0;
}