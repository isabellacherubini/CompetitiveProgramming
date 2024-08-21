#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    map <string, ll> m;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        if (m.count(s) == 0){
            cout << "OK\n";
            m[s] = 1;
        } else {
            cout << s << m[s] << endl;
            m[s] += 1;
        }
    }
}