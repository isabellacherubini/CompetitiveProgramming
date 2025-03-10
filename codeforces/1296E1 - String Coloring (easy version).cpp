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
    vector<char> arr1;
    vector<char> arr2;
    string ans;
    for (int i = 0; i < n; i++){
        if (i == 0){
            arr1.push_back(s[0]);
            ans += '0';
        } else {
            if (arr1[arr1.size() - 1] <= s[i]){
                if (arr2.size() != 0 && arr2[arr2.size()] <= s[i]){
                    if (arr1[arr1.size() - 1] > arr2[arr2.size() - 1]){
                        arr1.push_back(s[i]);
                        ans += '0';
                    } else {
                        arr2.push_back(s[i]);
                        ans += '1';
                    }
                } else {
                    arr1.push_back(s[i]);
                    ans += '0';
                }
            } else if (arr2.size() == 0 || arr2[arr2.size() - 1] <= s[i]){
                arr2.push_back(s[i]);
                ans += '1';
            } else {
                break;
            }
        }
    }
    if (arr1.size() + arr2.size() == n){
        cout << "YES\n";
        cout << ans << endl;
    } else {
        cout << "NO\n";
    }
}