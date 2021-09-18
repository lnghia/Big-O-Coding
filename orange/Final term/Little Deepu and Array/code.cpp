#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

void buildTree(vector<int>& a, vector<int>& segtree, int left, int right, int index){
    if(left == right){
        segtree[index] = a[left];
        return;
    }

    int mid = left + (right - left) / 2;

    buildTree(a, segtree, left, mid, 2 * index + 1);
    buildTree(a, segtree, mid + 1, right, 2 * index + 2);
    segtree[index] = segtree[2 * index + 1] + segtree[2 * index + 2];
}

void update(vector<int> &segtree, vector<int>& lazy, int left, int right, int from, int to, int delta, int index){
    if(left > right){
        return;
    }

    if(lazy[index]){
        segtree[index] += lazy[index] * (right - left + 1);
        if(left != right){
            lazy[2 * index + 1] += lazy[index];
            lazy[2 * index + 2] += lazy[index];
        }
        lazy[index] = 0;
    }

    if(from > right || to < left){
        return;
    }

    if(from <= left && to >= right){
        segtree[index] = delta * (right - left + 1);
        if(left != right){
            lazy[2 * index + 1] += delta;
            lazy[2 * index + 2] += delta;
        }
        return;
    }

    int mid = left + (right - left) / 2;
    update(segtree, lazy, left, mid, from, to, delta, 2 * index + 1);
    update(segtree, lazy, mid + 1, right, from, to, delta, 2 * index + 2);
    segtree[index] = segtree[2 * index + 1] + segtree[2 * index + 2];
}

int main(){


    return 0;
}