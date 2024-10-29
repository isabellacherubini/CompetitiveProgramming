#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll q;
    cin >> q;
    for (int i = 0; i < q; i++){
        ll ax, ay, bx, by;
        cin >> ax >> ay >> bx >> by;
        ll cx, cy;
        cin >> cx >> cy;
        ll dx = ax - bx;
        ll dy = ay - by;
        ll ex = cx - ax;
        ll ey = cy - ay;
        ll res = dx*ey - dy*ex;
        if (res < 0){
            cout << "LEFT\n";
        } else if (res > 0){
            cout << "RIGHT\n";
        } else {
            cout << "TOUCH\n";
        }
    }
}