#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n, e, t;
    cin >> n >> e >> t;
    ll m;
    cin >> m;
    vector<vector<pll>> graph(n + 1);
    for (int i = 0; i < m; i++){
        ll a, b, di;
        cin >> a >> b >> di;
        graph[b].push_back({di, a});
    }
    
    vector<ll> dist(n + 1, 1e9);
    priority_queue<pll, vector<pll>, greater<pll> > q;

    ll start = e;
    dist[start] = 0;
    q.push(pll(0,start));

    while(!q.empty())
    {
        pll p = q.top(); q.pop();
        ll d = p.first, u = p.second;

        if(d != dist[u]) continue;

        for(pll a : graph[u])
        {
            ll v = a.second, w = a.first;
            if(dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                q.push(pll(dist[v],v));
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i < n + 1; i++){
        if (dist[i] <= t){
            ans += 1;
        }
    }
    cout << ans << endl;
}