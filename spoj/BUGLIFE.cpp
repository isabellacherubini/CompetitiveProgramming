#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int b, m;
        cin >> b >> m;
        vector<vector<int>> adj(b+1);
        for (int j = 0; j < m; j++){
            int a, c;
            cin >> a >> c;
            adj[a].push_back(c);
            adj[c].push_back(a);
        }
        vector<int> side(b+1, -1);
        bool is_bipartite = true;
        queue<int> q;
        for (int st = 1; st < b+1; ++st) {
            if (side[st] == -1) {
                q.push(st);
                side[st] = 0;
                while (!q.empty()) {
                    int v = q.front();
                    q.pop();
                    for (int u : adj[v]) {
                        if (side[u] == -1) {
                            side[u] = side[v] ^ 1;
                            q.push(u);
                        } else {
                            is_bipartite &= side[u] != side[v];
                        }
                    }
                }
            }
        }
        cout << "Scenario #" << i+1 << ":\n";
        if (is_bipartite){
            cout << "No suspicious bugs found!\n";
        } else {
            cout << "Suspicious bugs found!\n";
        }
    }
}