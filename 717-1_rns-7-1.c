#include <stdio.h>

void quick_sorting(int *array, int left, int right) {
    int pivot;
    int leftHold = left;
    int rightHold = right;
    pivot = array[left];
    while (left < right) {
        while (array[right] >= pivot && left < right)
            right--;
        if (left != right) {
            array[left] = array[right];
            left++;
        }
        while (array[left] <= pivot && left < right)
            left++;
        if (left != right) {
            array[right] = array[left];
            right--;
        }
    }
    array[left] = pivot;
    pivot = left;
    left = leftHold;
    right = rightHold;
    if (left < pivot)
        quick_sorting(array, left, pivot - 1);
    if (right > pivot)
        quick_sorting(array, pivot + 1, right);
}

int main() {
    int n;
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    quick_sorting(array, 0, n - 1);
    printf("%d", array[0]);
    for (int i = 1; i < n; i++)
        printf(" %d", array[i]);
    printf("\n");
    return 0;
}
