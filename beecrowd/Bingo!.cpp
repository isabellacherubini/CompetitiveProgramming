#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, b;
    cin >> n >> b;
    while (n != 0 && b != 0){
        vector<int> arr;
        vector<int> gets(n + 1, 0);
        int total = 0;
        for (int i = 0; i < b; i++){
            int a;
            cin >> a;
            if (gets[a] == 0){
                total += 1;
                gets[a] = 1;
            }
            arr.push_back(a);
        }
        for (int i = 0; i < b - 1; i++){
            for (int j = i + 1; j < b; j++){
                int res = abs(arr[i] - arr[j]);
                if (res <= n && gets[res] == 0){
                    total += 1;
                    gets[res] = 1;
                }
            }
        }
        if (total == n + 1){
            cout << "Y" << endl;
        } else {
            cout << "N" << endl;
        }
        cin >> n >> b;
    }
}