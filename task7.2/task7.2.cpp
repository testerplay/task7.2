#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

// Функция для вывода матрицы
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

// Функция для проверки, что столбец содержит только отрицательные элементы
bool isNegativeColumn(const vector<vector<int>>& matrix, int col) {
    for (const auto& row : matrix) {
        if (row[col] >= 0) {
            return false;
        }
    }
    return true;
}

// Функция для обмена двух столбцов в матрице
void swapColumns(vector<vector<int>>& matrix, int col1, int col2) {
    for (auto& row : matrix) {
        swap(row[col1], row[col2]);
    }
}

// Основная функция для решения задачи
void processMatrix(vector<vector<int>>& matrix) {
    int M = matrix.size();
    if (M == 0) return;
    int N = matrix[0].size();
    if (N == 0) return;

    int firstNegativeCol = -1;
    for (int j = 0; j < N; ++j) {
        if (isNegativeColumn(matrix, j)) {
            firstNegativeCol = j;
            break;
        }
    }

    if (firstNegativeCol != -1) {
        swapColumns(matrix, firstNegativeCol, N - 1);
    }
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int M, N;
    cout << "Введите количество строк M и столбцов N: ";
    cin >> M >> N;

    vector<vector<int>> matrix(M, vector<int>(N));
    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> matrix[i][j];
        }
    }

    processMatrix(matrix);

    cout << "Результирующая матрица:" << endl;
    printMatrix(matrix);

    return 0;
}
