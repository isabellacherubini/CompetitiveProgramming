#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll k;
    cin >> k;
    ll cant_caminos = 1;
    ll coef = 1;
    ll coef_del_coef = 1;
    vector <pair<ll, ll>> ans;
    ans.push_back({1, 2});
    ll cant_nodos = 2;
    for (int i = 3; i <= 100; i++){
        if (k == cant_caminos){
            break;
        }
        ll pos_caminos = i - 3;
        //cout << k << " " << cant_caminos + coef << endl;
        if (k - (cant_caminos + coef) >= 0){
            ans.push_back({1, i});
            ans.push_back({i, 2});
            cant_caminos += coef;
            coef += coef_del_coef;
            coef_del_coef++;
            for (int j = 3; j < i; j++){
                ans.push_back({i, j});
            }
        } else {
            ans.push_back({1, i});
            ans.push_back({i, 2});
            cant_caminos += 1;
            for (int j = i - 1; j >= 3; j--){
                //cout << cant_caminos << endl;
                if (cant_caminos + pos_caminos <= k){
                    ans.push_back({i, j});
                    cant_caminos += pos_caminos;
                }
                pos_caminos --;
            }
        }
        cant_nodos ++;
    }
    cout << cant_nodos << " " << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}