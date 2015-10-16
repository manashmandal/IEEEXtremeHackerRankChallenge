/*
 * Problem Statement: https://www.hackerrank.com/contests/ieeextreme-challenges/challenges/sum-it-up
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int *shifted_array(int *num, int size, int shift){
    // Left shift algorithm
//    int shifted_number[size];
//       for (int i = 0; i < size; i++){
//          int position = i - shift;
//            if (position >= 0){
//                shifted_number[position] = num[i];
//            } else {
//                int pos = size + position;
//                shifted_number[pos] = num[i];
//            }
//        }

//    return shifted_number;

    //right shift algorithm
    int shifted_number[size];

    if (shift > size) shift = shift % size;

    for (int i = 0; i < size; i++){
        int position = i + shift;
        if (position < size){

            shifted_number[position] = num[i];

        } else {
            int pos = shift + i - size;
            shifted_number[pos] = num[i];
        }
    }
    return shifted_number;
}

int *shifted_sum(int *array, int size, int shift){
    int *shifted_numbers = shifted_array(array, size, shift);
    for (int i = 0; i < size; i++){
        array[i] +=  shifted_numbers[i];
    }
    return array;
}

int main(void)
{
    int total = 0;
    unsigned long long modulo = pow(10, 9) + 7;

    //Getting the inputs
    int N, QN;
    cin >> N;
    int numbers[N];

    for (int i = 0; i < N; i++) cin >> numbers[i];

    cin >> QN;
    int Q[QN];

    for (int i = 0; i < QN; i++) cin >> Q[i];

    if (QN != 0){
        for (int i = 0 ; i <  QN; i++){
            shifted_sum(numbers, N, Q[i]);
        }
    }

    //Calculating sum
    for (int i = 0; i < N ; i++){
        total += numbers[i];
    }

    cout << total % modulo << endl;
}
