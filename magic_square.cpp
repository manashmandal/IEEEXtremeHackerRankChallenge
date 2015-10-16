/*
 * Problem Statement: https://www.hackerrank.com/contests/ieeextreme-challenges/challenges/magic-square
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void)
{
    vector <int> report;

    int array_size = 0;
    int diagonal_sum = 0;
    int anti_diagonal_sum = 0;
    int mismatch = 0;

    cin >> array_size;

    int square[array_size][array_size];
    int row_index[array_size];
    int column_index[array_size];
    int row_sum[array_size];
    int column_sum[array_size];

    for (int i = 0; i < array_size; i++){
        for (int j = 0; j < array_size; j++){
            cin >> square[i][j];
        }
    }


    //calculate diagonal sum
    for (int i = 0; i < array_size; i++){
        diagonal_sum += square[i][i];
    }

    //calculate antidiagonal sum
    for (int j = array_size - 1, i = 0; i < array_size; i++, j--){
        anti_diagonal_sum += square[i][j];
    }


    //generate row and colum indices
    for (int i = 0; i < array_size; i++){
        row_index[i] = i + 1;
        column_index[i] = -(i+1);
    }

    //Calculate Row sum
    for (int i = 0; i < array_size; i++){
        row_sum[i] = 0;
        for (int j = 0; j < array_size; j++){
            row_sum[i] += square[i][j];
        }
    }

    //Calculate column sum
    for (int j = 0; j < array_size; j++){
        column_sum[j] = 0;
        for (int i = 0; i < array_size; i++){
            column_sum[j] += square[i][j];
        }
    }

    //Comparing diagonal with antidiagonal, row and column
    if (diagonal_sum != anti_diagonal_sum) report.push_back(0);
    for (int i = 0 ; i < array_size; i++){
        if (row_sum[i] != diagonal_sum) report.push_back(row_index[i]);
        if (column_sum[i] != diagonal_sum) report.push_back(column_index[i]);
    }

    mismatch = report.size();
    sort(report.begin(), report.end());

    //Printing out the result
    if (mismatch == 0) cout << 0 << endl;
    else {
        cout << mismatch << endl;
        for (int i = 0; i < report.size(); i++){
            cout << report[i] << endl;
        }
    }
}
