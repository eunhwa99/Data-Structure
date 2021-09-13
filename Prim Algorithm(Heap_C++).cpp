#include <stdio.h>
#include<vector>
#include<queue>
#define PII pair<int,int>
using namespace std;

const int N = 1005, INF = 2140000000;

vector<PII> ad[N];  // ad[i] : i ��尡 ������� ������, first = ���, second = ������
priority_queue<PII, vector<PII>, greater<PII> > dist;        // dist : ���õ� ���ɼ��� �ִ� ������
bool selected[N];   // selected[i] : i �� ������ ���õ� ����ΰ�?

void add_edge(int node) {
    for (auto edge : ad[node]) {
        dist.push(edge);
    }
}

long long prim(int pn) {
    long long ret = 0;
    for (int i = 1; i <= pn; i++) { // �ʱ�ȭ
        selected[pn] = false;
    }
    dist.push(PII(0, 1));
    for (int i = 1; i <= pn; i++) {
        int now = -1, min_dist = INF;
        while (!dist.empty()) {
            now = dist.top().second;
            if (!selected[now]) {
                min_dist = dist.top().first;
                break;
            }
            dist.pop();
        }
        if (min_dist == INF) return (long long)INF; // ���� �׷����� �ƴ�
        ret += min_dist;
        selected[now] = true;
        add_edge(now);
    }
    return ret;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    while (m--) {
        int v1, v2, c;
        scanf("%d %d %d", &v1, &v2, &c);
        ad[v1].push_back(PII(c, v2));
        ad[v2].push_back(PII(c, v1));
    }
    printf("%lld", prim(n));
    return 0;
}
