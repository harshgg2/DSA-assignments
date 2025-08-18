#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;

    int original[10][10], transposed[10][10];

    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            cin >> original[r][c];

    for (int c = 0; c < cols; c++)
        for (int r = 0; r < rows; r++)
            transposed[c][r] = original[r][c];

    for (int r = 0; r < cols; r++) {
        for (int c = 0; c < rows; c++)
            cout << transposed[r][c] << " ";
        cout << endl;
    }
}
