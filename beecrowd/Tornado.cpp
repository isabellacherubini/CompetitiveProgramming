#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    while (n != 0){
        int prezero = 0;
        int zero = 0;
        int seezero = 0;
        int fences = 0;
        for (int i = 0; i < n; i++){
            int r;
            cin >> r;
            if (r == 0 && seezero == 0){
                prezero += 1;
            } else if (r == 0){
                zero += 1;
            } else if (r == 1){
                seezero += 1;
                if (zero > 0){
                    fences += zero/2;
                }
                zero = 0;
            }
        }
        if (prezero + zero == n){
            fences = (prezero + zero + 1)/2;
        } else {
            fences += (prezero + zero)/2;
        }
        cout << fences << endl;
        cin >> n;
    }
}