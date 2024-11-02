#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k, e;
    cin >> n >> k >> e;
    int left = e;
    int center = k;
    int rigth = n - e - k;
    if (left != center && center != rigth && rigth != left){
        cout << 0 << endl;
    } else if (left == rigth && center == left){
        if (left == 1){
            cout << 2 << endl;
        } else if (left == 2){
            cout << 3 << endl;
        } else if (left == 3){
            cout << 3 << endl;
        } else if (left == 4){
            cout << 2 << endl;
        } else {
            cout << 0 << endl;
        }
    } else {
        int a, b, c;
        if (left == center){
            a = left;
            b = center;
            c = rigth;
        } else if (left == rigth){
            a = left;
            b = rigth;
            c = center;
        } else {
            a = rigth;
            b = center;
            c = left;
        }
        if (a >= 5 || a == 0){
            cout << 0 << endl;
        } else {
            if (a == 1){
                cout << 1 << endl;
            } else if (a == 2){
                if (c == 1){
                    cout << 2 << endl;
                } else {
                    cout << 1 << endl;
                }
            } else if (a == 3){
                if (c > 3 || c == 0){
                    cout << 0 << endl;
                } else if (c == 1){
                    cout << 1 << endl;
                } else if (c == 2){
                    cout << 2 << endl;
                } else {
                    cout << 3 << endl;
                }
            } else if (a == 4){
                if (c == 1){
                    cout << 1 << endl;
                } else if (c == 3){
                    cout << 1 << endl;
                } else {
                    cout << 0 << endl;
                }
            }
        }
    }
    return 0;
}