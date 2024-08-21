// choripunk

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    long long suma = 0;
    cin >> n >> m;
    vector <long long> alf;
    vector <long long> offi;
    for (int i = 0; i < n; i++){
        long long r;
        cin >> r;
        alf.push_back(r);
    }
    long long ant = -1;
    for (int i = 0; i < m; i++){
        long long c;
        cin >> c;
        if (ant > c || ant == -1){
            ant = c;
            offi.push_back(c);
        }
    }
    for (int i = 0; i < n; i++){
        long long ab = alf[i];
        int sp = 1;
        while (sp == 1){
            int l = 0;
            int r = offi.size() - 1;
            while (l != r){
                int mid = (l + r)/2;
                if (offi[mid] <= ab){
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            ab = ab%offi[l];
            if (ab == 0 || ab < offi[offi.size() - 1]){
                sp = 0;
            }
        }
        cout << ab << " ";
    }
}