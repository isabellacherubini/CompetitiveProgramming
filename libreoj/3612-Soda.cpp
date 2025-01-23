#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
typedef long long ll;
using namespace std;

map <int, map<int, int>> states;
vector <ll> ans(100001, -1);

void dp(int A, int B, int C, ll act_a, ll act_b, ll act_c){
    queue <vector<ll>> q;
    q.push({act_a, act_b, act_c, 0});
    while (!q.empty()){
        vector<ll> turn = q.front(); q.pop();
        ll a = turn[0];
        ll b = turn[1];
        ll c = turn[2];
        ll moves = turn[3];
        moves ++;
        if (a > 0){
            int diff = min(B - b, a);
            a -= diff;
            b += diff;
            if (states[a][b] == 0){
                states[a][b] ++;
                if (ans[a] == -1){
                    ans[a] = moves;
                }
                ans[a] = min(ans[a], moves);
                if (ans[b] == -1){
                    ans[b] = moves;
                }
                ans[b] = min(ans[b], moves);
               q.push({a, b, c, moves});
            }
            a += diff;
            b -= diff;
            diff = min(C - c, a);
            a -= diff;
            c += diff;
            if (states[a][b] == 0){
                states[a][b] ++;
                if (ans[a] == -1){
                    ans[a] = moves;
                }
                ans[a] = min(ans[a], moves);
                if (ans[c] == -1){
                    ans[c] = moves;
                }
                ans[c] = min(ans[c], moves);
                q.push({a, b, c, moves});
            }
            a += diff;
            c -= diff;
        }
        if (b > 0){
            int diff = min(A - a, b);
            b -= diff;
            a += diff;
            if (states[a][b] == 0){
                states[a][b] ++;
                if (ans[a] == -1){
                    ans[a] = moves;
                }
                ans[a] = min(ans[a], moves);
                if (ans[b] == -1){
                    ans[b] = moves;
                }
                ans[b] = min(ans[b], moves);
                q.push({a, b, c, moves});
            }
            b += diff;
            a -= diff;
            diff = min(C - c, b);
            b -= diff;
            c += diff;
            if (states[a][b] == 0 || ans[c] > moves || ans[b] > moves){
                states[a][b] ++;
                if (ans[b] == -1){
                    ans[b] = moves;
                }
                ans[b] = min(ans[b], moves);
                if (ans[c] == -1){
                    ans[c] = moves;
                }
                ans[c] = min(ans[c], moves);
                q.push({a, b, c, moves});
            }
            b += diff;
            c -= diff;
        }
        if (c > 0){
            int diff = min(A - a, c);
            c -= diff;
            a += diff;
            if (states[a][b] == 0){
                states[a][b] ++;
                if (ans[a] == -1){
                    ans[a] = moves;
                }
                ans[a] = min(ans[a], moves);
                if (ans[c] == -1){
                    ans[c] = moves;
                }
                ans[c] = min(ans[c], moves);
                q.push({a, b, c, moves});
            }
            c += diff;
            a -= diff;
            diff = min(B - b, c);
            c -= diff;
            b += diff;
            if (states[a][b] == 0|| ans[c] > moves || ans[b] > moves){
                states[a][b] ++;
                if (ans[b] == -1){
                    ans[b] = moves;
                }
                ans[b] = min(ans[b], moves);
                if (ans[c] == -1){
                    ans[c] = moves;
                }
                ans[c] = min(ans[c], moves);
                q.push({a, b, c, moves});
            }
            c += diff;
            b -= diff;
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int A, B, C, a, b, c;
    cin >> A >> B >> C >> a >> b >> c;
    states[a][b] = 1;
    ans[a] = 0;
    ans[b] = 0;
    ans[c] = 0;
    dp(A, B, C, a, b, c);
    for (int i = 0; i < C+1; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}