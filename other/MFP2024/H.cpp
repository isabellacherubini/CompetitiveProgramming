#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, k;
    cin >> n >> k;
    vector <pair<ll, ll>> clients;
    for (ll i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        clients.push_back({a, b});
    }
    //sort(clients.begin(), clients.end());
    ll ind = 0;
    queue <ll> wait_line;
    priority_queue <ll, vector<ll>, greater<ll>> lobby;
    ll res = 0;
    while (ind < n){
        ll act_time;
        if (lobby.size() > 0){
            act_time = min(clients[ind].first, lobby.top());
            //cout << clients[ind].first << " " << lobby.front() << endl;
            //cout << act_time << endl;
        } else {
            act_time = clients[ind].first;
        }
        while (lobby.size() > 0 && lobby.top() <= act_time){
            //cout << lobby.front() << endl;
            lobby.pop();
        }
        while (ind < n && clients[ind].first <= act_time){
            wait_line.push(clients[ind].second);
            ind += 1;
        }
        while (lobby.size() < k && wait_line.size() > 0){
            lobby.push(wait_line.front() + act_time);
            wait_line.pop();
        }
        ll ls = lobby.size();
        ll ws = wait_line.size();
        res = max(res, ws + ls);
    }
    cout << res << endl;
}