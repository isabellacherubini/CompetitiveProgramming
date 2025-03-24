#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<int> acum_goles;
    for (int i = 0; i < n; i++){
        int r;
        cin >> r;
        acum_goles.push_back(r);
    }
    for (int i = 0; i < q; i++){
        int buscar;
        cin >> buscar;
        int l = 0, r = n-1;
        while(l != r)
        {
            int mid = (l + r + 1) / 2;
            if(acum_goles[mid] <= buscar)
                l = mid;
            else
                r = mid-1;
        }
        if (acum_goles[l] > buscar){
            l = -1;
        }
        cout << l + 1 << " ";
    }
    cout << endl;
}