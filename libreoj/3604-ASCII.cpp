#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int unos = 0;
    int ceros = 0;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == '0'){
            ceros += 1;
        } else {
            unos += 1;
        }
    }
    if (unos/3 >= n && ceros/2 >= n){
        vector <char> ans;
        for (int i = 0; i < n; i++){
            unos -= 3;
            ceros -= 2;
        }
        for (int i = 0; i < n; i++){
            if (ceros >= 3){
                ans.push_back('a');
                ceros -= 3;
            } else if (ceros >= 2 && unos >= 1){
                ans.push_back('c');
                ceros -= 2;
                unos -= 1;
            } else if (ceros >= 1 && unos >= 2){
                ans.push_back('g');
                ceros -= 1;
                unos -= 2;
            } else if (unos >= 3){
                ans.push_back('o');
                unos -= 3;
            } else {
                cout << "NIE\n";
                break;
            }
        }
        if (ans.size() == n){
            for (int i = 0; i < n; i++){
                cout << ans[i];
            }
            cout << endl;
        }
    } else {
        cout << "NIE\n";
    }
}