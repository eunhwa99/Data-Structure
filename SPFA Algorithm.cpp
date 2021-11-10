#define MAX 987654321
#define V_Max 1000
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int V, E, u, v, w;
vector <pair<int, int> >adj[V_Max];
//�����Լ����� ������ ������ ���͸� ���������ϴ�.

vector<int> SPFA(int src) {

    vector<int> dist(V, MAX);
    //�ִܰ���� ���̸� ������ �����Դϴ�. �ʱⰪ�� MAX�Դϴ�.

    queue<int> q;
    //�湮�� ������ ������ ť�� �����մϴ�.

    bool inQ[V] = {};
    //O(1) �ð����� ť�� Ư�� ������ �ִ� �Ǵ��ϱ� ���� �迭 ����

    int visit[V] = {};
    //Ư�� ������ ��� �湮�ߴ��� �˱� ���� �迭 ����

    dist[src] = 0;
    //���������� ������������ �ִܰ�δ� 0���� �����صӴϴ�.

    q.push(src); inQ[src] = true;
    //�������� �湮�� ���� ��Ͽ� �ֽ��ϴ�. 

    ++visit[src];
    //�������� �ѹ� �湮�ߴٰ� ����մϴ�.

    while (!q.empty()) {
        //�湮�� ������ ���� ���� ������ �ݺ��մϴ�.

        int here = q.front(); Q.pop(); inQ[here] = false;
        //ť���� �湮�� ���� �ϳ��� �̽��ϴ�.

        for (int num = 0; num < (int)adj[here].size(); num++) {
            //���� ������ ������ ������ �湮�غ��ϴ�.

            int there = adj[here][num].first;
            //������ ������ ��ȣ

            int cost = adj[here][num].second;
            //������ �������� �������� ����ġ

            if (dist[there] > dist[here] + cost) {
                //������ �������� �湮�� ��, �ִܰ�ΰ� ª�����ٸ�

                dist[there] = dist[here] + cost;
                //����� ���̸� �����ϰ�

                if (!inQ[there]) {
                    //������ ������ ť�� ���ٸ�

                    Q.push(there); inQ[there] = true;
                    //ť�� �迭�� �־����

                    if (++visit[there] >= V)
                        //�ش� ������ V�� �̻� �湮�ߴٸ� ���� ����Ŭ�� �ִٴ� �ǹ��̹Ƿ�

                        return vector<int>();
                    //�� ���͸� ��ȯ�մϴ�.
                }
            }
        }
    }
    return dist;
    //���� ����Ŭ���� ť�� ������ٸ� ���������� �ִ� ��� ���̸� ���� ���͸� ��ȯ�մϴ�.
}
