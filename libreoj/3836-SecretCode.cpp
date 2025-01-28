#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    int ans = 0;
    cin >> n;
    map<int, int> seen;

    vector<int> adivisors;
    for (int i = 1; i*i <= n; i++){
        if (n%i == 0){
            adivisors.push_back(i);
            if (i != n/i){
                adivisors.push_back(n/i);
            }
        }
    }
    for (int i = 0; i < adivisors.size(); i++){
        vector<int> xdivisors;
        if (adivisors[i] - 1 >= 2){
            int w = adivisors[i] - 1;
            for (int j = 1; j*j <= w; j++){
                if (w%j == 0){
                    xdivisors.push_back(j);
                    if (j != w/j){
                        xdivisors.push_back(w/j);
                    }
                }
            }
            for (int j = 0; j < xdivisors.size(); j++){
                if (xdivisors[j] >= 2){
                    int z = w/xdivisors[j] - 1;
                    int a = n/adivisors[i];
                    int b = a*xdivisors[j];
                    int c = b*z;
                    //cout << a << ' ' << b << ' ' << c << '\n';
                    if (a < b && b < c && a + b + c == n){
                        ans += 1;
                    }
                }
            }
        }
    }
    cout << ans;
}