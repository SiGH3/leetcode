#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 向左合并一行
vector<int> slide(vector<int>& row) {
  vector<int> newRow;
  for (int num : row) {
      if (num != 0) newRow.push_back(num);
    }
  vector<int> merged;
  int i = 0;
  while (i < newRow.size()) {
      if (i < newRow.size() - 1 && newRow[i] == newRow[i + 1]) {
          merged.push_back(newRow[i] * 2);
          i += 2;
        } else {
          merged.push_back(newRow[i]);
          i++;
        }
    }
  while (merged.size() < row.size()) {
      merged.push_back(0);
    }
  return merged;
}

// 旋转矩阵 90 度
vector<vector<int>> rotate(const vector<vector<int>>& grid) {
  int M = grid.size(), N = grid[0].size();
  vector<vector<int>> rotated(N, vector<int>(M));
  for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
          rotated[j][M - i - 1] = grid[i][j];
        }
    }
  return rotated;
}

// 处理移动方向
vector<vector<int>> move_and_merge(vector<vector<int>> grid, int direction) {
  if (direction == 1) { // 左
      for (auto& row : grid) row = slide(row);
    } else if (direction == 3) { // 右
      for (auto& row : grid) {
          reverse(row.begin(), row.end());
          row = slide(row);
          reverse(row.begin(), row.end());
        }
    } else if (direction == 0 || direction == 2) { // 上或下
      bool reverse_needed = (direction == 2);
      grid = rotate(grid); // 旋转 90° 变成向左问题
      if (reverse_needed) {
          for (auto& row : grid) reverse(row.begin(), row.end());
        }
      for (auto& row : grid) row = slide(row);
      if (reverse_needed) {
          for (auto& row : grid) reverse(row.begin(), row.end());
        }
      grid = rotate(grid); // 旋转回去
      grid = rotate(grid);
      grid = rotate(grid);
    }
  return grid;
}

// 执行一系列操作
vector<vector<int>> simulate_2048(vector<vector<int>> grid, vector<int> moves) {
  for (int move : moves) {
      grid = move_and_merge(grid, move);
    }
  return grid;
}

// 打印矩阵


void printGrid(const vector<vector<int>>& grid) {
  // Loop through the rows in reverse order
  for (int i = grid.size() - 1; i >= 0; --i) {
      for (int num : grid[i]) {
          cout << num << " ";
        }
      cout << endl;
    }
}

int main() {
  int T;
  cin >> T;
  while (T--) {
      int C;
      cin >> C;
      vector<int> moves(C);
      for (int i = 0; i < C; ++i) {
          cin >> moves[i];
        }
      int M, N;
      cin >> M >> N;
      vector<vector<int>> grid(M, vector<int>(N));
      for (int i = 0; i < M; ++i) {
          for (int j = 0; j < N; ++j) {
              cin >> grid[i][j];
            }
        }
      grid = simulate_2048(grid, moves);
      printGrid(grid);
    }
  return 0;
}
/*
2
1 0
4 4
0 32 32 16
0 32 16 16
0 32 16 16
0 32 0 16
2 3 0
4 4
128 16 8 8
0 16 8 8
0 32 8 8
0 0 0 16
 */