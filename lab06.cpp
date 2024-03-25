#include <iostream>
#include <fstream>

const int N = 10; // Maximum size of the square matrix

void read_matrix(int matrixA[N][N], int matrixB[N][N], int& size, const std::string& file_name) { 
    std::ifstream file(file_name);
    if (!file.is_open()) { 
        std::cerr << "Error: Unable to open file " << file_name << std::endl; 
        exit(EXIT_FAILURE); 
    }

    file >> size;
    for (int i = 0; i < size; ++i) { 
        for (int j = 0; j < size; ++j) { 
            if (!(file >> matrixA[i][j])) { 
                std::cerr << "Error: Invalid data in file " << file_name << std::endl; 
                exit(EXIT_FAILURE); 
            }
        }
    }

    for (int i = 0; i < size; ++i) { 
        for (int j = 0; j < size; ++j) {
            if (!(file >> matrixB[i][j])) { 
                std::cerr << "Error: Invalid data in file " << file_name << std::endl; 
                exit(EXIT_FAILURE); 
            }
        }
    }
    file.close(); 
}

void print_matrix(const int matrix[N][N], int size) { 
    for (int i = 0; i < size; ++i) { 
        for (int j = 0; j < size; ++j) { 
            std::cout << matrix[i][j] << " "; 
        }
        std::cout << std::endl; 
    }
}

void add_matrix(const int matrixA[N][N], const int matrixB[N][N], int sum[N][N], int size) { 
    for (int i = 0; i < size; ++i) { 
        for (int j = 0; j < size; ++j) { 
            sum[i][j] = matrixA[i][j] + matrixB[i][j]; 
        }
    }
}

void mult_matrix(const int matrixA[N][N], const int matrixB[N][N], int product[N][N], int size) { 
    for (int i = 0; i < size; ++i) { 
        for (int j = 0; j < size; ++j) { 
            product[i][j] = 0; 
            for (int k = 0; k < size; ++k) { 
                product[i][j] += matrixA[i][k] * matrixB[k][j]; 
            }
        }
    }
}

void subt_matrix(const int matrixA[N][N], const int matrixB[N][N], int diff[N][N], int size) { 
    for (int i = 0; i < size; ++i) { 
        for (int j = 0; j < size; ++j) { 
            diff[i][j] = matrixA[i][j] - matrixB[i][j]; 
        }
    }
}

void update_element(int matrix[N][N], int row, int col, int value, int size) { 
    if (row >= 0 && row < size && col >= 0 && col < size) { 
        matrix[row][col] = value; 
    } else { 
        std::cerr << "Error: Invalid row or column index." << std::endl; 
    }
}

void max_value(const int matrix[N][N], int size) { 
    int max_val = matrix[0][0]; 
    for (int i = 0; i < size; ++i) { 
        for (int j = 0; j < size; ++j) { 
            if (matrix[i][j] > max_val) { 
                max_val = matrix[i][j]; 
            }
        }
    }
    std::cout << "Max value of the matrix: " << max_val << std::endl; 
}

void transpose_matrix(const int matrix[N][N], int size) { 
    int transpose[N][N]; 
    for (int i = 0; i < size; ++i) { 
        for (int j = 0; j < size; ++j) { 
            transpose[j][i] = matrix[i][j]; 
        }
    }
    std::cout << "Transposed Matrix A:" << std::endl; 
    print_matrix(transpose, size); 
}

int main() { 
    int size; 
    int matrixA[N][N], matrixB[N][N], result[N][N]; 

    read_matrix(matrixA, matrixB, size, "matrix_input.txt"); 

    std::cout << "Matrix A:" << std::endl; 
    print_matrix(matrixA, size);
    std::cout << std::endl; 

    std::cout << "Matrix B:" << std::endl; 
    print_matrix(matrixB, size);
    std::cout << std::endl; 

    add_matrix(matrixA, matrixB, result, size);
    std::cout << "Matrix Sum:" << std::endl; 
    print_matrix(result, size); 
    std::cout << std::endl; 

    mult_matrix(matrixA, matrixB, result, size); 
    std::cout << "Matrix Product:" << std::endl;
    print_matrix(result, size); 
    std::cout << std::endl;

    subt_matrix(matrixA, matrixB, result, size); 
    std::cout << "Matrix Difference:" << std::endl; 
    print_matrix(result, size); 
    std::cout << std::endl; 

    update_element(matrixA, 1, 1, 100, size); 
    std::cout << "Updated Matrix A:" << std::endl; 
    print_matrix(matrixA, size); 
    std::cout << std::endl; 

    max_value(matrixA, size); 
    std::cout << std::endl; 
    
    transpose_matrix(matrixA, size); 

    return 0; 
}
