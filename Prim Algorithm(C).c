// 프림 알고리즘: 정점 --> 트리
#include<stdio.h>
#define VERTEX 100
#define EDGE 100
#define INF 9999999;
int V, E;
int dist[VERTEX]; //정점 포함 최소 비용
int visited[VERTEX]; //정점 방문 유무
int cnt[VERTEX]; // 인접 리스트

typedef struct edge {
	int start, end, cost;
}Edge;
Edge arr[EDGE];

void merge(int s, int m, int l) {
	int i = s, j = m + 1, k = s;
	Edge temp[EDGE]; // 임시 배열
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
		dist[i] = INF; // 가중치 무한대로 초기화
		visited[i] = 0;
	}
	dist[0] = 0; // 초기 방문 정점 0으로 초기화

	for (int i = 0; i < E; i++) { // 간선 순회
		int now = -1, min_dist = INF;
		for (int j = 0; j < V; j++) {
			// 트리에 포함되지 않은 정점 중 비용이 가장 작은 것을 선택
			if (!visited[j] && min_dist > dist[j]) { 
				now = j;
				min_dist = dist[j];
			}
		}
		if (now < 0) return INF; // 연결 그래프가 아니다.
		ret += min_dist;
		visited[now] = 1;

		//현재 선택된 정점의 인접 정점의 비용을 업데이트 한다.
		for (int j = 0; j < cnt[now]; j++) {
			dist[arr[now].end] = getMin(dist[arr[now].end], arr[now].cost);
		}
	}
}

int main() {
	

}