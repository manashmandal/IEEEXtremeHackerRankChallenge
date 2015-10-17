/*
 * Problem statement: https://www.hackerrank.com/contests/ieeextreme-challenges/challenges/sum-it-up
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
typedef size_t uInt;

vector <ll> *cyclicAdder(vector <ll> &v, uInt shift){
    vector <ll> temp(v);
    uInt size = v.size();
    if (shift >= size) shift = shift % size;
    int start = size - shift;
    for (int i = 0; i < size; i++){
        if (start >= size) start = start % size;
        v[i] = v[i] + temp[start];
        start++;
    }
    return &v;
}


int main(void)
{
    vector <ll> n;
    vector <ll> q;

    uInt N, qN;
    cin >> N;
    while (N != 0){
        ll x;
        cin >> x;
        n.push_back(x);
        N--;
    }

    cin >> qN;

    while (qN != 0){
        ll x;
        cin >> x;
        q.push_back(x);
        qN--;
    }

    for (uInt i = 0; i < q.size(); i++){
        cyclicAdder(n, q[i]);
    }

//    for (uInt i = 0; i < n.size(); i++){
//        cout << n[i] << endl;
//    }
    ll total = std::accumulate(n.begin(), n.end(), 0);
    cout << total % (ll(pow(10, 9) + 7)) << endl;

}
