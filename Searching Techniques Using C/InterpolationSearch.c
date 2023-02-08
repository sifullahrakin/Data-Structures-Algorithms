#include <stdio.h>

int interpolationSearch(int arr[], int lo, int hi, int x)
{
    int pos;

     if (lo <= hi && x >= arr[lo] && x <= arr[hi])
     {
         pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));

         if (arr[pos] == x)
            return pos;

        if (arr[pos] < x)
            return interpolationSearch(arr, pos + 1, hi, x);

        if (arr[pos] > x)
            return interpolationSearch(arr, lo, pos - 1, x);
     }
     return -1;
}

int main()
{
    int arr[100];
	int n, i, x, s;

	printf("*****Interpolation Search*****\n\n");

	printf("Enter number of elements\n");
	scanf("%d",&n);
	s = sizeof(arr) / sizeof(arr[0]);

	printf("Enter %d integers\n", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
	}

	printf("Enter value to find\n");
	scanf("%d", &x);

	int index = interpolationSearch(arr, 0, n - 1, x);

	if (index != -1)
        printf("Element %d found at index %d", x, index);
    else
        printf("%d Element not found.", x);

    return 0;

}
