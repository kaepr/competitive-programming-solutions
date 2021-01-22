#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

//stores the segment tree
int t[4 * N];

//tells if a certain node is storing any unpropogated update or not
bool lazy[4 * N];

//the value of the unpropogated updates, memory of the nodes
int upd[4 * N];

//this is the process of telling the node to remember the val
void apply(int v, int tl, int tr, int val)
{
    //tl,tr -> node range, v -> node id
    t[v] += val * (tr - tl + 1); //set correct information at the node

    if (tl != tr)
    {
        //if it is not leaf, make it lazy
        lazy[v] = 1;
        upd[v] += val;
    }
}

//assigning the task to his child nodes
void pushdown(int v, int tl, int tr)
{
    //if it is lazy, propogate it
    if (lazy[v])
    {
        lazy[v] = 0; //not lazy anymore

        //remembering upd[v]
        int tm = (tl + tr) / 2;
        apply(2 * v, tl, tm, upd[v]);         //propogate on left child
        apply(2 * v + 1, tm + 1, tr, upd[v]); //propogate on right child
        upd[v] = 0;                           //update done
        //node does not remember anything anymore
    }
}

// l, r is the update range
// val update value
void update(int v, int tl, int tr, int l, int r, int val)
{
    //no overlap
    if (tl > r || tr < l)
    {
        return;
    }

    //fully within
    if (l <= tl && tr <= r)
    {
        //ask the node to remember the value
        apply(v, tl, tr, val);
        return;
    }

    //partial overlap
    //we remove lazy tag before going down
    //so that children nodes have correct information
    pushdown(v, tl, tr);

    int tm = (tl + tr) / 2;
    update(2 * v, tl, tm, l, r, val);
    update(2 * v + 1, tm + 1, tr, l, r, val);

    t[v] = t[2 * v] + t[2 * v + 1]; //store correct value
}

int query(int v, int tl, int tr, int l, int r)
{
    if (tl > r || tr < l)
    {
        return 0;
    }

    if (l <= tl && tr <= r)
    {
        return t[v];
    }

    //we remove lazy tag before going down
    //so that children nodes have correct information
    pushdown(v, tl, tr);

    int tm = (tl + tr) / 2;
    int ans = 0;
    ans += query(2 * v, tl, tm, l, r);
    ans += query(2 * v + 1, tm + 1, tr, l, r);
    return ans;
}

//v,tl,tr -> 1, 0 , length - 1

void solve()
{
    //adding 3 to [2,5]
    update(1, 0, N - 1, 2, 5, 3);

    //print sum in range [1,3]
    cout << query(1, 0, N - 1, 1, 3);
}

int main()
{
    // freopen("filename_input.txt","r",stdin);
    // freopen("filename_output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}