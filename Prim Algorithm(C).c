// ���� �˰���: ���� --> Ʈ��
#include<stdio.h>
#define VERTEX 100
#define EDGE 100
#define INF 9999999;
int V, E;
int dist[VERTEX]; //���� ���� �ּ� ���
int visited[VERTEX]; //���� �湮 ����
int cnt[VERTEX]; // ���� ����Ʈ

typedef struct edge {
	int start, end, cost;
}Edge;
Edge arr[EDGE];

void merge(int s, int m, int l) {
	int i = s, j = m + 1, k = s;
	Edge temp[EDGE]; // �ӽ� �迭
	while (i <= m && j <= l) {
		if (arr[i].start <= arr[j].start) temp[k++] = arr[i++];
		else temp[k++] = arr[j++];
	}
	while (i <= m) temp[k++] = arr[i++];
	while (j <= l) temp[k++] = arr[j++];
	for (int a = s; a <= l; a++) arr[a] = temp[a];
}

void mergeSort(int start, int last) {
	if (start < last) {
		int mid = (start + last) / 2;
		mergeSort(start, mid);
		mergeSort(mid + 1, last);
		merge(start, mid, last);
	}
}

void creatArr() {
	int last = arr[0].start;

	for (int i = 1; i < E; i++) {
		if (arr[i].start != last) {
			cnt[arr[i].start] += cnt[last];
			last = arr[i].start;
		}
		else cnt[i]++;
	}
}

int getMin(int a, int b) {
	return a < b ? a : b;
}

int prim() {
	int ret = 0;
	for (int i = 0; i < V; i++) {
		dist[i] = INF; // ����ġ ���Ѵ�� �ʱ�ȭ
		visited[i] = 0;
	}
	dist[0] = 0; // �ʱ� �湮 ���� 0���� �ʱ�ȭ

	for (int i = 0; i < E; i++) { // ���� ��ȸ
		int now = -1, min_dist = INF;
		for (int j = 0; j < V; j++) {
			// Ʈ���� ���Ե��� ���� ���� �� ����� ���� ���� ���� ����
			if (!visited[j] && min_dist > dist[j]) { 
				now = j;
				min_dist = dist[j];
			}
		}
		if (now < 0) return INF; // ���� �׷����� �ƴϴ�.
		ret += min_dist;
		visited[now] = 1;

		//���� ���õ� ������ ���� ������ ����� ������Ʈ �Ѵ�.
		for (int j = 0; j < cnt[now]; j++) {
			dist[arr[now].end] = getMin(dist[arr[now].end], arr[now].cost);
		}
	}
}

int main() {
	

}