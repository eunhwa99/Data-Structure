#include<stdio.h>
#include<vector>
#define MAX 10
using namespace std;

typedef struct que {
	int front, rear;
	int node;
}Que;
Que q[MAX];
vector<int> a[MAX];
int N, degree[MAX];

void push(int x) {
	q[q->rear].node = x;
	q->rear++;
}
int pop() {
	return q[q->front++].node;
}
int empty() {
	return q->front == q->rear; 
}

void topologySort() {
	//위상정렬 결과 배열
	int result[MAX];
	//진입차수가 0인 노드 큐에 삽입
	for (int i = 0; i < N; i++) {
		if (degree[i] == 0) push(i);
	}

	for (int i = 0; i < N; i++) {
		if (empty()) {
			printf("사이클 그래프: 위상정렬 불가\n");
			return;
		}
		int cur = pop();
		result[i] = cur; //위상정렬

		for (int j = 0; j < a[cur].size(); j++) {
			int next = a[cur][j];
			if (--degree[next] == 0) push(next);

		}
	}

	/* 사이클이 아닌 것이 확실하다면
	while (!empty()) {
		int cur = pop();
		
		for (int i = 0; i < a[cur].size(); i++) {
			int next = a[cur][i];
			if (--degree[next] == 0) push(next);
		}
	}*/

	//result 배열 출력
}

int main() {

}