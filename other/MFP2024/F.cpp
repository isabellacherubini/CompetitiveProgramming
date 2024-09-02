#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> dist(2*1e5 + 1, -1);
queue<int> q;
vector<vector<pair<int, int>>> graph(2*1e5 + 1);

void bfs(int start){
    dist[start] = 0;
    q.push(start);

    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(pair<int, int> v : graph[u])
        {
            int capacity = min(dist[u], v.second);
            if (u == start){
                capacity = v.second;
            }
            if(capacity > dist[v.first])
            {
                dist[v.first] = capacity;
                q.push(v.first);
            }
        }
    }
}

int main(){
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    bfs(s);
    cout << dist[t] << endl;
}