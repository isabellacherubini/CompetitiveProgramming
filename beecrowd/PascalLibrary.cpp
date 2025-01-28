#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, d;
    cin >> n >> d;
    while (n != 0 && d != 0){
        vector<int> alumni(n, 0);
        for (int i = 0; i < d; i++){
            for(int j = 0; j <n; j++){
                int r;
                cin >> r;
                alumni[j] += r;
            }
        }
        string res = "no";
        for (int i = 0; i < n; i++){
            if (alumni[i] == d){
                res = "yes";
            }
        }
        cout << res << endl;
        cin >> n >> d;
    }
}