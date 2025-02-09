#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        string a, b;
        cin >> a >> b;
        int pay = int(a[0] - 97);
        int aa = a[1] - '0';
        int pax = 8 - aa;
        //cout << pax << endl;
        int pby = int(b[0] - 97);
        int bb = b[1] - '0';
        int pbx = 8 - bb;
        vector<int> dist(64, 1e9);
        queue<int> q;

        int start = pax*8 + pay;
        dist[start] = 0;
        q.push(start);

        while(!q.empty()){
            int u = q.front(); q.pop();
            int x = u/8;
            int y = u%8;
            //cout << x << " " << y << " " << int(a[1]) << endl;
            if (y + 1 < 8){
                if (x + 2 < 8){
                    int nd = (x + 2)*8 + y + 1;
                    if(dist[u] + 1 < dist[nd]){
                        dist[nd] = dist[u] + 1;
                        q.push(nd);
                    }
                }
                if (x - 2 >= 0){
                    int nd = (x - 2)*8 + y + 1;
                    if(dist[u] + 1 < dist[nd]){
                        dist[nd] = dist[u] + 1;
                        q.push(nd);
                    }
                }
            }
            if (y - 1 >= 0){
                if (x + 2 < 8){
                    int nd = (x + 2)*8 + y - 1;
                    if(dist[u] + 1 < dist[nd]){
                        dist[nd] = dist[u] + 1;
                        q.push(nd);
                    }
                }
                if (x - 2 >= 0){
                    int nd = (x - 2)*8 + y - 1;
                    if(dist[u] + 1 < dist[nd]){
                        dist[nd] = dist[u] + 1;
                        q.push(nd);
                    }
                }
            }
            if (x + 1 < 8){
                if (y + 2 < 8){
                    int nd = (x + 1)*8 + y + 2;
                    if(dist[u] + 1 < dist[nd]){
                        dist[nd] = dist[u] + 1;
                        q.push(nd);
                    }
                }
                if (y - 2 >= 0){
                    int nd = (x + 1)*8 + y - 2;
                    if(dist[u] + 1 < dist[nd]){
                        dist[nd] = dist[u] + 1;
                        q.push(nd);
                    }
                }
            }
            if (x - 1 >= 0){
                if (y + 2 < 8){
                    int nd = (x - 1)*8 + y + 2;
                    if(dist[u] + 1 < dist[nd]){
                        dist[nd] = dist[u] + 1;
                        q.push(nd);
                    }
                }
                if (y - 2 >= 0){
                    int nd = (x - 1)*8 + y - 2;
                    if(dist[u] + 1 < dist[nd]){
                        dist[nd] = dist[u] + 1;
                        q.push(nd);
                    }
                }
            }
        }
        cout << dist[pbx*8 + pby] << endl;
    }
}