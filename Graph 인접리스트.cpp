#include <iostream>
using namespace std;

#define MAX_VERTICES 50

//��带 ������ ����ü
typedef struct GraphNode {
	int vertex; //����
	struct GraphNode* link; // �ڱ� ���� ����ü: ��ũ�� ���Ͽ� ���ʴ�� ���� ����(���Ḯ��Ʈ)
}GraphNode;

//��尡 ����Ǵ� ����Ʈ�� ������ ����ü
typedef struct GraphType {
	int n; //������ ����
	GraphNode* adj_list[MAX_VERTICES];
}GraphType;

//�׷��� �ʱ�ȭ
void init(GraphType* g) {
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++) {
		g->adj_list[v] = NULL;
	}
}

//���� ���� ����
void insert_vertex(GraphType* g, int v) {
	if (((g->n) + 1) > MAX_VERTICES) {
		cout << "�׷��� �ִ� ���� ���� �ʰ�!\n";
		return;
	}
	g->n++;
}

//���� ���� ����, v�� u�� ���� ����Ʈ�� ������
void insert_edge(GraphType* g, int u, int v) {
	GraphNode* node;
	//���� u�� ��ȣ�� ���� v�� ��ȣ�� �׷��� ������ ���� �̻��� ��
	//�׷����� ������ ������ n�̸� ������ ������ n-1�̴�.
	if (u >= g->n || v >= g->n) {
		cout << "�׷��� ���� ��ȣ ����!\n";
	}

	//���ο� ��� ���� ����, node���� ���� �޸� �ּҰ� ����
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}

void print_adj_list(GraphType* g) {
	for (int i = 0; i < g->n; i++) {
		GraphNode* p = g->adj_list[i];
		printf("���� %d�� ���� ����Ʈ ", i);
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
	cout << "������ ������ ������ �Է��ϼ��� : ";
	cin >> v_num;
	for (int i = 0; i < v_num; i++) {
		insert_vertex(g, i);
	}
	int e_num;
	cout << "������ ������ ������ �Է��ϼ��� : ";
	cin >> e_num;
	for (int i = 0; i < e_num; i++) {
		int x, y;
		cout << "���� u�� v�� �Է��ϼ���(u-v) : ";
		cin >> x >> y;
		//������ �׷������� �ݴ뵵 ������, ����׷����� (x, y)��
		insert_edge(g, x, y);
		insert_edge(g, y, x);
	}
	print_adj_list(g);
	free(g);
	return 0;

}