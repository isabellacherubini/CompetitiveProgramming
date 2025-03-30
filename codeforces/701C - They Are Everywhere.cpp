#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    map <char, int> positions;
    set <int> least_array;
    int minimum = 1000000;
    int setsize = 0;
    for (int i = 0; i < n; i++){
        if (positions[s[i]] == 0){
            positions[s[i]] = -1;
            setsize += 1;
        }
    }
    for (int i = 0; i < n; i++){
        if (positions[s[i]] == -1){
            positions[s[i]] = i + 1;
            least_array.insert(i + 1);
        } else {
            least_array.erase(positions[s[i]]);
            positions[s[i]] = i + 1;
            least_array.insert(i + 1);
        }
        if (least_array.size() == setsize){
            auto it = least_array.end();
            it --;
            int diff = *(it) - *(least_array.begin()) + 1;
            minimum = min(minimum, diff);
        }
    }
    cout << minimum << endl;
}