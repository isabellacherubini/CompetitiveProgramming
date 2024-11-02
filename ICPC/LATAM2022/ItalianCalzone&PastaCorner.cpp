#include<bits/stdc++.h>
using namespace std;
 
vector<vector<int>> m;
int visited[1000001];
 
int BFS(int vertex, int rows, int columns){
    int v = rows * columns + 1;
    int c = 0;
    for (int i = 0; i < 1000001; i++){
        visited[i] = 0;
    }
    queue <int> p;
    p.push(vertex);
    visited[vertex] = 1;
    while (!p.empty()){
        vertex = p.front();
        c += 1;
        p.pop();
        for (int i = 0; i < m[vertex].size(); i++){
            if (visited[m[vertex][i]] == 0){
                p.push(m[vertex][i]);
                visited[m[vertex][i]] = 1;
            }
        }
    }
    return c;
}
 
int main(){
    int r, c;
    cin >> r >> c;
    for (int i = 0; i < r*c + 1; i++){
        vector <int> rv;
        m.push_back(rv);
    }
    vector <int> ant;
    vector <int> act;
    for (int i = 0; i < r; i++){
        int a;
        for (int j = 0; j < c; j++){
            int res;
            cin >> res;
            act.push_back(res);
            if (j != 0){
                if (res > a){
                    m[a].push_back(res);
                } else {
                    m[res].push_back(a);
                }
            }
            a = res;
            if (i != 0){
                if (res < ant[j]){
                    m[res].push_back(ant[j]);
                } else {
                    m[ant[j]].push_back(res);
                }
            }
        }
        swap(ant, act);
        act.clear();
    }
    int ma = 0;
    for (int i = 0; i < r*c; i++){
        int c = BFS(i + 1, r, c);
        if (ma < c){
            ma = c;
        }
    }
    cout << ma << endl;
}