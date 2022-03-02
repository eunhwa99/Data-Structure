
const int MAX_V = 10;
const int INF = 987654321;
int capacity[MAX_V][MAX_V]; // 용량 배열
int flow[MAX_V][MAX_V]; // 현재 유량 배열
vector<int> adj[MAX];
int V;
 
 
int networkFlow(int source, int sink)
{
    memset(flow, 0, sizeof(flow));
    int totalFlow = 0;
    while(true)
    {
        vector<int> parent(MAX_V, -1);
        queue<int> q;
        parent[source] = source;
        q.push(source);
        while(!q.empty() && parent[sink] == -1)
        {
            int here = q.front(); q.pop();
            for(int there = 0; there < adj[here].size(); there++)
            {
                if(capacity[here][there] - flow[here][there] > 0 && parent[there] == -1)
                {
                    q.push(there);
                    parent[there] = here; // 인접 정점이 어느 정점으로부터 연결되어있는지 기억
                }
            }
        }
        if(parent[sink] == -1) break;  // sink 까지의 경로를 못 찾았다면, 더 이상의 증가 경로가 없음
         
        // 연결된 경로들을 도착지점부터 반대로 모두 확인하며, 최소 유량을 탐색
        int amount = INF;
        for(int p = sink; p != source; p = parent[p])
            amount = min(capacity[parent[p]][p] - flow[parent[p]][p], amount);
     
        // 증가 경로는 유량 증가, 역 방향 경로는 유량 감소
        for(int p = sink; p != source; p = parent[p]) 
        {
            // 유량(이전노드, 현재노드) += amount
            flow[parent[p]][p] += amount;
            // 유량(현재노드, 이전노드) -= amount
            flow[p][parent[p]] -= amount;
        }
        totalFlow += amount;
    }
    return totalFlow;
}
