#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

vector <int> mat(1000001, 1000002);

void dp(int n){
    for (int i = 1; i <= n; i++){
        int cp = i;
        while (cp != 0){
            int resto = cp%10;
            //cout << mat[i] << " ";
            mat[i] = min(mat[i], mat[i - resto] + 1);
            //cout << mat[i] << endl;
            cp /= 10;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    mat[0] = 0;
    dp(n);
    cout << mat[n] << endl;
    return 0;
}