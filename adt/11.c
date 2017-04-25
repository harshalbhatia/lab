#include <stdio.h>

void prims(int cost[20][20], int src, int n)
{
	int sum, i, k, u, v, visited[10], vertex[10], cmp[10], j, min;
	sum = 0;
	for (i = 1; i <= n; i++)
	{
		vertex[i] = src;
		visited[i] = 0;
		cmp[i] = cost[src][i];
	}
	visited[src] = 1;
	for (i = 1; i <= n; i++)
	{
		min = 999;
		for (j = 1; j <= n; j++)
		{
			if(visited[j] == 0 && cmp[i] < min)
			{
				min = cmp[j];
				u = j;
			}
		}
		visited[u] = 1;
		sum = sum + cmp[u];
		printf("%d -> %d is %d\n", vertex[u], u, cmp[u]);
		for(v = 1; v <= n; v++)
		{
			if (visited[v] == 0 && cost[u][v] < cmp[v])
			{
				cmp[v] = cost[u][v];
				vertex[v] = u;
			}
		}
	}
	printf("The cost of the spanning tree is %d.\n", sum);
}

int main()
{
	int n, i, j, cost[20][20], src;
	// clrscr();
	printf("Enter the number of nodes:\n");
	scanf("%d", &n);
	printf("Enter the cost matrix:\n");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &cost[i][j]);
		}
	}
	printf("Enter the source node:\n");
	scanf("%d", &src);
	prims(cost, src, n);
	return(0);
	// getch();
}