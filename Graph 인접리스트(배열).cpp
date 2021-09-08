#include <iostream>
using namespace std;

#define MAX_VERTICES 50

//노드를 정의할 구조체
typedef struct GraphNode {
	int* vertex; //인접 정점 배열
	int cnt; // 인접 정점 개수
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

	GraphNode* node;
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
	// 코드 간결성 위해 node 생성(여기에 g->adj_list[u] 주소 복사해서 간단하게 코드 작성
	node = (GraphNode*)malloc(sizeof(GraphNode));

	//만약 u 정점에 접근한 것이 처음이라면 cnt를 0으로 초기화해주고 vertex는 메모리 할당해주어야 함!
	if (g->adj_list[u]== NULL) {
		node->vertex = (int*)malloc(sizeof(int));
		node->cnt = 0;
	}
	else {
		node = g->adj_list[u]; //이 줄 안넣으면 node->vertex에 realloc 안됨. 
		//realloc은 이미 메모리가 있는 포인터에만 사용할 수 있는데 node는 여기서 새로 만든 것이므로
		//메모리가 없다. 
		node->vertex = (int*)realloc(node->vertex, sizeof(int));

	}
	node->vertex[node->cnt++] = v;

	g->adj_list[u] = node;
}

void print_adj_list(GraphType* g) {
	for (int i = 0; i < g->n; i++) {
		GraphNode* p = g->adj_list[i];
		printf("정점 %d의 인접 리스트 ", i);
		for (int j = 0; j < p->cnt; j++) {
			printf("-> %d ", p->vertex[j]);
			//printf("%d의 %d번째 인접 정점\n", i, j + 1, p->vertex[j]);
		}
		puts("");
		for (int j = 0; j < p->cnt; j++) {
			
			printf("%d의 %d번째 인접 정점 %d\n", i, j + 1, p->vertex[j]);
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