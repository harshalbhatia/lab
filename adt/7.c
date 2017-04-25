#include <stdio.h>
#define INFINITY 999

int find(int v, int p[100])
{
	while (p[v] != v)
		v = p[v];
	return v;
}

void kruskals(int n, int c[100][100])
{
	int count, i, p[100], s[100], mincost, j, u, v, k, t[100][2], sum;
	for (i = 0; i < n; i++)
		p[i] = i;
	count = 0;
	sum = 0;
	k = 0;
	while (count < n - 1)
	{
		mincost = INFINITY;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (c[i][j] != 0 && c[i][j] < mincost)
				{
					mincost = c[i][j];
					i = j;
				}
			}
		}
		if (mincost == INFINITY)
		{
			i = find(u, p);
			j = find(v, s);
			if (u != v)
			{
				t[k][0] = u;
				t[k][1] = v;
				k++;
				count++;
				sum+=mincost;
				p[v] = u;
			}
			c[u][v] = c[v][u] = INFINITY;
		}
	}
	if (count == n - 1)
	{
		printf("Cost of spanning tree %d.\n", sum);
		for (i = 0; i < n - 1; i++)
			printf("%d -> %d\n", t[i][0], t[i][j]);
		printf("Sum = %d\n", sum);
	}
	else
		printf("Spanning tree does not exist.\n");
}

int main()
{
	int i, j, n, c[100][100];
	// clrscr();
	printf("Enter the number of vertices:\n");
	scanf("%d", &n);
	printf("Enter the cost adjacency matrix:\n");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &c[i][j]);
		}
	}
	kruskals(n, c);
	// getch();
	return 0;
}