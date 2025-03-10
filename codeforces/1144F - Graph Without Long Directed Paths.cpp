#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector <pair<int, int>> check_ans;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        check_ans.push_back({a, b});
    }
    vector<int> side(n+1, -1);
    bool is_bipartite = true;
    queue<int> q;
    for (int st = 1; st < n+1; ++st) {
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
    if (is_bipartite){
        cout << "YES" << endl;
        for (int i = 0; i < m; i++){
            if (side[check_ans[i].first] == 0){
                cout << 1;
            } else {
                cout << 0;
            }
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
}