#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mat[1000][1000];
char grid[1000][1000];

void dp(int n){
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (i + 1 < n && grid[i + 1][j] == '.'){
                mat[i + 1][j] += mat[i][j];
                mat[i + 1][j] %= 1000000007;
            }
            if (j + 1 < n && grid[i][j + 1] == '.'){
                mat[i][j + 1] += mat[i][j];
                mat[i][j + 1] %= 1000000007;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        for (int j = 0; j < n; j++){
            char r = s[j];
            grid[i][j] = r;
            mat[i][j] = 0;
        }
    }
    if (grid[0][0] != '*'){
        mat[0][0] = 1;
    }
    dp(n);
    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < n; j++){
    //     cout << mat[i][j] << " ";
    // }
    // cout << endl;
    // }
    cout << mat[n - 1][n - 1] << endl;
}