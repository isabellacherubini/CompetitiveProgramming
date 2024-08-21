// choripunk

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int w, ll, tx, ty;
    cin >> w >> ll >> tx >> ty;
    w += 1;
    ll += 1;
    vector <double> A;
    vector <double> R;
    cout << setprecision(12);
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        double dist = sqrt(pow(a - tx, 2) + pow(b - ty, 2));
        A.push_back(dist);
    }
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        double dist = sqrt(pow(a - tx, 2) + pow(b - ty, 2));
        //cout << dist << endl;
        R.push_back(dist);
    }
    sort(A.begin(), A.end());
    sort(R.begin(), R.end());
    if (A[0] < R[0]){
        int l = 0;
        int r = n - 1;
        while (l != r){
            int mid = (l + r + 1)/2;
            if (A[mid] < R[0]){
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        cout << "A " << l + 1 << endl;
    } else {
        int l = 0;
        int r = n - 1;
        while (l != r){
            int mid = (l + r + 1)/2;
            if (R[mid] < A[0]){
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        cout << "R " << l + 1 << endl;
    }
}