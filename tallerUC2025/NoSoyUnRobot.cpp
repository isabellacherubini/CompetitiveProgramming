#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

vector<ll> needs;
vector<ll> has;

int test(ll k, ll mid){
    ll n = needs.size();
    int sp = 1;
    for (int i = 0; i < n; i++){
        if (needs[i]*mid > has[i]){
            if (needs[i]*mid > has[i] + k){
                sp = 0;
            } else {
                k -= needs[i]*mid - has[i];
            }
        }
    }
    return sp;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        ll r;
        cin >> r;
        needs.push_back(r);
    }
    ll max_robots = 0;
    for (int i = 0; i < n; i++){
        ll r;
        cin >> r;
        has.push_back(r);
        max_robots = max(max_robots, r);
    }
    max_robots += k;
    ll l = 0, r = max_robots;
    while(l != r)
    {
        ll mid = (l + r + 1) / 2;
        if(test(k, mid) == 1)
            l = mid;
        else
            r = mid-1;
    }
    cout << l << endl;
}