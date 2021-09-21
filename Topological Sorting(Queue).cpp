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
	//�������� ��� �迭
	int result[MAX];
	//���������� 0�� ��� ť�� ����
	for (int i = 0; i < N; i++) {
		if (degree[i] == 0) push(i);
	}

	for (int i = 0; i < N; i++) {
		if (empty()) {
			printf("����Ŭ �׷���: �������� �Ұ�\n");
			return;
		}
		int cur = pop();
		result[i] = cur; //��������

		for (int j = 0; j < a[cur].size(); j++) {
			int next = a[cur][j];
			if (--degree[next] == 0) push(next);

		}
	}

	/* ����Ŭ�� �ƴ� ���� Ȯ���ϴٸ�
	while (!empty()) {
		int cur = pop();
		
		for (int i = 0; i < a[cur].size(); i++) {
			int next = a[cur][i];
			if (--degree[next] == 0) push(next);
		}
	}*/

	//result �迭 ���
}

int main() {

}