#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

int simplemerge (int a[], int low, int mid, int high)
{
	int i, j, k, c[100];
	i = low;
	j = mid + 1;
	k = low;
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			c[k] = a[i];
			i++;
			k++;
		}
		else
		{
			c[k] = a[j];
			j++;
			k++;
		}
	}
	while (i <= mid)
	{
		c[k] = a[i];
		k++;
		j++;
	}
	while (i <= high)
	{
		c[k] = a[j];
		i++;
		k++;
	}
	for (i = low; i <= high; i++)
	{
		a[i] = c[i];
	}
}

void mergesort(int a[], int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high)/2;
		mergesort(a, low, mid);
		mergesort(a, mid + 1, high);
		simplemerge(a, low, mid, high);
		// sleep(1);
		// delay(1);
	}
}

int main()
{
	int a[10000], n, i, mid, low, high;
	float res;
	clock_t end, start;
	//clrscr();
	low = 0;
	printf("Enter the size of array:\n");
	scanf("%d", &n);
	high = n - 1;
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
	mergesort(a, low, high);
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