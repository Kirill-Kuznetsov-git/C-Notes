#include<iostream>
#include<vector>

using namespace std;

void makeSet(vector<int>& parent, int v) {
    parent[v] = v;
}

int findSet(vector<int>& parent, int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = findSet(parent, parent[v]);
}

void unionSet(vector<int>& parent, int a, int b){
    a = findSet(parent, a);
    b = findSet(parent, b); 
    if (a != b) {
        parent[b] = a;
    }
}


int main() {
    int n, tmp; cin >> n;
    vector<int> parent;
    for (int i = 0; i < n; i++){
        cin >> tmp;
        makeSet(parent, tmp);
    }
}