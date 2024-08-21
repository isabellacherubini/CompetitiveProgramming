#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector <ll> sq;

void csq(){
    ll n = 1e6;
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for(int i = 2; i < n; i++)
        if(prime[i])
            for(int j = 2*i; j < n; j += i)
                prime[j] = false;
    for (ll i = 0; i < 1e6; i++){
        if (prime[i]){
            sq.push_back(i*i);
            //cout << i*i << endl;
        }
    }
}

int main(){
    int n;
    cin >> n;
    csq();
    for (int i = 0; i < n; i++){
        ll num;
        cin >> num;
        ll l = 0;
        ll r = sq.size() - 1;
        while (l != r){
            ll mid = (l + r)/2;
            //cout << sq[mid] << endl;
            if (sq[mid] >= num){
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (sq[r] == num){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}