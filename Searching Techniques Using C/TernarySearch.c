#include <stdio.h>

int ternarySearch(int l, int r, int x, int arr[100])
{
	while (r >= l) {
		int m = l + (r - l) / 3;
		int m2 = l + (r - l) / 3;

		if (arr[m] == x)
			return m;

        if (arr[m2] == x)
            return m2;

		if (x < arr[m])
			return ternarySearch(l, m - 1, x, arr);

        if (x>arr[m2])
            return ternarySearch(m2 + 1, r, x, arr);

		else
			return ternarySearch(m + 1, m2 - 1, x, arr);
	}
	return -1;
}

int main()
{
    int arr[100];
    int i, n, x, l, r, p;

    printf("*****Ternary Search*****\n\n");

    printf("Enter number of elements\n");
	scanf("%d",&n);

	printf("Enter %d integers\n", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
	}

	l = 0;
	r = n;

	printf("Enter value to find\n");
	scanf("%d", &x);

	p = ternarySearch(l, r, x, arr);
	if (p != -1)
    {
	  printf("Index of %d is %d\n",x, p);
    }

	printf("Again Enter value to find\n");
	scanf("%d", &x);

	p = ternarySearch(l, r, x, arr);
	if (p != -1)
    {
      printf("Index of %d is %d", x, p);
    }

    else
        printf("%d Element not found.", x);

}
