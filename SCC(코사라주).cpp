#include<stdio.h>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
bool visited[10001];

vector<vector<int>> adj;
vector<vector<int>> adjTrans; // 역방향 그래프
stack<int>stk; // 스택
int num_scc; // # of SCC
vector<int> scc[10001]; // SCC 요소 저장
int V, E;

// 1번째 DFS
void dfs(int root) {
    visited[root] = true;

    for (int i = 0; i < adj[root].size(); i++) {

        if (!visited[adj[root][i]]) {
            dfs(adj[root][i]);
        }

    }
    stk.push(root);
    return;
}

// 2번째 DFS (역방향 그래프)
void dfsTrans(int vertex) {
    visited[vertex] = true;

    for (int i = 0; i < adjTrans[vertex].size(); i++) {

        if (!visited[adjTrans[vertex][i]]) {
            dfsTrans(adjTrans[vertex][i]);
            //result.back().push_back(adjTrans[root][i]);
        }

    }
    scc[num_scc].push_back(vertex);
    return;
}

void make_scc() {
    for (int i = 0; i <= V; i++) visited[i] = false; // 초기화

    // 스택이 빌때까지
    while (!stk.empty()) {
        int here = stk.top();
        stk.pop();
        if (!visited[here]) {
            dfsTrans(stk.top()); // 역방향 DFS
            num_scc++;
        }
    }


    for (int i = 0; i < num_scc; i++) {
        sort(scc[i].begin(), scc[i].end());
    }
}

void kosaraju() {
    for (int i = 1; i <= V; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}

int main() {

    scanf("%d %d", &V, &E);

    adj.resize(V + 1);
    adjTrans.resize(V + 1);

    for (int i = 0; i < E; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adjTrans[b].push_back(a);
    }

    kosaraju();
    make_scc();
   
}
