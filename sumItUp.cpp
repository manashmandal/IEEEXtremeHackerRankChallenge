/*
 * Problem statement: https://www.hackerrank.com/contests/ieeextreme-challenges/challenges/sum-it-up
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

typedef long long ull;
typedef size_t unsigned_int;

using namespace std;

vector<ull>* cyclicAdder(vector <ull> &add_vector, vector <ull> rotated, unsigned_int shift){
    std::rotate(rotated.rbegin(), rotated.rbegin() + shift, rotated.rend());
    for (unsigned_int i = 0; i < add_vector.size() ; i++){
        add_vector[i] += rotated[i];
    }
    return &add_vector;
}

int main()
{
    vector <ull> v;
    vector <ull> q;

    unsigned_int N, qN;
    cin >> N;
    while (N != 0){
        ull x;
        cin >> x;
        v.push_back(x);
        N--;
    }

    cin >> qN;

    while (qN != 0){
        ull x;
        cin >> x;
        q.push_back(x);
        qN--;
    }

    for (unsigned_int i = 0; i < q.size(); i++){
        cyclicAdder(v, v, q[i]);
    }

    unsigned_int total = 0;

    for (unsigned_int i = 0; i < v.size(); i++) total += v[i];

    unsigned_int modulo = std::pow(10, 9) + 7;

    cout << total % modulo << endl;

}

