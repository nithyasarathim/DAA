#include <iostream>
#include <vector>
using namespace std;
const int N = 5;
// All possible moves of a knight
int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
bool isSafe(int x, int y, vector<vector<int>>& board) {
    return (x >= 0 && y >= 0 && x < N && y < N && board[x][y] == -1);
}
bool solveKnightTour(int x, int y, int moveCount, vector<vector<int>>& board) {
    if (moveCount == N * N) {
        return true;
    }

    for (int i = 0; i < 8; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if (isSafe(nextX, nextY, board)) {
            board[nextX][nextY] = moveCount;

            if (solveKnightTour(nextX, nextY, moveCount + 1, board)) {
                return true;
            }

            board[nextX][nextY] = -1; // Backtrack
        }
    }
    return false;
}
void printBoard(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int cell : row) {
            cout << cell << "\t";
        }
        cout << "\n";
    }
}
int main() {
    vector<vector<int>> board(N, vector<int>(N, -1));
    board[0][0] = 0;
    if (solveKnightTour(0, 0, 1, board)) {
        printBoard(board);
    } else {
        cout << "No solution exists.\n";
    }
    return 0;
}
