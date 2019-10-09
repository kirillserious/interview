/*
 * Given an image represented by an NxN matrix, where each pixel in the image is
 * 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in
 * place?
 */ 
#include <iostream>

void
rotate (int **arr, int n)
{
        int max_place = n / 2;
        for (int i = 0; i < max_place + (n%2); ++i) { 
                for (int j = 0; j < max_place; ++j) {
                        
                        int tmp = arr[i][j];
                        arr[i][j] = arr[n - 1 - j][i];
                        arr[n - 1 - j][i] = arr[n - 1 - i][n - 1 - j];
                        arr[n - 1 - i][n - 1 - j] = arr[j][n - 1 - i];
                        arr[j][n - 1 - i] = tmp;

                }
        }
}

int
main (void)
{
        int n;
        std::cin >> n;
        int **arr = new int*[n];
        for (int i = 0; i < n; ++i) arr[i] = new int[n];
        for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j) std::cin >> arr[i][j];

        rotate(arr, n);

        for (int i = 0; i < n; ++i){
                for (int j = 0; j < n; ++j){
                        std::cout << arr[i][j] << ' ';
                }
                std::cout << std::endl;
        }

        return 0;
}