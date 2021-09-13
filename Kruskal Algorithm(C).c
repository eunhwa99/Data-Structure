#include<stdio.h>
int v, e, a, b, c;
int parent[100001];

typedef struct kruskal
{
	int from; int to; int cost;
}K;
K arr[100001];
K copy[100001];

int find(int x)
{
	if (parent[x] == x)
		return x;
	else
		return parent[x] = find(parent[x]);

}

void Union(int x, int y)
{
	x = find(x);
	y = find(y);
	parent[y] = x;
}

void merge(int start, int end)
{
	int mid = (start + end) / 2;
	int i = start, j = mid + 1, k = 0;
	while (i <= mid && j <= end)
	{
		if (arr[i].cost <= arr[j].cost) copy[k++] = arr[i++];
		else copy[k++] = arr[j++];
	}
	while (i <= mid) copy[k++] = arr[i++];
	while (j <= end) copy[k++] = arr[j++];
	for (int i = start; i <= end; i++)
		arr[i] = copy[i - start];
}

void sort(int start, int end)
{
	if (start == end)
		return;
	int mid = (start + end) / 2;
	sort(start, mid);
	sort(mid + 1, end);
	merge(start, end);
}

int main()
{
	scanf("%d %d", &v, &e);
	for (int i = 1; i <= v; i++)
		parent[i] = i;
	for (int i = 0; i < e; i++)
	{
		scanf("%d %d %d", &arr[i].from, &arr[i].to, &arr[i].cost);

	}
	sort(0, e - 1);
	long long sum = 0;
	for (int i = 0; i < e; i++)
	{
		K edge = arr[i];
		int x = find(edge.from);
		int y = find(edge.to);
		if (x != y)
		{
			Union(edge.from, edge.to);
			sum += edge.cost;
		}
	}
	printf("%lld\n", sum);
}