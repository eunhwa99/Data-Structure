vector<int> Vertex[20002];
int SCCnum[20002];
vector<int> stk;
int discovered[20002];
 
int sccCounter, vertexCounter;
 
 
int SCC(int now){
    int ret = discovered[now] = vertexCounter++;
    stk.push_back(now);
    
    for(int i = 0; i < Vertex[now].size(); i++){
        int next = Vertex[now][i];
        
        if(discovered[next] == -1){
            ret = min(ret, SCC(next));
        }
        else if(SCCnum[next] == -1){
            ret = min(ret, discovered[next]);
        }
    }
    
    if(ret == discovered[now]){
        while(true){
            int temp = stk.back();
            stk.pop_back();
            SCCnum[temp] = sccCounter;
            if(temp == now) break;
        }
        sccCounter++;
    }
    
    return ret;
}


출처: https://hyeo-noo.tistory.com/130 [개발냥발]
