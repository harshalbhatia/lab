#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

void bubblesort(int a[], int n)
{
	int i, j, temp;
	for (j = 1; j < n; j++)
	{
		for (i = 0; i < n - j; i++)
		{
			if (a[i] > a[i + 1])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
			sleep(1);
		}
	}
}

int main()
{
	int a[10000], n, i, j, temp;
	float res;
	clock_t end, start;
	//clrscr();
	printf("Enter the size of array:\n");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		a[i] = rand();
	}
	printf("The unsorted array is:\n");
	for (i = 0; i < n; i++)
	{
		printf("%d\n", a[i]);
	}
	start = clock();
	bubblesort(a, n - 1);
	end = clock();
	printf("The sorted array is:\n");
	for (i = 0; i < n; i++)
	{
		printf("%d\n", a[i]);
	}
	// res = (end - start)/CLK_TCK;
	res = (end - start)/CLOCKS_PER_SEC;
	printf("The time taken to sort %d elements is %f seconds.\n", n, res);
	return 0;
}