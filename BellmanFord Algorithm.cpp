#define MAX 987654321
#define V_Max 1000
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int V, E, v, e, weight;

vector <pair<int, int> >adj[V_Max];
//�����Լ����� ������ ������ ���͸� ���������ϴ�.

vector <int> bellman(int src) {
    vector <int> dist(V, MAX);
    //�ִܰ���� ���̸� ������ �����Դϴ�. �ʱⰪ�� MAX�Դϴ�.

    dist[src] = 0;
    //���������� ������������ �ִܰ�δ� 0���� �����صӴϴ�.

    bool check;
    //��ΰ� ���ŵǾ����� Ȯ���ϱ����� ��ġ�Դϴ�.

    for (int iter = 0; iter < V; iter++) {
        //�� (V-1)+1=V �� �湮�ϰ� �˴ϴ�. iter=V-1 �� ���� ������ �湮�Դϴ�.

        check = false;
        //true�� ���Ѵٸ� ���ſ� ������ ���Դϴ�.

        for (int here = 0; here < V; here++) {
            //���� ���ִ� ������ ��ġ�� ���մϴ�.

            if (dist[here] == MAX) continue;
            //���� �ִ� ������ �ִܰ�ΰ� ���� �������̶�� �Ѿ�ϴ�.

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
                    check = true;
                    //���ſ� ���������� �����մϴ�.
                }
            }
        }
        if (check == false) break;
        //������ �Ͼ�� �ʴ´ٸ� ���������մϴ�.
        //iter=V-1 ���� ������ �Ͼ�� �ʾҴٸ� ��������Ŭ�� ���ٴ� �ǹ��Դϴ�.

    }
    if (check == true)  dist.clear();
    //iter=V-1 ���� ������ �Ͼ�ٸ� true�̸� ��������Ŭ�� �ִٴ� �ǹ��Դϴ�.
    //���� ��������Ŭ�� �������� �˸������� ������ �ִܰ�θ� ��������ϴ�.

    return dist;
}
