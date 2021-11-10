#define MAX 987654321
#define V_Max 1000
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int V, E, u, v, w;
vector <pair<int, int> >adj[V_Max];
//메인함수에서 간선을 저장할 벡터를 만들어놓습니다.

vector<int> SPFA(int src) {

    vector<int> dist(V, MAX);
    //최단경로의 길이를 저장할 벡터입니다. 초기값은 MAX입니다.

    queue<int> q;
    //방문할 정점을 저장할 큐를 생성합니다.

    bool inQ[V] = {};
    //O(1) 시간만에 큐에 특정 정점이 있는 판단하기 위한 배열 생성

    int visit[V] = {};
    //특정 정점을 몇번 방문했는지 알기 위한 배열 생성

    dist[src] = 0;
    //시작점에서 시작점으로의 최단경로는 0으로 설정해둡니다.

    q.push(src); inQ[src] = true;
    //시작점을 방문할 정점 목록에 넣습니다. 

    ++visit[src];
    //시작점을 한번 방문했다고 기록합니다.

    while (!q.empty()) {
        //방문할 정점이 남지 않을 때까지 반복합니다.

        int here = q.front(); Q.pop(); inQ[here] = false;
        //큐에서 방문할 정점 하나를 뽑습니다.

        for (int num = 0; num < (int)adj[here].size(); num++) {
            //현재 정점에 인접한 정점을 방문해봅니다.

            int there = adj[here][num].first;
            //인접한 정점의 번호

            int cost = adj[here][num].second;
            //인접한 정점으로 가기위한 가중치

            if (dist[there] > dist[here] + cost) {
                //인접한 정점으로 방문할 때, 최단경로가 짧아진다면

                dist[there] = dist[here] + cost;
                //경로의 길이를 갱신하고

                if (!inQ[there]) {
                    //인접한 정점이 큐에 없다면

                    Q.push(there); inQ[there] = true;
                    //큐에 배열을 넣어놓고

                    if (++visit[there] >= V)
                        //해당 정점을 V번 이상 방문했다면 음수 사이클이 있다는 의미이므로

                        return vector<int>();
                    //빈 벡터를 반환합니다.
                }
            }
        }
    }
    return dist;
    //음수 사이클없이 큐가 비워졌다면 성공적으로 최단 경로 길이를 담은 벡터를 반환합니다.
}
