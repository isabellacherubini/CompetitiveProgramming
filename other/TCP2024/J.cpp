#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int a, b;
    cin >> a >> b;
    if (a < b){
        swap(a, b);
    }
    if (b < 2){
        cout << a + 1 + b*2 << endl;
    } else {
        cout << a + 1 + 2 + (b - 1) << endl;
    }
}