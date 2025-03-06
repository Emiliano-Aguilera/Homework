#include <iostream>
#include <format>

int main() {
    int n;

    std::cout << "Ingrese n: ";
    std::cin >> n;

    int matrix[n][n];

    int count = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = count;
            count++;
        }
    }

    int i = n-1;
    int j = n-1;
    for (int k = 0; k < n*n; k++) {
        std::cout << std::format("M[{}][{}] {}\n", i, j, matrix[i][j]);
        if (j == 0) {
            i--;
            j = n-1;
        }
        else {
            j--;
        }
    }

    return 0;
}