#include <iostream>
using namespace std;

int main() {
    int rowsA, colsA, rowsB, colsB;
    cin >> rowsA >> colsA >> rowsB >> colsB;

    int mat1[10][10], mat2[10][10], result[10][10] = {0};

    for (int r = 0; r < rowsA; r++)
        for (int c = 0; c < colsA; c++)
            cin >> mat1[r][c];

    for (int r = 0; r < rowsB; r++)
        for (int c = 0; c < colsB; c++)
            cin >> mat2[r][c];

    if (colsA == rowsB) {
        for (int r = 0; r < rowsA; r++) {
            for (int c = 0; c < colsB; c++) {
                int sum = 0;
                for (int k = 0; k < colsA; k++) {
                    sum += mat1[r][k] * mat2[k][c];
                }
                result[r][c] = sum;
            }
        }

        for (int r = 0; r < rowsA; r++) {
            for (int c = 0; c < colsB; c++)
                cout << result[r][c] << " ";
            cout << "\n";
        }
    }
}
