#include <stdio.h>

int search(int arr[100], int n, int x)
{
	int i;
	for (i = 0; i < n; i++)
		if (arr[i] == x)
			return i;
	return -1;
}

int main(void)
{
	int arr[100];
	int i, n, x;

	printf("Enter number of elements\n");
	scanf("%d",&n);

	printf("Enter %d integers\n", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter value to find\n");
	scanf("%d", &x);

	// Function call
	int result = search(arr, n, x);
	(result == -1)? printf("Element is not present in array"): printf("Element is present at index %d", result);
	return 0;
}
