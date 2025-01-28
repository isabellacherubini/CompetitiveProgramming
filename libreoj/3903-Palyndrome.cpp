#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
typedef long long ll;
using namespace std;

vector <char> palabra;
set<int> as;
set<int> bs;

void swap_letters(int pa, int pb){
    bs.insert(pa);
    as.insert(pb);
    as.erase(pa);
    bs.erase(pb);
}

ll find_next_a(int n, char a){ // lado izquierdo busca
    int l;
    if (a == 'a'){
        l = *as.lower_bound(n);
    } else {
        l = *bs.lower_bound(n);
    }
    return l;
} 

ll find_last_a(int n, char a){ // lado derecho busca
    int l;
    if (a == 'a'){
        auto it = as.lower_bound(n);
        it --;
        l = *it;
    } else {
        auto it = bs.lower_bound(n);
        it --;
        l = *it;
    }
    return l;
} 

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    int ca = 0;
    int cb = 0;
    for (int i = 0; i < s.length(); i++){
        palabra.push_back(s[i]);
        if (s[i] == 'a'){
            ca += 1;
            as.insert(i);
        } else {
            cb += 1;
            bs.insert(i);
        }
    }
    if ((ca%2 != 0 || cb%2 != 0) && palabra.size()%2 == 0){
        cout << -1;
    } else {
        int largo = palabra.size()/2;
        int f = palabra.size() - 1;
        ll moves = 0;
        for (int i = 0; i < largo; i++){
            //cout << palabra[i] << " " << palabra[f - i] << endl;
            if (palabra[i] != palabra[f - i]){
                int izq = find_next_a(i, palabra[f - i]);
                int der = find_last_a(f - i, palabra[i]);
                //cout << i << " " << izq << " " << der << endl;
                if (izq - i < (f - i) - der){
                    if (palabra[i] == 'a'){
                        swap_letters(i, izq);
                    } else {
                        swap_letters(izq, i);
                    }
                    swap(palabra[i], palabra[izq]);
                    moves += (izq - i);
                } else {
                    if (palabra[f - i] == 'a'){
                        swap_letters(f - i, der);
                    } else {
                        swap_letters(der, f - i);
                    }
                    swap(palabra[f - i], palabra[der]);
                    moves += ((f - i) - der);
                }
            }
            //for (int i = 0; i < palabra.size(); i++){
                //cout << palabra[i];
            //}
            //cout << endl;
        }
        cout << moves << endl;
    }
}