/*
 * Write an algorithm such that if an element in an MxN matrix is 0, 
 * its entire row and column are set to 0.
 */ 
#include <iostream>

using namespace std;

void
zero (int **arr, int n, int m)
{
        bool is_row = false, is_col = false; // First row and column zero indicate
        
        for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                        if (arr[i][j] == 0) {
                               if (i == 0) {
                                        is_row = true;
                                } else if (j == 0) {
                                        is_col = true;
                                } else {
                                        arr[i][0] = 0;
                                        arr[0][j] = 0;
                                }
                        }  
                }
        }

        for (int i = 0; i < n; ++i) {
                if (arr[i][0] == 0) {
                        for (int j = 1; j < m; ++j) {
                                arr[i][j] = 0;
                        }
                }
        }

        for (int j = 0; j < m; ++j) {
                if (arr[0][j] == 0) {
                        for (int i = 1; i < n; ++i) {
                                arr[i][j] = 0;
                        }
                }
        }

        if (is_row) {
                for (int j = 0; j < m; ++j) {
                        arr[0][j] = 0;
                }
        }

        if (is_col) {
                for (int i = 0; i < n; ++i) {
                        arr[i][0] = 0;
                }
        }
}

int
main (void)
{
        int n = 2;
        int m = 3; 
        int **arr = new int*[n];
        for (int i = 0; i < n; ++i) {
                arr[i] = new int[m];
        }
        for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                        cin >> arr[i][j];
                }
        }

        zero(arr, 2, 3);

        for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                        cout << arr[i][j] << ' ';
                }
                cout << endl;
        }

        for (int i = 0; i < n; ++i) {
                delete[] arr[i];
        }
        delete[] arr;
}