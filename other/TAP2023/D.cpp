// choripunk

#include <bits/stdc++.h>
using namespace std;

vector <long long> c;
vector <long long> p;

int contests(long long n, long long k){
    long long resto = 0;
    for (int i = 0; i < k; i++){
        long long ac = resto + p[i];
        if (ac >= c[i]*n){
            resto = ac - c[i]*n;
        } else {
            return 0;
        }
    }
    return 1;
}

int main(){
    long long k;
    cin >> k;
    for (int i = 0; i < k; i++){
        long long r;
        cin >> r;
        c.push_back(r);
    }
    for (int i = 0; i < k; i++){
        long long r;
        cin >> r;
        p.push_back(r);
    }
    long long l = 0;
    long long r = p[0]/c[0];
    long long ans = 0;
    while (l != r){
        long long mid = (l + r + 1)/2;
        if (contests(mid, k) == 1){
            l = mid;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
}