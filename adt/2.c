#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

int partition (int a[], int low, int high)
{
	int temp, key, i, j;
	key = a[low];
	i = low;
	j = high + 1;
	while (i <= j)
	{
		do i++; while (key > a[i]);
		do j--; while (key < a[j]);
		if (i < j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	temp = a[low];
	a[low] = a[j];
	a[j] = temp;
	return j;
}

void quicksort(int a[], int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = partition(a, low, high);
		quicksort(a, low, mid-1);
		quicksort(a, mid+1, high);
	}
	// delay(1);
	sleep(1);
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
	quicksort(a, low, high);
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