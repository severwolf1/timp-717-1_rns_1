#include <stdio.h>

void sortirovka (int *array, int root, int bottom){
    int max;
    int k = 0;
    while ((root * 2 <= bottom) && (!k))
    {
        if (root * 2 == bottom)
            max = root * 2;
        else if (array[root * 2] > array[root * 2 + 1])
            max = root * 2;
        else
            max = root * 2 + 1;
        if (array[root] < array[max]) {
            int t = array[root];
            array[root] = array[max];
            array[max] = t;
            root = max;
        }
        else
            k = 1;
    }
}

void sorting_function(int *array, int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        sortirovka (array, i, n - 1);
    for (int i = n - 1; i >= 1; i--) {
        int x = array[0];
        array[0] = array[i];
        array[i] = x;
        sortirovka (array, 0, i - 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    sorting_function(array, n);
    printf("%d", array[0]);
    for (int i = 1; i < n; i++)
        printf(" %d", array[i]);
    printf("\n");
    return 0;
}
