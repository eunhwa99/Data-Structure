#define MAX 987654321
#define V_Max 1000
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int V, E, v, e, weight;

vector <pair<int, int> >adj[V_Max];
//메인함수에서 간선을 저장할 벡터를 만들어놓습니다.

vector <int> bellman(int src) {
    vector <int> dist(V, MAX);
    //최단경로의 길이를 저장할 벡터입니다. 초기값은 MAX입니다.

    dist[src] = 0;
    //시작점에서 시작점으로의 최단경로는 0으로 설정해둡니다.

    bool check;
    //경로가 갱신되었는지 확인하기위한 장치입니다.

    for (int iter = 0; iter < V; iter++) {
        //총 (V-1)+1=V 번 방문하게 됩니다. iter=V-1 일 때가 마지막 방문입니다.

        check = false;
        //true로 변한다면 갱신에 성공한 것입니다.

        for (int here = 0; here < V; here++) {
            //현재 서있는 정점의 위치를 말합니다.

            if (dist[here] == MAX) continue;
            //현재 있는 정점의 최단경로가 아직 갱신전이라면 넘어갑니다.

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
                    check = true;
                    //갱신에 성공했음을 저장합니다.
                }
            }
        }
        if (check == false) break;
        //갱신이 일어나지 않는다면 조기종료합니다.
        //iter=V-1 에서 갱신이 일어나지 않았다면 음수사이클이 없다는 의미입니다.

    }
    if (check == true)  dist.clear();
    //iter=V-1 에서 갱신이 일어났다면 true이며 음수사이클이 있다는 의미입니다.
    //따라서 음수사이클이 존재함을 알리기위해 저장한 최단경로를 비워버립니다.

    return dist;
}
