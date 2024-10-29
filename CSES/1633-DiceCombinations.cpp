#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mat[6][1000001];

void dp(ll i, ll n){}

int main(){
    ll n;
    cin >> n;
    vector <int> dp(n+1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= 6; j++){
            if (i - j >= 0){
                dp[i] = (dp[i] + dp[i - j])%(1000000007);
            }
        }
    }
    cout << dp[n] << endl;
}