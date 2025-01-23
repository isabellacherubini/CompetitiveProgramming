#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector <int> girls;

ll memo[1501][1501];

ll dp(int i, int p, int x){
    if (p >= x){
        return 1;
    }
    if (i >= girls.size()){
        return 0;
    }
    // Si la respuesta ya fue calculada, no la calculo de nuevo y retorno el valor guardado
    if(memo[i][p] != -1) return memo[i][p];

    ll ans = 0;
    if (girls[i] <= p){
        ans += (dp(i + 1, girls[i] + p, x))%(1000000007);
    }
    ans += (dp(i + 1, p, x))%(1000000007);

    // Retorno y guardo la respuesta para no tener que calcularla de nuevo
    return memo[i][p] = ans%(1000000007);
}

int main(){

    memset(&memo, -1, sizeof(memo));

    int n, x;
    cin >> n >> x;
    int a;
    cin >> a;
    int ind = 0;
    for (int i = 1; i < n; i++){
        int b;
        cin >> b;
        girls.push_back(b);
    }
    sort(girls.begin(), girls.end());
    if (a >= x){
        cout << 1 << endl;
    } else {
        ll ans = dp(0, a, x);
        cout << ans << endl;
    }
}