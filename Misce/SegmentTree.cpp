#include <bits/stdc++.h>
using namespace std;
#define ll long long

//binary tree
//root node will represent entire array....leaf represents single element
//balanced binary tree, height diff is max 1
//segment tree will have 2*n nodes (if n is power of 2)
//used for finding--->range sum,range max,range min
//here we represents tree as in array
//sc=O(2*n)+O(logn)
//tc=O(n)    (for building a seg tree)

class SegTree
{
private:
    vector<ll> seg; // Segment tree array
    ll n;           // Size of the input array

    // Build the segment tree
    void build(ll i, ll low, ll high, const vector<ll> &v)
    {
        if (low == high)
        {
            seg[i] = v[low];
            return;
        }
        ll mid = (low + high) / 2;
        build(2 * i + 1, low, mid, v);
        build(2 * i + 2, mid + 1, high, v);

        seg[i] = max(seg[2 * i + 1], seg[2 * i + 2]); // Customizable operation
    }

    ll query(ll ind, ll low, ll high, ll l, ll r)  // l,r are the queries
    {
        if (low >= l && high <= r)
        {
            return seg[ind]; // Completely inside the range
        }
        if (l > high || r < low)
        {
            return LLONG_MIN; // Completely outside the range //customisable
        }

        ll mid = (low + high) / 2;
        ll left = query(2 * ind + 1, low, mid, l, r);
        ll right = query(2 * ind + 2, mid + 1, high, l, r);
        return max(left, right); // Customizable operation
    }

    void update(ll ind, ll low, ll high, ll pos, ll val)
    {
        if (low == high)
        {
            seg[ind] = val;
            return;
        }
        ll mid = (low + high) / 2;
        if (pos <= mid)
        {
            update(2 * ind + 1, low, mid, pos, val);
        }
        else
        {
            update(2 * ind + 2, mid + 1, high, pos, val);
        }

        seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]); // Customizable operation
    }

public:
    SegTree(const vector<ll> &v)
    {
        n = v.size();
        seg.resize(4 * n); // Resize segment tree to 4 * n
        build(0, 0, n - 1, v);
    }

    // Query the maximum in a range [l, r]
    ll Rangeq(ll l, ll r)
    {
        return query(0, 0, n - 1, l, r);
    }

    // Update the value at a specific position
    void Update(ll pos, ll val)
    {
        update(0, 0, n - 1, pos, val);
    }
};


//______________________________

//if n is not power of 2 we have to append some extra dummy nodes to ensure pairing, so leaf nodes will
//be approx. 2*n , hence 4*n is the size  for safest side.