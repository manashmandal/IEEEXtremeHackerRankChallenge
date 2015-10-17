/*
 * Problem Statement: https://www.hackerrank.com/contests/ieeextreme-challenges/challenges/sum-it-up
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define END return 0
using namespace std;

typedef long int lint;
typedef size_t uint;


//int *shifted_array(int *num, int size, int shift){
//    // Left shift algorithm
////    int shifted_number[size];
////       for (int i = 0; i < size; i++){
////          int position = i - shift;
////            if (position >= 0){
////                shifted_number[position] = num[i];
////            } else {
////                int pos = size + position;
////                shifted_number[pos] = num[i];
////            }
////        }

////    return shifted_number;

//    //right shift algorithm
//    int shifted_number[size];

//    if (shift > size) shift = shift % size;

//    for (int i = 0; i < size; i++){
//        int position = i + shift;
//        if (position < size){

//            shifted_number[position] = num[i];

//        } else {
//            int pos = shift + i - size;
//            shifted_number[pos] = num[i];
//        }
//    }
//    return shifted_number;
//}

//int *shifted_sum(int *array, int size, int shift){
//    int *shifted_numbers = shifted_array(array, size, shift);
//    for (int i = 0; i < size; i++){
//        array[i] +=  shifted_numbers[i];
//    }
//    return array;
//}

lint *cyclicAdder(lint *num, size_t size, size_t shift){
    uint temp;
    
    if (shift > size) shift = shift % size;


    for (size_t i = 0; i < size; i++){
//        uint position = size + i - shift;

        uint position = ((i-shift) < 0) ? (size + i - shift) : (i - shift);

        if (position > size - 1) position = position % size;

        if (i == 0){
            num[i] = num[i] + num[position];
            temp = position;
        }

        else {
            num[i] = num[i] + num[position] -  num[temp];
            temp = position;
        }


    }

    cout << "AFTER ADDING" << endl;

    for (int i = 0; i < size; i++) cout << num[i] << endl;

    return num;
}


int main(void)
{
//    int total = 0;
//    unsigned long long modulo = pow(10, 9) + 7;

//    //Getting the inputs
//    int N, QN;
//    cin >> N;
//    int numbers[N];

//    for (int i = 0; i < N; i++) cin >> numbers[i];

//    cin >> QN;
//    int Q[QN];

//    for (int i = 0; i < QN; i++) cin >> Q[i];

//    if (QN != 0){
//        for (int i = 0 ; i <  QN; i++){
//            shifted_sum(numbers, N, Q[i]);
//        }
//    }

//    //Calculating sum
//    for (int i = 0; i < N ; i++){
//        total += numbers[i];
//    }

//    cout << total % modulo << endl;

    unsigned long long modulo = pow(10, 9) + 7;

    lint bal[] = {1, 2, 3, 4, 5};


    cyclicAdder(bal, 5, 1 );







    END;
}
