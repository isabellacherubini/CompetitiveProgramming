#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
typedef long long ll;
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> sweets;
    for (int i = 0; i < n; i++){
        int r;
        cin >> r;
        sweets.push_back(r);
    }
    sort(sweets.begin(), sweets.end());
    int big = sweets[n - 1];
    vector <int> counts(big + 1, 0);
    counts[0] = 1;
    //cout << "a" << endl;
    for (int i = 0; i < n; i++){
        for (int j = big; j >= sweets[i] - 1; j--){
            int k = min(j + sweets[i], big);
            counts[k] += counts[j];
            counts[k] %= 1000000007;
            //cout << j << endl;
        }
    }
    int res = 0;
    for (int i = 1; i < counts.size(); i++){
        res += counts[i];
        res %= 1000000007;
    }
    cout << res << endl;
}