#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

// Find the value of x in range [l, r] 
// for which f(x) is minimum
// f(x) = 2*(x^2) - 10*x + 2

vector<double> distances;
vector<double> speeds;

double f(double x) {
    double ans = 0;
    for (int i = 0; i < distances.size(); i++){
        double t = abs(distances[i] - x)/speeds[i];
        ans = max(ans, t);
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    double l = 1e9 + 1, r = 0;
    for (int i = 0; i < n; i++){
        double j;
        cin >> j;
        distances.push_back(j);
        l = min(l, j);
        r = max(r, j);
    }
    for (int i = 0; i < n; i++){
        double j;
        cin >> j;
        speeds.push_back(j);
    }
    while((r - l) >= 1e-6) {
        double mid1 = l + (r - l)/3.0;
        double mid2 = r - (r - l)/3.0;
        double f_mid1 = f(mid1);
        double f_mid2 = f(mid2);
        if (f_mid1 < f_mid2) {
            r = mid2;
        }
        else if(f_mid1 > f_mid2) {
            l = mid1;
        }
        else if(f_mid1 == f_mid2) {
            l = mid1;
            r = mid2;
        }
    }
    cout << setprecision(20) << f(l) <<"\n";
    
    return 0;
}
