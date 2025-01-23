#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
typedef long long ll;
using namespace std;



int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector <string> matrix;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        matrix.push_back(s);
    }
    ll tim = -1;
    ll count = 0;
    vector <ll> dist(n*m, -1);
    queue <pair<pair <int, int>,pair <int, int>>> q;
    int start = 0;
    dist[start] = 0;
    q.push({{0, 0},{0,0}});
    int a = 1;
    int b = 1;
    int ca = 0;
    int cb = 0;
    int usea = 10000;
    int useb = 10000;
    while (!q.empty()){
        pair<pair <int, int>,pair <int, int>> duy = q.front(); q.pop();
        pair <int, int> du = duy.first;
        pair <int, int> actc = duy.second;
        int x = du.first;
        int y = du.second;
        //cout << x << " " << y << endl;
        if (x == n - 1 && y ==  m - 1){
            usea = actc.first;
            useb = actc.second;
        }
        if (x > 0){
            if (matrix[x - 1][y] == '.' && (dist[x*m + y] + b < dist[(x - 1)*m + y] || dist[(x - 1)*m + y] == -1)){
                dist[(x - 1)*m + y] = dist[x*m + y] + b;
                q.push({{x - 1, y}, {actc.first, actc.second+1}});
            }
        }
        if (x + 1 < n){
            if (matrix[x + 1][y] == '.' && (dist[x*m + y] + a < dist[(x + 1)*m + y] || dist[(x + 1)*m + y] == -1)){
                dist[(x + 1)*m + y] = dist[x*m + y] + a;
                q.push({{x + 1, y}, {actc.first + 1, actc.second}});
            }
        }
        if (y + 1 < m){
            if (matrix[x][y + 1] == '.' && (dist[x*m + y] + a < dist[x*m + y + 1] || dist[x*m + y+1] == -1)){
                dist[x*m + y+1] = dist[x*m + y] + a;
                q.push({{x, y+1}, {actc.first + 1, actc.second}});
            }
        }
        if (y > 0){
            if (matrix[x][y - 1] == '.' && (dist[x*m + y] + b < dist[x*m + y-1] || dist[x*m + y-1] == -1)){
                dist[x*m + y-1] = dist[x*m + y] + b;
                q.push({{x, y-1}, {actc.first, actc.second+1}});
            }
        }
    }

    //cout << usea << " " << useb << endl;

    for (int i = 0; i < k; i++){
        ll a,b;
        cin >> a >> b;
        if (a*usea + b*useb < tim || tim == -1){
            tim = a*usea + b*useb;
            count = 1;
        } else if (a*usea + b*useb == tim){
            count += 1;
        }
        //for (int i = 0; i < n; i++){
            //for (int j = 0; j < m; j++){
                //cout << dist[i*m + j] << " ";
            //}
            //cout << endl;
        //}
    }
    cout << tim << " " << count << endl;
}