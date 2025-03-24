#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

vector<int> heights;

int test(int k){
    int sp = 1;
    int n = heights.size();
    for (int i = 0; i < k; i++){
        if (heights[k - i - 1]* 2 > heights[n - i - 1]){
            sp = 0;
        }
    }
    return sp;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int r;
        cin >> r;
        heights.push_back(r);
    }
    sort(heights.begin(), heights.end());
    int l = 0, r = n/2;
    while(l != r)
    {
        int mid = (l + r + 1) / 2;
        if(test(mid) == 1)
            l = mid;
        else
            r = mid-1;
    }
    cout << n - l << endl;
}