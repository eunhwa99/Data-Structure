#include <iostream>
using namespace std;

#define MAX_VERTICES 50

//노드를 정의할 구조체
typedef struct GraphNode {
	int vertex; //정점
	struct GraphNode* link; // 자기 참조 구조체: 링크를 통하여 차례대로 연결 가능(연결리스트)
}GraphNode;

//노드가 저장되는 리스트를 정의할 구조체
typedef struct GraphType {
	int n; //정점의 개수
	GraphNode* adj_list[MAX_VERTICES];
}GraphType;

//그래프 초기화
void init(GraphType* g) {
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++) {
		g->adj_list[v] = NULL;
	}
}

//정점 삽입 연산
void insert_vertex(GraphType* g, int v) {
	if (((g->n) + 1) > MAX_VERTICES) {
		cout << "그래프 최대 정점 개수 초과!\n";
		return;
	}
	g->n++;
}

//간선 삽입 연산, v를 u의 인접 리스트에 삽입함
void insert_edge(GraphType* g, int u, int v) {
	GraphNode* node;
	//정점 u의 번호나 정점 v의 번호가 그래프 정점의 개수 이상일 때
	//그래프의 정점의 개수가 n이면 간선의 개수는 n-1이다.
	if (u >= g->n || v >= g->n) {
		cout << "그래프 정점 번호 오류!\n";
	}

	//새로운 노드 동적 생성, node에는 시작 메모리 주소가 저장
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}

void print_adj_list(GraphType* g) {
	for (int i = 0; i < g->n; i++) {
		GraphNode* p = g->adj_list[i];
		printf("정점 %d의 인접 리스트 ", i);
		while (p != NULL) {
			printf("-> %d ", p->vertex);
			p = p->link;
		}
		printf("\n");
	}
}


int main() {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);

	int v_num;
	cout << "삽입할 정점의 개수를 입력하세요 : ";
	cin >> v_num;
	for (int i = 0; i < v_num; i++) {
		insert_vertex(g, i);
	}
	int e_num;
	cout << "삽입할 간선의 개수를 입력하세요 : ";
	cin >> e_num;
	for (int i = 0; i < e_num; i++) {
		int x, y;
		cout << "정점 u와 v를 입력하세요(u-v) : ";
		cin >> x >> y;
		//무방향 그래프기준 반대도 삽입함, 방향그래프면 (x, y)만
		insert_edge(g, x, y);
		insert_edge(g, y, x);
	}
	print_adj_list(g);
	free(g);
	return 0;

}