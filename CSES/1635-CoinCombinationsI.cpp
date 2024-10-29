#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector <int> coins;

int dp(int n){
    vector <int> mat(n + 1, 0);
    mat[0] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < coins.size(); j++){
            if ((coins[j] <= i && mat[i - coins[j]] != 0) || i == coins[j]){
                mat[i] += max(mat[i - coins[j]], 1);
                mat[i] %= 1000000007;
            }
        }
        //cout << mat[i] << endl;
    }
    return mat[n];
}

int main(){
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++){
        int c;
        cin >> c;
        coins.push_back(c);
    }
    cout << dp(x) << endl;
}