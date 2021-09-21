#include<stdio.h>
#include<vector>
#define MAX 10
using namespace std;

typedef struct stack {
	int idx = -1;
	int node;
}Stack;

void push(int x) {
	stk[++stk->idx].node = x;
}
int pop() {
	return stk[stk->idx--].node;
}
int empty() {
	return stk->idx == -1;
}
Stack stk[MAX];
vector<int> a[MAX];
int visited[MAX];
int N, degree[MAX];

void dfs(int now) {
	visited[now] = 1;

	for (int i = 0; i < a[now].size(); i++) {
		int next = a[now][i];
		if (!visited[next])
			dfs(next);
	}
	// 정점 처리 종료 ==> 정점 추가
	push(now);
}

void topologySort() {

	for (int i = 0; i < N; i++) {
		if (!visited[i]) dfs(i);
	}

	while (!empty()) {
		printf("%d ", pop());
	}

}

int main() {

}