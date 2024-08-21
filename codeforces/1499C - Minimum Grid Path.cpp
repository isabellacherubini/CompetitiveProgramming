#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    for (int k = 0; k < t; k++){
        ll n;
        cin >> n;
        vector <ll> dh;
        ll anth = -1;
        ll mh = -1;
        vector <ll> dv;
        ll antv = -1;
        ll mv = -1;
        for (int i = 0; i < n; i++){
            ll r;
            cin >> r;
            if (i%2 == 0){
                if (i == 0){
                    dh.push_back(n*r);
                    anth = r;
                    mh = r;
                } else {
                    dh.push_back(min((n - i/2)*r + anth, (n - i/2)*mh + (anth - mh + r)));
                    anth += r;
                    mh = min(mh, r);
                }
            } else {
                if (i == 1){
                    dv.push_back(n*r);
                    antv = r;
                    mv = r;
                } else {
                    dv.push_back(min((n - (i - 1)/2)*r + antv, (n - (i - 1)/2)*mv + (antv - mv + r)));
                    antv += r;
                    mv = min(mv, r);
                }
            }
        }
        ll res = dv[0] + dh[0];
        for (int j = 0; j < n/2; j++){
            res = min(res, dv[j] + dh[j]);
            if (j + 1 < dh.size()){
                res = min(res, dv[j] + dh[j + 1]);
            }
        }
        cout << res << endl;
    }
}