#include <iostream>

struct Matrix {
    // двумерный массив с данными.
    int** data_ = nullptr;
    // количество столбцов
    size_t n_ = 0u;
    // количество строк
    size_t m_ = 0u;
};

// Создает заполненную нулями матрицу n x m.
void Construct(Matrix& out, size_t n, size_t m) {
    out.n_ = n;
    out.m_ = m;
    out.data_ = new int* [m];
    for (int i = 0; i < m; i++) {
        out.data_[i] = new int[n];
        for (int j = 0; j < n; j++) {
            out.data_[i][j] = 0;
        }

    }
}
// Освобождает выделенную память.
void Destruct(Matrix& in) {
    for (int i{}; i < in.m_; ++i) {
        delete[] in.data_[i];
    }
    delete[] in.data_;
}

// Создает копию матрицы |matrix|.
Matrix Copy(const Matrix& matrix) {
    Matrix m1;
    Construct(m1,matrix.n_,matrix.m_);
    for (int i{}; i < matrix.m_; ++i) {
        for (int j{}; j < matrix.n_; ++j) {
            m1.data_[i][j] = matrix.data_[i][j];
        }
    }
    return m1;

}
// Возвращает сумму двух матриц.
// Если операция невозможна - вернуть пустую матрицу
Matrix Add(const Matrix& a, const Matrix& b) {
    Matrix m1;
    if (a.m_ == b.m_ and a.n_ == b.n_) {
        
        Construct(m1, a.n_, a.m_);
        for (int i{}; i < a.m_; ++i) {
            for (int j{}; j < a.n_; ++j) {
                m1.data_[i][j] = a.data_[i][j] + b.data_[i][j];
            }
        }
    }
    else {
        return m1;
    }

    return m1;
}
// Возвращает разницу двух матриц.
// Если операция невозможна - вернуть пустую матрицу
Matrix Sub(const Matrix& a, const Matrix& b) {
    Matrix m1;
    if (a.m_ == b.m_ and a.n_ == b.n_) {

        Construct(m1, a.n_, a.m_);
        for (int i{}; i < a.m_; ++i) {
            for (int j{}; j < a.n_; ++j) {
                m1.data_[i][j] = a.data_[i][j] - b.data_[i][j];
            }
        }
    }
    else {
        return m1;
    }
    return m1;
}

// Возвращает произведение двух матриц.
// Если операция невозможна - вернуть пустую матрицу
Matrix Mult(const Matrix& a, const Matrix& b) {
    Matrix m1;
    if (a.n_ == b.m_) {
        int res = 0;
        Construct(m1, b.n_, a.m_);
        for (int i{}; i < m1.m_; ++i) {
            for (int j{}; j < m1.n_; ++j) {
                for (int k{}; k < a.n_; ++k) {
                    m1.data_[i][j] += a.data_[i][k] * b.data_[k][j];
                }
            }
        }
    }
    else {
        return m1;
    }
    return m1;
}

// Транспонирование матрицы.

Matrix Transposition(Matrix& matrix) {
    Matrix m1;
    m1.m_ = matrix.n_;
    m1.n_ = matrix.m_;
    m1.data_ = new int* [m1.m_];
    for (int i = 0; i < matrix.n_; i++) {
        int* uk = new int[matrix.m_];
        for (int j = 0; j < matrix.m_; j++) {
            uk[j] = matrix.data_[j][i];
        }
        m1.data_[i] = uk;

    }
    Destruct(matrix);
    matrix.m_ = m1.m_;
    matrix.n_ = m1.n_;
    matrix.data_ = m1.data_;

    return matrix;
}
    


bool operator==(const Matrix& a, const Matrix& b) {
    int q = 0;
    if (a.m_ == b.m_ and a.n_ == b.n_) {

        for (int i = 0; i < a.m_; ++i) {
            for (int j = 0; j < a.n_; ++j) {
                if (b.data_[i][j] != a.data_[i][j]) {
                    return 0;
                }
            }
        }
    }
    else {
        return 0;
    }
    return 1;
}

int main()
{
    Matrix A;
    Construct(A, 3, 3);
    Matrix B;
    Construct(B, 3, 3);

    int arr_A[3][3] = { {1, 2, 1},
                        {4, 2, 2},
                        {0, 1, 7} };

    int arr_B[3][3] = { {7, 5, 1},
                        {2, 1, 2},
                        {4, 3, 4} };

    for (int i{}; i < 3; ++i) {
        for (int j{}; j < 3; ++j) {
            A.data_[i][j] = arr_A[i][j];
        }
    }
    for (int i{}; i < 3; ++i) {
        for (int j{}; j < 3; ++j) {
            B.data_[i][j] = arr_B[i][j];
        }
    }

    
    Matrix matrica,matrica1;
    std::cout << "1)" << std::endl;
    Construct(matrica, 3, 4);
    for (int i = 0; i < matrica.m_; i++) {
        for (int j = 0; j < matrica.n_; j++) {
            std::cout << matrica.data_[i][j] << " ";
        }
        std::cout << "\n";
    }
    //2)
    //Destruct(matrica);
    std::cout << "3)" << std::endl;
    matrica1 = Copy(B);
    for (int i = 0; i < matrica1.m_; i++) {
        for (int j = 0; j < matrica1.n_; j++) {
            std::cout << matrica1.data_[i][j] << " ";
        }
        std::cout << "\n";
    }
    Destruct(matrica1);

    std::cout << "4)" << std::endl;
    matrica1 = Add(A, B);
    for (int i = 0; i < matrica1.m_; i++) {
        for (int j = 0; j < matrica1.n_; j++) {
            std::cout << matrica1.data_[i][j] << " ";
        }
        std::cout << "\n";
    }
    Destruct(matrica1);

    std::cout << "5)" << std::endl;
    matrica1 = Sub(A, B);
    for (int i = 0; i < matrica1.m_; i++) {
        for (int j = 0; j < matrica1.n_; j++) {
            std::cout << matrica1.data_[i][j] << " ";
        }
        std::cout << "\n";
    }
    Destruct(matrica1);

    std::cout << "6)" << std::endl;
    matrica1 = Mult(A, B);
    for (int i = 0; i < matrica1.m_; i++) {
        for (int j = 0; j < matrica1.n_; j++) {
            std::cout << matrica1.data_[i][j] << " ";
        }
        std::cout << "\n";
    }
    Destruct(matrica1);



    std::cout << "7)" << std::endl;

    Transposition(A);
    for (int i = 0; i < A.m_; i++) {
        for (int j = 0; j < A.n_; j++) {
            std::cout << A.data_[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "8)" << std::endl;
    if (A == A) {
        std::cout << "YES";
    }
    else {
        std::cout << "NO";
    }


   
}
