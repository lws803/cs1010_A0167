#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define klar(v) memset(v, 0, sizeof(v))
#define SYNC ios_base::sync_with_stdio(false)
#define debug cout << "chuj" << endl;

typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
const int maxn = 5e5+10;
const int base = 1<<20;
const int inf = 1e6;

pii tree[2*base];
set <int> beg[maxn];
set <pii> inv;

void add(int v, int val){
    v += base;
    tree[v] = mp(val, v-base);
    v >>= 1;
    while(v > 0){
        tree[v] = min(tree[v*2], tree[v*2+1]);
        v >>= 1;
    }
}

pii query(int a, int b){
    a += base; b += base;
    pii ans = mp(inf, inf);
    ans = min(tree[a], tree[b]);
    while((a>>1) != (b>>1)){
        if(!(a&1))ans = min(ans, tree[a+1]);
        if(b&1)ans = min(ans, tree[b-1]);
        a >>= 1;
        b >>= 1;
    }
    return ans;
}

void del(pii k){
    beg[k.nd-k.st+1].erase(k.st);
    add(k.nd-k.st+1, *beg[k.nd-k.st+1].begin());
}

void ans(int a, int n){
    pii h = query(a, n);
    if(h.st == inf)
        printf("NIE\n");
    else{
        pii k = *inv.lower_bound(h);
        inv.erase(k);
        del(k);
        if(mp(h.st, h.st+a-1) != k){
            k = mp(h.st+a, k.nd);
            beg[k.nd-k.st+1].insert(k.st);
            add(k.nd-k.st+1, *beg[k.nd-k.st+1].begin());
            inv.insert(k);
        }
        printf("%d %d\n", h.st, h.st+a-1);
    }
}

void merz(pii x){
    auto left = inv.lower_bound(x);
    if(left != inv.begin())left--;
    if(!(left->st <= x.st and left->nd >= x.nd)){
        if(left != inv.end() and left->st <= x.st and left->nd+1 >= x.st){
            x = mp(left->st, x.nd);
            del(*left);
            inv.erase(left);
        }
        auto right = inv.upper_bound(mp(x.nd, inf));
        if(right != inv.begin() and !(right->st-1 <= x.nd and right->nd >= x.nd))right--;
        if(right != inv.end() and right->st-1 <= x.nd and right->nd >= x.nd){
            x = mp(x.st, right->nd);
            del(*right);
            inv.erase(right);
        }
        auto it = inv.lower_bound(x);
        while(it != inv.end() and it->st >= x.st and it->nd <= x.nd){
            inv.erase(it);
            del(*it);
            it = inv.lower_bound(x);
        }
        inv.insert(x);
        beg[x.nd-x.st+1].insert(x.st);
        add(x.nd-x.st+1, *beg[x.nd-x.st+1].begin());
    }
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = base; i < 2*base; i++)
        tree[i] = mp(inf, i-base);
    for(int i = base-1; i >= 1; i--)tree[i] = min(tree[2*i], tree[2*i+1]);
    for(int i = 1; i <= n; i++)beg[i].insert(inf);
    inv.insert(mp(1, n));
    beg[n].insert(1);
    add(n, 1);
    while(m--){
        int x, a, b;
        scanf("%d", &x);
        if(x&1){
            scanf("%d", &a);
            ans(a, n);
        }
        else{
            scanf("%d%d", &a, &b);
            merz(mp(a, b));
        }
    }
}