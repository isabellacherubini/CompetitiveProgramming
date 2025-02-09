#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int numm = 1e9;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n, r, m;
        cin >> n >> r >> m;
        vector<vector<int>> graph(n + 1);
        for (int j = 0; j < r; j++){
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        int ans = 1;
        vector<int> dist(n + 1, 1e9);
        vector<int> parent(n + 1, -1);
        for (int j = 0; j < m; j++){
            queue<int> q;
            int start, d;
            cin >> start >> d;
            if (dist[start] != numm){
                ans = 0;
            }
            dist[start] = 0;
            parent[start] = start;
            q.push(start);

            while(!q.empty()){
                int u = q.front(); q.pop();
                for(int v : graph[u]){
                    if(dist[v] == numm && dist[u] + 1 <= d){
                        dist[v] = dist[u] + 1;
                        parent[v] = start;
                        q.push(v);
                    } else if (dist[u] + 1 <= d && parent[v] != parent[u]){
                        ans = 0;
                    }
                }
            }
        }
        //cout << ans << endl;
        for (int j = 1; j < n + 1; j++){
            if (dist[j] == numm){
                ans = 0;
            }
        }
        if (ans){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}