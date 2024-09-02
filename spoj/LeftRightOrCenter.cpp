#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll ax, ay, bx, by, q;
    cin >> ax >> ay >> bx >> by >> q;
    for (int i = 0; i < q; i++){
        ll cx, cy;
        cin >> cx >> cy;
        ll dx = ax - bx;
        ll dy = ay - by;
        ll ex = cx - ax;
        ll ey = cy - ay;
        ll res = dx*ey - dy*ex;
        if (res < 0){
            cout << "I\n";
        } else if (res > 0){
            cout << "D\n";
        } else {
            cout << "C\n";
        }
    }
}