#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while (cin >> n){
        if (n%6 == 0 && n <= 180){
            cout << "Y\n";
        } else {
            cout << "N\n";
        }
    }
}