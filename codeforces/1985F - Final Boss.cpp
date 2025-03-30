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
        int h, n;
        cin >> h >> n;
        vector<ll> attacks;
        for (int j = 0; j < n; j++){
            ll r;
            cin >> r;
            if (h > 0 ){
                h -= r;
            }
            attacks.push_back(r);
        }
        map <ll, ll> cooldown;
        multiset <pair<ll, pair<ll, ll>>> counts;
        for (int j = 0; j < n; j++){
            ll cd;
            cin >> cd;
            cooldown[cd] += attacks[j];
        }
        for (auto k = cooldown.begin(); k != cooldown.end(); k++){
            counts.insert({k->first, {k->first, k->second}});
        }
        ll turns = 1;
        while (h > 0){
            auto a = counts.begin();
            pair<ll, pair<ll, ll>> b = *a;
            h -= b.second.second;
            counts.erase(a);
            turns = b.first + 1;
            b.first += b.second.first;
            counts.insert(b);
        }
        cout << turns << endl;
    }
}