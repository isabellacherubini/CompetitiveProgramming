#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

vector <int> cities;
vector <int> towers;

int find_left(int j){
    int l = 0, r = towers.size() - 1;
    while (l != r){
        int mid = (l + r + 1)/2;
        if (towers[mid] <= cities[j]){
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return abs(towers[l] - cities[j]);
}

int find_right(int j){
    int l = 0, r = towers.size() - 1;
    while(l != r){
        int mid = (l + r)/2;
        if (towers[mid] >= cities[j]){
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return abs(towers[l] - cities[j]);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        cities.push_back(a);
    }
    for (int i = 0; i < m; i++){
        int b;
        cin >> b;
        towers.push_back(b);
    }
    int ans = -1;
    for (int i = 0; i < n; i++){
        int res = min(find_right(i), find_left(i));
        if (ans == -1){
            ans = res;
        } else {
            ans = max(ans, res);
        }
    }
    cout << ans << endl;
}