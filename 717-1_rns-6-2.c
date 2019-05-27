#include <stdio.h>

void Shell(int *arr, int arr_len)
{
    int q;
    int j;
    for (int s = arr_len / 2; s > 0; s /= 2)
        for (int i = s; i < arr_len; i++)
        {
            q = arr[i];
            for (j = i; j >= s; j -= s)
            {
                if (q < arr[j - s])
                    arr[j] = arr[j - s];
                else
                    break;
            }
            arr[j] = q;
        }
}
 
int main()
{
	int n;
	scanf("%d", &n);	
	if (n == 0) return 0;
	int arr[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	Shell(arr, n);
	printf("%d", arr[0]);
	for (int i = 1; i < n; i++)
		printf(" %d", arr[i]);
	printf("\n");
	return 0;
}
