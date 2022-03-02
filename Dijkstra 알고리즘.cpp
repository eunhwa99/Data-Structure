#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

#define MAX 30
#define INF 10000000

vector<pair<int, int>>a[MAX];
int cost[MAX];

void dijkstra(int start) {
	for (int i = 1; i <= MAX; i++)
		cost[i] = INF;
	cost[start] = 0;
	priority_queue<pair<int, int>>pq;
	pq.push(make_pair(start, 0));

	while (!pq.empty()) {
		int cur = pq.top().first;
		// 짧은 것이 먼저 오도록 음수화
		int dist = -pq.top().second;
		pq.pop();

		if (cost[cur] < dist) continue;
		for (int i = 0; i < a[cur].size(); i++) {
			int next = a[cur][i].first;

			int nextDist = dist + a[cur][i].second;

			if (nextDist < cost[next]) {
				d[next] = nextDist;
				pq.push({ next, -nextDist });
			}
		}
	}
}
