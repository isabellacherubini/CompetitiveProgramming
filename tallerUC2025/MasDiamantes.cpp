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
    int l = 1;
    int r = n;
    int second = 0;
    int secondr;
    while (l != r){
        if (second == 0){
            cout << "? " << l << " " << r << endl;
            cin >> secondr;
        }
        if (l + 1 == r){
            if (secondr == l){
                l = r;
            }
            break;
        }
        int mid = (l + r + 1)/2;
        if (secondr >= mid){
            cout << "? " << mid << " " << r << endl;
            int ssr;
            cin >> ssr;
            if (secondr == ssr){
                l = mid;
                second = 1;
            } else {
                r = mid - 1;
                second = 0;
            }
        } else {
            if (l == mid - 1){
                mid += 1;
            }
            cout << "? " << l << " " << mid - 1 << endl;
            int ssr;
            cin >> ssr;
            if (secondr == ssr){
                r = mid - 1;
                second = 1;
            } else {
                l = mid;
                second = 0;
            }
        }
    }
    cout << "! " << l << endl;
}