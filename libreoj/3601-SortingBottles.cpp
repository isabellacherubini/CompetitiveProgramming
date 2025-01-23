#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int brn = 0;
    vector<pair<int, int>> apparition(n+1, {1000000, -1});
    for (int i = 0; i < n; i++){
        int r;
        cin >> r;
        if (apparition[r].second == -1){
            apparition[r] = {i + 1, r};
            brn += 1;
        }
    }
    //cout << brn << endl;
    if (k > brn){
        cout << "-1\n";
    } else {
        sort(apparition.begin(), apparition.end());
        long long swaps = 0;
        for (int i = 0; i < k; i++){
            swaps += apparition[i].first - (i + 1);
        }
        cout << swaps << endl;
    }
}