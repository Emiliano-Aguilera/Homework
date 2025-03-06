#include <iostream>
#include <format>

// prototipos de funcion
int** create_matrix(int size);
void print_matrix(int** matrix, int size);
void print_matrix_b(int** matrix, int size);

int main() {
    int n = 0;

    std::cout << "Ingrese n: ";
    std::cin >> n;

    while (n <= 1) {
        std::cout << "n debe ser mayor a 1." << '\n';
        std::cout << "Ingrese n: ";
        std::cin >> n;
    }
    
    int** matrix = create_matrix(n);

    //print_matrix(matrix, n);
    print_matrix_b(matrix, n);

    return 0;
}

// declaracion de funciones

int** create_matrix(int size) {
    // se crea el array de pointers
    int** matrix = new int*[size];
    // se rellena el array de pointers con los arrays que contienen ints
    for (int i = 0; i < size; i++){
        matrix[i] = new int[size];
    }
    

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // parentesis redundantes, mejoran legibilidad
            int value = (i * size) + (j+1);
            matrix[i][j] = value;
        }
    }

    return matrix;
}


void print_matrix(int** matrix, int size) {
    int i = size-1;
    int j = size-1;
    
    for (int k = 0; k < size*size; k++) {
        std::cout << std::format("M[{}][{}] = {}\n", i, j, matrix[i][j]);
        if (j == 0) {
            i--;
            j = size-1;
        }
        else {
            j--;
        }
    }
}

void print_matrix_b(int** matrix, int size) {
    // Intento de iterar inversamente la matriz sin usar condicionales
    for (int k = 0; k < size*size; k++) {
        int i = size - (k / size) - 1;
        int j = size - (k % size) - 1;
        std::cout << std::format("M[{}][{}] = {}\n", i, j, matrix[i][j]);
    }
}