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

ll temp1 = 0;
ll temp2 = 0;

vector <ll> *cyclicAdder(vector <ll> &v, uInt shift){
    uInt size = v.size();

    if (shift >= size) shift = shift % size;

    int start = size - shift;

    for (int i = 0; i < size; i++){
        if (start >= size) start = start % size;
        cout << "index: " << start << endl;
        start++;
    }


    return &v;
}


int main(void)
{

    vector <ll> v{1, 2, 3, 4, 5};
    cyclicAdder(v, 5);

    for (int i = 0; i < v.size(); i++) cout << v[i] << endl;

}
