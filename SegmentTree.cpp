#include <iostream>
#include <vector>

using namespace std;


void buildSegmentTree(vector<int> x, int u, int tl, int tr, vector<int>& tree){
    if (tr - tl <= 0) {
        tree[u] = x[tr];
    } else {
        int tm = (tr + tl) >> 1;
        buildSegmentTree(x, 2 * u + 1, tl, tm, tree);
        if (2 * u + 2 < 2 * x.size() - 1){
            buildSegmentTree(x, 2 * u + 2, tm + 1, tr, tree);
            tree[u] = tree[2 * u + 1] + tree[2 * u + 2];
        }
        else{
            tree[u] = tree[2 * u + 1];
        }
    }
}

void update(vector<int>& tree, int u, int tl, int tr, int pos, int delta){
    tree[u] += delta;
    if (tl == tr) return;

    int tm = (tl + tr) >> 1;
    if (pos <= tm) update(tree, 2 * u + 1, tl, tm, pos, delta);
    else update(tree, 2 * u + 1, tm, tr, pos, delta);
}

int getSum(vector<int>& tree, int u, int tl, int tr, int l, int r){
    if (tl == l && tr == r){
        return tree[u];
    }
    int tm = (tl + tr) >> 1, ans = 0;
    if (l <= tm) ans += getSum(tree, 2 * u + 1, tl, tm, l, min(r, tm));
    if (r >= tm + 1) ans += getSum(tree, 2 * u + 2, tm + 1, tr, max(l, tm + 1), r);
    return ans;
}

void printVector(vector<int> x){
    for (auto &el : x) {
        cout << el << " ";
    }
    cout << endl;
}


int main() {
    int n, tmp; cin >> n;
    vector<int> x;
    for (int i = 0; i < n; i++){
        cin >> tmp;
        x.push_back(tmp);
    }
    vector<int> tree(2 * x.size() - 1);
    buildSegmentTree(x, 0, 0, n - 1, tree);

    int m; cin >> m;
    int l, r;
    for (int i = 0; i < m; i++){
        cin >> l >> r;
        cout << getSum(tree, 0, 0, n - 1, l, r) << endl;
    }
}